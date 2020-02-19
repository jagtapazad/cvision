#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
struct node
	{
		int x,y;
	};

#include<queue>
queue <node> myq;
void bfs(Mat a, Mat b, int i,int j);
int isvalid(Mat a,int i, int j);

int main()
{
Mat d=imread("example.png",0);

int l,m;


Mat a(d.rows,d.cols,CV_8UC1,Scalar(0));	
	for(l=0;l<a.rows;l++)
	{
		for(m=0;m<a.cols;m++)
		{
			if(d.at<uchar>(l,m)<150)
				a.at<uchar>(l,m)=0;
			else
				a.at<uchar>(l,m)=255;
	    }
	}



Mat b=a.clone();
int i,j,k;
node temp;
int count=0;

for(l=0;l<a.rows-1;l++)
{
	for(m=0;m<a.cols-1;m++)
	{	
		
		if(b.at<uchar>(l,m)==0)
		{
		    temp.x=l;
		    temp.y=m;
		    myq.push(temp);
		   	b.at<uchar>(l,m)=255;
			bfs(a,b,l,m);
			
			count++; 
			
		}
	}
}
cout<<count<<endl;
return 0;
}

void bfs(Mat a,Mat b,int i,int j)
{	
	node temp;
	
	
	while(!myq.empty())
	{
			
			if(isvalid(a,i,j+1)&&b.at<uchar>(i,j+1)==0)
			{
				b.at<uchar>(i,j+1)=255;
				temp.x=i;
			    temp.y=j+1;
				myq.push(temp);

			}
			if (isvalid(a,i+1,j)&&b.at<uchar>(i+1,j)==0)
			{
				b.at<uchar>(i+1,j)=255;
				temp.x=i+1;
			    temp.y=j;
				myq.push(temp);	
			}
			if(isvalid(a,i,j-1)&&b.at<uchar>(i,j-1)==0)
			{
				b.at<uchar>(i,j-1)=255;
				temp.x=i;
			    temp.y=j-1;
				myq.push(temp);   
			}
			 if(isvalid(a,i-1,j)&&b.at<uchar>(i-1,j)==0)
			  {
				b.at<uchar>(i-1,j)=255;
				temp.x=i-1;
			    temp.y=j;
				myq.push(temp);
			  }
				myq.pop();
				if(!myq.empty())	
					{temp=myq.front();
				i=temp.x;j=temp.y;}                                 //check
	}
}

int isvalid(Mat a,int x, int y)
{
	if(x<0||y<0||x>a.rows-1||y>a.cols-1){
		
	 	return 0;
	}
	else return 1;
}