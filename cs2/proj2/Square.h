#include "Simple_window.h"
#include "Graph.h"
#include <iostream>



class Square : public Shape {

public:
    

//constructor for Square defined by single point and side length
    Square(Point xy, int ll) : l(ll)
	{
	    if (l <= 0){
		throw 1;
	    }
	    add(xy);
	}
//constructor for Square defined by two points
    Square(Point point1, Point point2) : l(point2.x-point1.x)
	{

	    if(l != (point2.y-point1.y)){
		throw 2;
	    }
	    if(l <=  0){
		throw 1;
	    }
	
	    add(point1);
	}
//draw square
    void draw_lines() const;

    int side() const { return l;}
    
private: 
    int l;    //side length
};

