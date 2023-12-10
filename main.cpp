#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
    VideoCapture vid(0);
    if (!vid.isOpened()) {
        cout << "Error opening video capture device";
    }
    else {
        int a = vid.get(5);
        int b = vid.get(7);
        cout << "Frame Rate: " << a << endl;
        cout << "Frame Count: " << b << endl;

        int frame_width = static_cast<int>(vid.get(3));
        int frame_height = static_cast<int>(vid.get(4));
        Size frame_size(frame_width, frame_height);
        int fps = 20;

        VideoWriter output("C:/Users/91902/Downloads/output1.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, frame_size);

        while (vid.isOpened()) {
            Mat frame;
            bool s = vid.read(frame);

            if (s == true) {
                output.write(frame);
                imshow("video", frame);
            }
            else {
                cout << "Problem reading frame";
                break;
            }

            int key = waitKey(20);
            if (key == 'q') {
                cout << "Ended by user";
                break;
            }
        }

        // Release the VideoWriter after the loop
        output.release();
        vid.release();
        destroyAllWindows();
    }

    return 0;
}







//opening image
/*#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;

int main() {
	Mat img = imread("C:/Users/91902/Downloads/Untitled-2.png", 0);
	imshow("hai", img);
	imwrite("C:/Users/91902/Downloads/Untitled-21.png", img);
	waitKey(0);
	destroyAllWindows();
}
// playing video
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;


int main() {
	VideoCapture vid("C:/Users/91902/OneDrive/Pictures/Video Projects/$50.mp4");
	if (!vid.isOpened()) {
		cout << "error in problem";
	}
	else {
		int a = vid.get(5);
		int b = vid.get(7);
		cout << "Frame Rate : " << a << endl;
		cout << "Frame count : " << b << endl;
	}
	while (vid.isOpened()) {
		Mat frame;
		bool s = vid.read(frame);
		if (s == true) {
			imshow("video", frame);
		}
		else {
			cout << "problem";
			break;
		}
		int h = waitKey(20);
		if (h == 'q') {
			cout << "ended";
			break;
		}
	}
	vid.release();
	destroyAllWindows();
}


//C: / Users / 91902 / Downloads / Untitled - 1.png*/