#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

/**********************************************************************
*                         Image Manipulation                          *
**********************************************************************/
int main() {
    
    string path = "../resources/test.png";

    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgDilate, imgErode;

    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
    Canny(imgGray, imgCanny, 25, 100);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDilate, kernel);

    erode(imgDilate, imgErode, kernel);

    imshow("Image", img);
    imshow("Gray Image", imgGray);
    imshow("Blur Image", imgBlur);
    imshow("Canny Image", imgCanny);
    imshow("Dilate Image", imgDilate);
    imshow("Erode Image", imgErode);

    waitKey(0);

    return 1;
}
