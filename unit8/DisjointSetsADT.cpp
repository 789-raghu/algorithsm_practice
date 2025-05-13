#include <bits/stdc++.h>

using namespace std;

class disjoint_sets{
    vector<int>Set;
    public:
      int find(int a) {
          if (Set[a] < 0) {
              return a;
          }
          return Set[a] = find(Set[a]);
      }


      void Union(int a,int b){
          int parent_a = find(a);
          int parent_b = find(b);
          if(parent_b!=parent_a){
              if(Set[parent_a]<Set[parent_b]){
                  int temp = Set[parent_b];
                  Set[parent_b] = parent_a;
                  Set[parent_a] = Set[parent_a]+temp;
              }
              else{
                  int temp = Set[parent_a];
                  Set[parent_a] = parent_b;
                  Set[parent_b] = Set[parent_b]+temp;
              }
          }
      }

      bool forms_cycles(int a, int b) {
          return find(a) == find(b);
      }

      disjoint_sets(int capacity){
          Set.resize(capacity);
          fill(Set.begin(), Set.end(), -1);
      }
};

int main(){

}