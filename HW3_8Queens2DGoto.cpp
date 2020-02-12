/*
Name: Denny Feng
Date: September 16, 2019
Task: 8 Queens 2D Array with Goto Feature
Description: Using a 2-dimensional array create the Eight Queens program. The eight queens problem is the problem of placing eight queens on an 8×8 chessboard such that none of them attack one another (no two are in the same row, column, or diagonal). For this version, use a 2D array with the goto feature. 
*/

#include <iostream>
using namespace std; 

int main() {
  //8 Queens 2D with Goto - Backtracking Algorithm:


    //Initialize board q[8][8] to 0;
    int q[8][8] = {}; 
    int r, c = 0; 

    //Place the first Queen at q[0][0] (1st row, 1st col)
    q[0][0] = 1; 

nextCol: 
    //Move to the next column
    c++; 

    //If passed the last column, ie find a solution, goto print
    if(c > 7) goto print; 

    //(Otherwise,) reset row to -1 (before the first row)
    r = -1; 


nextRow:
    //Move to the next row
    r++; 

    //If passed the end of the row, ie cannot place a queen on that column, goto backtrack
    if(r > 7) goto backtrack; 

    //If there is a queen in the same row, goto nextRow
    for(int i = 0; i < c; i++){
      if(q[r][i] == 1) goto nextRow; 
    }

    //If there is a queen in the same upper-left diagonal, goto nextRow
    for(int i = 1; (r - i >= 0) && (c - i >= 0); i++){
      if(q[r-i][c-i] == 1) goto nextRow; 
    }

    //If there is a queen in the same lower-left diagonal, goto nextRow
    for(int i = 1; (r + i <= 7) && (c - i >= 0); i++){
      if(q[r+i][c-i] == 1) goto nextRow; 
    }

    //Place a queen in the current q[row][col]
    q[r][c] = 1; 

    goto nextCol;

backtrack:
    //Move to the previous column
    c--;

    //If column is -1, (out of board, no more solution can be found), exit the program
    if(c < 0) return 0; 

    //Locate the position (row number) of the queen in that column
    for (r = 0; r < 8; r++){
      if (q[r][c] == 1) break;
    }
    
    //Remove the queen
    q[r][c] = 0; 

    goto nextRow;

print:
    static int solution = 0; 
    //Print the solution counter
    cout << "Solution #" << ++solution << endl; 

    //Write a nested loop to print the solution
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        cout << q[i][j];  
      }
      cout << endl; 
    }

    //goto backtrack
    goto backtrack; 

}