# Image Segmentation

This was the final class project for CSS 342 (Data Structure & Algorithms I) taught by Professor Clark Olson. 
The object was to create a program that performs image segmentation on a valid .gif file. The process of segmentation is done
by finding connected groups of pixels and using their averages to modify the output image. The resulting 
segmented image is thus output to a file. 

### Example 

Before image segmentation: 

<img width="300" height="300" src="https://github.com/jonyu96/Image-Segmentation/blob/master/Program4/test.gif">

After image segmentation: 

<img width="300" height="300" src="https://github.com/jonyu96/Image-Segmentation/blob/master/Program4/testOutput.gif">

### Installing 

Program was created on Microsoft Visual Studio. To run, please use MVS and download project source code files. To segment a particular image, please download an image and rename file name extension to .gif (e.g. "test.gif"). Include image in the project folder. 

### Contribution 

ImageLib.h, ImageLib.lib, and ImageLib.pdb files were provided by Professor Olson for this project. These files allow the program to work with valid .gif image files and be able to modify the pixels in order to perform image segmentation. 
