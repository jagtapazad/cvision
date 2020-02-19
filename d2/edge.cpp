#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
int sobelx(Mat a,int row , int col);
int sobely(Mat a,int row , int col);
int main()
{
	Mat a=imread("lena.png",0);
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
	float ck;
	namedWindow("IMG",WINDOW_NORMAL);
	int t=1,i,j,t1=1,t2=1,ck1,ck2;
	createTrackbar("t","IMG",&t,255);
	createTrackbar("x","IMG",&t1,255);
	createTrackbar("y","IMG",&t2,255);
    while(1)
    {
		for(i=1;i<a.rows-1;i++)
		{
			for(j=1;j<a.cols-1;j++)
			{
				ck=sqrt(sobelx(a,i,j)*sobelx(a,i,j)+sobely(a,i,j)*sobely(a,i,j));
				if(sobelx(a,i,j)>0) ck1=sobelx(a,i,j); else ck1=-sobelx(a,i,j); 
				if(sobely(a,i,j)>0) ck2=sobely(a,i,j); else ck2=-sobely(a,i,j);
				if (ck>t||ck1>t1||ck2>t2)
				b.at<uchar>(i,j)=255;
				else b.at<uchar>(i,j)=0;

			}
		}
	imshow("IMG",b);
	waitKey(1);
	}
}

int sobelx(Mat a,int row,int col)
{
	return a.at<uchar>(row-1,col-1)*(-1)+a.at<uchar>(row,col-1)*(-2)+a.at<uchar>(row+1,col-1)*(-1)+a.at<uchar>(row-1,col+1)*1+a.at<uchar>(row,col+1)*2+a.at<uchar>(row+1,col+1)*1;
}
int sobely(Mat a,int row,int col)
{
	return a.at<uchar>(row-1,col-1)*(-1)+a.at<uchar>(row-1,col)*(-2)+a.at<uchar>(row-1,col+1)*(-1)+a.at<uchar>(row+1,col-1)*1+a.at<uchar>(row+1,col)*2+a.at<uchar>(row+1,col+1)*1;
}