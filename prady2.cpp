#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()


{

Mat b=imread("ext1.png",1);
Mat a(b.rows/2,b.cols/2,CV_8UC3,Scalar(0,0,0));
int i,j;
	for(i=0;i<b.rows;i++)
		{
			for(j=0;j<b.cols;j++)
			{ 
                                  if(i%2!=0 && j%2!=0){

                                   
			
					a.at<Vec3b>(i/2+1,j/2+1)[0]=b.at<Vec3b>(i,j)[0];
					a.at<Vec3b>(i/2+1,j/2+1)[1]=b.at<Vec3b>(i,j)[1];
					a.at<Vec3b>(i/2+1,j/2+1)[2]=b.at<Vec3b>(i,j)[2];
			    }
			}
		}
 

namedWindow("window1",WINDOW_NORMAL);

imshow("window1",a);
waitKey(0); //0 for infinite
}

