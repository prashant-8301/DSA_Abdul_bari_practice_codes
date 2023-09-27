#include <iostream>
using namespace std;

void insert(int arr[], int n){
    
    int j = n;
    while(j>=0 && arr[j] > arr[(j-1)/2]){
        swap(arr[j],arr[(j-1)/2]);
        j = (j-1)/2;
        
    }
}

int main() {
// 	cout<<"GfG!";
	
	int arr[11] = {1,3,5,4,6,13,10,9,8,15,17};
	
// 	arr = {1,3,5,4,6,13,10,9,8,15,17};
	
	for(int i = 1;i<11;i++){
	    insert(arr,i);
	}
	for(int i = 0;i<11;i++){
	    cout<<arr[i]<<endl;
	}
	
	return 0;
}