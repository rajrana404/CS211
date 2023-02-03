#include <iostream>
#include <cmath>
using namespace std;

bool checker(int q[], int c);
void printBoard(int q[]);

int main() {
   int chessBoard[8] = {}, col = 0;
   while (col >= 0) { 

      if (col == 7) { 
         printBoard(chessBoard);
         col--;
      }
      
      else{
        col++;
        chessBoard[col] = -1;
      }
      while (col >= 0) {
         chessBoard[col]++;            
         if (chessBoard[col] == 8)     
            col--;
         else if (checker(chessBoard, col)) 
            break;
      }
  
   }
   return 0;
}


bool checker(int q[], int c) {
   for (int i = 0; i < c; i++){
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i){
         return false;
      }
   }
    return true;
}

void printBoard(int q[]) {
  static int count = 1;
   cout << "Solution " << count << ": ";
   for (int i = 0; i < 8; i++)
      cout << q[i];
   cout << "\n";
   count++;
}