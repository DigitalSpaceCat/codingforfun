#include <opencv2\core\core_c.h>
#include <opencv2\highgui\highgui_c.h>
#include <opencv\highgui.h>

using namespace cv;
using namespace std;




int main(){
	

	//open camera no. 0
	VideoCapture cap(1);

	while(1){
		Mat frame;//declaire frame

		cap.read(frame);//read frame

		//flip(source, destination, flipcode)
		//flipcode can be 1 (flip around y-axis), 0 (flip around x-axis) or -1 (flip both axes)
		flip(frame, frame, 0);

		imshow("original",frame);//imshow(window name, frame)
		waitKey(30);//wait 30 milliseconds
	}
	return 0;
}
