/*
Name: Denny Feng
Date: November 1, 2019
Task: Fancy Eight Queens
Description: The goal of this project is to print a chess board graphic of the solutions to 8 queens problem. This project will be utilize typedef. 
*/

#include <iostream>
#include <cmath>
using namespace std;
 
bool ok(int q[], int c) {
    for (int i = 0; i < c; ++i)
        if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
            return false;
    return true;
}
 
void print(int q[]) {
    static int solution = 0;
    int i, j, k, l;
    typedef string box[5][7];   // box is now a data type: a 5x7 2D array of characters
    static box bb, wb;
    box *board[8][8];
    // board is an 8x8 array of pointers to boxes (each element is a pointer, stores an address).
    
    // Fill in bb (black box) and wb (white box), each represent a square of the chessboard.
    string black = " ";
    string white = "\u2588";
    for (i=0; i<5; i++) {
        for (j=0; j<7; j++) {
            bb[i][j] = black;
            wb[i][j] = white;
        }
    }
 
    // Fill in bq (black queen) and wq (white queen).
    static box bq = { {white, white, white, white, white, white, white},
           {white, black, white, black, white, black, white},
           {white, black, black, black, black, black, white},
           {white, black, black, black, black, black, white},
           {white, white, white, white, white, white, white} };
 
    static box wq = { {black, black, black, black, black, black, black},
           {black, white, black, white, black, white, black},
           {black, white, white, white, white, white, black},
           {black, white, white, white, white, white, black},
           {black, black, black, black, black, black, black} };
 
 
    /************************************************************************
     * Fill board with pointers that stores the address of proper boxes. (Fill out this part.)
     ************************************************************************/
    // fill wb at ((i+j)%2 == 0), e.g. (0, 0), otherwise fill bb
    for(i=0; i<8; i++) {
        for(j=0; j<8; j++) {
            if ((i+j)%2 == 0) { // for wb
                // if there is a queen, fill bq
                if (q[j] == i) 
                  board[i][j] = &bq;
                // otherwsie simply fill wb
                else 
                  board[i][j] = &wb;
            }
            else {  // for bb
                // if there is a queen, fill wq
                if (q[j] == i) 
                  board[i][j] = &wq;
                // otherwise simply fill bb
                else 
                  board[i][j] = &bb;
            }           
        }
    }    
    
    // Start printing to the console:
    cout << "Solution #" << ++solution << ":\t ";
    for(i=0; i<8; i++) cout << q[i] << " ";
    cout << endl;
    
    // Print upper border
    cout << " ";
    for (i=0; i<7*8; i++) cout << '_';
    cout << endl;
    
    // Print the board
    for (i=0; i<8; i++) {           // for each board row
        for (k=0; k<5; k++) {       // for each box row
            cout << char(179);      // left border
            for (j=0; j<8; j++) {   // for each board column
                for (l=0; l<7; l++) // for each box column
                cout << (*board[i][j])[k][l];
                // board[i][j] = Address of wb (or bb, wq, bq)
                // *board[i][j] = Dereference to get that wb.
                // (*board[i][j])[k][l] = wb[k][l] 
            }
            cout << char(179) << "\n";   // right border
        }
    }
 
    // Print lower border
    cout << " ";
    for (i=0; i<7*8; i++) cout << char(196);
    cout << "\n\n";
}
 
int main() {
    int q[8] = {}, c = 0;
    q[0] = 0;
 
    while (c >= 0) {  // NEXT COL:
        c++;                // Move to the next column
        if (c>7) {          // If you have passed the last column, a solution is found
            print (q);      // Call the print function and backtrack
            c--;
        }
        else q[c] = -1;   // set to -1 so in inner loop you can start q[c] from 0
        while (c >= 0) {  // NEXT ROW:
            q[c]++;           // Move to the next row
            if (q[c] > 7) c--;  // If you have passed the end of the row, backtrack
            else              // Otherwise, call the ok function.
                if(ok(q, c)) break; // If ok (returns true), a queen is filled in the row
        }
    } 
    return 0;
}