#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat a=imread("fruits.png",1);
	Mat b(a.rows,2*a.cols,CV_8UC3,Scalar(0,0,0));

	int i,j;
	for(i=0;i<a.rows;i++)
	{
		for(j=a.cols;j<2*a.cols;j++)
		{
			b.at<Vec3b>(i,j)=a.at<Vec3b>(i,j-a.cols);
			b.at<Vec3b>(i,j-a.cols)=a.at<Vec3b>(i,2*a.cols-j);
		}
	}
imshow("IMG",b);
waitKey(10000);

}