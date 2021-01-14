#include "cv.hpp"

void TydCV::deviceQuery() {  
    //��ȡ�Կ�����Ϣ
    cuda::printShortCudaDeviceInfo(cuda::getDevice());  //���Կ���Ϣ��ʾGPUģ�����óɹ�
    //��ȡ�Կ���ϸ��Ϣ
    cuda::printCudaDeviceInfo(cuda::getDevice());  //���Կ���Ϣ��ʾGPUģ�����óɹ�
    //��ȡ�Կ��豸����
    int Device_Num = cuda::getCudaEnabledDeviceCount();
    cout << Device_Num << endl;  //����ֵ����0��ʾGPUģ�����óɹ�
    //��ȡ�Կ��豸״̬
    cuda::DeviceInfo Device_State;
    bool Device_OK = Device_State.isCompatible();
    cout << "Device_State: " << Device_OK << endl;  //����ֵ����0��ʾGPUģ�����óɹ�
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