#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

int main(int,char**)
{
VideoCapture cap(0);
if(!cap.isOpened())
return -1;
Mat img1;
namedWindow("IMG",WINDOW_NORMAL);
while(1)
	{
	Mat img;
	cap>>img;
	Canny(img,img1,400,700,5);
	imshow("IMG",img1);
	waitKey(1);
	}
}
