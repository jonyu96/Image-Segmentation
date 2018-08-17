// Container.cpp
// Author:  Jonathan Yu
// Purpose: This file defines the member functions of a 
//		    container for storing a connected group of pixels and 
//			traversing through it. 

#include "Container.h"
#include <math.h>

// Constructor 
// Default constructor to create an empty container
// Preconditions:	none
// Postconditions:  an empty container is constructed
Container::Container() {
	head = nullptr;
	tail = head;
	cur = head;
	size = 0;
}

// Copy constructor 
// Copy constructor to create a copy of another container
// Preconditions:	a container is passed in 
// Postconditions:	a copy of passed container is constructor 
Container::Container(const Container &other) {
	size = 0;
	head = nullptr;
	tail = head;
	*this = other;
}

// Destructor
// Preconditions:	none
// Postconditions:  container is emptied 
Container::~Container() {
	removeAllNodes();
}

// Operator=
// Overloaded assignment operator
// Preconditions:	a container is passed in 
// Postconditions:  a container is assigned connected group of pixels 
//					(including location of each pixel) and seed pixel 
//					from another container and is returned 
const Container& Container::operator=(const Container &other) {
	if (this == &other) return *this;
	removeAllNodes();
	if (other.head == nullptr) {
		head = nullptr;
		tail = head;
	}
	else {
		seed = other.seed;
		head = new PixelNode;
		head->imagePixel = other.head->imagePixel;
		head->row = other.head->row;
		head->col = other.head->col;
		PixelNode *ptr = head;
		PixelNode *otherPtr = other.head->next;
		while (otherPtr != nullptr) {
			ptr->next = new PixelNode;
			ptr = ptr->next;
			ptr->imagePixel = otherPtr->imagePixel;
			ptr->row = otherPtr->row;
			ptr->col = otherPtr->col;
			otherPtr = otherPtr->next;
		}
		ptr->next = nullptr;
		tail = ptr;
		addTotalColor(other);
		size = other.size;
	}
	return *this;
}

// Operator== 
// Compares two containers if they are the same 
// Preconditions:	a container is passed in 
// Postconditions:	returns true if both containers are same, 
//					false otherwise
bool Container::operator==(const Container& other) const {
	PixelNode *ptr = head;
	PixelNode *otherPtr = other.head;
	while (ptr != nullptr || otherPtr != nullptr) {
		if ((ptr == nullptr && otherPtr != nullptr) ||
			(ptr != nullptr && otherPtr == nullptr)) return false;
		if (ptr->imagePixel.red != otherPtr->imagePixel.red ||
			ptr->imagePixel.green != otherPtr->imagePixel.green ||
			ptr->imagePixel.blue != otherPtr->imagePixel.blue) return false;
		ptr = ptr->next;
		otherPtr = otherPtr->next;
	}
	return true;
}

// Checks if container is empty 
// Preconditions:	none
// Postconditions:  return true if empty, false otherwise 
bool Container::isEmpty() const {
	return (size == 0);
}

// Adds pixel and its location to container of connected pixels
// Preconditions:	pixel is passed in, row and col of pixel 
//					are within bounds of input image 
// Postconditions:	pixel is added to the group of connected pixels,
//					RGB and size information of container is updated
void Container::addPixel(const pixel &p, int row, int col) {
	if (head == nullptr) {
		head = new PixelNode;
		head->imagePixel = p;
		head->row = row;
		head->col = col;
		head->next = nullptr;
		tail = head;
		cur = head;
	}
	else {
		tail->next = new PixelNode;
		tail = tail->next;
		tail->imagePixel = p;
		tail->row = row;
		tail->col = col;
		tail->next = nullptr;
	}
	addPixelColor(p);
	size++;
}

