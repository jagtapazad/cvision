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



		
	imshow("IMG",b);
	waitKey(1);
	
	}
}