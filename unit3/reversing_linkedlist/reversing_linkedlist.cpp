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

        void insertion_at_begining(T data){
            Node<T>* node = new Node<T>(data);
            node->link = head;
            head = node;
        }

        void display_linkedlist(){
            Node<T>* node = head;
            while(node){
                cout<<node->data<<" ";
                node = node->link;
            }
            cout<<endl;
        }

        void merge_sorted_linkedlist(Node<T>* head1,Node<T>* head2){
            Node<T>* dummy = new Node<T>(-1);
            Node<T>* tail = dummy;
            Node<T>* temp1 = head1,*temp2 = head2;
            while(temp1 && temp2){
                if(temp1->data<temp2->data){
                    tail->link = temp1;
                    temp1 = temp1->link;
                }
                else{
                    tail->link = temp2;
                    temp2 = temp2->link;
                }
                tail = tail->link;
            }

            if(temp1){
                tail->link = temp1;
            }
            else{
                tail->link = temp2;
            }
            dummy = dummy->link;
        }

        void reversal_without_recursion(){
            Node<T>*prev = nullptr,*curr = head,*next = nullptr;
            while(curr){
                next = curr->link;
                curr->link = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }

        void display_reversal(Node<T>* node){
            if(node->link){
                display_reversal(node->link);
            }
            cout<<node->data<<" ";
        }

        LinkedList(T data){
            head = new Node<T>(data);
        }
};

int main(){
    LinkedList<int>linked_list(10);
    linked_list.insertion_at_begining(20);
    linked_list.insertion_at_begining(30);
    linked_list.insertion_at_begining(40);
    linked_list.insertion_at_begining(50);
    linked_list.display_linkedlist();
    Node<int>* node = linked_list.head;
    linked_list.display_reversal(node);
    return 0;
}
