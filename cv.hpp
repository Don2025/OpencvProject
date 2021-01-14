#include <opencv2/opencv.hpp>
#include <opencv2/opencv_modules.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudaoptflow.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/cudafeatures2d.hpp>
#include <opencv2/cudaobjdetect.hpp>
#include <opencv2/cudawarping.hpp>
#include <opencv2/cudafilters.hpp>
#include <bits/stdc++.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2\imgproc\types_c.h>

using namespace std;
using namespace cv;
using namespace cv::cuda;
using namespace cv::dnn;

class TydCV {
private:
    string IMG_PATH;
public:
    TydCV() {
        cout << "Built with OpenCV " << CV_VERSION << endl;
    }
    void deviceQuery(); //CUDA�豸��ѯ
    void colorSpace(Mat& image); //ͼ��ɫ�ʿռ�ת��
    void colorSpace(Mat &image, string filename); //ͼ��ɫ�ʿռ�ת��, �ɱ���ͼ��
    ~TydCV() {
        waitKey(0);
        destroyAllWindows();
    }
};