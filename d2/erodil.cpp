#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()

{
Mat a=imread("erosion.png",0);

//waitKey(2000); //0 for infinite 
int i,j;




int k=50;

namedWindow("IMG1",WINDOW_NORMAL);
Mat d(a.rows,a.cols,CV_8UC1,Scalar(255));
Mat e(a.rows,a.cols,CV_8UC1,Scalar(255));
Mat f(a.rows,a.cols,CV_8UC1,Scalar(255));
createTrackbar("Threshhold","IMG1",&k,254);

	while(1)
	{


		for(i=0;i<a.rows;i++)
		{
			for(j=0;j<a.cols;j++)
			{
				if(a.at<uchar>(i,j)<k)
					d.at<uchar>(i,j)=0;
				else
					d.at<uchar>(i,j)=255;
	    	}	
		}
		for(i=1;i<a.rows-1;i++)
		{
			for(j=1;j<a.cols-1;j++)
			{	
                if(d.at<uchar>(i,j)==0||d.at<uchar>(i+1,j)==0||d.at<uchar>(i+1,j+1)==0||d.at<uchar>(i-1,j)==0||d.at<uchar>(i,j-1)==0||d.at<uchar>(i,j+1)==0||d.at<uchar>(i-1,j-1)==0||d.at<uchar>(i+1,j-1)==0||d.at<uchar>(i-1,j+1)==0)
				e.at<uchar>(i,j)=0;
				else
				e.at<uchar>(i,j)=255;		    
		    }
		}
		for(i=1;i<a.rows-1;i++)
		{
			for(j=1;j<a.cols-1;j++)
			{	
                if(e.at<uchar>(i,j)==255||e.at<uchar>(i+1,j)==255||e.at<uchar>(i+1,j+1)==255||e.at<uchar>(i-1,j)==255||e.at<uchar>(i,j-1)==255||e.at<uchar>(i,j+1)==255||e.at<uchar>(i-1,j-1)==255||e.at<uchar>(i+1,j-1)==255||e.at<uchar>(i-1,j+1)==255)
				f.at<uchar>(i,j)=255;
				else
				f.at<uchar>(i,j)=0;		    
		    }
		}
		

		imshow("IMG1",f);
		imshow("IMG2",a);
		waitKey(10);
	}
	waitKey(0);
}
