#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()

{
Mat a(320,320,CV_8UC3,Scalar(255,165,0));
int i,j,n;
	for(i=0;i<320;i++)
	{
		for(j=0;j<320;j++)
		{
			n=(i+j)/20;
			if((n%2+(i/20)%2+(j/20)%2)%2==0)
			{
				a.at<Vec3b>(i,j)[0]=128; 
				a.at<Vec3b>(i,j)[1]=0; 
				a.at<Vec3b>(i,j)[2]=128; 
			}
		}
	}




namedWindow("window1",WINDOW_NORMAL);
imshow("window1",a);
waitKey(10000); //0 for infinite 


}
