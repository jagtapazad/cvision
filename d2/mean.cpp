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

	int i,j,k=1,sum=0,l,m;
	namedWindow("IMG",WINDOW_NORMAL);
	createTrackbar("kernelsize(2k-1)","IMG",&k,40);
	Mat b=a.clone();
	while(1)
	{
		for(i=k;i<a.rows;i++)
		{
			for(j=k;j<a.cols;j++)
			{	sum=0;
                for(l=0;l<2*k-1;l++)
                {
                	for(m=0;m<2*k-1;m++)
                	{
                		sum=sum+a.at<uchar>(i-k+l,j-k+m);
                	}
                }    

					b.at<uchar>(i,j)=sum/((2*k-1)*(2*k-1));
		    }
		}

	imshow("IMG",b);
	waitKey(1);
	
	}
}