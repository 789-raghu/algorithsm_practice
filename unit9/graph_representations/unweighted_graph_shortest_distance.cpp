#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> Adj_list;

  public:
    bool BFS(int target) {
        vector<int> visited(V, 0);
        queue<int> bfs_queue;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                bfs_queue.push(i);
                visited[i] = 1;

                while (!bfs_queue.empty()) {
                    int front = bfs_queue.front();
                    bfs_queue.pop();

                    if (front == target) {
                        return true;
                    }

                    for (int neighbor : Adj_list[front]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = 1;
                            bfs_queue.push(neighbor);
                        }
                    }
                }
            }
        }
        return false;
    }
};

int main() {
}