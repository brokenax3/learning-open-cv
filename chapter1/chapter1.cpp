#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

/**********************************************************************
*                       This imports an image                        *
**********************************************************************/
int import_image() {
    
    string path = "../resources/test.png";

    Mat img = imread(path);

    imshow("Image", img);
    waitKey(0);

    return 1;
}

/**********************************************************************
*                        This imports a video                        *
**********************************************************************/
int import_video() {

    VideoCapture cap("../resources/test_video.mp4");
    Mat img;

    while(true) {
        cap.read(img);
        imshow("Video", img);
        waitKey(20);
    }
}

/**********************************************************************
*                        This uses the webcam                        *
**********************************************************************/
int use_webcam() {

    VideoCapture cap(0);
    Mat img;

    while(true) {
        cap.read(img);
        imshow("Video", img);
        waitKey(20);
    }
}
