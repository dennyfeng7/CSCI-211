/*
Name: Denny Feng
Date: September 23, 2019
Task: 8 Queens 1D Array without Goto Feature
Description: Using a 1-dimensional array create the Eight Queens program. The eight queens problem is the problem of placing eight queens on an 8×8 chessboard such that none of them attack one another (no two are in the same row, column, or diagonal). For this version, use a 1D array without the goto feature. 
*/

#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the queen in column c is ok
bool ok(int q[], int c) {
   //for each i from 0 to c-1
      //if (there is a conflict between the queens in //columns i and c)
      for (int i = 0; i < c; i++)
        if(q[c] == q[i] || (c - i) == abs(q[c] - q[i]))
        return false;
   return true;
}

void print(int q[]) {
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ": ";
   // Print the array 
   for(int i = 0; i < 8; i++)
    cout << q[i]; 
   // 1st print this: 04752613
   /*then print this: 
      1 0 0 0 0 0 0 0
      0 0 0 0 0 0 1 0
      0 0 0 0 1 0 0 0
      0 0 0 0 0 0 0 1
      0 1 0 0 0 0 0 0
      0 0 0 1 0 0 0 0
      0 0 0 0 0 1 0 0
      0 0 1 0 0 0 0 0
   */

   cout << endl; 
   
   for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
          if(i == q[j]) cout << "1";
            else
          cout << "0";
        }
        cout << endl; 
      }
  cout << endl; 
}

// in 1D version, index is the column number, 
// value (q[index]) is the row number where a queen is placed
int main() {
   // int c to 0 <- index and column number
   int q[8] = {};   // Initialize the array to 0.
   // Start in the 1st row, 1st column
   int c = 0; 
   while (c >= 0) { // End the loop if you backtrack from the first column
      // Move to the next column
      c++;
      // If you have passed the last column,
      if(c > 7){
         // Call the print function and backtrack
         print(q); 
         c--;
   }
      // Otherwise, move to one before the first row
	else q[c] = -1;
      while (c >= 0) { // NR
		q[c]++; // q[c] = q[c] +1;
         // Move to the next row
         // If you have passed the end of the column, backtrack
         if(q[c] == 8)
         c--; 
         // Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
         else if(ok(q,c) == true) break; 
      }
   }
   return 0;
}
