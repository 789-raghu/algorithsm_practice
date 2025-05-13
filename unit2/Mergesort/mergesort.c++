#include<bits/stdc++.h>
using namespace std;

void merge(int start,int end,vector<int>&arr,int mid){
    int i= start,j = mid+1,k = 0;
    vector<int> temp;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
        k++;
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
        k++;
    }

    while(j<=end){
        temp.push_back(arr[j]);
        j++;
        k++;
    }

    for(auto i:temp){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i = 0;i<k;i++){
        arr[start+i] = temp[i];
    }
}

void mergeSort(int start,int end,vector<int>&arr){
    if(start<end){
        int mid = (start+end)/2;
        mergeSort(start,mid,arr);
        mergeSort(mid+1,end,arr);
        merge(start,end,arr,mid);
    }
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cout<<"arr["<<i<<"] : ";
        cin>>arr[i];
    }
    mergeSort(0,n-1,arr);

    for(int nums:arr){
        cout<<nums<<" ";
    }
    return 0;
}