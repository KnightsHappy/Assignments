#include <iostream>
#include <string>

struct Node {
    int prn;
    std::string name;
    Node* next;
};

class VertexClub {
    Node* head;
public:
    VertexClub() { head = nullptr; }

    void addPresident(int p, std::string n) {
        Node* newNode = new Node{p, n, head};
        head = newNode;
    }

    void addSecretary(int p, std::string n) {
        Node* newNode = new Node{p, n, nullptr};
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void addMember(int p, std::string n) {
        if (!head) { addPresident(p, n); return; }
        Node* newNode = new Node{p, n, head->next};
        head->next = newNode;
    }

    void deleteMember(int p) {
        if (!head) return;
        if (head->prn == p) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->prn != p) temp = temp->next;
        if (temp->next) {
            Node* toDel = temp->next;
            temp->next = temp->next->next;
            delete toDel;
        }
    }

    int countMembers() {
        int cnt = 0;
        Node* temp = head;
        while (temp) { cnt++; temp = temp->next; }
        return cnt;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << "[" << temp->prn << "|" << temp->name << "] -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    void reverseList() {
        Node *prev = nullptr, *current = head, *next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void concatenate(VertexClub& other) {
        if (!head) { head = other.head; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = other.head;
        other.head = nullptr; 
    }
};

int main() {
    VertexClub divA, divB;
    
    divA.addPresident(101, "Alice");
    divA.addSecretary(105, "Bob");
    divA.addMember(102, "Charlie");
    
    std::cout << "Div A: "; divA.display();
    std::cout << "Count: " << divA.countMembers() << "\n";
    
    divA.reverseList();
    std::cout << "Reversed A: "; divA.display();
    
    divB.addPresident(201, "Dave");
    divB.concatenate(divA); 
    
    std::cout << "Concatenated (B+A): "; divB.display();

    return 0;
}
