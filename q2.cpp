#include <iostream>

struct Element {
    int row, col, val;
};

void simpleTranspose(Element a[], Element b[]) {
    int n = a[0].val; 
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = n;
    
    int k = 1;
    for (int i = 0; i < a[0].col; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j].col == i) {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].val = a[j].val;
                k++;
            }
        }
    }
}

int main() {
    Element a[20], b[20];
    int r, c, n;
    std::cout << "Enter Rows, Cols, Non-Zero values: ";
    std::cin >> r >> c >> n;
    
    a[0].row = r; a[0].col = c; a[0].val = n;
    
    std::cout << "Enter Row, Col, Value for each:\n";
    for(int i=1; i<=n; i++) {
        std::cin >> a[i].row >> a[i].col >> a[i].val;
    }
    
    simpleTranspose(a, b);
    
    std::cout << "\nTranspose (Compact Representation):\n";
    std::cout << b[0].row << " " << b[0].col << " " << b[0].val << "\n";
    for(int i=1; i<=n; i++) {
        std::cout << b[i].row << " " << b[i].col << " " << b[i].val << "\n";
    }
    
    return 0;
}
