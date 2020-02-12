/*
Name: Denny Feng
Date: September 4, 2019
Task: Finding the Perfect Square
Description: Write a program to find and print the first perfect square (i*i) whose last two digits are both odd. 
*/

#include <iostream>
using namespace std; 

int main() {
  int i = 0; 
  while(true){
    int square = i*i;
    int lastdigit2 = square % 10; 
    int lastdigit = (square / 10) % 10; 

      if(lastdigit2 % 2 == 1 && lastdigit % 2 == 1){
        cout << "Square is: " << square << endl;
		cout << "i is: " << i << endl; 
        break;
      }
      i++;
    }
}