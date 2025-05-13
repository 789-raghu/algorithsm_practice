#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* link;

    Node(T data) {
        this->data = data;
        this->link = nullptr;
    }
};

template <typename T>
class LinkedList {
public:
    Node<T>* head;
    unordered_map<int, Node<T>*>* tracking;
    int size;

    LinkedList(T data) {
        head = new Node<T>(data);
        this->tracking = new unordered_map<int, Node<T>*>;
        (*tracking)[0] = head;
        size = 1;
    }

    void insertionofNode(T data) {
        Node<T>* node = new Node<T>(data);
        node->link = head;
        head = node;
        (*tracking)[size] = head;
        size++;
    }

    void insertionOfCycle() {
        if (!head) {
            return;
        }
        Node<T>* temp = head;
        while (temp->link) {
            temp = temp->link;
        }
        temp->link = (*tracking)[rand() % size];
    }

    Node<T>* FloydCycleDetection() {
        Node<T>* tortoise = head, *rabbit = head;
        while (rabbit && rabbit->link) {
            tortoise = tortoise->link;
            rabbit = rabbit->link->link;
            if (rabbit == tortoise) {
                return rabbit;
            }
        }
        return nullptr;
    }

    Node<T>* beginingOfTheLoop() {
        Node<T>* node = FloydCycleDetection();
        if (node == nullptr) {
            cout << "Loop doesnot Exist" << endl;
            return nullptr;
        }
        Node<T>* slow = head, *fast = node;
        while (slow != fast) {
            cout << fast->data << " -> ";
            slow = slow->link;
            fast = fast->link;
        }
        return fast;
    }
};

int main() {
    srand(time(0));
    LinkedList<int> list(10);
    list.insertionofNode(20);
    list.insertionofNode(30);
    list.insertionofNode(40);
    list.insertionofNode(50);
    list.insertionOfCycle();

    Node<int>* loopStart = list.beginingOfTheLoop();
    if (loopStart) {
        cout << "Cycle starts at node with data: " << loopStart->data << endl;
    }

    return 0;
}
