#include<iostream>
#include "ImageProcessor.hpp"
int
main(int argc, char** argv){
	std::cout<<"Hello From Image Processor's main"<<std::endl;
	ImageProcessor imageProcessor{"./images/", "./output"};
	imageProcessor.getEdgesForImage("./images/butterfly.jpg");
}
