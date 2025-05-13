#include<bits/stdc++.h>

using namespace std;

template <typename T>
class Node{
    public:
        T data,
        Node<T>* next;

        Node(T data){
            this->data = data;
            next = nullptr;
        }
};

template <typename T>
class Stack{
    public:
        Node<T>* head;
        int size,top = -1;

        bool isEmpty(){
            if(top==-1){
                return true;
            }
            return false;
        }

        bool isFull(){
            if(size==top){
                return true;
            }
            return false;
        }

        void Push(T data){
            if(isFull()){
                cout<<"Stack is Full"<<endl;
            }
            Node<T>* node = new Node<T>(data);

            if(head==nullptr){
             head = node;   
            }
            else{
                node->next = head;
                head = node;
            }
        }

        T Pop(){
            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
                return nullptr;
            }
            Node<T>* temp = head;
            head = head->next;
            return temp;
        }

        Stack(T data,int size){
            this->head = new Node<T>(data);
            this->size = size;
        }

};

int main(){

}