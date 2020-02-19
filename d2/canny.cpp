#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
int main()

{
	Mat a=imread("lenaTest3.jpg",0);

	int i,j,sum=0,l,m;
	namedWindow("IMG",WINDOW_NORMAL);
	
	Mat b=a.clone();
	
	
	
		for(i=1;i<a.rows;i++)
		{
			for(j=1;j<a.cols;j++)
			{	
                b.at<uchar>(i,j)=0.2*a.at<uchar>(i,j)+0.15*a.at<uchar>(i-1,j-1)+0.15*a.at<uchar>(i+1,j+1)+0.15*a.at<uchar>(i-1,j+1)+0.15*a.at<uchar>(i+1,j-1)+0.05*a.at<uchar>(i,j+1)+0.05*a.at<uchar>(i,j-1)+0.05*a.at<uchar>(i-1,j)+0.05*a.at<uchar>(i+1,j);
		    }
		}

	Mat c=b.clone();
	Canny(b,c,50,150,3);




	imshow("IMG",c);
	waitKey(0);
	
	
}
