#include <iostream>

struct Student {
    int id;
    float marks;
    int rollNo;
};

void bubbleSort(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        std::cout << "Pass " << i + 1 << ": ";
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].marks < s[j + 1].marks) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
        for(int k=0; k<n; k++) std::cout << s[k].marks << " ";
        std::cout << "\n";
    }
}

int main() {
    int n;
    std::cout << "Enter number of students: ";
    std::cin >> n;
    
    Student s[20];
    for (int i = 0; i < n; i++) {
        s[i].id = i + 1; 
        std::cout << "Enter marks for student ID " << s[i].id << ": ";
        std::cin >> s[i].marks;
    }
    
    std::cout << "\nAnalyzing Bubble Sort (Descending):\n";
    bubbleSort(s, n);
    
    std::cout << "\nFinal Roll No Assignment:\n";
    for(int i=0; i<n; i++) {
        s[i].rollNo = i + 1;
        std::cout << "Rank " << i+1 << ": Student ID " << s[i].id 
                  << " (Marks: " << s[i].marks << ")\n";
    }
    
    return 0;
}
