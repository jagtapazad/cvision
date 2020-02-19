#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()

{
Mat a=imread("fruits.png",1);
imshow("IMG",a);
waitKey(2000); //0 for infinite 

Mat b(a.rows,a.cols,CV_8UC1,Scalar(255));

int i,j;
	for(i=0;i<a.rows;i++)
	{
		for(j=0;j<a.cols;j++)
		{
				b.at<uchar>(i,j)=(a.at<Vec3b>(i,j)[0]+a.at<Vec3b>(i,j)[1]+a.at<Vec3b>(i,j)[2])/3;
	    }
	}
imshow("IMG",b);
waitKey(2000);

Mat c(a.rows,a.cols,CV_8UC1,Scalar(255));
	for(i=0;i<a.rows;i++)
	{
		for(j=0;j<a.cols;j++)
		{
				c.at<uchar>(i,j)=0.299*a.at<Vec3b>(i,j)[2]+0.587*a.at<Vec3b>(i,j)[1]+0.11*a.at<Vec3b>(i,j)[0];
	    }
	}
imshow("IMG",c);
waitKey(2000);

Mat d(a.rows,a.cols,CV_8UC1,Scalar(255));
	for(i=0;i<a.rows;i++)
	{
		for(j=0;j<a.cols;j++)
		{
			if(c.at<uchar>(i,j)<50)
				d.at<uchar>(i,j)=0;
			else
				d.at<uchar>(i,j)=255;
	    }
	}
imshow("IMG",d);
waitKey(2000);
}
