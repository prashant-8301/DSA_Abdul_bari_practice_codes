

#include <iostream>
using namespace std;

class Array{
    private :
    int *A;
    int size;
    int length;
//
    public:
    Array(int sz){
        size = sz;
        A = new int[size];
    }
    void create(){
        cout<<"Enter the total number of the element present in your array"<<endl;
        cin>>length;
        cout<<"Enter the element of your array "<<endl;
        for(int i = 0;i<length;i++){
            cout<<"Enter the element "<<i<<": "<<endl;
            cin>>A[i];
        }
    }
    void display(){
        for(int i = 0;i<length;i++){
            cout<<A[i] <<" "<<endl;
        }
        cout<<endl;
    }
    ~ Array(){
        delete[]A;
        cout<<"Array is destroyed"<<endl;
    }

};

int main(){
    Array arr1(10);
    arr1.create();
    arr1.display();

    return 0;
}



// #include <iostream>
// using namespace std;
 
// class Array{
// private:
//     int *A;
//     int size;
//     int length;
// public:
//     Array (int size);
//     void create();
//     void display();
//     ~Array();
// };
// Array::Array(int sz){
//     size = sz;
//     A = new int [sz];
// }
// void Array::create(){
//     cout<<"Enter number of elements: ";
//     cin>>length;
//     cout<<"Enter array elements"<<endl;
//     for(int i{0}; i<length; i++){
//         cout<<" enter element at "<<i<<":"<<endl;
//         cin>>A[i];
//     }
// }
// void Array::display(){
//     for(int i{0}; i<length; i++){
//         cout<<A[i]<<" ";
//     }
//     cout<<endl;
// }
// Array::~Array(){
//     delete [] A;
// }
// int main(){
//     Array arr(10);
//     arr.create();
//     arr.display();
//     return 0;
// }


// #include <iostream>
// using namespace std;
 
// class Array{
 
// private:
//     int* A;
//     int size;
//     int length;
 
// public:
//     Array(int size){
//         this->size = size;
//         A = new int [size];
//     }
 
//     void create(){
//         cout << "Enter number of elements: " << flush;
//         cin >> length;
//         cout << "Enter the array elements: " << endl;
//         for (int i = 0; i < length; i++){
//             cout << "Array element: " << i << " = " << flush;
//             cin >> A[i];
//         }
//     }
 
//     void display(){
//         for (int i = 0; i < length; i++){
//             cout << A[i] << " ";
//         }
//     }
 
//     ~Array(){
//         delete[] A;
//         cout << "Array destroyed" << endl;
//     }
// };

// int main() {
 
 
//     Array arr(10);
//     arr.create();
//     arr.display();
 
 
//     return 0;
// }
