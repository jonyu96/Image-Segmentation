/*****************************************************************/
/* Container.h
/*
/* Author: Jonathan Yu
/*
/* This file describes the interface to the Container class. It declares 
/* functions that allow client to store connected group of pixels and their 
/* information in a container.
/*
/*****************************************************************/

#pragma once
#include "ImageLib.h"

class Container {
	
public:

	// Constructor, Copy Constructor
	// Preconditions:	none
	// Postconditions:	container is constructed 
	Container();
	Container(const Container &);

	// Destructor
	// Preconditions:	none
	// Postconditions:	container is destructed 
	~Container();

	// Assignment operator
	// Preconditions:	container
	// Postconditions:	container is assigned passed container
	const Container& operator=(const Container &);

	// Compares two containers 
	// Preconditions:	container
	// Postconditions:	returns true if containers are same, false otherwise
	bool operator==(const Container &) const;

	// Checks to see if container is empty
	// Preconditions:	none
	// Postconditions:	returns true if empty, false otherwise
	bool isEmpty() const;

	// Checks to see if pixel passed is close to seed pixel
	// Preconditions:	pixel 
	// Postconditions:	true if pixel is close to seed, false otherwise
	bool isPixelClose(const pixel &) const;

	// Adds pixel and row/col to container 
	// Preconditions:	pixel to be added and its row/col 
	// Postconditions:	pixel is added to container
	void addPixel(const pixel &, int row, int col);

	// Merges a container with another container
	// Preconditions:	container
	// Postconditions:	two containers are merged
	void merge(const Container &);

	// Adds seed pixel to container
	// Preconditions:	pixel to be added
	// Postconditions:	pixel added becomes seed pixel of container
	void addSeed(const pixel &);

	// Gets average pixel, red/green/blue and size values
	// Preconditions:	none
	// Postconditions:	returns container information 
	pixel getAvgPixel() const;
	int getAvgRed() const;
	int getAvgGreen() const;
	int getAvgBlue() const;
	int getSize() const;

	// Allows client to traverse within the container
	// Preconditions:	none
	// Postconditions:	returns information of nodes from container
	bool isCurNull() const;
	void moveCur();
	int getCurRow() const;
	int getCurCol() const;

private: 

	struct PixelNode // a pixelnode stores a pixel data, 
					 // a pointer to next node, and row/col
					 // values of that pixel
	{
		pixel imagePixel;	// a pixel from image
		PixelNode *next;	// a pointer to next node
		int row;			// row value of that pixel
		int col;			// col value of that pixel
	};

	// Private Functions
	// Updates RGB values of container
	// Preconditions:	pixel, container
	// Postconditions:	RGB values from pixel or container
	//					are added to RGB values of container
	void addPixelColor(const pixel &);
	void addTotalColor(const Container &);

	// Private Function
	// Removes all nodes in a container
	// Preconditions:	none
	// Postconditions:	all nodes in a container are deleted
	void removeAllNodes();

	PixelNode *head;	// first pointer in container
	PixelNode *tail;	// last pointer in container
	pixel seed;			// designated seed pixel of container
	PixelNode *cur;		// pointer to traverse nodes in container

	int size;			// size of container
	int totalRed;		// total red value of all pixels in container
	int totalGreen;		// total green value of all pixels in container
	int totalBlue;		// total blue value of all pixels in container
};