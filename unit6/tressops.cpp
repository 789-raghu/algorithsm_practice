#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node
{
    T data;
    Node<T> *right, *left;

public:
    Node(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class Tree
{
    Node<T> *root;

public:
    void inorder(Node<T> *root)
    {
        if (root)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node<T> *root)
    {
        if (root)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node<T> *root)
    {
        if (root)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void inorder_literative(Node<T> *root)
    {
        stack<Node<T> *> inorder_stack;

        while (true)
        {
            while (root)
            {
                inorder_stack.push(root);
                root = root->left;
            }
            if (inorder_stack.empty())
            {
                break;
            }
            cout << inorder_stack.top()->data << " ";
            root = inorder_stack.top()->right;
            inorder_stack.pop();
        }
    }

    void preorder_iterative(Node<T> *root)
    {
        stack<Node<T> *> preorder_stack;
        while (true)
        {
            while (root)
            {
                cout << root->data << " ";
                preorder_stack(root->left);
                root->left;
            }
            if (preorder_stack.empty())
            {
                break;
            }
            root = preorder_stack.top();
            preorder_stack.pop();
        }

        free(preorder_stack);
    }

    void postorder_iterative(Node<T> *root)
    {
    }

    Node<T> *lowest_common_ancestor(Node<T> *root, Node<T> *node1, Node<T> *node2)
    {
        Node<T> *right = nullptr, *left = nullptr;

        if (!root)
        {
            return nullptr;
        }
        if (root == node1 || root == node2)
        {
            return root;
        }

        left = lowest_common_ancestor(root->left, node1, node2);
        right = lowest_common_ancestor(root->right, node1, node2);

        if (left && right)
        {
            return root;
        }
        return left ? left : right;
    }

    Node<T> *treeconstruction(vector<T> inorder, vector<T> postorder)
    {
    }

    void levelorder(Node<T> *root)
    {
        queue<Node<T> *> level_order_q, auxillary_q;
        level_order_q.push(root);

        while (!level_order_q.empty())
        {
            auxillary_q = level_order_q;
            while (!auxillary_q.empty())
            {
                Node<T> *node = auxillary_q.front();
                if (node->left)
                {
                    level_order_q.push(node->left);
                }
                if (node->right)
                {
                    level_order_q.push(node->right);
                }
                cout << level_order_q.front()->data << " ";
                level_order_q.pop();
                auxillary_q.pop();
            }
        }
    }

    void get_maximum(Node<T> *head)
    {
        queue<Node<T> *> level_ordered_queue;
        level_ordered_queue.push(head);
        T temp = head->data;
        while (!level_ordered_queue.empty())
        {
            Node<T> *node = level_ordered_queue.front();
            level_ordered_queue.pop();
            temp = max(temp, node->data);
            if (node->left)
                level_ordered_queue.push(node->left);
            if (node->right)
                level_ordered_queue.push(node->right);
        }
    }

    int count_half_nodes(Node<T> *temp)
    {
        if (!temp)
        {
            return 0;
        }
        int isPossible = !((temp->right && temp->left) || (!temp->right && !temp->left));
        return isPossible + count_half_nodes(temp->left) + count_half_nodes(temp->right);
    }

    bool structurally_idential(Node<T> *root1, Node<T> *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
        {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr)
        {
            return false;
        }

        if (root1->data != root2->data)
        {
            return false;
        }

        return structurally_idential(root1->left, root2->left) && structurally_idential(root1->right, root2->right);
    }

    int diameter_of_tree(Node<T> *root, int *diameter)
    {
        if (!root)
        {
            return 0;
        }
        int left = diameter_of_tree(root->left, diameter);
        int right = diameter_of_tree(root->right, diameter);
        *diameter = max(right + left, *diameter);
        return max(left, right) + 1;
    }

    int get_max_level_sum(Node<T> *node)
    {
        if (!node)
            return 0;
        queue<Node<T> *> level_order_queue;
        level_order_queue.push(node);
        int max_sum = INT_MIN, sum;
        while (!level_order_queue.empty())
        {
            sum = 0;
            int size = level_order_queue.size();

            for (int i = 0; i < size; i++)
            {
                Node<T> *temp = level_order_queue.front();
                level_order_queue.pop();
                sum += temp->data;
                if (temp->left)
                {
                    level_order_queue.push(temp->left);
                }
                if (temp->right)
                {
                    level_order_queue.push(temp->right);
                }
            }
            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }

    void insertion(vector<T> *nodes)
    {
        if (!nodes || nodes->empty())
            return;

        queue<Node<T> *> q;
        Node<T> *root = new Node<T>((*nodes)[0]);
        q.push(root);
        int i = 1;

        while (i < nodes->size())
        {
            Node<T> *current = q.front();
            q.pop();
            if (i < nodes->size())
            {
                current->left = new Node<T>((*nodes)[i++]);
                q.push(current->left);
            }
            if (i < nodes->size())
            {
                current->right = new Node<T>((*nodes)[i++]);
                q.push(current->right);
            }
        }

        this->root = root;
    }

    void vertical_traversal_sum(Node<T> *root, int offset, unordered_map<int, int> &tracker)
    {
        if (!root)
        {
            return;
        }
        vertical_traversal_sum(root->left, offset - 1, tracker);
        tracker[offset] += root->data;
        vertical_traversal_sum(root->right, offset + 1, tracker);
    }

    long long total_number_of_trees(int n)
    {
        return ((long long)1 << n) - n;
    }

    Node<T> *special_tree_construction(Node<T> *root)
    {
    }

    template <typename T>
    Node<T> *connect_siblings(Node<T> *root)
    {
        if (!root)
            return nullptr;

        queue<Node<T> *> level_order_queue;
        level_order_queue.push(root);

        while (!level_order_queue.empty())
        {
            int size = level_order_queue.size();
            Node<T> *prev = nullptr;

            for (int i = 0; i < size; i++)
            {
                Node<T> *current = level_order_queue.front();
                level_order_queue.pop();

                if (prev)
                {
                    prev->sibling = current;
                }
                prev = current;

                if (current->left)
                    level_order_queue.push(current->left);
                if (current->right)
                    level_order_queue.push(current->right);
            }
        }

        return root;
    }
};

int main()
{
}
