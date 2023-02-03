#include <iostream>
using namespace std;
 
int main(){ 
int chessBoard[8][8]={0};
int row, col = 0;
int counter = 1;
 
//put the queen at (0,0)
chessBoard[0][0] = 1;
 
nxtCol: col++;
if(col == 8) goto printBoard;
row = -1;
 
nxtRow: row++;
if(row == 8) goto backtrack;
 
//row test
for(int i=0; i<col; i++)
  if(chessBoard[row][i] == 1) goto nxtRow;

// up diagonal test
for(int i=1; (row-i)>=0 && (col-i)>=0; i++)
  if(chessBoard[row-i][col-i] == 1) goto nxtRow;

//down diagonal test
for(int i=1; (row+i)<=8 && (col-i)>=0; i++)
  if(chessBoard[row+i][col-i] == 1) goto nxtRow;

chessBoard[row][col] = 1;
goto nxtCol;

backtrack: col--;
if(col == -1) return 0;
row=0;
while(chessBoard[row][col] != 1)
      row++;
chessBoard[row][col] = 0;
goto nxtRow;

printBoard:
cout << "Solution " << counter << endl;
counter++;
for(int i=0; i<8; i++){
  for(int j=0; j<8; j++){
    cout << chessBoard[i][j] << "  ";    
  }
  cout << endl;
}
cout << endl;

goto backtrack;

}
 



