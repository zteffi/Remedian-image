#include <iostream>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include "remedian_image.hpp"

int main(int argc, char* args[]) {
	if (argc < 2) {
		std::cout << "Missing source video path" << std::endl;
		return -1;
	}

	cv::VideoCapture cap(args[1]);
	if (!cap.isOpened()) {
		std::cout << "Error opening video stream or file" << std::endl;
		return -2;
	}
	RemedianImage rem;
	while (true) {
		cv::Mat frame;
		cap >> frame;
		if (frame.empty()) {
			break;
		}
		rem.Update(frame);
	}
	auto res = rem.GetRemedian();
	cv::imwrite("remedian.jpg", res);
}