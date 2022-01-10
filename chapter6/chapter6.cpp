#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

/**********************************************************************
*                          Color Detection                           *
**********************************************************************/
int hmin = 0, smin = 0, vmin = 0;
int hmax = 0, smax= 0, vmax = 0;

void test(int x){
}
    
int main() {

    Mat imgHSV, mask;

    Mat img = imread("../resources/lambo.png");

    cvtColor(img, imgHSV, COLOR_BGR2HSV);
    
    namedWindow("Trackbar", (700, 200));
    createTrackbar("Hue Min", "Trackbar", &hmin, 180);
    createTrackbar("Sat Min", "Trackbar", &smin, 255);
    createTrackbar("Val Min", "Trackbar", &vmin, 255);

    createTrackbar("Hue Max", "Trackbar", &hmax, 180);
    createTrackbar("Sat Max", "Trackbar", &smax, 255);
    createTrackbar("Val Max", "Trackbar", &vmax, 255);


    while (true) {

        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);

        inRange(imgHSV, lower, upper, mask);

        imshow("Image", img);
        imshow("Image HSV", imgHSV);
        imshow("Mask", mask);

        waitKey(1);
    }
    return 1;
}
