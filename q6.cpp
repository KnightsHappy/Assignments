#include <iostream>
#include <iomanip>

void generateMagicSquare(int n) {
    int magicSquare[15][15] = {0};
    
    int i = n / 2;
    int j = n - 1;
    
    for (int num = 1; num <= n * n; ) {
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            if (j == n) j = 0;
            if (i < 0) i = n - 1;
        }
        
        if (magicSquare[i][j]) {
            j -= 2;
            i++;
            continue;
        } else {
            magicSquare[i][j] = num++;
        }
        
        j++; i--;
    }
    
    std::cout << "Magic Square of order " << n << ":\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            std::cout << std::setw(4) << magicSquare[i][j];
        std::cout << "\n";
    }
    
    std::cout << "Magic Constant: " << n * (n * n + 1) / 2 << "\n";
}

int main() {
    int n;
    std::cout << "Enter odd order (n): ";
    std::cin >> n;
    if (n % 2 == 0) std::cout << "Code supports Odd order only.\n";
    else generateMagicSquare(n);
    return 0;
}
