// 新建视频.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Size s(320, 240);
	VideoWriter video("D:\\Desktop\\myvideo.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 25, s);
	if (!video.isOpened())
		cerr << "视频未创建";
	Mat img(s, CV_8UC3);
	for (int i = 0; i < 100; i++) {
		img = Scalar(0);
		char text[128];
		snprintf(text, sizeof(text), "%d", i);
		putText(img, text, Point(s.width / 3, s.height / 3), FONT_HERSHEY_SCRIPT_SIMPLEX, 3, Scalar(0, 0, 255), 3, 8);
		video << img;
		uchar a;
	}
}

