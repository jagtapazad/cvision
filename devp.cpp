#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int IsValid(int x,int y,int rows,int cols)
{
    if(x<0 || y<0 || x>=rows || y>=cols)
        return 0;
    return 1;
}
int main()
{

    Mat image=imread("lena.png",0);
    namedWindow("WIN",WINDOW_NORMAL);
    int i,j,k,l,rows=3, bright=0;
createTrackbar("EROSION","WIN",&bright,255);
    Mat img(image.rows,image.cols,CV_8UC1,Scalar(0));
while(1)
{
        for(i=0;i<image.rows;i++)
        {
            for(j=0;j<image.cols;j++)
            {
                    for(k=(-rows/2);k<=(rows/2);k++)
                    {
                        for(l=(-rows/2);l<=(rows/2);l++)
                        {       
                            if(IsValid(i+k,j+l,image.rows,image.cols)==1)
                                { if(image.at<uchar>(i+k,j+l)<=bright)
                                  img.at<uchar>(i, j) =255-bright;                 }
                        }
                   }
            }
        }
    imshow("WIN",img);
    waitKey(1);
    }
}