// OpenCV热身运动.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>

using namespace std;
using namespace cv;

int main(){
	
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

	}
	/*

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
	*/

}



/*
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







Mat img = imread("D:\\Desktop\\1.jpg",1);//这里的文件路径要自己选择，注意是“\\”而不是“\”
//Mat img2 = 255-img; //灰度反转

float pixels[256];
for (int i = 0; i < 256; i++)
	pixels[i] = pow(i,2.0/5.0);
Mat imagn(img.size(), CV_32FC3);
for (int i = 0; i < img.rows; i++){
	for (int j = 0; j < img.cols; j++){
		imagn.at<Vec3f>(i, j)[0] = pixels[img.at<Vec3b>(i, j)[0]];
		imagn.at<Vec3f>(i, j)[1] = pixels[img.at<Vec3b>(i, j)[1]];
		imagn.at<Vec3f>(i, j)[2] = pixels[img.at<Vec3b>(i, j)[2]];
	}
}
//归一化到0~255
normalize(imagn, imagn, 0, 255, NORM_MINMAX);
//转换成8bit图像显示
convertScaleAbs(imagn, imagn);

imwrite("D:\\Desktop\\000.jpg", imagn); //保存图片

*/
