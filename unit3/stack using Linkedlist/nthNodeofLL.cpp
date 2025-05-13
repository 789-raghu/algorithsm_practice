#include<bits/stdc++.h>

using namespace std;

template <typename T>
class Node{
    T data;
    Node<T>* next;

    Node(T data){
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class LinkedList{
    Node<T>* head;

    Node<T>* nthNodeFromLast(int n){
        int k = 0;
        Node<T>* temp = head,*temp2 = head;
        while(k<n && temp){
            temp = temp->next;
        }
        if(k==n && temp==nullptr){
            return head;
        }
        else if(k==n){
            cout<<"Noo valid index is found"<<endl;
            return nullptr;
        }

        while(temp!=nullptr && temp2!=nullptr){
            temp = temp->next;
            temp2 = temp2->next;
        }
        return temp2;
    }

    LinkedList(T data){
        head = new Node<T>(data);
    }
};