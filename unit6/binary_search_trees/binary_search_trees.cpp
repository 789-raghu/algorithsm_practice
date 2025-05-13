#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left,*right;

        Node(int data = 0,Node* left = nullptr,Node* right = nullptr){
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

class binary_search_tree{
    public:
        Node* root;

        Node* insertion(int data,Node* root){
            if(root==nullptr){
                return new Node(data);
            }
            if(root->data>data){
                root->left = insertion(data,root->left);
            }
            else{
                root->right = insertion(data,root->right);
            }
            return root;
        }

        int find_min(Node* root){
            if(!root){
                return 0;
            }
            while(root->left){
                root = root->left;
            }
            return root->data;
        }


        Node* deletion(int data,Node* root){
            if(root==nullptr){
                return root;
            }

            if(root->data==data){
                if(!root->right){
                    return root->left;
                }
                else if(!root->left){
                    return root->right;
                }
                Node* temp = root->right;
                if(temp->left==nullptr){
                    temp->left = root->left;
                    return temp;
                }
                while(temp->left->left){
                    temp = temp->left;
                }
                Node* temp1 = temp->left;
                temp->left = temp->left->right;
                temp1->right = root->right;
                temp1->left = root->left;
                return temp1;
            }

            if(root->data>data){
                root->left = deletion(data,root->left);
            }
            else{
                root->right = deletion(data,root->right);
            }
            return root;
        }

        Node* LCA(Node* alpha,Node* beta, Node* root){
            if(!root){
                return nullptr;
            }

            if(alpha->data>root->data && beta->data>root->data){
                return  LCA(alpha,beta,root->right);
            }
            else if(beta->data<root->data&& alpha->data<root->data){
                return LCA(alpha,beta,root->left);
            }
            return root;
        }

        bool is_bst(Node* root, int min_val = INT_MIN, int max_val = INT_MAX) {
            if (!root) return true;

            if (root->data <= min_val || root->data >= max_val)
                return false;

            return is_bst(root->left, min_val, root->data) &&
                   is_bst(root->right, root->data, max_val);
        }

        void kth_smallest_element(int k,int* count,Node* root,int* result){
            if(!root){
                return;
            }
            kth_smallest_element(k,count,root->left,result);
            if(*count>k){
                return;
            }
            if(k== *count){
                *result = root->data;
                (*count)++;
                return;
            }
            (*count)++;
            kth_smallest_element(k,count,root->right,result);
        }


        void floor_ceiling(Node* root,Node* target,pair<Node*,Node*>*result){
            if(!root){
                return;
            }
            floor_ceiling(root->left,target,result);
            if(target->data>=root->data){
                result->first = root;
            }
            floor_ceiling(root->right,target,result);
            if(target->data<=root->data){
                result->second = root;
            }
        }

        void RangePrinter(Node* root,int k1,int k2){
            if(!root){
                return;
            }
            if(root->data>=k1){
                RangePrinter(root->left,k1,k2);
            }
            if(root->data>=k1 && root->data<=k2){
                cout<< root->data<<" ";
            }
            if(root->data<=k2){
                RangePrinter(root->right,k1,k2);
            }
        }

        int CountTress(int n){
            if(n<=1){
                return 1;
            }
            else{
                int sum = 0;
                int left,right,root;
                for(root = 1;root<=n;root++){
                    left = CountTress(root-1);
                    right = CountTress(n-root);
                    sum+=left*right;
                }
                return sum;
            }
        }
        binary_search_tree(int data = 0){
            root->data = data;
        }
};