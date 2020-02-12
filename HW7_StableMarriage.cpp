/*
Name: Denny Feng
Date: October 19, 2019
Task: Stable Marriage
Description: The goal of this project to match n men and n women with their preference rankings of each other and give a "stable" set of marriages. This project uses backtracking to find its solutions. A matching is stable if there are no “instabilities.” Say the match assigns m1 to w1 and m2 to w2. An instability is the situation where there is a mutual greater preference for the other person’s partner than for one’s own. For example m1 would prefer w2 to w1 and likewise w2 prefers m1 to m2.
*/

#include <iostream>
using namespace std;
 
bool ok(int q[], int c) {
    // c and q[c] are the current man and woman to be matched
    // i and q[i] are the man and woman already married
 
    // the smaller number means more preferable.
    // mp[man][woman] = the score that man given to that woman
    static int mp[3][3] = {{ 0,2,1 },   // Man#0's preferences
                           { 0,2,1 },   // Man#1's preferences
                           { 1,2,0 }};  // Man#2's preferences
    
    // wp[woman][man] = the score that woman given to that man
    static int wp[3][3] = {{ 2,1,0 },   // Woman#0's preferences
                           { 0,1,2 },   // Woman#1's preferences
                           { 2,0,1 }};  // Woman#2's preferences
 
// Test #1: Similar to row test in 8 queens 
    // Check if the current woman has already been married to other men.
    for(int i = 0; i < c; i++){
      if(q[c] == q[i]) return false; 
 
// Test #2:
//Note: Current man = c; Other man = i
      //Current woman = q[c]; Other woman = q[i]; 
    // Part A: Current man and other women
    // Check if the current man (c) likes any other woman (q[i]) more than current woman (q[c]).
    // mp[ c ][ q[i] ] < mp[ c ][ q[c] ] 
    // (Use <, since smaller number preferred)
    // At the same time, check if other women likes the current man more than their own husband.
    // wp[ q[i] ][ c ] < wp[ q[i] ][ i ]
    // If both occurs - that's an unstable marriage.  
    if(mp[c][q[i]] < mp[c][q[c]] && wp[q[c]][i] < wp[q[c]][c]) 
      return false;
   
    // Part B: Current woman and other men
    // Check if other men (i) like the current woman (q[c]) more than their own wifes (q[i]).
    // mp[ i ][ q[c] ] < mp[ i ][ q[i] ]   
    // At the same time, check if woman c likes any other man more than the current man.
    // wp[ q[c] ][ i ] < wp[ q[c] ][ c ]
    // If both occurs - that's an unstable marriage.
    if(mp[i][q[c]] < mp[i][q[i]] && wp[q[i]][c] < wp[q[i]][i]) 
      return false; 
    }
    return true; 
}
 
void print(int q[]) {
    static int solution = 0;
    cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
    for (int i = 0; i < 3; ++i)
        cout << i << "\t" << q[i] << "\n";
    cout << "\n";
}
 
int main() {
    // c indicates the new man and
    // q[c] is the new woman to be matched.
    int q[3] = {}; 
 
    // initialize...
    q[0] = 0;  // Starting with matching woman 0 to man 0
 
    // Use your code similar to 8 Queens, except the condition to find a solution...
    int c = 0; 
    while (c >= 0){
      c++; 

      if(c > 2){ 
      print(q); 

      c--;
    }
    
    else q[c] = -1; 

    while(c >= 0){
      q[c]++;

      if(q[c] == 3)
      c--;

      else if(ok(q,c) == true) break; 

      }
    }

    return 0;
}