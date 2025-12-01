#include <iostream>

struct Node {
    int data;
    Node *left, *right;
    Node(int v) { data = v; left = right = nullptr; }
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() { root = nullptr; }

    Node* create() {
        int x;
        std::cout << "Enter data (-1 for no node): ";
        std::cin >> x;
        if (x == -1) return nullptr;
        Node* newNode = new Node(x);
        std::cout << "Enter left child of " << x << "\n";
        newNode->left = create();
        std::cout << "Enter right child of " << x << "\n";
        newNode->right = create();
        return newNode;
    }

    void inorder(Node* t) {
        if (t) {
            inorder(t->left);
            std::cout << t->data << " ";
            inorder(t->right);
        }
    }

    void preorder(Node* t) {
        if (t) {
            std::cout << t->data << " ";
            preorder(t->left);
            preorder(t->right);
        }
    }

    int countLeaves(Node* t) {
        if (!t) return 0;
        if (!t->left && !t->right) return 1;
        return countLeaves(t->left) + countLeaves(t->right);
    }

    void mirror(Node* t) {
        if (!t) return;
        Node* temp = t->left;
        t->left = t->right;
        t->right = temp;
        mirror(t->left);
        mirror(t->right);
    }
};

int main() {
    BinaryTree bt;
    bt.root = bt.create();

    std::cout << "Inorder: "; bt.inorder(bt.root); std::cout << "\n";
    std::cout << "Preorder: "; bt.preorder(bt.root); std::cout << "\n";
    std::cout << "Leaf Nodes: " << bt.countLeaves(bt.root) << "\n";

    bt.mirror(bt.root);
    std::cout << "Mirrored Inorder: "; bt.inorder(bt.root); std::cout << "\n";
    
    return 0;
}
