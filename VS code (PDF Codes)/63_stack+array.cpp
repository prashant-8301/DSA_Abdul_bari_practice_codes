#include <iostream>
using namespace std;

template<class T> class stack{
    private:
    T *st;
    int size;
    int top;
    public:
    stack(){ size = 10; top = -1; st = new T[size];}
    stack(int size){ this->size = size; top = -1; st = new T[this->size];}
    
    void push( T x); 
    T pop();
    T peek(int index);
    int stacktop();
    int isEmpty();
    int isFull();
    void Display();
};

template<class T>
void stack<T>::push(T x){
    
}

int main(){

    return 0;
}