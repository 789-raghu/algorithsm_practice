#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Node{
    T data;
    Node<T>* prev,*next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template<typename T>
class DoublyLinkedList{
    Node<T>* root;  
    
    Node<T>* insertionAtBegining(int data){
        if(root==nullptr){
            root = new Node(data);
        }
        else{
            Node<T>* node = new Node<T>(data);
            node->next = root;
            root->prev = node;
            root = node;
        }
        return root;
    }

    Node<T>* inserionAtEnd(int data){
        if(root==nullptr){
            root = new Node(data);
        }
        else{
            Node<T>* node = new Node<T>(data);
            Node<T>* temp = root;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = node;
            node->prev = temp;
        }
        return root;
    }

    Node<T>* insertionAtPosition(int data,int position){
        if(position==1){
            return insertionAtBegining(data);
        }
        Node<T>* temp = root;
        while(temp->next && position>2){
            position--;
            temp = temp->next;
        }
        Node<T>* node = new Node<T>(data);
        if(temp->next==nullptr){
            node->prev = temp;
            temp->next = node;
        }
        else{
            node->prev = temp;
            node->next = temp->next;
            temp->next->prev = node;
            temp->next = node;
        }
        return root;
    }

    Node<T>* deletionAtBegining(){

    }

    Node<T>* deletionAtEnding(){

    }

    Node<T>* deletionAtPosition(){

    }

    public:
        DoublyLinkedList(Node* head){
            this->root = head;
        }
};