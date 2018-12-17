// 三通道图像转单通道灰度算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

int main()
{
	//这是彩色图片转换灰度 算法的例子
	//明亮度=0.2989*R+0.5870*G+0.1140*B	公式
	//opencv 默认是BGR  顺序和RGB不一样
	Mat img = imread("D:\\Desktop\\1.jpg", 1);//抓取图片 保存
	Mat imagn(img.size(), CV_8UC1);	//新建图片,像素点长宽和img一样,像素点格式为8位的uchar格式1维
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			imagn.at<uchar>(i, j) = (uchar)(0.2989 * img.at<Vec3b>(i, j)[2] + 0.5870 * img.at<Vec3b>(i, j)[1] + 0.114 * img.at<Vec3b>(i, j)[0]); //灰度值函数
		}
	}
	imwrite("D:\\Desktop\\000.jpg", imagn); //保存图片

	//灰度= (R+G+B)/3 公式
	Mat imagn2(img.size(), CV_8UC1);
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			imagn2.at<uchar>(i, j) = (uchar)((img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3); //平均值
		}
	}
	imwrite("D:\\Desktop\\001.jpg", imagn2); //保存图片 
}


