/***************************************************************
 *
 * Project 1b: Some Computer Graphics Examples
 *
 * Author: Nicholas Primiano <nprimiano@fordham.edu>
 * Date: 18 September 2013
 *
 * This program draws a red and black checkerboard
 * in a window.
 *
 **************************************************************/

#include "Simple_window.h"
#include "Graph.h"
#include <iostream>

using namespace Graph_lib;

//usual main function
int main(){
    //Window starting point and size
    Point point_start(100,100);
    int size_x = 800;
    int size_y = 800;
    //Make Checkerbaord window
    Simple_window matrix(point_start, size_x,size_y, "Checkerboard");
     
    //Make checkerbaord boxes and fill vectors
    Vector_ref<Rectangle> fill;

    //Fill alternating boxes red and black
    for(int y = 0; y <8; y++){
        for(int x = 0; x < 8; ++x){
	    fill.push_back(new Rectangle(Point(y*90, x*90),90,90));	   
	    if(x % 2 == 0 && y % 2 == 0){
                fill[fill.size()-1].set_fill_color(Color::red);
	    }
	    else if (x % 2 == 1 && y % 2 == 1){
                fill[fill.size()-1].set_fill_color(Color::red);
	    }
	    else{
		fill[fill.size()-1].set_fill_color(Color::black);
	    }
	    //Add fill to window
	    matrix.attach(fill[fill.size()-1]);        
	}
    }
    matrix.wait_for_button();
    //Return 0 indicating successful completion
    return 0;
}
