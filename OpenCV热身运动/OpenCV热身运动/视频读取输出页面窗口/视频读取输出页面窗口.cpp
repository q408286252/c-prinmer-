// 视频读取输出页面窗口.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//视频读取输出的简单例子
	VideoCapture capture(0);
	//VideoCapture capture("D:\\Desktop\\1.mp4");
	if (!capture.isOpened()) {
		cerr << "视频没加载哦!";
		return -1;
	}
	Mat img2;

	while (1) {
		Mat img;
		capture >> img;
		if (img.empty()) {
			cerr << "图片没加载到哦";
			break;
		}
		cvtColor(img, img2, COLOR_BGR2GRAY);
		Canny(img2, img2, 0, 30, 3);
		imshow("视频", img2);
		waitKey(10);
	}
}