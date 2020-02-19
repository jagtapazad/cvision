#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
vector<vector<Point> > contours;
Point2f nik;
vector<Vec4i> hierarchy;
void redex(Mat a, Mat b);

int main(int, char**)
{
					VideoCapture cap(0);
					if(!cap.isOpened())
					return -1;
					Mat img1;
					
					namedWindow("IMG",WINDOW_NORMAL);
					namedWindow("IMG1",WINDOW_NORMAL);
					namedWindow("IMG2",WINDOW_NORMAL);
					while(1)
						{
						
						cap>>img1;
						Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));
						Mat img3(img1.rows,img1.cols,CV_8UC1,Scalar(0));
						imshow("IMG",img1);
						redex(img1,img2);
						imshow("IMG1",img2);
						//medianblr(img2,img3)
						//imshow("IMG2",img3);
						findContours(img2,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);
						
						int max=0,i,v;
						for(i=0;i<contours.size();i++)
						{
							if(max<contourArea(contours[i]));
							max=contourArea(contours[i]);
								v=i;

						}
						float r;
						drawContours(img3,contours,v,255,1,8);
						minEnclosingCircle(contours[v],nik,r);
						
						imshow("IMG2",img3);

						if(nik.x<img1.rows/2-50)
						{
							cout<<"d"<<endl;
						}
						if(nik.x>img1.rows/2+50)
						{
							cout<<"a"<<endl;
						}
						if(r<50)
						{
							cout<<"w"<<endl;
						}
						if(r>50)
						{
							cout<<"s"<<endl;
						}


						//area condition
						//contour centre
						//range of area cond
						//range left right condition
						waitKey(1);
						}



/*
	Mat a=imread("aaa.jpg",3);
	Mat b(a.rows,a.cols,CV_8UC1, Scalar(255));

	redex(a,b);

*/	

	
	
}


void redex(Mat a, Mat d)
{
	int i,j;



int r1=255,g1=104,b1=63,r2=129,g2=0,b2=0;

namedWindow("IMG1",WINDOW_NORMAL);


		for(i=0;i<a.rows;i++)
		{
			for(j=0;j<a.cols;j++)
			{
				if(a.at<Vec3b>(i,j)[2]<=r1&&a.at<Vec3b>(i,j)[2]>=r2)
				{
					if(a.at<Vec3b>(i,j)[0]<=b1&&a.at<Vec3b>(i,j)[0]>=b2)
					{
						if(a.at<Vec3b>(i,j)[1]<=g1&&a.at<Vec3b>(i,j)[1]>=g2)
						{
				          {
					 d.at<uchar>(i,j)=255;
					

				          }				
						}else
				{d.at<uchar>(i,j)=0;} 
					}else
				{d.at<uchar>(i,j)=0;} 
				}
				else
				{d.at<uchar>(i,j)=0;} 
				
				
	    	}	
		}
		
		
		return ;
}
