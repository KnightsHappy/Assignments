#include <iostream>

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* findMax(Node* node) {
        while (node && node->right) node = node->right;
        return node;
    }

    Node* remove(Node* node, int val) {
        if (!node) return node;
        if (val < node->data) node->left = remove(node->left, val);
        else if (val > node->data) node->right = remove(node->right, val);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    bool search(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            std::cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    BST() { root = nullptr; }

    void insert(int val) { root = insert(root, val); }
    void remove(int val) { root = remove(root, val); }
    
    void find(int val) {
        if (search(root, val)) std::cout << "Found\n";
        else std::cout << "Not Found\n";
    }

    void showMinMax() {
        if (!root) { std::cout << "Tree empty\n"; return; }
        std::cout << "Min: " << findMin(root)->data << "\n";
        std::cout << "Max: " << findMax(root)->data << "\n";
    }

    void show() {
        std::cout << "Inorder: ";
        inorder(root);
        std::cout << "\n";
    }
};

int main() {
    BST tree;
    int choice, val;
    do {
        std::cout << "\n1.Insert 2.Delete 3.Find 4.Show 5.Min/Max 6.Exit: ";
        std::cin >> choice;
        switch(choice) {
            case 1: std::cin >> val; tree.insert(val); break;
            case 2: std::cin >> val; tree.remove(val); break;
            case 3: std::cin >> val; tree.find(val); break;
            case 4: tree.show(); break;
            case 5: tree.showMinMax(); break;
        }
    } while (choice != 6);
    return 0;
}
