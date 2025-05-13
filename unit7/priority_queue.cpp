#include <bits/stdc++.h>

using namespace std;

class Priority_queue {
    vector<int> pq;
    int count, capacity, heap_type;

  public:
    int get_parent(int node) {
        if (node <= 0 || this->capacity <= node) {
            return -1;
        }
        return (node - 1) / 2;
    }

    int leftChild(int node) {
        if (2 * node + 1 >= this->capacity) {
            return -1;
        }
        return 2 * node + 1;
    }

    int rightChild(int node) {
        if (2 * (node + 1) >= this->capacity) {
            return -1;
        }
        return 2 * (node + 1);
    }

    void Prelocatedown(int i){
        if(i==-1) return;

        int right,left,max = i;
        right = rightChild(i);
        left = leftChild(i);
        if(left!=-1 && pq[left]>pq[i]){
            max = left;
        }
        if(right!=-1 && pq[right]>pq[max]){
            max = right;
        }
        if(max!=i &&  max!=-1){
            swap(pq[max],pq[i]);
            Prelocatedown(max);
        }
    }

    void arbitrary(int index){
        if(index>=capacity){
            return;
        }
        swap(pq[index],pq[--capacity]);
        pq.pop_back();
        Prelocatedown(index);
    }

    void heapify(vector<int> elements){
        int n = elements.size();
        for(int i = 0;i<n;i++){
            pq.emplace_back(elements[i]);
        }
        capacity = elements.size();

        for(int i= (n-1)/2;i>=0;i--){
            Prelocatedown(i);
        }
    }

    void insertion(int i){
        pq.emplace_back(i);
        int parent = capacity++;
        while(parent!=-1){
            Prelocatedown(parent);
            parent = get_parent(parent);
        }
    }

    int delete_top() {
        if (capacity == 0) {
            return -1;
        }
        int maximum = pq[0];
        swap(pq[0], pq[capacity - 1]);
        pq.pop_back();
        capacity--;
        Prelocatedown(0);
        return maximum;
    }

    int get_maximum() {
        if (this->capacity == -1) {
            return INT_MIN;
        }
        return pq[0];
    }

    Priority_queue(int heap_type) {
        this->capacity = 0;
        this->heap_type = heap_type;
    }
};