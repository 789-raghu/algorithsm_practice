#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node{
    public:
        int data;
        Node<T>* firstchild;
        Node<T>* next_sibling;
};

template<typename T>
class Tree{
    long long tree_sum(Node<T>* root){
        if(!root){
            return 0;
        }
        return (long long)root->data +tree_sum(root->firstchild)+tree_sum(root->next_sibling);
    }

    bool isOperator(char a) {
        switch (a) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
                return true;
        }
        return false;
    }

    Node<T>* expressionTree(string postfix_expression) {
        stack<Node<T>*> expression_stack;

        for (char i : postfix_expression) {
            if (isOperator(i)) {
                Node<T>* operand1 = expression_stack.top(); expression_stack.pop();
                Node<T>* operand2 = expression_stack.top(); expression_stack.pop();
                Node<T>* opNode = new Node<T>(i);
                opNode->right = operand1;
                opNode->left = operand2;
                expression_stack.push(opNode);
            } else {
                expression_stack.push(new Node<T>(i));
            }
        }
        return expression_stack.top();
    }
};