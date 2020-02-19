#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()

{
Mat a=imread("lena.png",1);
//
//waitKey(2000); //0 for infinite 
int i,j;


Mat c(a.rows,a.cols,CV_8UC1,Scalar(255));
	for(i=0;i<a.rows;i++)
	{
		for(j=0;j<a.cols;j++)
		{
				c.at<uchar>(i,j)=0.299*a.at<Vec3b>(i,j)[2]+0.587*a.at<Vec3b>(i,j)[1]+0.11*a.at<Vec3b>(i,j)[0];
	    }
	}

int k=50;

namedWindow("IMG1",WINDOW_NORMAL);
Mat d(a.rows,a.cols,CV_8UC1,Scalar(255));
createTrackbar("Threshhold","IMG1",&k,254);

	while(1)
	{


		for(i=0;i<a.rows;i++)
		{
			for(j=0;j<a.cols;j++)
			{
				if(c.at<uchar>(i,j)<k)
					d.at<uchar>(i,j)=0;
				else
					d.at<uchar>(i,j)=255;
	    	}	
		}
		
		imshow("IMG1",d);
		waitKey(1);
	}
	waitKey(0);
}
