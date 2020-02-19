#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
int main()

{
	Mat a=imread("88.jpg",0);

	int i,j,k=2,sum=0,l,m;
	namedWindow("IMG",WINDOW_NORMAL);

	Mat b=a.clone();
	
	   int q=(2*k-1)*(2*k-1);
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

		for(i=0;i<a.rows;i++)
		{
			for(j=0;j<a.cols;j++)
			{
				if(b.at<uchar>(i,j)>100)
					b.at<uchar>(i,j)=255;
				else
					b.at<uchar>(i,j)=0;
			}
		}

	imshow("IMG",b);
	waitKey(10000);
	Mat c=b.clone();
	Mat d=c.clone();
	for(i=1;i<a.rows-1;i++)
		{
			for(j=1;j<a.cols-1;j++)
			{	
                if(b.at<uchar>(i,j)==255||b.at<uchar>(i+1,j)==255||b.at<uchar>(i+1,j+1)==255||b.at<uchar>(i-1,j)==255||b.at<uchar>(i,j-1)==255||b.at<uchar>(i,j+1)==255||b.at<uchar>(i-1,j-1)==255||b.at<uchar>(i+1,j-1)==255||b.at<uchar>(i-1,j+1)==255)
				c.at<uchar>(i,j)=255;
				else
				c.at<uchar>(i,j)=0;		    
		    }
		}

		imshow("IMG",c);
		waitKey(4000);

		for(i=1;i<a.rows-1;i++)
		{
			for(j=1;j<a.cols-1;j++)
			{	
                if(c.at<uchar>(i,j)==255||c.at<uchar>(i+1,j)==255||c.at<uchar>(i+1,j+1)==255||c.at<uchar>(i-1,j)==255||c.at<uchar>(i,j-1)==255||c.at<uchar>(i,j+1)==255||c.at<uchar>(i-1,j-1)==255||c.at<uchar>(i+1,j-1)==255||c.at<uchar>(i-1,j+1)==255)
				d.at<uchar>(i,j)=255;
				else
				d.at<uchar>(i,j)=0;		    
		    }
		}

		imshow("IMG",d);
		waitKey(4000);
}
