#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T> *link;
    Node(T data){
        this->data = data;
        this->link = nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T> *head;

public:
    LinkedList(){
        head = nullptr;
    }

    void insertAtBeginning(T data){
        Node<T> *newNode = new Node<T>(data);
        newNode->link = head;
        head = newNode;
    }

    void insertAtEnd(T data){
        Node<T> *newNode = new Node<T>(data);
        if (!head){
            head = newNode;
            return;
        }
        Node<T> *temp = head;
        while (temp->link){
            temp = temp->link;
        }
        temp->link = newNode;
    }

    void insertAtPosition(T data, int position){
        if (position == 1){
            insertAtBeginning(data);
            return;
        }
        Node<T> *newNode = new Node<T>(data);
        Node<T> *temp = head;
        for (int i = 1; temp != nullptr && i < position - 1; i++){
            temp = temp->link;
        }
        if (temp == nullptr){
            cout << "Position out of bounds\n";
            return;
        }
        newNode->link = temp->link;
        temp->link = newNode;
    }

    void deleteAtBeginning(){
        if (!head){
            cout << "List is empty\n";
            return;
        }
        Node<T> *temp = head;
        head = head->link;
        delete temp;
    }

    void deleteAtEnd(){
        if (!head){
            cout << "List is empty\n";
            return;
        }
        if (!head->link){
            delete head;
            head = nullptr;
            return;
        }
        Node<T> *temp = head;
        while (temp->link->link){
            temp = temp->link;
        }
        delete temp->link;
        temp->link = nullptr;
    }

    void deleteAtPosition(int position){
        if (!head){
            cout << "List is empty\n";
            return;
        }
        if (position == 1){
            deleteAtBeginning();
            return;
        }
        Node<T> *temp = head;
        for (int i = 1; temp != nullptr && i < position - 1; i++){
            temp = temp->link;
        }
        if (!temp || !temp->link){
            cout << "Position out of bounds\n";
            return;
        }
        Node<T> *nodeToDelete = temp->link;
        temp->link = temp->link->link;
        delete nodeToDelete;
    }

    void traversal(){
        Node<T> *temp = head;
        while (temp){
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << "\n";
    }
};

int main(){
    LinkedList<int> ll;
    ll.insertAtBeginning(10);
    ll.insertAtBeginning(20);
    ll.insertAtEnd(5);
    ll.insertAtPosition(15, 2);
    ll.traversal();

    ll.deleteAtBeginning();
    ll.traversal(); 

    ll.deleteAtEnd();
    ll.traversal();

    ll.deleteAtPosition(2);
    ll.traversal();

    return 0;
}
