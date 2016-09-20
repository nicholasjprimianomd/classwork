/**********************************************************************
 *
 * Project 3: Graphing Data
 *
 * Author: Nicholas Primiano <nprimiano@fordham.edu>
 * Date: 30 October 2013
 *
 * Graph life expectancy verus age based on gender.
 * 
 **********************************************************************/
#include "Simple_window.h"
#include "Graph.h"
#include <iostream>

using namespace Graph_lib;

//Empty error handling classes
struct out_of_range{};
struct file_error{};

//Struct for information held in the text file
struct Ages{
    //Variables for holding information from text file
    int current_age;
    double average_expectancy;
    double male_expectancy;
    double female_expectancy;
};

//Class for scaling data
class Scale {
    //Scaling data member for each line
    int cbase;
    int vbase;
    double scale;
public:
    Scale(int b, int vb, double s) : cbase(b), vbase(vb), scale(s){}
    int operator() (int v) const {return cbase + (v-vbase)*scale;}
};

//Overload >> operator to use with data from txt file
ifstream& operator>> (ifstream& is, Ages& a);

int main()
    try{
	//Name of file from which to read data
	string file_name = "life-expectancy.txt";
	//Open file for reading
	ifstream ifs(file_name.c_str());
	if (!ifs) throw file_error();
    
	//Age and terminal years
	Ages a;
	int base_year = 0;
	int end_year = 100;

	//Scaling constants
	const int xmax = 600;
	const int ymax = 400;

	const int xoffset = 60;
	const int yoffset = 60;

	const int xspace = 40;
	const int yspace = 40;

	const int xlength = xmax - xoffset - xspace;
	const int ylength = ymax - yoffset - yspace;
    
	//Max x value
	const int xrange = 100;
	//Max y value
	const double yrange = 80.4;

	const double xscale = double(xlength)/xrange;
	const double yscale = ylength/yrange;
    
	//Scale x and y 
	Scale xs(xoffset,base_year,xscale);
	Scale ys(ymax-yoffset,0,-yscale);
    
	//Window start point
	Point start_point(100,100);
	//Axes starting points
	Point x_axis_point(xoffset, ymax-yoffset);
	Point y_axis_point(xoffset, ymax-yoffset);

	//Define window
	Simple_window win(start_point, xmax, ymax, "U.S. Life Expectancy");
    
	Axis x(Axis::x, x_axis_point,
	       xlength, (end_year-base_year)/10, 
	       "Age      0          10         20         30        40        "
	       "50        60         70         80        90       100");
  
	const int xlabel_movex = -160; 
	x.label.move(xlabel_movex,0);

	const int yticks = 8;
	Axis y(Axis::y, y_axis_point, ylength, yticks, "Life expectancy");
	const int ylabel_movey = -45;
	y.label.move(ylabel_movey,0);

	//Lines for data
	Open_polyline all;
	Open_polyline male;
	Open_polyline female;

	//Read in data
	while(ifs>>a){
	    if(a.current_age < base_year || end_year < a.current_age)
		throw out_of_range();
	    int x = xs(a.current_age);
	    all.add(Point(x, ys(a.average_expectancy)));
	    male.add(Point (x, ys(a.male_expectancy)));
	    female.add(Point (x, ys(a.female_expectancy)));
	}
   
	//Attach objects to window
	win.attach(all);
	win.attach(male);
	win.attach(female);

	//Label points
	Point all_label_point(40,58);
	Point male_label_point(120,130);
	Point female_label_point(120,70);

	//Style and place lables and lines
	Text all_label(all_label_point, "all");
	all.set_color(Color::magenta);
	all_label.set_color(Color::magenta);
	Text male_label(male_label_point, "male");
	male.set_color(Color::red);
	male_label.set_color(Color::red);
	Text female_label(female_label_point, "female");
	female.set_color(Color::blue);
	female_label.set_color(Color::blue);
    
	//Attach lables
	win.attach(all_label);
	win.attach(male_label);
	win.attach(female_label);
    
	//Attach lines
	win.attach(x);
	win.attach(y);
	win.wait_for_button();
    }
    catch(out_of_range& e0){
	cerr << "Out of range error" << endl;
	return 1;
    }	
    catch (file_error & e1){
	cerr << "Could not open file" << endl;
	return 2;
    }
    catch (...){
	cerr << "Other error" << endl;
	return 3;
    }

//Overload >>
ifstream& operator>> (ifstream& is, Ages& a){
    //Chars for format check
    char ch1 ;
    char ch2 ;
    char ch3 ;
    //New object to take data from file
    Ages aa;

    //Read in data and check format
    if(is >> aa.current_age >> ch1 >> aa.average_expectancy 
       >> ch2 >> aa.male_expectancy >> ch3 >> aa.female_expectancy){
	if(ch1 != '|' || ch2 != '|' || ch3 != '|'){
	    is.clear(ios_base::failbit);
	    return is;
	}
    }
    else 
	return is;
    a = aa;
    return is;
}

