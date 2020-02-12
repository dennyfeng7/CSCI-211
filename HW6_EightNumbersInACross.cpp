/*
Name: Denny Feng
Date: October 8, 2019
Task: 8 Numbers in a Cross
Description: Write a program which allocates the integers 1-8 to the squares in the figure above, subject to the restrictions that no two adjacent squares contain consecutive integers. By adjacent we mean vertically, horizontally, or diagonally.
*/

#include <iostream>
#include <cmath>
using namespace std;
 
bool ok(int q[], int c) { //c = current number
   // c is the box index, q[c] is the number to fill in the box
   //checkList[c][i];
   static int checkList[8][5] = {
      // write this together...
      {-1}, // box 0's checklist
      {0, -1}, // box 1's checklist
      {1, -1}, //box 2 check checkList
      {0, 1, 2, -1}, //box 3 checklist
      {1, 2, 3, -1}, //box 4 checklist
      {2, 4, -1}, //box 5 checklist
      {0, 3, 4, -1}, //box 6 checkList
      {3, 4, 5, 6, -1}, //box 7 checkList
   };
 
   // Test 1: Similar to row test in 8 Queens
   // If the number you are writing in box c has already been written to previous boxes
   for(int i = 0; i < c; i++) {
     //if(...) return false;
     if(q[c] == q[i])
      return false;
   }
 
   // Test 2: 
   // If the number you are writing in box c (q[c]) differs by 1 
   // from any of the numbers in box c's checklist before -1 
	for(int i = 0; checkList[c][i] != -1; i++) {
      // abs(q[c] - q[checkList[c][i]) == 1
      if(abs(q[c] - q[checkList[c][i]]) == 1)
			return false;
  }
	return true;
  }
 
void print(int q[]) {
   static int solution = 1;
   cout << "solution " << solution++ <<endl;
   cout << " " << " " << q[1] << q[2] << endl;
   cout << " " << q[0] << q[3] << q[4] << q[5] << endl;
   cout << " " << " " << q[6] << q[7] << endl;
   cout << "----------------" << endl;
}
 
int main() {
 
   // initialize…
	int q[8] = {};
  q[0] = 1;
  int c =0; 
   while (c >= 0) { // BOX PART:
      // Move to the next box
      c++;
      // If you have passed the last index, you found a solution
      // call the print function and backtrack

    if(c > 7){
      print(q);
      c--;
    }
      
      // Otherwise, reset number to 0, so you will start from number 1 in the inner loop
      else q[c] = 0; 
      while (c >= 0) { // NUMBER PART:
         // Move to the next number
         q[c]++;
         // If you tried all number answers, backtrack
         if(q[c] == 9)
          c--; 
         // Otherwise, call the ok function.
         else if(ok(q,c) == true)
          break; 
         // If it returns true, go back to the box part.
         // otherwise continue this loop to next number
      }
   }
   
   return 0;
}