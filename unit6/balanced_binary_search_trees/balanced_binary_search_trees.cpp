#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

class Node{
  public:
    int data,height;
    Node* right,*left;

    Node(int data = -1,Node* left = nullptr,Node* right = nullptr){
        this->data = data;
        this->right = right;
        left->left = left;
    }
};

class Balanced_bst{
    public:
      Node* root;

      int Height(Node* root){
          if(!root){
              return -1;
          }
          return root->height;
      }

      int get_height(Node* root){
          if(!root){
              return 0;
          }
          int right = get_height(root->right);
          int left = get_height(root->left);
          return max(left,right)+1;
      }

      Node* rr_rotation(Node* root){
          Node* temp = root->right;
          temp->right = root->left;
          root->left = temp;
          root->height = max(Height(root->left),Height(root->right))+1;
          temp->height = max(Height(temp->left),Height(temp->right))+1;
          return temp;
      }

      Node* ll_rotation(Node* root){
          Node* temp = root->left;
          temp->right = root;
          root->height = max(Height(root->left),Height(root->right))+1;
          temp->height = max(Height(temp->left),Height(temp->right))+1;
          return temp;
      }

      Node* lr_rotation(){
          return nullptr;
      }

      Node* rl_rotation(){
          return nullptr;
      }

      Node* insertion(Node* root,int data){
          if(!root){
              return new Node(data);
          }

          if(data>root->data){
              root->right = insertion(root->right,data);
          }
          else{
              root->left = insertion(root->left,data);
          }
          return root;
      }

      Balanced_bst(int data){
          this->root = new Node(data);
      }
};