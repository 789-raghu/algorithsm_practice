#include <algorithm>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

class Node{
  public:
    int data;
    Node* next;
      Node(int data = -1,Node* next = nullptr){
          this->data = data;
          this->next = next;
      }
};

class Graph{
    int V,E;
    vector<Node*>Adj_list;
    public:

      void add_edge(pair<int,int>edge){
          Node* dummy = new Node(edge.second);
          dummy->next = Adj_list[edge.first];
          Adj_list[edge.first] = dummy;
      }

      void delete_edge(pair<int, int> edge) {
          Node* temp = Adj_list[edge.first];
          if (temp->data == edge.second) {
              Adj_list[edge.first] = temp->next;
              delete temp;
              return;
          }
          while (temp->next && temp->next->data != edge.second) {
              temp = temp->next;
          }

          if (temp->next) {
              Node* nodeToDelete = temp->next;
              temp->next = temp->next->next;
              delete nodeToDelete;
          }
      }

      void get_indegree(vector<int>& indegree){
          for(int i = 0;i<V;i++){
              Node* dummy = Adj_list[i];
              while(dummy){
                  dummy = dummy->next;
                  if(dummy){
                      indegree[dummy->data]++;
                  }
              }
          }
      }

      void toposort(){
          queue<int> topo_queue;
          int counter = 0;
          vector<int>visited(V,0),indegree(V,0);
          get_indegree(indegree);

          for(int i = 0;i<V;i++){
              if(indegree[i]==0){
                  topo_queue.push((i));
              }
          }

          while(topo_queue.size()){
              int data = topo_queue.front();
              topo_queue.pop();
              visited[data] = ++counter;
              Node* dummy = Adj_list[data];
              while(dummy){
                  indegree[dummy->data]--;
                  if(!indegree[dummy->data]){
                      topo_queue.push(dummy->data);
                  }
                  dummy = dummy->next;
              }
          }
          if(counter!=V){
              cout<<"No valid path found"<<endl;
          }
      }

      Graph(int V,int E){
          this->V = V;
          this->E = E;
          Adj_list = vector<Node*>(V,nullptr);
      }
};

int main(){

}