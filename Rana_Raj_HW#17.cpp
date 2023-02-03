#include <iostream>
#include <cmath>
using namespace std;

int kbishops(int n, int k); // returns the solutions
bool checker(int q[], int c, int n); // checks the kBishop combinations

int main(){
int n, k;
   while (true) {
      cout << "Enter value of n: ";
      cin >> n;
      if (n == -1) break;

      cout << "Enter value of k: ";
      cin >> k;
      cout << "number of solutions: " << kbishops(n, k) << endl << endl;
   }

}

int kbishops(int n, int k){

  int* arrQ = new int[k];
  int col = 0;
  int solution = 0;
  
   while (col >= 0) {
      col++;
      if (col == k) { 
         solution++;
         col--;
      }
      else
         arrQ[col] = arrQ[col-1];
      while (col >= 0) {
         arrQ[col]++;
         if (arrQ[col] == n*n)
            col--;
         else if (checker(arrQ, col, n))
            break;
      }
   }

  delete [] arrQ; //delete the array from  heap
  return solution;
}


bool checker(int q[], int c, int n){
 for (int i = 0; i < c; i++)     
      if ((q[c]/n - q[i]/n) == abs(q[c]%n - q[i]%n))
         return false;

   return true;
}
