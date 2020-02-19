#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
int main()
{
	Mat a=imread("lowcontrast.PNG",0);
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
	namedWindow("IMG",WINDOW_NORMAL);
    int t=50,i,j;
    int n=1,p=0;
    createTrackbar("brightness","IMG",&p,80);
	createTrackbar("threshold","IMG",&t,255);
	createTrackbar("contrast","IMG",&n,500);
while(1)
{
	for(i=0;i<a.rows;i++)
	{
		for(j=0;j<a.cols;j++)
		{       if(a.at<uchar>(i,j)>t)
				b.at<uchar>(i,j)=a.at<uchar>(i,j)*50/n;
				else
				{
					if(a.at<uchar>(i,j)<t)
					b.at<uchar>(i,j)=a.at<uchar>(i,j)*n/50;
					else
					{
						b.at<uchar>(i,j)=a.at<uchar>(i,j);
					}	
				}
				b.at<uchar>(i,j)=b.at<uchar>(i,j)+p;
	    }
	}

imshow("IMG",b);
waitKey(5);
}


}