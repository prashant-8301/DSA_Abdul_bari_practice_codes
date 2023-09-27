#include <iostream>
using namespace std;

int main(){
    int A[3][4] = {{1,2,3,4},{2,4,6,8},{1,3,5,7}};// first way of creating 2D array
    int *B[3]; // second way of creating array
    int **C; // third way of creating array
    
    int i,j;
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    C = new int*[3];
    C[0] = new int[4];
    C[1] = new int [4];
    C[2] = new int [4];

    for(int i = 0;i<3;i++){
        for(j = 0;j<4;j++){
            cout<<"Element: "<<i<<j<<endl;
        cin>>C[i][j];
        }
    }
    for(int i = 0;i<3;i++){
        for(j = 0;j<4;j++){
            cout<<"Element "<<i<<j<<":"<<C[i][j]<<endl;
       
        }
    }
        return 0;
    }

    
