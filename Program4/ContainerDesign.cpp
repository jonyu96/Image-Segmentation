// ContainerDesign.cpp
// Author: Jonathan Yu 
// Purpose: This file defines the member functions of Container object.

Include Container header file 
Include Math class 

// Constructor 
// Preconditions:	none
// Postconditions:  constructs a Container object 
Create a Container object constructor 
	Set head pointer to nullptr 
	Set size to zero 

// Copy constructor 
// Preconditions:	Container object is passed in 
// Postconditons:	Copy of passed Container object is constructed
Create a Container object copy constructor with Container 
object passed in 
	Set head pointer to nullptr
	Set size to zero 
	Assign Container to other container 

// Destructor 
// Preconditions:	none
// Postconditions:  all nodes are removed in Container 
Create a Container object destructor
	Calls function that removes all nodes

// Overloader for operator=
// Preconditions:	Container object is passed 
// Postconditions:	Container is assigned to other Container object
Create an operator= overloader function with Container object passed in 
	If this and other Container object are same, return this 
	Call function to remove all nodes 
	If head pointer of other Container object points to nullptr
		Set head pointer to nullptr 
	Else
		Assign seed pixel to other seed pixel
		Create a new node and set head pointer to it 
		Assign head pixel data to other head pixel data 
		Create a new pointer for this and other Container object
		While other pointer does not equal nullptr 
			Create a new Node in this Container object
			Copy over the image pixel values 
		Set last node in this Container object pointing nullptr 
	Update the size 
	Update the color values of red, green, and blue 
	Return this Container object 

// Compares two Container objects 
// Preconditions:	Container object is passed in 
// Postconditions:	Return true if both Container objects are same, false otherwise
Create a function that compares two Container objects 
	If both objects do not have any nodes, return true
	If head pointer of this Container points to a node and 
	head pointer of other Container points to nullptr, or vice versa, 
	return false

	Create a pointer for this Container object
	Create a pointer for other Container object 

	While this or other pointer does not equal nullptr 
		If the color values of the node from this and other 
		Container objects are not equal, return false 

	Return true

// Checks to see if Container object is empty 
// Preconditions:	Container object is passed in 
// Postconditions:	Return true if empty, false otherwise
Create a function that checks if Container object is empty 
	Return true if size equals zero, false otherwise 

// Adds pixel nodes to Container group 
// Preconditions:	Passes in a pixel object 
// Postconditions:  Adds pixel to Container with size and colors updated
Create a function that adds pixels to the Container group 
	If head pointer equals nullptr 
		Create a new node 
		Assign node pixel value to passed pixel 
	Else, 
		Traverse through the end of the linked list in this Container 
		Add a new node with the pixel value assigned to pixel passed 
	Call function that updates color values of Container 
	Increment size of Container 

// Merges two Container objects
// Preconditions:	Container object is passed in 
// Postconditions:  Merges Container object with updated size and color values 
Create a function that merges Container object with another 
	If other Container object contains nodes
		Create a pointer to traverse linked list of other Container
		If this Container does not contain any nodes
			Create the first node 
			Copy node pixel values
			Assign node to head
		Create a pointer to traverse through this linked list 
		While other pointer does not equal nullptr 
			Create a new node for this linked list
			Copy the pixel values 
		Update total color values of Container object 
		Update the size 

// Creates the seed
// Preconditions:	Pixel is passed in 
// Postconditions:  Seed is updated with pixel values
Create a function that adds a pixel object as the seed 
	Assign seed to passed pixel 

// Returns average pixel of Container group
// Preconditions:	none
// Postconditions:  Returns pixel
Create a function that returns pixel of average values 
	Create a new pixel object
	Assign pixel colors to red, green, and blue average 
	Return pixel 

// Returns average red value of Container
// Preconditions:	none
// Postconditions:  Returns average red value 
Create a function that returns average red value of Container 
	Return total red value divided by size 

// Returns average green value of Container
// Preconditions:	none
// Postconditions:  Returns average green value 
Create a function that returns average green value of Container 
	Return total green value divided by size 

// Returns average blue value of Container
// Preconditions:	none
// Postconditions:  Returns average blue value 
Create a function that returns average blue value of Container 
	Return total blue value divided by size 

// Returns Container size 
// Preconditions:	none
// Postconditions:  Returns number of nodes
Create a function that returns the number of nodes in Container 
	Returns the size 

// Checks whether given pixel is close enough to seed pixel
// Preconditions:	pixel object is passed in 
// Postconditions:  Return true if pixel is close to seed pixel, false otherwise
Create a function that checks whether a pixel is close enough to the seed 
	If the total difference between the red, green, blue values of seed and 
	pixel is less than 100, return true, otherwise false 

// Updates the red, green, and blue values of Container
// Preconditions:	pixel is passed in 
// Postconditions:	red, green, and blue values of Container are updated 
Create a private function that updates the pixel values with passed pixel 
	Adds the passed pixel values of red, green, and blue

// Updates the red, green, and blue values of Container
// Preconditions:	Container object passed is valid
// Postconditions:  red, green, and blue values of Container are updated
Create a private function that updates the pixel values with passed Container 
	Adds the red, green, and blue values of passed Container 

// Removes the nodes in the Container 
// Preconditions:	Container is not empty
// Postconditions:	Nodes in the Container are removed
Create a private function that removes all nodes in Container 
	While Container is not empty
		Create a temporary pointer pointing to head node 
		Set head pointer pointing to next node 
		Delete temporary pointer 


			
		
			
		
