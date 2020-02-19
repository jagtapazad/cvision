#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
int main()
{
	Mat a=imread("highcontrast.PNG",0);
	int n[256],i,j,num,max;
    for(i=0;i<256;i++)
    {
    	n[i]=0;
    }
     
	
		for(i=0;i<a.rows;i++)
		{
			for(j=0;j<a.cols;j++)
			{
				num=a.at<uchar>(i,j);
				n[num]=n[num]+1;
		 	}
		}
        max=n[0];
		for(i=0;i<256;i++)
		{
			if(n[i]>max) max=n[i];
		}
	Mat b(max,256,CV_8UC1,Scalar(255));
	    for(i=0;i<256;i++)
	    {
	    	for(j=max-1;j>max-n[i];j--)
	    	{   if(n[i]!=0)
	    		b.at<uchar>(j,i)=0;
	    	}
	    }
	
namedWindow("IMG",WINDOW_NORMAL);
imshow("IMG",a);
waitKey(3000);
imshow("IMG",b);
waitKey(10000);
}