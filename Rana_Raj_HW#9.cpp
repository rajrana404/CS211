#include <iostream>
using namespace std;

bool ok(int q[], int c);
void print(int q[]);

int main() {
    int matchPair[3] = {};
    int col = 0;
    while (col >= 0) {
        if (col == 2) {
            print(matchPair);
            col--;
        }
        
        else{
            col++;
            matchPair[col] = -1;
        }
        
        while (col >= 0) {
            matchPair[col]++;
            if (matchPair[col] == 3)
                col--;
            else if (ok(matchPair, col))
                break;
        }
        
    }
    return 0;
}


bool ok(int q[], int c) {
    
    static int mp[3][3] = {
                            {0,2,1},  // Men 0's preferences
                            {0,2,1},  // Men 1's preferences
                            {1,2,0}   // Men 2's preferences
                        };
    
    static int wp[3][3] = {
                            {2,1,0},  // Women 0's preferences
                            {0,1,2},  // Women 1's preferences
                            {2,0,1}   // Women 2's preferences
                        };
    
    
    for (int i = 0; i < c; ++i) {
        if (q[i] == q[c]) return false;    // if man[i] and man[c] are married to the same woman
   else if(mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) return false;  // if man[i] and man[c] wife like each more than their own spouse OR
   else if(mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) return false; // if its other way around
    }
    return true;
}


void print(int q[]) {
    static int count = 1;
    cout << "Solution: " << count++ << ":\nMan\tWoman\n";
    for (int i = 0; i < 3; ++i)
        cout << i << "     " << q[i] << endl;
    cout << endl;
}
