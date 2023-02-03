#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    
int chessBoard[8];
int col = 0;
int counter = 1;

//put the queen at (0,0)
chessBoard[0] = 0;

nxtCol:
col++;
if(col == 8) goto printBoard;
chessBoard[col] = -1; //row = -1

nxtRow:
chessBoard[col]++; //row++
if(chessBoard[col] == 8) goto backtrack;

//test
for(int i=0; i < col; i++)
  if(chessBoard[col] == chessBoard[i] || abs(chessBoard[col] - chessBoard[i]) == (col - i)) goto nxtRow;

goto nxtCol;

backtrack: col--;
if(col == -1) return 0;

goto nxtRow;

printBoard:
cout << "Solution " << counter << endl;
counter++;
for(int i=0; i<8; i++){
    cout << chessBoard[i] << "  ";
}
cout << endl << endl;


goto backtrack;
}



