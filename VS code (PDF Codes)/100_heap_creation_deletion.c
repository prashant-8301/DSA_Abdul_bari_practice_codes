// This code is not correct ....analyse and write it correctly
#include <stdio.h>
#include <stdlib.h>

void insert(int A[],int n){
    int i = n,temp;
    temp = A[i];
    while(i>1 && temp > A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

void delete(int A[],int n){
    int temp;
A[1] = A[n];
int i = 1;
int j = 2*i;

while(i<n-1){
    if(A[j+1] > A[j]){
        j = j+1;
    }
    if(A[j]>A[i]){
     temp = A[i];
     A[i] = A[j];
     A[j] = temp;
     i = j;
     j = 2*j;
    }
    else{
        break;
    }
}

}

int main(){
    int H[] = {0,14,15,5,20,30,8,40};

    int i;
    for(i = 2;i<=7;i++)
    insert(H,i);

delete(H,8);
// delete(H,7);
for(int i = 1;i<=7;i++)
printf("%d ",H[i]);
printf("\n");
    return 0;
}