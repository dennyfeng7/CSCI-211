/*
Name: Denny Feng
Date: November 8, 2019
Task: Integration Problem
Description: The goal of this project is to find the area of a function between two points. The program uses typedef to create an alias for a function. By doing so, we can pass a function as a parameter for another function call. This function returns the area under the curve between x=a and x=b.
*/

#include <iostream>
using namespace std;
 
typedef double FUNC (double);
 
// Returns the area under the curve between x=a and x=b.
// The function passed as the first parameter determines the shape of the curve.
// Use a Riemann sum to estimate the area by dividing it into narrow rectangles 
// (each rectangle should have a width of .0001)
// and adding up the areas of the individual rectangles.
// For a rectangle at horizontal position x, the height will be f(x).
// (when you call f(x) it'll call whatever function you passed as the first parameter)
double integrate(FUNC f, double a, double b) {
    // Fill in.

    double w=0.0001, h, area=0; 
    // loop x from a to b, each x represents width of rectangle (0.0001)
    for(double x = (a+w) / 2; x < b; x+= w)
    area += f(x) * w; 
    return area; 
}
    /*for(double x = a; x < b; x+=0.001){
         f = h; 
         area += w * h; 
        //height is equal to the value of the y axis
        
    }*/
    // area += height * width, 
    // where width = 0.0001, height = f(x + 0.0001/2) (the mid-point is more accurate)
    // return area;
 
double line(double x) {
   return x;
}
 
 /*.................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................*/
 
double square(double x) {  
   return x*x;
}
 
double cube(double x) { 
   return x*x*x;
}
 
int main() {
   cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;   // output: 12
   cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // output: 41.3333
   cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // output: 156
   return 0;
}