// AUstin Kingrey
// This program creates a square and puts a word in it
//

#include "stdafx.h"
#include "Simple_window.h"
#include "Graph.h"



int main()
{
	using namespace Graph_lib; //namespace
	Point x{ 100,100 }; //create point for window
	Simple_window win{ x,600,400,"Canvas" }; //create window

	Polygon poly; //create new polygon

	//add the 4 points
	poly.add(Point{ 200,200 });
	poly.add(Point{ 200,170 });
	poly.add(Point{ 300,200 });
	poly.add(Point{ 300,170 });

	poly.set_color(Color::blue); //sets the color

	//add text
	Text t{ Point{220,185}, "Howdy!" };

	//attach my elements
	win.attach(poly);
	win.attach(t);
	win.wait_for_button();


    return 0;
}

