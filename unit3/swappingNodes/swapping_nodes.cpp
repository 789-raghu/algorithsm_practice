#include<bits/stdc++.h>

using namespace std;

template <typename T>
class Node{
    public:
        T data;
        Node<T>* link;

        Node(T data){
            this->data = data;
            link = nullptr;
        }
};

template <typename T>
class LinkedList{
    public:
        Node<T>* head;

        bool has_kth_element(Node<T>* node,int k){
            while(node){
                k--;
                node = node->link;
                if(k==0){
                    return node;
                }
            }
            return nullptr;
        }

        void swapping_k_nodes(int k){
            Node<T>* temp = head;
            Node<T>* kth_node = has_kth_element(temp,k);
            while(kth_node){
                Node<T>* next = kth_node->link;
                kth_node = reversal_of_list();
            }
        }

        Node<T>* reversal_of_list(){

        }

        LinkedList(T data){
            head = new Node<T>(data);
        }
};

int main(){

}