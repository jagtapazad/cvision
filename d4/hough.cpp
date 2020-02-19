#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

#include<queue>
struct node
	{
		int x,y;
	};

queue<node> myq; 
void bfs(Mat e, Mat c, int i,int j,Mat f);
int isvalid(Mat a,int x, int y);
void plot(int i,int j, Mat c);
int main()

{
	int i,j;

	Mat b=imread("A3.png",0);
	Mat a=b.clone();
	Mat c(sqrt(a.rows*a.rows+a.cols*a.cols)/10,360,CV_8UC1,Scalar(0));
	node temp;
	for(i=0;i<a.rows;i++)
	{
		for(j=0;j<a.cols;j++)
		{
			if(a.at<uchar>(i,j)==255)
			{
				 temp.x=i;
		    temp.y=j;
		    myq.push(temp);
		   	b.at<uchar>(i,j)=255;
		   	plot(i,j,c);
			
			

			}
		}
	}
	imshow("IMG",c);
	waitKey(3000);

for(i=0;i<c.rows;i++)
{
	for(j=0;j<c.cols;j++)
	{
		if(c.at<uchar>(i,j)>100)
			c.at<uchar>(i,j)=255;
		else
			c.at<uchar>(i,j)=0;

	}
}

imshow("IMG",c);
waitKey(3000);


int count=0;
for(i=0;i<c.rows;i++)
{
	for(j=0;j<c.cols;j++)
	{
		if(c.at<uchar>(i,j)==255)
		{
			
		}
	}

}
//imshow("IMG",f);
cout<<count<<endl;
waitKey(3000);
}




void plot(int i,int j, Mat c)
{
	
	float thf;
	int r;
	int s;
		for(s=0;s<360;s++)
		{
			
			thf=s*3.14/180.0;
			r=i*cos(thf)+j*sin(thf);
			if(r>0)
			c.at<uchar>(r/10,s)=(c.at<uchar>(r/10,s)+1);

		}

}


