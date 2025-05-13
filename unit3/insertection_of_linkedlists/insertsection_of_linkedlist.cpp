#include<bits/stdc++.h>

using namespace std;

template <typename T>
class Node{
    public:
        T data;
        Node<T>* link;

        Node(T data){
            this->data = data;
            this->link = nullptr;
        }
};

template <typename T>
class LinkedList{
    public:
        Node<T>* head;

        void insertion_at_begining(T data){
            Node<T>* node = new Node<T>(data);
            node->link = head;
            head = node;
        }

        void combining_two_lists(Node<T>* node){
            
        }

        void detection_of_intersection(Node<T>* node){
            Node<T>* temp1 = node,*temp2 = head;
            while(temp1 || temp2){
                if(!temp1){
                    temp1 = head;
                }
                if(!temp2){
                    temp2 = node;
                }
                temp1 = temp1->link;
                temp2 = temp2->link;
                if(temp1==temp2){
                    cout<<"The intersection is at "<<temp1->data<<endl;
                    return;
                }
            }
            cout<<"No intersection is detected"<<endl;
        }

        LinkedList(T data){
            head = new Node<T>(data);
            head->link = nullptr;
        }
};

int main(){
    return 0;
}