#include "pch.h"
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
//#include "pch.h" 新建图片

using namespace std;
using namespace cv;

/* 660ms 一针 的脸部检测算法*/

static void help()
{
	cout << "\nThis program demonstrates the use of cv::CascadeClassifier class to detect objects (Face + eyes). You can use Haar or LBP features.\n"
		"This classifier can recognize many kinds of rigid objects, once the appropriate classifier is trained.\n"
		"It's most known use is for faces.\n"
		"Usage:\n"
		"./facedetect [--cascade=<cascade_path> this is the primary trained classifier such as frontal face]\n"
		"   [--nested-cascade[=nested_cascade_path this an optional secondary classifier such as eyes]]\n"
		"   [--scale=<image scale greater or equal to 1, try 1.3 for example>]\n"
		"   [--try-flip]\n"
		"   [filename|camera_index]\n\n"
		"see facedetect.cmd for one call:\n"
		"./facedetect --cascade=\"data/haarcascades/haarcascade_frontalface_alt.xml\" --nested-cascade=\"data/haarcascades/haarcascade_eye_tree_eyeglasses.xml\" --scale=1.3\n\n"
		"During execution:\n\tHit any key to quit.\n"
		"\tUsing OpenCV version " << CV_VERSION << "\n" << endl;
}

void detectAndDraw(
	Mat& img, CascadeClassifier& cascade, CascadeClassifier& nestedCascade, double scale, bool tryflip);

string cascadeName;
string nestedCascadeName;

int main(int argc, const char** argv)
{
	VideoCapture capture;
	Mat frame, image;
	string inputName;
	bool tryflip;
	//阶梯 分类器
	CascadeClassifier cascade, nestedCascade;
	double scale;

	//命令行解释器
	cv::CommandLineParser parser(argc, argv,
		"{help h||}"
		"{cascade|data/haarcascades/haarcascade_frontalface_alt.xml|}"
		"{nested-cascade|data/haarcascades/haarcascade_eye_tree_eyeglasses.xml|}"
		"{scale|1|}{try-flip||}{@filename||}"
	);
	//查找终端传参是否有 help
	if (parser.has("help"))
	{
		help();
		return 0;
	}


	//string cascadeName   查找标签cascade的值	
	cascadeName = parser.get<string>("cascade");
	//string nestedCascadeName   查找标签nested-cascade的值	
	nestedCascadeName = parser.get<string>("nested-cascade");
	//double scale 查找标签scale的值	
	scale = parser.get<double>("scale");
	//double scale 永远>=1
	if (scale < 1)
		scale = 1;
	//bool tryflip   查找是否有try-flip 是否反转
	tryflip = parser.has("try-flip");
	//吧inputName理解相机编号的string     string inputName   查找标签@filename的值
	inputName = parser.get<string>("@filename");


	//parser.check() 检查parser是否错误 错误则false
	if (!parser.check()) {
		//打印错误信息
		parser.printErrors();
		return 0;
	}
	//没有就运行的报错 提示
	//加载 阶梯 分级器 读取(样本查找并保留 (string nestedCascadeName) )
	if (!nestedCascade.load(cv::samples::findFileOrKeep(nestedCascadeName)))
		cerr << "WARNING: Could not load classifier cascade for nested objects" << endl;
	//同理没有就运行的报错 提示
	if (!cascade.load(cv::samples::findFile(cascadeName))) {
		cerr << "ERROR: Could not load classifier cascade" << endl;
		help();
		return -1;
	}


	//如果相机编号  为空  或   [0]是数字且就1字符
	if (inputName.empty() || (isdigit(inputName[0]) && inputName.size() == 1)) {
		//空则 0  不空则输出数字;  也就是返回相机编号
		int camera = inputName.empty() ? 0 : inputName[0] - '0';
		//打不开相机则
		if (!capture.open(camera)) {
			cout << "Capture from camera #" << camera << " didn't work" << endl;
			return 1;
		}
		//相机编号不空 且不是"一个数字" 时
	}
	else if (!inputName.empty()) {
		//   加载图片     样本直接查找这个"相机编号"		IMREAD_COLOR默认1
		image = imread(cv::samples::findFileOrKeep(inputName), IMREAD_COLOR);
		//空则
		if (image.empty()) {
			if (!capture.open(cv::samples::findFileOrKeep(inputName))) {
				cout << "Could not read " << inputName << endl;
				return 1;
			}
		}
		//什么情况会运行这个..我很好奇 应该可以删掉										有疑问
	}
	else {
		image = imread(cv::samples::findFile("lena.jpg"), IMREAD_COLOR);
		if (image.empty()) {
			cout << "Couldn't read lena.jpg" << endl;
			return 1;
		}
	}


	//相机打开了则
	if (capture.isOpened()) {
		cout << "Video capturing has been started ..." << endl;
		for (;;) {
			//传图
			capture >> frame;
			if (frame.empty())
				break;
			//拷贝对象给 frame1														为什么拷贝?我已经注销了
			//Mat frame1 = frame.clone();
			//			 图片 , 阶梯分级器1,  阶梯分级器1, double的数量,是否反转bool
			//detectAndDraw(frame1, cascade, nestedCascade, scale, tryflip);
			detectAndDraw(frame, cascade, nestedCascade, scale, tryflip);
			//按键Q q结束
			char c = (char)waitKey(10);
			if (c == 27 || c == 'q' || c == 'Q')
				break;
		}
		//没打开相机则
	}
	else {
		cout << "Detecting face(s) in " << inputName << endl;
		//图片不为空则
		if (!image.empty()) {
			detectAndDraw(image, cascade, nestedCascade, scale, tryflip);
			waitKey(0);
			//图片空 且 相机编号不空	怀疑是一个文本目录
		}
		else if (!inputName.empty()) {
			//FILE文件类型 
			FILE* f;
			//打开 "相机编号" 文件
			fopen_s(&f, inputName.c_str(), "rt");
			//打开了则
			if (f) {
				//天啊我讨厌 char[] 日的狗的c语言
				char buf[1000 + 1];
				//f指针文件 吧string 传char[]的buf
				while (fgets(buf, 1000, f)) {
					//识别buf 多少字符
					int len = (int)strlen(buf);
					//字符大于0 且 最后一字符是空格
					while (len > 0 && isspace(buf[len - 1]))
						len--;
					//不是空格了就 添加\0
					buf[len] = '\0';
					cout << "file " << buf << endl;
					//加载图片
					image = imread(buf, 1);
					//图片不空则
					if (!image.empty()) {
						detectAndDraw(image, cascade, nestedCascade, scale, tryflip);
						//按Q q退出
						char c = (char)waitKey(0);
						if (c == 27 || c == 'q' || c == 'Q')
							break;
						//图片空则
					}
					else {
						cerr << "Aw snap, couldn't read image " << buf << endl;
					}
				}
				//关闭文件
				fclose(f);
			}
		}
	}

	return 0;
}

