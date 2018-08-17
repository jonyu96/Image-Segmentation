// Image.cpp
// Author:  Jonathan Yu
// Purpose: This file defines member functions for class Image.

#include "Image.h"

// Constructor 
// Default constructor for class Image 
// Preconditions:	valid filename of input file
// Postconditions:	image of input GIF file is constructed
Image::Image(string filename) {
	gif = ReadGIF(filename);
}

// Constructor 
// Alternative constructor for class Image
// Preconditions:	number of rows and columns are >= 0
// Postconditions:  a blank, black image of given rows/cols is constructed
Image::Image(int rows, int cols) {
	gif = CreateImage(rows, cols);
}

// Destructor
// Destructor for class Image
// Preconditions:	none
// Postconditions:  image is deallocated 
Image::~Image() {
	DeallocateImage(gif);
}

// Copy constructor for class Image
// Preconditions:	Image class object is passed in 
// Postconditions:  creates a copy of an image 
Image::Image(const Image &input) {
	copy(input);
}

// operator= 
// Overloaded assignment operator 
// Preconditions:	Image class object is passed in 
// Postconditions:  an Image class object is assigned
const Image& Image::operator=(const Image& input) {
	if (&input != this) {
		DeallocateImage(gif);
		copy(input);
	}
	return *this;
}

// Copy method 
// Called by copy constructor and operator= to do actual copying of image
// Preconditions:	image to copy 
// Postconditions:  input image is copied 
void Image::copy(const Image& toCopy) {
	gif = CopyImage(toCopy.gif);
}

// Access number of rows of image
// Preconditions:	none
// Postconditions:  returns number of rows
int Image::getRows() const {
	return gif.rows;
}

// Access number of columns of image
// Preconditions:	none
// Postconditions:  return number of columns 
int Image::getCols() const {
	return gif.cols;
}

// Change image pixel 
// Preconditions:	pixel location is within image boundaries
// Postconditions:  image pixel is changed to passed pixel value
void Image::changePixel(int row, int col, const pixel p) {
	if (row >= 0 && col >= 0) {
		gif.pixels[row][col] = p;
	}
}

// Access Image pixel  
// Preconditions:	row and col are within image boundaries
// Postconditions:  returns image pixel at given location
pixel Image::getPixel(int row, int col) const {
	if (row >= 0 && col >= 0) {
		return gif.pixels[row][col];
	}
}

void Image::markPixel(int row, int col) {
	gif.pixels[row][col].blue = 255;
	gif.pixels[row][col].red = 0;
	gif.pixels[row][col].green = 0;
}

bool Image::isPixelMarked(int row, int col) const {
	return (gif.pixels[row][col].blue == 255 &&
			gif.pixels[row][col].red == 0 &&
			gif.pixels[row][col].green == 0);
}

// Changes all three colors for a given pixel 
// Preconditions:	row and col are 0 or larger; red, green, and 
//					blue values are passed in 
// Postconditions:	red, green, and blue values of the pixel are changed
void Image::changeAllColors(byte redValue, byte greenValue, 
	byte blueValue, int row, int col) {
	if (row >= 0 && col >= 0) {
		gif.pixels[row][col].red = redValue;
		gif.pixels[row][col].green = greenValue;
		gif.pixels[row][col].blue = blueValue;
	}
}

// Checks to see if pixel has any color
// Preconditions:	given row and col are in bounds; throws
//					exception otherwise
// Postconditions:  returns true if pixel has color, false otherwise
bool Image::isPixelColored(int row, int col) const {
	if (row < 0 || col < 0) {
		throw "Out of bounds!";
	}
	return (gif.pixels[row][col].red > 0 ||
		gif.pixels[row][col].green > 0 ||
		gif.pixels[row][col].blue > 0);
}

bool Image::isPixelBlack(int row, int col) const {
	return (gif.pixels[row][col].red == 0 &&
		gif.pixels[row][col].green == 0 &&
		gif.pixels[row][col].blue == 0);
}

// output image to a GIF file
// Preconditions:	parameter is filename to output file
// Postconditions:  output GIF file is created 
void Image::outputFile(string filename) const {
	WriteGIF(filename, gif);
}

// compares two images if they are equal 
// Preconditions:	parameter is an Image class object
// Postconditions:  returns true if two images are same, false otherwise
bool Image::operator==(const Image& input) const {
	if (*this > input || *this < input) {
		return false;
	}
	for (int row = 0; row < gif.rows; row++) {
		for (int col = 0; col < gif.cols; col++) {
			if (gif.pixels[row][col].red !=
				input.gif.pixels[row][col].red ||
				gif.pixels[row][col].blue !=
				input.gif.pixels[row][col].red ||
				gif.pixels[row][col].green !=
				input.gif.pixels[row][col].green) {
				return false;
			}
		}
	} 
	return true;
}

// checks to see if two images are not same 
// Preconditions:	parameter is an Image class object
// Postconditions:  returns true if two images are not same, false otherwise
bool Image::operator!=(const Image& input) const {
	return !(*this == input);
}

// compares two images if one is smaller than the other
// Preconditions:	paremeter is an Image class object
// Postconditions:  returns true if image is smaller than 
//					other image, false otherwise
bool Image::operator<(const Image& input) const {
	return (gif.rows * gif.cols) < (input.getRows() * input.getCols());
}

// compares two images if one is bigger than the other
// Preconditions:	parameter is an Image class object
// Postconditions:  returns true if image is bigger than other image, 
//					false otherwise
bool Image::operator>(const Image& input) const {
	return (gif.rows * gif.cols) > (input.getRows() * input.getCols());
}

// outputs the number of rows and columns of image 
// Preconditions:	parameters are output stream and Image objects
// Postconditions:  returns output stream object for chaining 
ostream& operator<<(ostream &output, const Image &input) {
	output << "Number of rows/cols: " << input.gif.rows << "/" << input.gif.cols;
	return output;
}

// rotates image 90 degrees counter-clockwise
// Preconditions:	none
// Postconditions:  a rotated version of input image is returned 
Image Image::rotate() const {
	Image rotatedImage(gif.cols, gif.rows);
	for (int row = 0; row < rotatedImage.getRows(); row++) {
		for (int col = 0; col < rotatedImage.getCols(); col++) {
			rotatedImage.gif.pixels[row][col] =
				gif.pixels[col][gif.cols - 1 - row];
		}
	}
	return rotatedImage;
}


