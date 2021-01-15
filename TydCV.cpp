#include "cv.hpp"

void TydCV::deviceQuery() {  
    //获取显卡简单信息
    cuda::printShortCudaDeviceInfo(cuda::getDevice());  //有显卡信息表示GPU模块配置成功
    //获取显卡详细信息
    cuda::printCudaDeviceInfo(cuda::getDevice());  //有显卡信息表示GPU模块配置成功
    //获取显卡设备数量
    int Device_Num = cuda::getCudaEnabledDeviceCount();
    cout << Device_Num << endl;  //返回值大于0表示GPU模块配置成功
    //获取显卡设备状态
    cuda::DeviceInfo Device_State;
    bool Device_OK = Device_State.isCompatible();
    cout << "Device_State: " << Device_OK << endl;  //返回值大于0表示GPU模块配置成功
}

void TydCV::colorSpace(Mat& image) {
    GpuMat src, gray, hsv;
    src.upload(image);
    cuda::cvtColor(src, gray, COLOR_BGR2GRAY);
    cuda::cvtColor(src, hsv, COLOR_BGR2HSV);
    Mat _gray, _hsv;
    gray.download(_gray);
    hsv.download(_hsv);
    imshow("virgin", image);
    imshow("gray", _gray);
    imshow("hsv", _hsv);

}

void TydCV::colorSpace(Mat& image, string filename) {
    GpuMat src, gray, hsv;
    src.upload(image);
    cuda::cvtColor(src, gray, COLOR_BGR2GRAY);
    cuda::cvtColor(src, hsv, COLOR_BGR2HSV);
    Mat _gray, _hsv;
    gray.download(_gray);
    hsv.download(_hsv);
    imshow("virgin", image);
    imshow("gray", _gray);
    imshow("hsv", _hsv);
    imwrite(IMG_PATH + "gray_" + filename, _gray);
    imwrite(IMG_PATH + "hsv_" + filename, _hsv);
}

Mat TydCV::createA() {
    Mat a = Mat(12, 12, CV_8UC1, 255);   //创建空白灰度图像
    // cout << "width:" << a.cols << ",height:" << a.rows << ",channels:" << a.channels() << endl;
    int width = a.cols;
    int height = a.rows;
    int dims = a.channels();
    for(int row = 0; row < width; row++) {
        for(int col = 0; col < height; col++) {
            if(dims == 1) {  //灰度图像
                a.at<uchar>(1,5) = 0;
                a.at<uchar>(1,6) = 0;
                a.at<uchar>(2,4) = 0;
                a.at<uchar>(2,5) = 0;
                a.at<uchar>(2,6) = 0;
                a.at<uchar>(2,7) = 0;
                a.at<uchar>(3,3) = 0;
                a.at<uchar>(3,4) = 0;
                a.at<uchar>(3,5) = 0;
                a.at<uchar>(3,6) = 0;
                a.at<uchar>(3,7) = 0;
                a.at<uchar>(3,8) = 0;
                a.at<uchar>(4,2) = 0;
                a.at<uchar>(4,3) = 0;
                a.at<uchar>(4,4) = 0;
                a.at<uchar>(4,7) = 0;
                a.at<uchar>(4,8) = 0;
                a.at<uchar>(4,9) = 0;
                a.at<uchar>(5,2) = 0;
                a.at<uchar>(5,3) = 0;
                a.at<uchar>(5,8) = 0;
                a.at<uchar>(5,9) = 0;
                a.at<uchar>(6,2) = 0;
                a.at<uchar>(6,3) = 0;
                a.at<uchar>(6,8) = 0;
                a.at<uchar>(6,9) = 0;
                a.at<uchar>(7,2) = 0;
                a.at<uchar>(7,3) = 0;
                a.at<uchar>(7,4) = 0;
                a.at<uchar>(7,5) = 0;
                a.at<uchar>(7,6) = 0;
                a.at<uchar>(7,7) = 0;
                a.at<uchar>(7,8) = 0;
                a.at<uchar>(7,9) = 0;
                a.at<uchar>(8,2) = 0;
                a.at<uchar>(8,3) = 0;
                a.at<uchar>(8,4) = 0;
                a.at<uchar>(8,5) = 0;
                a.at<uchar>(8,6) = 0;
                a.at<uchar>(8,7) = 0;
                a.at<uchar>(8,8) = 0;
                a.at<uchar>(8,9) = 0;
                a.at<uchar>(9,2) = 0;
                a.at<uchar>(9,3) = 0;
                a.at<uchar>(9,8) = 0;
                a.at<uchar>(9,9) = 0;
                a.at<uchar>(10,2) = 0;
                a.at<uchar>(10,3) = 0;
                a.at<uchar>(10,8) = 0;
                a.at<uchar>(10,9) = 0;
            } else if(dims == 3) {  //彩色图像
                Vec3b bgr = a.at<Vec3b>(row,col);
                int blue = a.at<Vec3b>(row,col)[0];  //B通道数据
                int green = a.at<Vec3b>(row,col)[1]; //G通道数据
                int red = a.at<Vec3b>(row,col)[2];   //R通道数据
            }
        }
    }
    cout << a << endl;
    return a;
}

Mat TydCV::createBGR() {
    Mat a = Mat(300, 300, CV_8UC3, Scalar(0,0,0)); 
    // cout << "width:" << a.cols << ",height:" << a.rows << ",channels:" << a.channels() << endl;
    int width = a.cols; //列数，反映矩阵宽度
    int height = a.rows; //行数，反映矩阵高度
    int dims = a.channels();
    for(int row = 0; row < width; row++) {
        if(row < 100) { //0<=row<100
            for(int col = 0; col < height; col++) {
                Vec3b bgr = a.at<Vec3b>(row,col);
                a.at<Vec3b>(row,col)[0] = 255;
            }
        } else if(row < 200) { //100<=row<200
            for(int col = 0; col < height; col++) {
                Vec3b bgr = a.at<Vec3b>(row,col);
                a.at<Vec3b>(row,col)[1] = 255;
            }
        } else { //200<=row<300
            for(int col = 0; col < height; col++) {
                Vec3b bgr = a.at<Vec3b>(row,col);
                a.at<Vec3b>(row,col)[2] = 255;
            }
        }
    }
    return a;
}