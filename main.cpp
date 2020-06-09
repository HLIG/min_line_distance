/* 
Author:HLG
Date:2020年6月5日
huang.liguang@qq.com
*/
#define _GLIBCXX_USE_CXX11_ABI 0//如果电脑的gcc版本比opencv编译的版本低，则需要使用这一行来避免string编译出错，gcc版本与opencv版本一致，将其注释即可
#include<opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include<vector>
#include<string>
#include<ctime>
#include<iostream>
#include<ctime>
#include<cmath>
#include"my_tracking_function.h"

using namespace std;
using namespace cv;


int main()
{

    int h=480;//h
    int w=640;//w
    cv::Point A1,A2,B1,B2;
    
    int delta=100;//偏移



    cv::namedWindow("min_line_distance");
    while(true)
    {
        A1.x=rand()%w+delta;
        A1.y=rand()%h+delta;
        A2.x=rand()%w+delta;
        A2.y=rand()%h+delta;
        B1.x=rand()%w+delta;
        B1.y=rand()%h+delta;
        B2.x=rand()%w+delta;
        B2.y=rand()%h+delta;

        cv::Mat img=cv::Mat::zeros(h+2*delta,w+2*delta,CV_8UC3);
        cv::line(img,A1,A2, cv::Scalar(255,0,0), 2 );
        cv::line(img,B1,B2, cv::Scalar(0,255,0), 2 );
        cv::putText(img, "A1", A1, FONT_HERSHEY_SIMPLEX, 0.6, Scalar(255, 0, 0), 1);
        cv::putText(img, "A2", A2, FONT_HERSHEY_SIMPLEX, 0.6, Scalar(255, 0, 0), 1);

        cv::putText(img, "B1", B1, FONT_HERSHEY_SIMPLEX, 0.6, Scalar(0, 255, 0), 1);
        cv::putText(img, "B2", B2, FONT_HERSHEY_SIMPLEX, 0.6, Scalar(0, 255, 0), 1);

        int label_x=0;
        int label_y=20;
        cv::putText(img, "A1:"+to_string(A1.x)+" "+to_string(A1.y),cv::Point(label_x,label_y), FONT_HERSHEY_SIMPLEX, 0.6, Scalar(255, 0, 0), 1);
        label_y+=20;
        cv::putText(img, "A2:"+to_string(A2.x)+" "+to_string(A2.y),cv::Point(label_x,label_y), FONT_HERSHEY_SIMPLEX, 0.6, Scalar(255, 0, 0), 1);
        label_y+=20;
        cv::putText(img, "B1:"+to_string(B1.x)+" "+to_string(B1.y),cv::Point(label_x,label_y), FONT_HERSHEY_SIMPLEX, 0.6, Scalar(0, 255, 0), 1);
        label_y+=20;
        cv::putText(img, "B2:"+to_string(B2.x)+" "+to_string(B2.y),cv::Point(label_x,label_y), FONT_HERSHEY_SIMPLEX, 0.6, Scalar(0, 255, 0), 1);
        
        double line_distance=hlg::Min_Line_Distance(A1,A2,B1,B2);
        label_y+=20;
        cv::putText(img, "min_line_distance:"+to_string(line_distance),cv::Point(label_x,label_y), FONT_HERSHEY_SIMPLEX, 0.6, Scalar(0, 255, 0), 1);

        //计算直线枝干直线夹角
        double k1=double(A2.y-A1.y)/double(A2.x-A1.x);
        double k2=double(B2.y-B1.y)/double(B2.x-B1.x);
        cout<<"k1:"<<k1<<" "<<"k2:"<<k2<<endl;
        double theta=acos(abs((1+k1*k2)/(sqrt(1+k1*k1)*sqrt(1+k2*k2))));
        // double theta1=atan(k1)*double(180)/M_PI;
        // double theta2=atan(k2)*double(180)/M_PI;
        theta=theta*180/M_PI;
        label_y+=20;
        // cv::putText(img, "theta1:"+to_string(theta1)+" "+to_string(theta2),cv::Point(label_x,label_y), FONT_HERSHEY_SIMPLEX, 0.6, Scalar(0, 255, 0), 1);
        cv::putText(img, "theta:"+to_string(theta),cv::Point(label_x,label_y), FONT_HERSHEY_SIMPLEX, 0.6, Scalar(0, 255, 0), 1);

        cv::imshow("min_line_distance",img);
        cv::waitKey(0);
    }


    
    
    return 0;
}
