#include "cv.hpp"
string IMG_PATH = "D:/Code/CppCode/OpencvProject/img/";

int main() {
    Mat lena = imread(IMG_PATH+"lena.png",1);
    TydCV demo;
    demo.colorSpace(lena);
    waitKey(0);
    return 0;
}
