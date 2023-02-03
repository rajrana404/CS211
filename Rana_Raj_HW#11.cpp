#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

bool checker(int q[],int c);
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



bool checker(int q[],int c){
    for(int i=0;i<c;i++){
        if((q[c]==q[i])||((c-i)==(abs(q[c]-q[i])))){
            return false;
        }
    }
    return true;
}

void printBoard(int q[]){

    static int count=0;
    count++;

    cout<<"Solution #"<<count<<" :"<<endl;

    for(int i=0;i<8;i++){
        cout<<q[i]<<" ";
    }
    cout<<endl;

    // fancy board code
    typedef string box[5][7];
    box bb,wb,*board[8][8];
    static box bq = {
            {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
            {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
            {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
            {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
            {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}
        };

    static box wq = {
            {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
            {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
            {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
            {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
            {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      }
        };

    for (int r=0; r<5; r++)
        for (int c=0; c<7; c++) {
            bb[r][c] = ' ';
            wb[r][c] = char(219);
        }

    for(int r=0; r<8; r++)
        for(int c=0; c<8; c++)
            if((r+c)%2 == 0)
                board[r][c] = &wb;
            else
                board[r][c] = &bb;

    for(int i=0; i<8; i++)
        if((i+q[i])%2 == 0)
            board[q[i]][i] = &bq;
        else
            board[q[i]][i] = &wq;

    // upper border
    for (int i=0; i<7*8; i++)
        cout << '_';
    cout <<endl;

    // Print the board
    for (int i=0; i<8; i++)          // board row
        for (int k=0; k<5; k++) {     // box row
            cout << char(179);
            for (int j=0; j<8; j++)    // board column
                for (int l=0; l<7; l++) // box column
                    cout << (*board[i][j])[k][l];
            cout << char(179) <<endl;
        }

    // lower border
    cout << " ";
    for (int i=0; i<7*8; i++)
        cout << char(196);
    cout <<endl<<endl;

}
