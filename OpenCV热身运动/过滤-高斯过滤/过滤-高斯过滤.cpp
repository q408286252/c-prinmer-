#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

template<int N>
//公式	H_ij = (1/2派σ) *  e^-( ( (i-k-1)^2+(j-k-1)^2 )/2σ^2 )	左上系数为1
void generateGaussianTemplate(double  window[N][N], int ksize, double sigma)	//ksize行高	sigma正太偏差的宽可以理解为偏差
{
	static const double pi = 3.1415926;
	int center = ksize / 2; // 这里算的是k    2k+1=行和高	
	double x2, y2;
	for (int i = 0; i < ksize; i++)
	{
		x2 = pow(i - center, 2);	//i在公式中从1开始代码从0 默认-1了		(i-k-1)^2
		for (int j = 0; j < ksize; j++)
		{
			y2 = pow(j - center, 2);//(j-k-1)^2
			double g = exp(-(x2 + y2) / (2 * sigma * sigma));	//e^-( ( (i-k-1)^2+(j-k-1)^2 )/2σ^2 )
			g /= 2 * pi * sigma; //H_ij
			window[i][j] = g;
		}
	}
	double k = 1 / window[0][0]; // 算出左上角相乘=1的系数   
	for (int i = 0; i < ksize; i++)
	{
		for (int j = 0; j < ksize; j++)
		{
			window[i][j] *= k;	//最低值归一化为1
		}
	}
}

template<int N>
//H_ij = (1/2派σ) *  e^-( ( (i-k-1)^2+(j-k-1)^2 )/2σ^2 )			所有系数和为1
void generateGaussianTemplatexp(double window[N][N], int ksize, double sigma)
{
	static const double pi = 3.1415926;
	int center = ksize / 2;
	double x2, y2;
	double sum = 0;
	for (int i = 0; i < ksize; i++)
	{
		x2 = pow(i - center, 2);
		for (int j = 0; j < ksize; j++)
		{
			y2 = pow(j - center, 2);
			double g = exp(-(x2 + y2) / (2 * sigma * sigma));
			g /= 2 * pi * sigma;
			sum += g;
			window[i][j] = g;
		}
	}
	for (int i = 0; i < ksize; i++)
	{
		for (int j = 0; j < ksize; j++)
		{
			window[i][j] /= sum;
		}
	}
}

//m*n *(2k+1)*(2k+1)*3
//上面都是别人人为写的 下面是opencv接口的写法
void GaussianFilter(const Mat &src, Mat &dst, int ksize, double sigma)
{
	CV_Assert(src.channels() || src.channels() == 3); // 只处理单通道或者三通道图像
	const static double pi = 3.1415926;
	//生成数组每个数组的元素为双浮点指针, templateMatrix指向第一个元素的double
	double **templateMatrix = new double*[ksize];
	for (int i = 0; i < ksize; i++)
		//templateMatrix第一个元素 改指向一个double数组
		templateMatrix[i] = new double[ksize];
	int origin = ksize / 2; // 以模板的中心为原点
	double x2, y2;
	double sum = 0;
	for (int i = 0; i < ksize; i++)
	{
		x2 = pow(i - origin, 2);
		for (int j = 0; j < ksize; j++)
		{
			y2 = pow(j - origin, 2);
			// 高斯函数前的常数可以不用计算，会在归一化的过程中给消去
			double g = exp(-(x2 + y2) / (2 * sigma * sigma));
			sum += g;
			templateMatrix[i][j] = g;
		}
	}
	for (int i = 0; i < ksize; i++)
	{
		for (int j = 0; j < ksize; j++)
		{
			templateMatrix[i][j] /= sum;
			cout << templateMatrix[i][j] << " ";
		}
		cout << endl;
	}
	// 将模板应用到图像中
	int border = ksize / 2;//k
	copyMakeBorder(src, dst, border, border, border, border, BorderTypes::BORDER_REFLECT);
	Mat src_n = dst;
	int channels = src_n.channels();	//通道数3
	int rows = src_n.rows - border;	//行-k
	int cols = src_n.cols - border;	//宽-k
	for (int i = border; i < rows; i++)	//k行~m-1
	{
		for (int j = border; j < cols; j++)	//k列~n-1
		{
			double sum[3] = { 0 };
			for (int a = -border; a <= border; a++)	//-2 ~ 2
			{
				for (int b = -border; b <= border; b++)	//-2 ~ 2
				{
					if (channels == 1)
					{
						sum[0] += templateMatrix[border + a][border + b] * src_n.at<uchar>(i + a, j + b);
					}
					else if (channels == 3)
					{
						Vec3b rgb = src_n.at<Vec3b>(i + a, j + b);	//(2k+1)*(2k+1) 左上角取出像素~最后右下角
						auto k = templateMatrix[border + a][border + b];	//取出系数
						sum[0] += k * rgb[0]; 
						sum[1] += k * rgb[1];
						sum[2] += k * rgb[2];
					}
				}
			}
			for (int k = 0; k < channels; k++)
			{	//归为0~255
				if (sum[k] < 0)
					sum[k] = 0;
				else if (sum[k] > 255)
					sum[k] = 255;
			}
			if (channels == 1)
				dst.at<uchar>(i, j) = static_cast<uchar>(sum[0]);
			else if (channels == 3)
			{
				Vec3b rgb = { static_cast<uchar>(sum[0]), static_cast<uchar>(sum[1]), static_cast<uchar>(sum[2]) };
				dst.at<Vec3b>(i, j) = rgb;
				//其实这里有问题 用原图像的像素计算写入到图像 会导致之后的像素计算用修改过的值
			}
		}
	}
	// 释放模板数组
	for (int i = 0; i < ksize; i++)
		delete[] templateMatrix[i];
	delete[] templateMatrix;
}

