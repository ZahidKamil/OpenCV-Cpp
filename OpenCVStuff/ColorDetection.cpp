#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat imgHSV, mask;

int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

void main()
{
	string path = "Resources/car.jpg";
	Mat img = imread(path); //Mat - matrix datatype
	
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Minimum", "Trackbars", &hmin, 179);
	createTrackbar("Hue Maximum", "Trackbars", &hmax, 179);
	createTrackbar("Sat Minimum", "Trackbars", &smin, 255);
	createTrackbar("Sat Maximum", "Trackbars", &smax, 255);
	createTrackbar("Val Minimum", "Trackbars", &vmin, 255);
	createTrackbar("Val Maximum", "Trackbars", &vmax, 255);

	while (true)
	{
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Mask", mask);
		waitKey(1); // 0 for infinity
	}

	

}