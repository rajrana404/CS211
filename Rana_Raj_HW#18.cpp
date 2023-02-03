#include <iostream>
#include <cmath>
using namespace std;

class Rat{
private:
   int n;
   int d;
   
public:
   // default constructor
   Rat(){
      n=0;
      d=1;
   }
   
   // 2 parameter constructor
   Rat(int i, int j){
      n=i;
      d=j;
   }
   
   // conversion constructor
   Rat(int i){
      n=i;
      d=1;
   }
   
   //accessor functions
   int getN(){ return n;}
   int getD(){ return d;}
   
   //mutuator functions
   void setN(int i){ n=i;}
   void setD(int i){ d=i;}
   
   //arithmetic operators
   Rat operator+(Rat r){
      Rat t;
      t.n = n*r.d + d*r.n;
      t.d = d*r.d;
      t.simplify();
      return t;
   }
   
   Rat operator-(Rat r){
      Rat t;
      t.n = n*r.d - d*r.n;
      t.d = d*r.d;
      t.simplify();
      return t;
   }
   
   Rat operator*(Rat r){
      Rat t;
      t.n = n*r.n;
      t.d = d*r.d;
      t.simplify();
      return t;
   }
   
   Rat operator/(Rat r){
      Rat t;
      t.n = n*r.d;
      t.d = d*r.n;
      t.simplify();
      return t;
   }
   
   // Reduce the fraction to lowest terms
   void simplify(){
      int gcd_ = gcd(n, d);
      n /= gcd_;
      d /= gcd_;
      if (d < 0) { // Make sure the denominator is positive
         d = -d;
         n = -n;
      }
   }
   
   // Calculate the GCD
   int gcd(int a, int b){
      if (b == 0) 
        return a; 
    return gcd(b, a % b);
   }

   friend ostream& operator<<(ostream& os, Rat r);
   friend istream& operator>>(istream& is, Rat& r);
};

ostream& operator<<(ostream& os, Rat r){
   r.simplify();
   if (abs(r.n) >= r.d || r.n == 0)
      os << r.n/r.d << " ";
   if (r.d != 1)
      os << (r.n/r.d <= -1 ? abs(r.n%r.d) : r.n%r.d) << "/" << r.d;
   return os;
}

istream& operator>>(istream& is, Rat& r){
   is >> r.n >> r.d;
   r.simplify();
   return is;
}

int main(){
   Rat a(10, 3), b(4, 8);
   
   cout << "Fraction a: " << a << endl;
   cout << "Fraction b: " << b << endl;
   cout << "a + b: " << a + b << endl;
   cout << "b + 5: " << b + 5 << endl;
   cout << "a - b: " << a - b << endl;
   cout << "a * b: " << a * b << endl;
   cout << "a / b: " << a / b << endl;
   cout << endl;
   
   return 0;
}