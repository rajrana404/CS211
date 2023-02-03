#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c);

int main() {

int crossEight[8]={0};
int col = 0, counter = 0;
	crossEight[col]=1;

	nxtCol:
		col++;
		if(col==8)goto print;
		crossEight[col]=0;

	nxtNum:	
		crossEight[col]++;
		if(crossEight[col] > 8) goto backtrack;

  //test
	if(ok(crossEight,col)) goto nxtCol;
    goto nxtNum;

  backtrack:
		col--;
		if(col==-1)return 0;
		goto nxtNum;

	print:
		counter++;
		cout<<"solution: "<< counter <<endl;
		cout<< "   " <<                 crossEight[1] << "  " << crossEight[4] << "   " << endl;
		cout<< crossEight[0] << "  " << crossEight[2] << "  " << crossEight[5] << "  " << crossEight[7] << endl;
		cout<< "   " <<                 crossEight[3] << "  " << crossEight[6] << "   " << endl << endl;

		goto backtrack;
    //There is only one solution. So, no need for backtrack at end. 
    //I just wanted to see it gives me the all the symmetrical solutions
}

bool ok(int q[], int c) {
  /* The following helper array is for 
     8-cross with correspinding index
            1 4
          0 2 5 7
            3 6          
  */
  static int helper[8][5] = { 
                            {-1},         
                            {0, -1},
                            {0, 1, -1},   
                            {0, 2, -1},
                            {1, 2, -1},
                            {1, 2, 3, 4, -1},
                            {2, 3, 5, -1},
                            {4, 5, 6, -1}
                          }; 

   for (int i = 0; i < c; ++i)
      if (q[i] == q[c]) 
        return false;

   for (int i = 0; helper[c][i] != -1; ++i)
      if (abs(q[c] - q[helper[c][i]]) == 1)
         return false;

return true;
}
