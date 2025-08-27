#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    void leafConnect(Node* root, Node *last) {
        if (root == NULL || root->left == NULL) return;
        root->left->next = root->right;
        leafConnect(root->left, root->right);
        if (last != NULL) {
            root->right->next = last->left;
            leafConnect(root->right, last->left);
        } else {
            leafConnect(root->right, NULL);
        }
    }
    Node* connect(Node* root) {
        leafConnect(root, NULL);
        return root;
    }
};

void main() {
    Node *root = new Node(1, new Node(2, new Node(4), new Node(5), NULL), new Node(3, new Node(6), new Node(7), NULL), NULL);
    Solution sol;
    sol.connect(root);
    // check with prints
    Node *cur = root;
    while (cur != NULL) {
        Node *level_start = cur;
        while (level_start != NULL) {
            cout << level_start->val << " ";
            level_start = level_start->next;
        }
        cout << "# ";
        cur = cur->left;
    }
    cout << endl;
}