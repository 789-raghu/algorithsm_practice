#include <bits/stdc++.h>

using namespace std;

class Node {
    int data;
    Node *next;
  public:
    Node(int data = 0, Node *next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

class Graph {
    int V, E;
    vector<Node *> Adjlist;
    public:
      Graph(int V,int E){
          this->V = V;
          this->E = E;
          Adjlist = vector<Node*>(V,nullptr);
      }
};