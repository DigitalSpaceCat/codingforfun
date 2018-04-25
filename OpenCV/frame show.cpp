void main() {
    int frame_cnt = 0 ; 
    char mag[20] = ""; 
    Mat frame; 
    VideoCapture cap; 
    cap.open("~/move.avi");
    if(!cap.isOpened()) {
        printf("The camera is disconnected\n");
        exit(1); 
    }
    double frame_rate = cap.get(CV_CAP_PROP_FPS) ; // Bring the frame numbers per second
    int delay = 1000/frame_rate ; // Set up delay
    while(cap.read(frame)){
        if ( waitKey(delay) >= 0 ) break;
            sprintf(mag , "frame_cnt = %3d ", ++frame_cnt );
            putText ( frame, mag, Point(352,452) , FONT_HERSHEY_PLAIN, 2 , CV_RGB(50,50,50), 2 ); 
            putText ( frame, mag, Point(350,450) , FONT_HERSHEY_PLAIN, 2 , CV_RGB(255,255,255), 2 ); 
        imshow("Reading movie file", frame);
    }
    cap.release();
}