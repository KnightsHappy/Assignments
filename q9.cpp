#include <iostream>

struct Node {
    int data;
    Node *prev, *next;
};

class DLLSort {
public:
    Node* head;
    DLLSort() { head = nullptr; }

    void insert(int val) {
        Node* newNode = new Node{val, nullptr, nullptr};
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void bubbleSort() {
        if (!head) return;
        bool swapped;
        Node* ptr;
        Node* lptr = nullptr;

        do {
            swapped = false;
            ptr = head;

            while (ptr->next != lptr) {
                if (ptr->data > ptr->next->data) {
                    int t = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = t;
                    swapped = true;
                }
                ptr = ptr->next;
            }
            lptr = ptr;
        } while (swapped);
    }

    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

int main() {
    DLLSort list;
    list.insert(50); list.insert(20); list.insert(10); list.insert(40);
    
    std::cout << "Before Sort: "; list.display();
    list.bubbleSort();
    std::cout << "After Sort: "; list.display();
    
    return 0;
}
