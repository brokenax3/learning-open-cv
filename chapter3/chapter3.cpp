#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

/**********************************************************************
*                       Image Resize and Crop                        *
**********************************************************************/

int main() {
    
    string path = "../resources/test.png";

    Mat img = imread(path);
    Mat imgResize, imgCrop;

    resize(img, imgResize, Size(), 0.5, 0.5);

    Rect roi(100, 100, 300, 250);
    imgCrop = img(roi);


    /* cout << img.size() << endl; */
    /* imshow("Resized Image", imgResize); */
    imshow("Resized Image", imgResize);
    imshow("Crop Image", imgCrop);


    waitKey(0);

    return 1;
}
