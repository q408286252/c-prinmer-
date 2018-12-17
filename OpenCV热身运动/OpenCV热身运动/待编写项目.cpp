
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include "pch.h"

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

int main(int argc, const char** argv)
{
	/*
	double fix[3][3], sigma = 1;//sigma为偏差 偏差越大正太越平缓
	int ksize = 3;
	generateGaussianTemplatexp<3>(fix, ksize, sigma);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			cout << fix[i][j] << "  ";
		cout << '\n';
	}
	*/

	Mat img = imread("D:\\Desktop\\1.jpg", 1);
	cout << img.channels();
	img = imread("D:\\Desktop\\1.jpg", 0);
	cout << "\n" << img.channels();
	//imwrite("D:\\Desktop\\001.jpg",img);
}


