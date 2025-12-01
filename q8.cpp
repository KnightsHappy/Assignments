#include <iostream>

struct Node {
    int data;
    Node *prev, *next;
};

class DLL {
    Node* head;
public:
    DLL() { head = nullptr; }

    void insertFront(int val) {
        Node* newNode = new Node{val, nullptr, head};
        if (head) head->prev = newNode;
        head = newNode;
    }

    void insertEnd(int val) {
        Node* newNode = new Node{val, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        
        Node* newNode = new Node{val, temp, temp->next};
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteFront() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void deleteEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteVal(int val) {
        if (!head) return;
        Node* temp = head;
        while (temp && temp->data != val) temp = temp->next;
        if (!temp) return;

        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;

        if (temp->next) temp->next->prev = temp->prev;
        
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    DLL list;
    list.insertEnd(10); list.insertEnd(20); list.insertFront(5);
    list.insertAfter(10, 15);
    list.display(); 
    
    list.deleteFront();
    list.deleteEnd();
    list.deleteVal(15);
    list.display(); 
    
    return 0;
}
