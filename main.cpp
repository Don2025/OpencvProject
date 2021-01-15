#include "cv.hpp"
string IMG_PATH = "D:/Code/CppCode/OpencvProject/img/";

int main() {
    // Mat lena = imread(IMG_PATH+"lena.png");
    TydCV demo;
    Mat BGR = demo.createBGR();
    imshow("BGR",BGR);
    waitKey(0);
    return 0;
}
