#include<bits/stdc++.h>

using namespace std;

template <typename T>
class Stack{
    vector<pair<T,T>> stack;
    int top;

    public:
        bool isEmpty(){
            return top==-1;    
        }

        void Push(T data){
            if(top==-1){
                stack.push_back({data,data});
                return;
            }
            stack.push_back({data,min(data,Peek().second)});
        }

        T Pop(){
            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            T data = stack[top];
            stack.pop_back();
            return data;
        }

        T get_min(){
            if(isEmpty()){
                cout<<"Array is empty"<<endl;
                return INT_MIN;
            }
            return Peek().second;
        }

        pair<T,T> Peek(){
            return stack[top];
        }

        Stack(){
            top = -1;
        }
};