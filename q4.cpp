#include <iostream>

int partition(float arr[], int low, int high) {
    float pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    float temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(float arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        std::cout << "Pivot placed at " << pi << " : ";
        for(int k=0; k<n; k++) std::cout << arr[k] << " ";
        std::cout << "\n";
        
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

void findMinMax(float arr[], int low, int high, float &min, float &max) {
    if (low == high) {
        min = max = arr[low];
        return;
    }
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            min = arr[low]; max = arr[high];
        } else {
            min = arr[high]; max = arr[low];
        }
        return;
    }
    
    int mid = (low + high) / 2;
    float min1, max1, min2, max2;
    
    findMinMax(arr, low, mid, min1, max1);
    findMinMax(arr, mid + 1, high, min2, max2);
    
    if (min1 < min2) min = min1; else min = min2;
    if (max1 > max2) max = max1; else max = max2;
}

int main() {
    int n;
    float arr[20], min, max;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter marks: ";
    for(int i=0; i<n; i++) std::cin >> arr[i];
    
    std::cout << "\nQuick Sort Pass Analysis:\n";
    quickSort(arr, 0, n - 1, n);
    
    findMinMax(arr, 0, n - 1, min, max);
    std::cout << "\nMin: " << min << "\nMax: " << max << "\n";
    
    return 0;
}
