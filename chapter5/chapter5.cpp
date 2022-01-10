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
    
    Mat imgWarp, matrix;

    float w = 250, h = 350;
    Mat img = imread("../resources/cards.jpg");

    Point2f src[4] = {
        {529, 142},
        {771, 190},
        {405, 395},
        {674, 457}
    };

    Point2f dst[4] = {
        {0.0f, 0.0f},
        {w, 0.0f},
        {0.0f, h},
        {w, h}
    };

    
    matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, imgWarp, matrix, Point(w, h));

    imshow("Image", img);
    imshow("Image Warp", imgWarp);

    waitKey(0);

    return 1;
}
