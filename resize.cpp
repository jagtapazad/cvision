#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat a=imread("ext1.png",1);
	Mat b(2*a.rows,2*a.cols,CV_8UC3,Scalar(0,0,0));

	int i,j;
	for(i=0;i<b.rows;i++)
	{
		for(j=0;j<b.cols;j++)
		{
			b.at<Vec3b>(i,j)[0]=a.at<Vec3b>(i/2,j/2)[0];
			b.at<Vec3b>(i,j)[1]=a.at<Vec3b>(i/2,j/2)[1];
			b.at<Vec3b>(i,j)[2]=a.at<Vec3b>(i/2,j/2)[2];

		}
	}
	imshow("IMG",a);
	waitKey(3000);
	imshow("IMG",b);
	waitKey(3000);

	Mat c(a.rows/2,a.cols/2,CV_8UC3,Scalar(0,0,0));
		for(i=0;i<c.rows-1;i++)
		{
			for(j=0;j<c.cols-1;j++)
			{
				c.at<Vec3b>(i,j)[0]=(a.at<Vec3b>(2*i,2*j)[0]+a.at<Vec3b>(2*i+1,2*j)[0]+a.at<Vec3b>(2*i,2*j+1)[0]+a.at<Vec3b>(2*i+1,2*j+1)[0])/4;
				c.at<Vec3b>(i,j)[1]=(a.at<Vec3b>(2*i,2*j)[1]+a.at<Vec3b>(2*i+1,2*j)[1]+a.at<Vec3b>(2*i,2*j+1)[1]+a.at<Vec3b>(2*i+1,2*j+1)[1])/4;
				c.at<Vec3b>(i,j)[2]=(a.at<Vec3b>(2*i,2*j)[2]+a.at<Vec3b>(2*i+1,2*j)[2]+a.at<Vec3b>(2*i,2*j+1)[2]+a.at<Vec3b>(2*i+1,2*j+1)[2])/4;

			}
		}	
	imshow("IMG",c);
	waitKey(3000);
}