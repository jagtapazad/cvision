#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
int main()

{
	Mat a=imread("veg.jpg",0);
    imshow("IMG",a);
    
	int i,j,k=1,sum=0,l,m;
	namedWindow("IMGmedian",WINDOW_NORMAL);
	createTrackbar("kernelsize(2k-1)","IMG",&k,40);
	Mat b=a.clone();
	while(1)
	{   int q=(2*k-1)*(2*k-1);
		int mm[q];
		for(i=k;i<a.rows-k;i++)                                                                                                               
			{
			for(j=k;j<a.cols-k;j++)
			{	
                for(l=0;l<2*k-1;l++)
                {
                	for(m=0;m<2*k-1;m++)
                	{
                     mm[l*(2*k-1)+m]=a.at<uchar>(i-k+1+l,j-k+1+m);	 
                	}
                }    
                sort(mm,mm+q);
					b.at<uchar>(i,j)=mm[q/2];
		    }
		}

	imshow("IMGmedian",b);
	waitKey(1);
	
	}


int x;
namedWindow("IMGmean",WINDOW_NORMAL);
	createTrackbar("kernelsz(2k-1)","IMG1",&x,40);
	Mat c=a.clone();
	while(1)
	{
		for(i=x;i<a.rows;i++)
		{
			for(j=x;j<a.cols;j++)
			{	sum=0;
                for(l=0;l<2*x-1;l++)
                {
                	for(m=0;m<2*x-1;m++)
                	{
                		sum=sum+a.at<uchar>(i-x+1+l,j-x+1+m);
                	}
                }    

					c.at<uchar>(i,j)=sum/((2*x-1)*(2*x-1));
		    }
		}

	imshow("IMGmean",c);
	waitKey(1);
	
	}


namedWindow("IMGgaus",WINDOW_NORMAL);
	
	Mat d=a.clone();
	
	
		for(i=1;i<a.rows;i++)
		{
			for(j=1;j<a.cols;j++)
			{	
                d.at<uchar>(i,j)=0.2*a.at<uchar>(i,j)+0.15*a.at<uchar>(i-1,j-1)+0.15*a.at<uchar>(i+1,j+1)+0.15*a.at<uchar>(i-1,j+1)+0.15*a.at<uchar>(i+1,j-1)+0.05*a.at<uchar>(i,j+1)+0.05*a.at<uchar>(i,j-1)+0.05*a.at<uchar>(i-1,j)+0.05*a.at<uchar>(i+1,j);
		    }
		}

	imshow("IMGgaus",d);
	waitKey(0);
	




}