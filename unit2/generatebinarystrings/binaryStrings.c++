#include<vector>
#include<string>
#include<iostream>
using namespace std;

void n_bit_string(int n,string current){
    if(n==0){
        cout<<current<<endl;
        return;
    }
    n_bit_string(n-1,current+"0");
    n_bit_string(n-1,current+"1");
}

int main(){
    int n;
    cout<<"Enter the length of the string to be generated : ";
    cin>>n;
    string s = "";
    n_bit_string(n,s);
}