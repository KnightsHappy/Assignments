#include <iostream>

int stringLength(char s[]) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

void stringCopy(char src[], char dest[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void stringReverse(char s[]) {
    int len = stringLength(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

void stringConcat(char s1[], char s2[]) {
    int i = stringLength(s1);
    int j = 0;
    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
}

int main() {
    char str1[100], str2[100], str3[100];
    
    std::cout << "Enter string 1: ";
    std::cin >> str1;
    
    std::cout << "Length: " << stringLength(str1) << "\n";
    
    stringCopy(str1, str2);
    std::cout << "Copied to str2: " << str2 << "\n";
    
    stringReverse(str1);
    std::cout << "Reversed str1: " << str1 << "\n";
    stringReverse(str1); 
    
    std::cout << "Enter string 3 to concat: ";
    std::cin >> str3;
    stringConcat(str1, str3);
    std::cout << "Concatenated: " << str1 << "\n";
    
    return 0;
}
