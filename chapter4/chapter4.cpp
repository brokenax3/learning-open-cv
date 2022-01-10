#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

/**********************************************************************
*                           Warping Images                           *
**********************************************************************/

int main() {
    
    Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

    circle(img, Point(256, 256), 155, Scalar(10, 10, 155));
    rectangle(img, Point(10, 10), Point(110, 110), Scalar(255, 10, 10), FILLED);

    imshow("Image", img);

    waitKey(0);

    return 1;
}