//图片		阶梯 分类器																是否反转
void detectAndDraw(Mat& img, CascadeClassifier& cascade, CascadeClassifier& nestedCascade, double scale, bool tryflip) {
	double t = 0;
	vector<Rect> faces, faces2;
	const static Scalar colors[] =
	{
		Scalar(255,0,0),
		Scalar(255,128,0),
		Scalar(255,255,0),
		Scalar(0,255,0),
		Scalar(0,128,255),
		Scalar(0,255,255),
		Scalar(0,0,255),
		Scalar(255,0,255)
	};
	Mat gray, smallImg;
	//gray 生成灰度图像

	cvtColor(img, smallImg, COLOR_BGR2GRAY);
	//cvtColor(img, gray, COLOR_BGR2GRAY);															注释了
	double fx = 1 / scale;
	//调整图片 输出smallimg  Mat,Mat,长宽空不改, 阀1,阀2,INTER_LINEAR_EXACT默认=5线性互相之间的精确值
	resize(smallImg, smallImg, Size(), fx, fx, INTER_LINEAR_EXACT);
	//resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR_EXACT);									注释了			
	//均匀灰度图像直方图算法
	equalizeHist(smallImg, smallImg);
	//计数t
	t = (double)getTickCount();
	//阶梯 分类器 传入图片 和 矩阵 double, int, int Size
	cascade.detectMultiScale(smallImg, faces,
		1.1, 2, 0
		//|CASCADE_FIND_BIGGEST_OBJECT
		//|CASCADE_DO_ROUGH_SEARCH
		| CASCADE_SCALE_IMAGE,
		Size(30, 30));
	//如果反转
	if (tryflip)
	{
		flip(smallImg, smallImg, 1);
		cascade.detectMultiScale(smallImg, faces2,
			1.1, 2, 0
			//|CASCADE_FIND_BIGGEST_OBJECT
			//|CASCADE_DO_ROUGH_SEARCH
			| CASCADE_SCALE_IMAGE,
			Size(30, 30));
		for (vector<Rect>::const_iterator r = faces2.begin(); r != faces2.end(); ++r)
		{
			faces.push_back(Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
		}
	}
	//在计数 算时间差t
	t = (double)getTickCount() - t;
	//显示用时
	printf("detection time = %g ms\n", t * 1000 / getTickFrequency());
	for (size_t i = 0; i < faces.size(); i++)
	{
		Rect r = faces[i];
		Mat smallImgROI;
		vector<Rect> nestedObjects;
		Point center;
		Scalar color = colors[i % 8];
		int radius;

		double aspect_ratio = (double)r.width / r.height;
		if (0.75 < aspect_ratio && aspect_ratio < 1.3)
		{
			center.x = cvRound((r.x + r.width*0.5)*scale);
			center.y = cvRound((r.y + r.height*0.5)*scale);
			radius = cvRound((r.width + r.height)*0.25*scale);
			circle(img, center, radius, color, 3, 8, 0);
		}
		else
			rectangle(img, Point(cvRound(r.x*scale), cvRound(r.y*scale)),
				Point(cvRound((r.x + r.width - 1)*scale), cvRound((r.y + r.height - 1)*scale)),
				color, 3, 8, 0);
		if (nestedCascade.empty())
			continue;
		smallImgROI = smallImg(r);
		nestedCascade.detectMultiScale(smallImgROI, nestedObjects,
			1.1, 2, 0
			//|CASCADE_FIND_BIGGEST_OBJECT
			//|CASCADE_DO_ROUGH_SEARCH
			//|CASCADE_DO_CANNY_PRUNING
			| CASCADE_SCALE_IMAGE,
			Size(30, 30));
		for (size_t j = 0; j < nestedObjects.size(); j++)
		{
			Rect nr = nestedObjects[j];
			center.x = cvRound((r.x + nr.x + nr.width*0.5)*scale);
			center.y = cvRound((r.y + nr.y + nr.height*0.5)*scale);
			radius = cvRound((nr.width + nr.height)*0.25*scale);
			circle(img, center, radius, color, 3, 8, 0);
		}
	}
	imshow("result", img);
}


