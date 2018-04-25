
// int main() {   
//     Mat frame;
    
//     VideoCapture cap;
//     VideoWriter writer;
//     cap.open(0);
//     if (!cap.isOpened()){
//         printf("Cam is disconnected.\n");
//         exit(1);
//     }
//     double fps =30;
//     //Set 320x240 as capturing size
//     cap.set(CAP_PROP_FRAME_WIDTH,320);
//     cap.set(CAP_PROP_FRAME_HEIGHT,240);
//     //Bring the images captured from webcam
//     int width = cap.get(CAP_PROP_FRAME_WIDTH);
//     int height = cap.get(CAP_PROP_FRAME_HEIGHT);
//     writer.open("~/move.avi", CV_FOURCC_PROMPT , fps, Size(width, height) );
//     for(;;) {
//         Mat frame ;
//         cap >> frame; // Recieving cam
//         writer << frame; // Saving Matrix cam
//         imshow("Reading Cam Clip", frame);
//         if ( waitKey(30) >= 0) break;
//     }
    
// }

//
//  main.cpp
//  OpenCV_Template
//
//  Created by Gyuri Kim on 7/11/2017.
//  Copyright © 2017 Gyuri Kim. All rights reserved.
//
// #include <opencv2/core/core.hpp>
// #include <opencv2/highgui/highgui.hpp>
// #include <iostream>
// #include <iomanip>
// #include "opencv2/opencv.hpp"

// using namespace cv;
// using namespace std;

// //int main(int, char**)

// int main() {
//     Mat frame;
    
//     VideoCapture cap;
//     VideoWriter writer;
//     cap.open(0);
//     if (!cap.isOpened()){
//         printf("Cam is disconnected.\n");
//         exit(1);
//     }
//     double fps =30;
//     //Set 320x240 as capturing size
//     cap.set(CAP_PROP_FRAME_WIDTH,320);
//     cap.set(CAP_PROP_FRAME_HEIGHT,240);
//     //Bring the images captured from webcam
//     int width = cap.get(CAP_PROP_FRAME_WIDTH);
//     int height = cap.get(CAP_PROP_FRAME_HEIGHT);
//     writer.open("~/move.avi", CV_FOURCC('P','I','M','1') , fps, Size(width, height) );
//     for(;;) {
//         Mat frame ;
//         cap >> frame; // Recieving cam
//         writer << frame; // Saving Matrix cam
//         imshow("Reading Cam Clip", frame);
//         if ( waitKey(30) >= 0) break;
//     }
    
// }

// current success code so far
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <iomanip>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

//int main(int, char**)

int main() {
    Mat frame;
    
    VideoCapture cap;
    VideoWriter normal;
    VideoWriter flipped;
    cap.open(0);
    if (!cap.isOpened()){
        printf("Cam is disconnected.\n");
        exit(1);
    }
    double fps =30;
    //Set 320x240 as capturing size
    cap.set(CAP_PROP_FRAME_WIDTH,320);
    cap.set(CAP_PROP_FRAME_HEIGHT,240);
    //Bring the images captured from webcam
    int width = cap.get(CAP_PROP_FRAME_WIDTH);
    int height = cap.get(CAP_PROP_FRAME_HEIGHT);
    normal.open("~/test/move.avi", CV_FOURCC('P','I','M','1') , fps, Size(width, height), true );
    flipped.open("~/test/flipped.avi", CV_FOURCC('P','I','M','1') , fps, Size(width, height), true );
    int counter = 0;
    for(;;) {
        counter++;
        Mat frame ;
        cap >> frame; // Recieving cam
        normal << frame; // Saving Matrix cam
        //double currentFrame = flipped.get(CV_CAP_PROP_POS_FRAMES);
        //cout << currentFrame << endl;
        if (counter % 100 > 50){
            flip(frame, frame, 1);
        }
        flipped << frame;
        imshow("Reading Cam Clip", frame);
        if ( waitKey(30) >= 0) break;
    }
    
}