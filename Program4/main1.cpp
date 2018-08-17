// main.cpp
// Author:  Jonathan Yu
// Purpose: This program...

#include "Image.h"
#include "Container.h"

#include <iostream>
using namespace std;

void createGroup(const Image &input, Image &result, Container &group,
	int row, int col);
void modifyOutput(Image &output, const Container &group, int row, int col);

int main() {

	Image input("image001.gif");
	Image output(input.getRows(), input.getCols());

	Container bigGroup;
	int segments = 0;

	for (int row = 0; row < output.getRows(); row++) {
		for (int col = 0; col < output.getCols(); col++) {
			if (output.isPixelBlack(row, col)) {
				Container group;
				group.addSeed(input.getPixel(row, col));
				createGroup(input, output, group, row, col);
				modifyOutput(output, group, row, col);
				bigGroup.merge(group);
				segments++;
			}
		}
	}

	output.outputFile("output.gif");

	cout << "Total number of segments found: " << segments << endl;
	cout << "Number of pixels in merged group: " << bigGroup.getSize() << endl;
	cout << "Average color of merged group (red/green/blue): " <<
		bigGroup.getAvgRed() << "/" << bigGroup.getAvgGreen() << "/" <<
		bigGroup.getAvgBlue() << endl;

	Container bigGroup2(bigGroup);
	cout << "Number of pixels in bigGroup2: " << bigGroup2.getSize() << endl;

	Container bigGroup3 = bigGroup;
	cout << "Number of pixels in bigGroup3: " << bigGroup3.getSize() << endl;

	system("PAUSE");
	return 0;
}

void createGroup(const Image &input, Image &output, Container &group,
	int row, int col) {
	if (row >= input.getRows() || col >= input.getCols() ||
		row < 0 || col < 0) return;
	if (output.isPixelColored(row, col)) return;
	pixel p = input.getPixel(row, col);
	if (group.isPixelClose(p)) {
		group.addPixel(p);
		output.markPixel(row, col);
		createGroup(input, output, group, row + 1, col);
		createGroup(input, output, group, row, col + 1);
		createGroup(input, output, group, row - 1, col);
		createGroup(input, output, group, row, col - 1);
	}
}

void modifyOutput(Image &output, const Container &group, int row, int col) {
	if (row >= output.getRows() || col >= output.getCols() ||
		row < 0 || col < 0) return;
	if (output.isPixelMarked(row, col)) {
		output.changePixel(row, col, group.getAvgPixel());
		modifyOutput(output, group, row + 1, col);
		modifyOutput(output, group, row, col + 1);
		modifyOutput(output, group, row - 1, col);
		modifyOutput(output, group, row, col - 1);
	}
}

