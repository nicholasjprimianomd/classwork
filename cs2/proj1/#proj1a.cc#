/***************************************************************
 *
 * Project 1a: Some Computer Graphics Examples
 *
 * Author: Nicholas Primiano <nprimiano@fordham.edu>
 * Date: 18 September 2013
 *
 * This program prompts the user to enter a name then it
 * displays that name in a window.
 *
 **************************************************************/

#include "Simple_window.h"
#include <iostream>

using namespace Graph_lib;

//usual main function
int main(){
    //string to hold user's full name
    string full_name;
    //prompt user and read in a full line of text
    cout << "Enter your name: "; 
    getline(cin, full_name);

    //Tell user how to exit the program
    cout << "Click the ""Next"" button to quit the program!\n";
    
    //Create a window to display the user's name in bold
    Point point_start(100,100);
    Point point_name(150,200);
    int size_window_x = 600;
    int size_window_y = 400;
    Simple_window window(point_start,size_window_x,size_window_y,"Name Window");
    Text name_text(point_name, full_name);
    
    int font_size = 32;
    name_text.set_font_size(font_size);
    name_text.set_font(Graph_lib::Font::times_bold);
    window.attach(name_text);
    

    window.wait_for_button();    
    //return 0 indicating successful completion
    return 0;
}
