/*
Name: Denny Feng
Date: November 18, 2019
Task: Stable Marriage - Using Recursion
Description: The goal of this project to match n men and n women with their preference rankings of each other and give a "stable" set of marriages. This project uses recursion to find its solutions.
*/

#include <iostream>
using namespace std;
bool ok(int q[], int c) {
    static int mp[3][3] = {{ 0,2,1 },   // Man#0's preferences
                           { 0,2,1 },   // Man#1's preferences
                           { 1,2,0 }};  // Man#2's preferences
    
    // wp[woman][man] = the score that woman given to that man
    static int wp[3][3] = {{ 2,1,0 },   // Woman#0's preferences
                           { 0,1,2 },   // Woman#1's preferences
                           { 2,0,1 }};  // Woman#2's preferences

    for(int i = 0; i < c; i++){
    if(q[c] == q[i]) return false; 
  
    if(mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) 
      return false;
    if(wp[q[c]][i] < wp[q[c]][c] && mp[i][q[c]] < mp[i][q[i]])
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

void next(int q[], int i){
    if(i == 3){
        print(q);
        return;
    }
    for(int j = 0; j < 3; j++){
        q[i]=j;
        if(ok(q,i))
        next(q,i+1);
    }
}
int main(){
    int q[3]; 
    q[0]=0;
    next(q,0);
    
}