// Merges two containers together 
// Preconditions:	a container to be merged with is passed
// Postconditions:	a container is merged with another container 
//					and its RGB and size information updated
void Container::merge(const Container &other) {
	if (other.head != nullptr) {
		PixelNode *otherPtr = other.head;
		if (head == nullptr) {
			head = new PixelNode;
			head->imagePixel = otherPtr->imagePixel;
			head->row = otherPtr->row;
			head->col = otherPtr->col;
			head->next = nullptr;
			tail = head;
			otherPtr = otherPtr->next;
		}
		while (otherPtr != nullptr) {
			tail->next = new PixelNode;
			tail = tail->next;
			tail->imagePixel = otherPtr->imagePixel;
			tail->row = otherPtr->row;
			tail->col = otherPtr->col;
			otherPtr = otherPtr->next;
		}
		tail->next = nullptr;
		addTotalColor(other);
		size += other.size;
	}
}

// Adds seed pixel to container
// Preconditions:	pixel to become seed is passed
// Postconditions:	pixel is assigned as seed pixel 
//					of container
void Container::addSeed(const pixel &p) {
	seed = p;
}

// Gets average pixel of container
// Preconditions:	none
// Postconditions:	pixel containing average RGB values 
//					of container is returned
pixel Container::getAvgPixel() const {
	pixel average;
	average.red = totalRed / size;
	average.green = totalGreen / size;
	average.blue = totalBlue / size;
	return average;
}

// Gets average red value of container
// Preconditions:	none
// Postconditions:	average red value of container is returned
int Container::getAvgRed() const {
	return totalRed / size;
}

// Gets average green value of container
// Preconditions:	none
// Postconditions:	average green value of container is returned
int Container::getAvgGreen() const {
	return totalGreen / size;
}

// Gets average blue value of container
// Preconditions:	none
// Postconditions:	average blue value of container is returned
int Container::getAvgBlue() const {
	return totalBlue / size;
}

// Gets size of container
// Preconditions:	none
// Postconditions:	size of container is returned
int Container::getSize() const {
	return size;
}

// Checks to see if pixel is close enough to seed pixel of container
// Preconditions:	pixel is passed in 
// Postconditions:	return true if pixel is close enough, false otherwise
bool Container::isPixelClose(const pixel &p) const {
	return ((abs(seed.red - p.red) + abs(seed.green - p.green) +
		abs(seed.blue - p.blue)) < 100);
}

// Updates RGB information of container from a single pixel
// Preconditions:	pixel is passed in 
// Postconditions:	RGB values of pixel are added to RGB values 
//					of container 
void Container::addPixelColor(const pixel &p) {
	totalRed += p.red;
	totalGreen += p.green;
	totalBlue += p.blue;
}

// Updates RGB information of container from another container
// Preconditions:	a container is passed in 
// Postconditions:	RGB values of another container are added 
//					to the RGB values of container
void Container::addTotalColor(const Container &other) {
	totalRed += other.totalRed;
	totalGreen += other.totalGreen;
	totalBlue += other.totalBlue;
}

// Empties a container of connected pixels 
// Preconditions:	none
// Postconditions:	all pixels are removed and container 
//					RGB and size values are accounted for 
void Container::removeAllNodes() {
	while (!isEmpty()) {
		PixelNode *temp;
		temp = head;
		head = head->next;
		size--;
		delete temp;
	}
	totalRed = 0;
	totalGreen = 0;
	totalBlue = 0;
	tail = head;
}

// Checks to see if pointer is pointing to nullptr
// Preconditions:	none
// Postconditions:  returns true if pointing to nullptr, 
//					false otherwise
bool Container::isCurNull() const {
	return (cur == nullptr);
}

// Moves pointer to next pixel 
// Preconditions:	none
// Postconditions:	pointer is pointed to next 
void Container::moveCur() {
	cur = cur->next;
}

// Gets row value of pixel 
// Preconditions:	none
// Postconditions:	row value of pixel location is returned
int Container::getCurRow() const {
	return cur->row;
}

// Gets col value of pixel 
// Preconditions:	none
// Postconditions:	col value of pixel location is returned
int Container::getCurCol() const {
	return cur->col;
}