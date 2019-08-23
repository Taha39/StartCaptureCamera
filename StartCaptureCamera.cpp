// StartCaptureCamera.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
//#include <iostream>
#include "CamResolutionDShow.h"
#include "CamCaptureOpenCV.h"

using namespace std;

int main()
{
	int w{ 0 };
	int h{ 0 };
	auto cam_details = cam_resolutioin::enum_devices();
	auto itr = cam_details.begin();
	for (; itr != cam_details.end(); itr++) {
		cam_resolutioin::setcolor(GREEN);
		std::cout << "\n Cam Name: " << (itr->first).c_str() <<std::endl << " Resolution supportd: \n";
		auto resolution = itr->second;
		for (int i = 0; i < resolution.size(); i++) {
			cam_resolutioin::setcolor(BLUE);
			std::cout << "\t \t " << resolution[i].first << " x " << resolution[i].second << std::endl;
		}
		w = resolution[3].first;
		h = resolution[3].second;
	}

	cam_capture::startCamCapture(0, w, h);

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
