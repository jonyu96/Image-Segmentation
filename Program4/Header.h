/*****************************************************************/
/* Container.h
/*
/* Author: Jonathan Yu
/*
/* This file describes the interface to the Container object class.
/*
/*****************************************************************/

#pragma once

Include the ImageLib header file 

class Container {

public: 

	Constructor
	Copy Constructor
	Destructor 

	Operator= overloader function 
	Operator== overloader function 
	Function that checks if Container object is empty or not 
	Function that checks if pixel passed in is close enough to seed pixel

	Function that adds pixel to Container group 
	Function that merges two Containter groups together
	Function that adds seed pixel to Container 

	Function that returns average pixel of Container 
	Function that returns average red value of Container
	Function that returns average green value of Container
	Function that returns average blue value of Container 
	Function that returns size of Container

private: 

	Struct class of node containing image pixel and pointer 
	
	Private function that passes in single pixel and updates color values
	Private function that passes in Container and updates color values 
	Private function that removes all nodes in Container object 

	Class definition of head pointer 
	Class definition of seed pixel 

	Class definition of integer size  
	Class definition of total red value
	Class definition of total green value 
	Class definition of total blue value 
};
