#include <iostream>

struct Node {
    int coeff;
    int exp;
    Node* next;
};

class Polynomial {
public:
    Node* head;

    Polynomial() { head = nullptr; }

    void insert(int c, int e) {
        Node* newNode = new Node{c, e, nullptr};
        if (!head || e > head->exp) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->exp >= e) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->coeff << "x^" << temp->exp;
            if (temp->next) std::cout << " + ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    void addPoly(Polynomial p1, Polynomial p2) {
        Node* t1 = p1.head;
        Node* t2 = p2.head;
        
        while (t1 && t2) {
            if (t1->exp > t2->exp) {
                insert(t1->coeff, t1->exp);
                t1 = t1->next;
            } else if (t1->exp < t2->exp) {
                insert(t2->coeff, t2->exp);
                t2 = t2->next;
            } else {
                insert(t1->coeff + t2->coeff, t1->exp);
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        while (t1) {
            insert(t1->coeff, t1->exp);
            t1 = t1->next;
        }
        while (t2) {
            insert(t2->coeff, t2->exp);
            t2 = t2->next;
        }
    }
};

int main() {
    Polynomial p1, p2, res;
    
    p1.insert(3, 2); p1.insert(5, 1); p1.insert(6, 0); 
    p2.insert(6, 1); p2.insert(8, 0); 
    
    std::cout << "Poly 1: "; p1.display();
    std::cout << "Poly 2: "; p2.display();
    
    res.addPoly(p1, p2);
    std::cout << "Result: "; res.display();
    
    return 0;
}
