/*
Name: Denny Feng
Date: September 23, 2019
Task: 8 Queens 1D Array with Goto Feature
Description: Using a 1-dimensional array create the Eight Queens program. The eight queens problem is the problem of placing eight queens on an 8×8 chessboard such that none of them attack one another (no two are in the same row, column, or diagonal). For this version, use a 1D array with the goto feature. 
*/

#include <iostream>
#include <cmath>
using namespace std; 

int main(){
  int q[8], c = 0; 

  q[0] = 0;

  nextCol: c++;
      if (c == 8) goto print; 

      q[c] = -1; 

  nextRow: q[c]++; 
      if(q[c] == 8) goto backtrack;

      //Row Test
      for(int i = 0; i < c; i++){
        if(q[i] == q[c] || (c-i) == abs(q[c] - q[i])) goto nextRow;
      }
      goto nextCol; 

  backtrack: c--;
      if(c == -1) return 0;
      goto nextRow;

print:
      static int solution = 0; 
      //Print the solution counter
      cout << "Solution #" << ++solution << ": "; 
      for(int i = 0; i < 8; i++){
        cout << q[i]; 
      }

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

    //goto backtrack
    goto backtrack; 
   } 