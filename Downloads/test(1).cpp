#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
Mat img = imread("lenna.png", 1);
imshow("test", img);
waitKey(0);
return 0;
}
