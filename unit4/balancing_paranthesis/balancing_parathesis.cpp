#include<bits/stdc++.h>

using namespace std;

template <typename T>
class Stack{
    vector<int> stack;
    int top;

    public:
    void push(T data){
        stack.push_back(data);
        top++;
    }

    T pop(){
        if(isempty()){
            cout<<"Their are no elements in the stack"<<endl;
            return -1;
        }
        T data = stack[top];
        top--;
        stack.pop_back();
        return data;
    }

    T peek(){
        if(isempty()){
            return ' ';
        }
        return stack[top];
    }

    bool isempty(){
        return top==-1;
    }

    Stack(){
        top = -1;
    }
};


int main(){
    string str;
    Stack<char> stack;
    cout<<"Enter the expression:";
    cin>>str;
    unordered_map<char,char>mapping;

    mapping[')'] = '(';
    mapping['}'] = '{';
    mapping[']'] = '[';

    for(auto i:str){
        if(i=='('||i=='{'||i=='['){
            stack.push(i);
        }
        else{
            if(stack.peek()==mapping[i]){
                stack.pop();
            }
            else{
                cout<<"Not a valid expression"<<endl;
                return 0;
            }
        }
    }
    if(stack.isempty()){
        cout<<"Not a valid expression"<<endl;
        return 0;
    }
    cout<<"Valid expression"<<endl;
    return 0;
}