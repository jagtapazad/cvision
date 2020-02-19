#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()

{
Mat a(100,100,CV_8UC3,Scalar(0,0,0));
int x=a.at<Vec3b>(2,5)[0];    //<uchar> for gray
namedWindow("window1",WINDOW_NORMAL);

imshow("window1",a);
waitKey(2000); //0 for infinite 

}


// createTrackbar("window_name","Slider_name",&th,maxvalueth)
/*
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
int main()

{
	Mat a=imread("lena.png",0);

	int i,j,k=1,sum=0,l,m;
	namedWindow("IMG",WINDOW_NORMAL);
	createTrackbar("kernelsize(2k-1)","IMG",&k,40);
	Mat b=a.clone();
	while(1)
	{
		for(i=k;i<a.rows;i++)
		{
			for(j=k;j<a.cols;j++)
			{	
                for(l=0;l<k;l++)
                {
                	for(m=0;m<k;m++)
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
*/