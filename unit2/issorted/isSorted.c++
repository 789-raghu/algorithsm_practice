#include<bits/stdc++.h>

using namespace std;

bool isSorted(vector<int>&arr,int n){
    if(arr.size()==n-1){
        return arr[n]<arr[n-1];
    }
    return arr[n]<arr[n-1] || isSorted(arr,n+1);
}

int main(){
    vector<int> array = {1,2,4,3,5,6,7,8};
    cout<<!isSorted(array,1)<<endl;
}