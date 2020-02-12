/*
Name: Denny Feng
Date: December 5, 2019
Task: K Bishops
Description: Write a program that inputs two integers n and k, where n>=k. Your program should calculate the number of different ways that k bishops could be placed on an nXn chessboard. 
*/

#include <iostream>
#include <cmath>
using namespace std;
 
bool ok(int q[], int c, int n) {
    for (int i = 0; i < c; i++)
        // if col difference == row difference, bishop c and i are diagonal to each other
        // row # = q[...] % n
        // col # = q[...] / n
        if ((q[c]/n - q[i]/n) == abs(q[c]%n - q[i]%n))
         return false;
   return true;
}
 
int kBishops(int n, int k) {
    // dynamic allocate an array in heap base on k (num of bishops)
    int* q = new int[k];
 
    // place first bishop at first (top-left) box
    q[0] = 0;
 
    int c = 0, solutions = 0;
 
    // Similar Backtracking Algorithm
    while (c >= 0) {    // NEXT BISHOP
        c++; 

        // if all the bishop has been put onto the broad
            // increment solution count
            // backtrack
        if (c == k) {
          solutions++; 
          c--;
        }
        else 
            // start from the position of the previous bishop to avoid duplicate solutions
            q[c] = q[c-1];
 
        while (c >= 0) { 
         // NEXT SQUARE
         q[c]++;

            if (q[c] == n*n) // If all the squares have been tried (passed the bottom-right square) for the bishop
                // backtrack
                c--;

                // check if it's ok to put the bishop on this sqaure...
                else if (ok(q, c, n)) break; 
        }
    }
    
    // free up the memory in heap
    delete [] q;
    return solutions; 
}
 
int main() {
    // Declare n and k.
    int n, k; 
    
    // keep asking user input for n and k.
    // n >= k
    // if user input -1 for n, terminate the loop.
    // otherwise call the kBishop(n, k) function to get the number of solutions.
    while (true) {

      cout << "Enter value of n: ";
      cin >> n;

      if (n == -1)
         break;

      cout << "Enter value of k: ";

      cin >> k;

      cout << "number of solutions: " << kBishops(n, k) << "\n";

    }
  return 0;
}