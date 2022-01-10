#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;


/**********************************************************************
*                          Shape Detection                           *
**********************************************************************/
int hmin = 0, smin = 0, vmin = 0;
int hmax = 0, smax= 0, vmax = 0;

void getContours(Mat imgDil, Mat img) {

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());
    /* drawContours(img, contours, -1, Scalar(255, 0, 0), 2); */
    int count = 0;

    for(vector<Point> contour : contours) {
        int area = contourArea(contour);

        if(area > 500){

            float peri = arcLength(contour, true);

            approxPolyDP(contour, conPoly[count], 0.02*peri, true);

            drawContours(img, conPoly, count, Scalar(255, 0, 0), 2);

            // Print the number of corners of a contour
            /* cout << conPoly[count].size() << endl; */

            // Draw a bounding rectangle arount the contour
            boundRect[count] = boundingRect(conPoly[count]);
            rectangle(img, boundRect[count].tl(), boundRect[count].br(), Scalar(0, 255, 0));

            // Find the number of corners
            string objType;
            int objCorner = (int) conPoly[count].size();
            float ratio;
            switch (objCorner) {
                case 3:
                    objType = "Triangle";
                    break;
                case 4:
                    ratio = (float) boundRect[count].height / (float) boundRect[count].width;
                    if (ratio <= 1.05 && ratio >= 0.95) {
                        objType = "Square";
                    } else {
                        objType = "Rectangle";
                    }
                    break;
                default:
                    objType = "Circle";
            }

            putText(img, objType, {boundRect[count].x, boundRect[count].y - 2}, FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255), 1);
        }
        count++;
    }

}

int main() {

    Mat imgBlur, imgGrey, imgCanny, imgCannyNoBlur, imgDil, imgDilNoBlur;

    Mat img = imread("../resources/shapes.png");

    cvtColor(img, imgGrey, COLOR_BGR2GRAY);
    GaussianBlur(imgGrey, imgBlur, Size(5, 5), 10, 5);
    Canny(imgBlur, imgCanny, 25, 75);
    Canny(imgGrey, imgCannyNoBlur, 25, 75);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

    dilate(imgCanny, imgDil, kernel);
    dilate(imgCannyNoBlur, imgDilNoBlur, kernel);

    getContours(imgDilNoBlur, img);

    /* imshow("Image Blur", imgBlur); */
    imshow("Image Canny", imgCanny);
    /* imshow("Image Canny No Blur", imgCannyNoBlur); */
    imshow("Image Dil", imgDil);
    /* imshow("Image Dil No Blur", imgDilNoBlur); */
    imshow("Image", img);



    waitKey(0);
    return 1;
}
