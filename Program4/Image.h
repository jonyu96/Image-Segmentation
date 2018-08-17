/*****************************************************************/
/* Image.h
/*
/* Author: Jonathan Yu
/*
/* This file describes the interface to the Image object class. 
/* This interface includes the ImageLib interface to the ImageLib
/* Library, which provides the functionality to read/write GIF images 
/* and process them. Image class object contains an image structure 
/* from the ImageLib class.
/*
/*****************************************************************/

#pragma once

#include "ImageLib.h"
#include <iostream>
using namespace std;

class Image {

	// overloaded <<: prints the number of rows and cols of Image object
	// Preconditions:	Output stream object and Image object are passed in
	// Postconditions:  Output stream object is returned for chaining
	friend ostream& operator<<(ostream &, const Image &);
	
public:

	// constructor 
	// Preconditions:	valid filename is passed in 
	// Postconditions:  reads from a file to construct image
	Image(string filename);

	// alternative constructor
	// Preconditions:	parameters are number of rows and columns
	// Postconditions:  creates a blank, black image
	Image(int rows, int cols);

	// copy constructor
	// Preconditions:	none
	// Postconditions:  an Image class object is copied
	Image(const Image &);

	// destructor 
	// Preconditions:	none
	// Postconditions:  image is deallocated  
	~Image();

	// assigns Image objects
	const Image& operator=(const Image &);

	// access number of rows and columns of image
	// Preconditions:	none
	// Postconditions:  returns rows and columns
	int getRows() const;
	int getCols() const;

	// change and access image pixel
	// Preconditions:	parameters are row and column and new pixel
	// Postconditions:  return pixel or changes pixel
	void changePixel(int row, int col, const pixel p);
	pixel getPixel(int row, int col) const;
	void  markPixel(int row, int col);
	
	// changes all three colors of pixel
	// Preconditions:	row and col of given pixel are in bounds
	// Postconditions:  changes all three color values of pixel
	void changeAllColors(byte redValue, byte greenValue, byte blueValue,
		int row, int col);

	// checks to see if pixel has any color values
	// Preconditions:	row and col of pixel are legal bounds of an image
	// Postconditions:  returns true or false
	bool isPixelColored(int row, int col) const;
	bool isPixelMarked(int row, int col) const;
	bool isPixelBlack(int row, int col) const;

	// output image to a file
	// Preconditions:	filename for output file is passed 
	// Postconditions:  output file of iamge is created
	void outputFile(string filename) const;

	// boolean comparison operators
	// Preconditions:	Image class object is passed in 
	// Postconditions:  returns true/false for each comparisons
	bool operator==(const Image &) const;
	bool operator!=(const Image &) const;
	bool operator<(const Image &) const;
	bool operator>(const Image &) const;

	// rotate an image by 90 degrees counter-clockwise 
	// Preconditions:	none
	// Postconditions:  returns a rotated image
	Image rotate() const;

private: 
	image gif;					// an image 
	void copy(const Image &);	// create a copy of an image
};
