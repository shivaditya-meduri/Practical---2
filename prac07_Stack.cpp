#include<iostream>
#include <bits/stdc++.h>
#include<exception>
using namespace std;
class EmptyStackException: public exception
{
  virtual const char* what() const throw()
  {
    return "EmptyStackException: Stack is empty.";
  }
} ESE;
class FullStackException: public exception{
    virtual const char* what() const throw()
    {
        return "FullStackException: Stack is full. No new elements can be added";
    }
}FSE;
template <typename T>
class Stack{
    T *st;
    int size;
    int top=-1;
    public:
        Stack(){
            st = new T(20);
            size=20;
        }
        Stack(int l){
            st = new T(l);
            size = l;
        }
        void push(T t){
            if(top+1<size){
                top = top+1;
                st[top] = t;
            }
            else{
                throw FSE;
            }
            return;
        }
        void pop(){
            if(top==-1){
                throw ESE;
            }
            else{
                cout<<"The popped element is :"<<st[top]<<endl;
                top=top-1;
            }
        }
        T Top(){
            if(top==-1){
                throw ESE;
                    }  
            cout<<"The top of the stack is :"<<st[top]<<endl;          
            return st[top];
        }
        bool isEmpty(){
            if(top ==-1){
                return true;
            }
            return false;
        }
        void print(){
            if(top==-1){
            cout<<"The stack is empty."<<endl;
            }
            else{
            cout<<"The elements of the stack are :"<<endl;
            cout<<"[ ";
            for(int i=top;i>=0;i--){
                cout<<st[i]<<" ";
            }
            cout<<"]";
            cout<<endl;
            }
        }
};
int main(){
    Stack<float> a(10);
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.print();
    a.pop();
    a.print();
    Stack<char> b(10);
    b.print();
    b.push('a');
    b.push('b');
    b.push('c');
    cout<<b.Top()<<endl;
    b.pop();
    cout<<b.Top()<<endl;
    b.print();
    Stack<int> c;
    c.push(10);
    c.push(4);
    c.push(11);
    Stack<int> d(2);
    try{
    d.Top();
    } catch(exception& e){
        cout<<e.what()<<endl;
    }
    try{
    d.push(1);
    d.push(2);
    d.push(3);
    } catch(exception& e){
        cout<<e.what()<<endl;
    }
    d.pop();
    d.Top();
    return 0;
}
