/*
Name: Denny Feng
Date: September 13, 2019
Task: Finding the Perfect Square
Description: Write a function "string add(string a, string b)" where a and b are strings representing integers and the function add(a,b) returns a string representing their sum. Strings a and b can have a maximum of 100 characters. Write a main program that loops asking the user for the two numbers a and b. The program should terminate if the user enters “done” what asked for “number” a. 
*/

#include <iostream>
using namespace std;

string add(string a, string b){
    if(a.length() < b.length())
        swap(a, b); //big, small 

    int j = a.length() - 1;
    for(int i = b.length() - 1; i >= 0; i--, j--){
        a[j]+=(b[i] - 48);
    }

    for(int i = a.length() - 1; i > 0; i--){
        if(a[i] > 57)
        {
            int d = a[i] - 48;
            a[i-1] = ((a[i - 1] - 48) + d / 10) + 48;
            a[i] = (d % 10) + 48;
        }
    }

    if(a[0] > 57)
    {
        string z;
        z += a[0];
        a[0] = ((a[0] - 48) % 10) + 48;
        z[0] = ((z[0] - 48) / 10) + 48;
        a = z + a;
    }

    return a;
}

int main() { 
  cout << add("9999", "999") << endl; 
  
  cout << add("2345566777844567", "9999988777765768009998") << endl; // 9999991123332545854565
    cout << add("9999988777765768009998", "9999988777765768009998") << endl; // 19999977555531536019996
    cout << add("2345566777844567", "745566777844567") << endl; // 3091133555689134
}