//m*n *(2k+1)*3 + m*n *(2k+1)*3 =  m*n *(2k+1)*3*2  复杂度2/(2k+1)
//每个点ksize次运算 运算玩再ksize次运算
void separateGaussianFilter(const Mat &src, Mat &dst, int ksize, double sigma)
{
	CV_Assert(src.channels() == 1 || src.channels() == 3); // 只处理单通道或者三通道图像
	// 生成一维的高斯滤波模板
	double *matrix = new double[ksize];
	double sum = 0;
	int origin = ksize / 2;
	for (int i = 0; i < ksize; i++)
	{
		// 高斯函数前的常数可以不用计算，会在归一化的过程中给消去
		double g = exp(-(i - origin) * (i - origin) / (2 * sigma * sigma));
		sum += g;
		matrix[i] = g;
	}
	// 归一化
	for (int i = 0; i < ksize; i++) 
	{
		matrix[i] /= sum;
		cout << matrix[i] << " ";
	}
	// 将模板应用到图像中
	int border = ksize / 2;
	copyMakeBorder(src, dst, border, border, border, border, BorderTypes::BORDER_REFLECT);
	int channels = dst.channels();
	int rows = dst.rows - border;
	int cols = dst.cols - border;
	// 水平方向
	for (int i = border; i < rows; i++)
	{
		for (int j = border; j < cols; j++)
		{
			double sum[3] = { 0 };
			for (int k = -border; k <= border; k++)
			{
				if (channels == 1)
				{
					sum[0] += matrix[border + k] * dst.at<uchar>(i, j + k); // 行不变，列变化；先做水平方向的卷积
				}
				else if (channels == 3)
				{
					Vec3b rgb = dst.at<Vec3b>(i, j + k);
					sum[0] += matrix[border + k] * rgb[0];
					sum[1] += matrix[border + k] * rgb[1];
					sum[2] += matrix[border + k] * rgb[2];
				}
			}
			for (int k = 0; k < channels; k++)
			{
				if (sum[k] < 0)
					sum[k] = 0;
				else if (sum[k] > 255)
					sum[k] = 255;
			}
			if (channels == 1)
				dst.at<uchar>(i, j) = static_cast<uchar>(sum[0]);
			else if (channels == 3)
			{
				Vec3b rgb = { static_cast<uchar>(sum[0]), static_cast<uchar>(sum[1]), static_cast<uchar>(sum[2]) };
				dst.at<Vec3b>(i, j) = rgb;
			}
		}
	}
	// 竖直方向
	for (int i = border; i < rows; i++)
	{
		for (int j = border; j < cols; j++)
		{
			double sum[3] = { 0 };
			for (int k = -border; k <= border; k++)
			{
				if (channels == 1)
				{
					sum[0] += matrix[border + k] * dst.at<uchar>(i + k, j); // 列不变，行变化；竖直方向的卷积
				}
				else if (channels == 3)
				{
					Vec3b rgb = dst.at<Vec3b>(i + k, j);
					sum[0] += matrix[border + k] * rgb[0];
					sum[1] += matrix[border + k] * rgb[1];
					sum[2] += matrix[border + k] * rgb[2];
				}
			}
			for (int k = 0; k < channels; k++)
			{
				if (sum[k] < 0)
					sum[k] = 0;
				else if (sum[k] > 255)
					sum[k] = 255;
			}
			if (channels == 1)
				dst.at<uchar>(i, j) = static_cast<uchar>(sum[0]);
			else if (channels == 3)
			{
				Vec3b rgb = { static_cast<uchar>(sum[0]), static_cast<uchar>(sum[1]), static_cast<uchar>(sum[2]) };
				dst.at<Vec3b>(i, j) = rgb;
			}
		}
	}
	delete[] matrix;
}

int main()
{
	double t = (double)getTickCount();
	int i = 1;
	double fix[3][3], sigma = 1;//sigma为偏差 偏差越大正太越平缓
	int ksize = i;
	Mat img = imread("D:\\Desktop\\1.jpg", 1);
	/*
	GaussianFilter(img, img, i*2+1, 5.0);
	//separateGaussianFilter(img, img, i*2+1, 5.0);
	Rect r(i, i, img.rows - 2*i, img.cols - 2*i);
	Mat smallImg = img(r);
	*/
	medianBlur(img, img, 1);
	t = (double)getTickCount() - t;
	printf("detection time = %g ms\n", t * 1000 / getTickFrequency());
	imshow("a", img);
	waitKey(0);

}