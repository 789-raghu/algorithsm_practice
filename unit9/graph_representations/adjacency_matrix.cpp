#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Graph{
    int V;
    int E;
    vector<vector<int>>Adj_matrix;

    public:
      void Add_edge(int u,int v){
          Adj_matrix[u][v] = 1;
          Adj_matrix[v][u] = 1;
      }

      void Delete_edge(int u,int v){
          Adj_matrix[u][v] = 0;
          Adj_matrix[v][u] = 0;
      }


      void DFS(int i,vector<int>&visited){
          visited[i] = 1;
          for(int v = 0;v<V;v++){
              if(!visited[v] && Adj_matrix[i][v]){
                  DFS(v,visited);
              }
          }
      }

      void DFS_traversal(){
          vector<int> visited(V,0);

          for(int i = 0;i<V;i++){
              if(!visited[i]){
                  DFS(i,visited);
              }
          }
      }

      void BFS(){
          queue<int> bfs_queue;
          bfs_queue.push(0);
          vector<int> visited(V,0);
          visited[0] = 1;
          while(!bfs_queue.empty()){
              int current = bfs_queue.front();
              bfs_queue.pop();
              for(int i = 0;i<V;i++){
                  if(!visited[i] && Adj_matrix[current][i]){
                      bfs_queue.push(i);
                      visited[i] = 1;
                  }
              }
              cout<<current<<endl;
          }
      }

      Graph(int V,int E){
          this->V = V;
          this->E = E;
          Adj_matrix = vector<vector<int>>(V, vector<int>(V, 0));
      }
};

int main(){

}