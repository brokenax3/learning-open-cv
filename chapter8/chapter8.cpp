#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/objdetect.hpp>
#include <string>

using namespace cv;
using namespace std;

int main() {

    /* Mat img = imread("../resources/test.png"); */
    VideoCapture cap(0);
    Mat img;

    CascadeClassifier faceCascade;
    faceCascade.load("../resources/haarcascade_frontalface_default.xml");

    if (faceCascade.empty()) {
        cout << "XML File not loaded" << endl;
    }

    while (true) {
        vector<Rect> faces;
        cap.read(img);
        faceCascade.detectMultiScale(img, faces, 1.1, 10);

        for (Rect face : faces){
            rectangle(img, face, Scalar(255, 0, 0));

        }

        imshow("Image", img);

        waitKey(20);
    }
    return 1;
}
