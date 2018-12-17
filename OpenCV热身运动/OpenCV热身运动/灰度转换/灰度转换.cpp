// 灰度转换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat img = imread("D:\\Desktop\\4.jpg", 1);
	//Mat img2 = 255-img; //灰度反转

	float pixels[256];
	for (int i = 0; i < 256; ++i)
		//	pixels[i] = (float)pow(i, 2);			x^2指数
		//	pixels[i] = (float)pow(i, 2.0 / 5.0);	x^0.4指数
		pixels[i] = (float)log(1 + i);		//	log(1+x)
	Mat imagn(img.size(), CV_32FC3);
	for (int i = 0; i < img.rows; ++i) {
		for (int j = 0; j < img.cols; ++j) {
			imagn.at<Vec3f>(i, j)[0] = pixels[img.at<Vec3b>(i, j)[0]];
			imagn.at<Vec3f>(i, j)[1] = pixels[img.at<Vec3b>(i, j)[1]];
			imagn.at<Vec3f>(i, j)[2] = pixels[img.at<Vec3b>(i, j)[2]];
		}
	}
	//归一化到0~255
	normalize(imagn, imagn, 0, 255, NORM_MINMAX);
	//转换成8bit图像显示
	//convertScaleAbs(imagn, imagn);

	imwrite("D:\\Desktop\\004.jpg", imagn); //保存图片
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
