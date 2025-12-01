#include <iostream>
#include <vector>
#include <string>
#include <list>

struct Student {
    int rollNo;
    std::string name;
    float cgpa;
};

class PlacementPortal {
    int capacity;
    int size;
    std::vector<std::list<Student>> table;

    int hashFunction(int key) {
        return key % capacity;
    }

    void rehash() {
        int oldCapacity = capacity;
        capacity = capacity * 2;
        std::vector<std::list<Student>> newTable(capacity);
        
        for (int i = 0; i < oldCapacity; i++) {
            for (auto& s : table[i]) {
                int newIndex = s.rollNo % capacity;
                newTable[newIndex].push_back(s);
            }
        }
        table = newTable;
        std::cout << "Table resized to " << capacity << "\n";
    }

public:
    PlacementPortal(int cap = 5) {
        capacity = cap;
        size = 0;
        table.resize(capacity);
    }

    void insert(int roll, std::string name, float cgpa) {
        if ((float)size / capacity > 0.75) {
            rehash();
        }

        int index = hashFunction(roll);
        for (auto& s : table[index]) {
            if (s.rollNo == roll) {
                std::cout << "Duplicate Record.\n";
                return;
            }
        }

        table[index].push_back({roll, name, cgpa});
        size++;
        std::cout << "Inserted: " << name << "\n";
    }

    void search(int roll) {
        int index = hashFunction(roll);
        for (auto& s : table[index]) {
            if (s.rollNo == roll) {
                std::cout << "Found: " << s.name << " CGPA: " << s.cgpa << "\n";
                return;
            }
        }
        std::cout << "Student not found.\n";
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            std::cout << "Bucket " << i << ": ";
            if (table[i].empty()) {
                std::cout << "NULL";
            } else {
                for (auto& s : table[i]) {
                    std::cout << "[" << s.rollNo << "|" << s.name << "] -> ";
                }
            }
            std::cout << "\n";
        }
    }
};

int main() {
    PlacementPortal portal;
    portal.insert(101, "Alice", 9.5);
    portal.insert(102, "Bob", 8.2);
    portal.insert(106, "Charlie", 7.9); 
    portal.insert(111, "Dave", 8.8);    
    
    portal.display();
    
    portal.insert(112, "Eve", 9.1); 
    portal.display(); 

    return 0;
}
