#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

int threshold_value = 0;
int threshold_type = 3;        //Default Value Start on 4. Threshold_To_Zero
int const max_value = 100;
int const max_type = 4;
int const max_binary_value = 255;
Mat src, src_gray, dst;

const char* window_name = "Threshold Demo";
const char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
const char* trackbar_value = "Value";


static void Threshold_Demo(int, void*)
{
	threshold(src_gray, dst, threshold_value, max_binary_value, threshold_type);
	imshow(window_name, dst);
}
int main(int argc, char** argv)
{


	String imageName("lena.jpg");
	if (argc > 1)
	{
		imageName = argv[1];

	}
	src = imread(samples::findFile(imageName), IMREAD_COLOR);
	if (src.empty())
	{
		cout << "Cannot read the image:" << imageName << std::endl;
		return -1;
	}
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	namedWindow(window_name, WINDOW_GUI_NORMAL);
	createTrackbar(trackbar_type, window_name, &threshold_type, max_type, Threshold_Demo);
	createTrackbar(trackbar_value, window_name, &threshold_type, max_value, Threshold_Demo);
	Threshold_Demo(0, 0);
	waitKey();
	destroyAllWindows();
	return 0;
}