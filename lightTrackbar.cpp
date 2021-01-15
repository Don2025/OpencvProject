#include "cv.hpp"

Mat src, dst, m;
int lightness;

static void on_track(int,void*) {
    m = Scalar(lightness, lightness, lightness);
    cv::add(src, m, dst);
    imshow("���ȵ���", dst);
}

void TydCV::lightTrackbar(Mat& image) {
    namedWindow("���ȵ���", WINDOW_AUTOSIZE);
    dst = Mat::zeros(image.size(),image.type());
    m = Mat::zeros(image.size(),image.type());
    src = image;
    int max_value = 100;
    lightness = 50;
    createTrackbar("Light Trackbar","���ȵ���", &lightness, max_value, on_track);
    on_track(50,0);
}