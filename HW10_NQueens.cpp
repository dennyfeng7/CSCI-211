/*
Name: Denny Feng
Date: November 11, 2019
Task: N Queens Problem
Description: The goal of this project is to find the solutions to the n number of queens on a nxn board. This project uses dynamic arrays and dynamic memory to accomplish its task. 
*/

#include <iostream>
#include <cmath> 
using namespace std;
 
bool ok(int q[], int c) {
    // you know how to write this
    for (int i = 0; i < c; i++)
      if(q[c] == q[i] || (c - i) == abs(q[c] - q[i]))
        return false;
   return true;
}
 
int nqueens(int n) {
    int solutions = 0; 


    // Dynamically creates an array of size n.
    // Initalize your variables...
    int* q = new int[n];
 
    //The loop goes on until column becomes -1
    int c = 0; 
    q[0]=0;
    while (c >= 0) {
        // write the n queens backtracking algorithm
        // condition to backtrack is based on n
        // simply increment solutions, no need to print
        c++;
        if (c >= n){
          solutions++;
          c--;
        }

        else q[c] = -1;

        while (c >= 0){
          q[c]++;
          if (q[c] >= n)
            c--;

          else if(ok(q,c) == true) break; 
        }
    }
    // Delete the array
    delete[] q;
 
    return solutions; //Returns the number of solutions found.
}
 
int main() {
    int n = 12;
    for (int i = 1; i <= n; ++i)
        cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
 
    return 0;
}

