#include <iostream>
#include <cmath>
using namespace std;

int nQueens(int n); // returns the solutions
bool checker(int q[], int c); // checks the nQueen combination

int main(){

  int input;
  cout<< "Enter a number for nQueens: ";
  cin >> input;

  for(int i = 1; i <= input; i++){
    cout << "There are " << nQueens(i) << " solutions to the " << i << " queens problem."<< endl;
  }

}

int nQueens(int n){

  int* arrQ = new int[n];
  int col = 0;
  int solution = 0;
  
  while(col >= 0){

    if(col == (n-1)){
      solution++;
      col--;
    }

    else{
      col++;
      arrQ[col] = -1;
    }

   while(col >= 0){
     arrQ[col]++;
      if(arrQ[col] == n)  col--;

      else if(checker(arrQ,col))
        break;
    }
  }

  delete [] arrQ; //delete the array from  heap
  return solution;
}


bool checker(int q[], int c){
  for(int i = 0; i < c; i++)
    if(q[c]==q[i] || abs(q[c]-q[i]) == c-i )
      return false;

  return true;
}
