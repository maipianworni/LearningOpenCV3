// example_02-07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\..\_opencv.h"
#include <iostream>

void help(char** argv) {
	std::cout << "\n"
		<< "\nExample 2-7. The Canny edge detector writes its output to a single-channel (grayscale) image"
		<< "\nCall:\n"
		<< argv[0] << " <path/image>\n"
		<< "For example:\n"
		<< argv[0] << " ../fruits.jpg\n"
		<< std::endl;
}

int main(int argc, char** argv) {

	if (argc != 2) {
		help(argv);
		return 0;
	}

	cv::Mat img_rgb, img_gry, img_cny;

	cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

	img_rgb = cv::imread(argv[1]);

	cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
	cv::imshow("Example Gray", img_gry);

	cv::Canny(img_gry, img_cny, 10, 100, 3, true);
	cv::imshow("Example Canny", img_cny);

	cv::waitKey(0);

}