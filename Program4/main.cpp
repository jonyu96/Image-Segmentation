co// main.cpp
// Author:  Jonathan Yu
// Purpose: This program performs image segmentation on a valid test GIF file. 
//			The process of segmentation is done by finding connected groups 
//			of pixels and using their averages to modify the output image. The 
//			resulting segmented image is thus output to a file. 

#include "Image.h"
#include "Container.h"

#include <iostream>
using namespace std;

// forward declarations 
void createGroup(const Image &input, Image &output, Container &group,
	int row, int col);
void modifyOutput(Image &output, Container &group);

// main()
// Preconditions:	test image is a valid GIF file 
// Postconitions:	outputs resulting segmented image to output file
int main() {

	Image input("test.gif");
	Image output(input.getRows(), input.getCols()); // create blank output image

	Container bigGroup; // container to store merged group 
	int segments = 0;

	// examine all possible seed pixels in the raster order
	// create connected groups of pixels and modify output image
	for (int row = 0; row < output.getRows(); row++) {
		for (int col = 0; col < output.getCols(); col++) {
			if (output.isPixelBlack(row, col)) {
				Container group;
				group.addSeed(input.getPixel(row, col));
				createGroup(input, output, group, row, col);
				modifyOutput(output, group);
				bigGroup.merge(group);
				segments++;
			}
		}
	}

	// output segmented image to an output file 
	output.outputFile("output.gif");

	// output to console information about the merged group 
	cout << "Total number of segments found: " << segments << endl;
	cout << "Number of pixels in merged group: " << bigGroup.getSize() << endl;
	cout << "Average color of merged group (red/green/blue): " <<
		bigGroup.getAvgRed() << "/" << bigGroup.getAvgGreen() << "/" <<
		bigGroup.getAvgBlue() << endl;

	system("PAUSE");
	return 0;
}

// build a connected group of pixels around a seed pixel, by examining 
// neighboring pixels 
// Preconditions:	pixels of given row and col are within image boundaries
//					and not already colored in output image
// Postconditions:  pixels not colored in output image and are close 
//					enough to seed pixel is added to connected group
void createGroup(const Image &input, Image &output, Container &group, 
	int row, int col) {
	if (row >= input.getRows() || col >= input.getCols() ||
		row < 0 || col < 0) return;
	if (output.isPixelColored(row, col)) return;
	pixel p = input.getPixel(row, col);
	if (group.isPixelClose(p)) {
		group.addPixel(p, row, col);
		output.markPixel(row, col);
		createGroup(input, output, group, row + 1, col);
		createGroup(input, output, group, row, col + 1);
		createGroup(input, output, group, row - 1, col);
		createGroup(input, output, group, row, col - 1);
	}
}

// modify output image with average of all pixels in connected group 
// at each pixels' locations 
// Preconditions:	connected group has at least one pixel 
// Postconditions:  output image contains a segment of input image
void modifyOutput(Image &output, Container &group) {
	while (!group.isCurNull()) {
		output.changePixel(group.getCurRow(), group.getCurCol(),
			group.getAvgPixel());
		group.moveCur();
	}
}

