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