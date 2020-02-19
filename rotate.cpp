#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
int main()
{
	Mat a=imread("fruits.png",1);
	int x,y,z,i,j;
	x=a.rows;
	y=a.cols;
	z=(int)sqrt(x*x+y*y);

int n=20;
cout<<"hello"<<endl;
Mat b(z+5,z+5,CV_8UC3,Scalar(0,0,0));

int p,q;
namedWindow("IMG",WINDOW_NORMAL);

imshow("IMG",b);
waitKey(5000);
createTrackbar("angle","IMG",&n,360);
while(1)
	{
		for(i=-z/2;i<z/2;i++)
		{
		for(j=-z/2;j<z/2;j++)
		{   
			p=(int)(i*cos(n*3.14/180)+j*sin(n*3.14/180));
			q=(int)(j*cos(n*3.14/180)-i*sin(n*3.14/180));
			if(p+x/2<x&&q+y/2<y&&p+x/2>0&&q+y/2>0)
			{
			b.at<Vec3b>(i+z/2,j+z/2)[0]=a.at<Vec3b>(p+x/2,q+y/2)[0];
			b.at<Vec3b>(i+z/2,j+z/2)[1]=a.at<Vec3b>(p+x/2,q+y/2)[1];
			b.at<Vec3b>(i+z/2,j+z/2)[2]=a.at<Vec3b>(p+x/2,q+y/2)[2];
			}

        
		}
		}
	
imshow("IMG",b);
waitKey(5);
}
}