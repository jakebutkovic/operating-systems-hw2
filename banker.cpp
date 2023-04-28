//Jacob Butkovic

#include <iostream>

using namespace std;

const int p = 5;
const int r = 3;

void calcNeed(int need[p][r], int maxm[p][r], int allot[p][r]){
    for(int i = 0; i < p; i++)
        for(int j = 0; j < r; j++)

            need[i][j] = maxm[i][j] - allot[i][j];
        
}

bool isSafe(int processes[], int avail[], int maxm[][r], int allot[][r]){
    
    int need[p][r];

    calcNeed(need, maxm, allot);

    bool finish[p] = {0};

    int safeSeq[p];

    int work[r];
    for(int i = 0; i < r; i++)
        work[i] = avail[i];

    int count = 0;
    while(count < p){
        bool found = false;
        for (int t = 0; t < p; t++){
            if (finish[t] == 0){
                int j;
                for (j = 0; j < r; j++)
                    if (need[t][j] > work[j])
                        break;

                if(j == r){
                    for (int k = 0; k < r; k++)
                        work[k] += allot[t][k];

                    safeSeq[count++] = p;

                    finish[t] = 1;

                    found = true;    
                }
            }
        }
        if (found == false){
            cout << "The system is not in a safe state";
            return false;

        }
    }

    cout << "The system is in a safe state" << endl;
            cout << " sequence is: ";
    for( int i = 0; i < p; i++)
        cout << safeSeq[i] << " ";
    
    return true;
}

int main(){

    int processes[] = {0, 1, 2, 3, 4};

    int avail[] = {3, 3, 2};

    int maxm[][r] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 1, 1}, {0, 0, 2}};

    int allot[][r] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};

    isSafe(processes, avail, maxm, allot);

    return 0;

}