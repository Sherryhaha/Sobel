//
// Created by sunguoyan on 16/4/5.
//

#ifndef SOBEL_SOBEL_H
#define SOBEL_SOBEL_H
#include<opencv2/highgui.hpp>
#include<cv.h>
#include<iostream>
using namespace cv;
using namespace std;
typedef uchar ty;
class Sobel{
public:
    int X_image,Y_image;
    void ToTwoValue(Mat src,Mat dst,int K);
    bool IsOnePoint(Mat src,int x,int y,int K);
    void ToOnePointWide(Mat src,Mat dst,int K);
};


#endif //SOBEL_SOBEL_H
