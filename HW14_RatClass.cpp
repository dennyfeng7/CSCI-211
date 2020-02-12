/*
Name: Denny Feng
Date: December 12, 2019
Task: Rat Class
Description: Create a class called rational class that can perform operations on two rational numbers. 
*/

#include <iostream>
using namespace std;
 
class Rat {
    private:
        int n;
        int d;
 
    public:
        // constructors
 
        // default constructor
        Rat() {
            n = 0;
            d = 1;
        }
 
        // 2 parameter constructor
        Rat(int i, int j) {
            n = i/gcd(i, j);
            d = j/gcd(i, j);
        }
 
        // conversion constructor
        Rat(int i) {
            n = i;
            d = 1;
        }
 
        //accessor functions (usually called get() and set(...) )
        int getN() { 
            return n; 
        }
        
        int getD() { 
            return d; 
        }
 
        void setN(int i){
			      n = i / gcd(i, d);
			      d = d / gcd(i, d);
		    }

		    void setD(int j){
			      int tGCD = gcd(n, j);
			      n = n / tGCD;
			      d = j / tGCD;
			        if(d < 0){
				        d = d * -1;
				        n = n * -1;
			    }
		    }
 
        // Overloading operator+ (redefine the operator '+' for Rat objects)
        Rat operator+ (Rat r){
			    Rat t;
			    t.setN(n * r.d + d * r.n);
			    t.setD(d * r.d);
				  return t;
		    }

		    Rat operator- (Rat r){
			    Rat t;
			    t.setN(n * r.d - d * r.n);
			    t.setD(d * r.d);
				  return t;
		    }
		
		    Rat operator* (Rat r){
			    Rat t;
			    t.setN(n * r.n);
			    t.setD(d * r.d);
				  return t;
		    }
	
		    Rat operator/ (Rat r){
			    Rat t;
			    t.setN(n * r.d);
			    t.setD(d * r.n);
				  return t;
		    }
        
 
        // The GCD (Euclid's algorithm) finds the largest common divisor
        int gcd(int n, int d) {
            return d == 0 ? n : gcd(d, n%d);
        }
        
        
        // Write a function to reduce the Rat to lowest terms.
        // 1. Use the GCD function provided above to find the greatest common divisor
        // 2. divide both n and d by the number found in step 1
        // 3. also double check if denominator is negative, if so, add negative sign to both n and d
        
 
        // 2 overloaded i/o operators
        friend ostream& operator<<(ostream& os, Rat r);
        friend istream& operator>>(istream& is, Rat& r);
}; //end Rat

ostream& operator<< (ostream& os, Rat r){
	if (r.getN() > r.getD()){
		os << r.getN()/r.getD() << " ";
		if (r.getN() % r.getD() != 0){
			 os << r.getN() % r.getD() << "/" << r.getD();
		}
	}	
	else{
		os << r.getN() << "/" << r.getD();
	}
   return os;
}
 
int main() {
    Rat r1(5, 2), r2(3, 2);
 
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;
 
    r1 = r2;
    r2 = r1 * r2;
 
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;
 
    r1 = r2 + r1 * r2 / r1;
    r2 = r2 + r1 * r2 / r1;
 
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
 
    return 0;
}