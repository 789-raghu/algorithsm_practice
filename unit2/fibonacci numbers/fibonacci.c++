#include <bits/stdc++.h>
using namespace std;

int fibonacciSequence(int n){
    if(n<=1){
        return n;
    }
    return fibonacciSequence(n-1)+fibonacciSequence(n-2);
}

int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    if(n<=0){
        cout<<"Invalid sequence";
        return 0;
    }
    cout<<n<<"th fibonacci number : "<<fibonacciSequence(n);
    return 0;
}