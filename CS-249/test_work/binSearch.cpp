#include <iostream>

int binSearch(int arr[], int beg, int end, int query) {
    int mid = beg + (end - beg) / 2;
    if(arr[mid] == query) {
        return mid;
    }
    else if(beg > end) {
        std::cout << "The query " << query << " is not present in the array." << std::endl;
        return -1;
    }
    else if(query > arr[mid]) {
        return binSearch(arr, mid + 1, end, query);
    }
    else {
        return binSearch(arr, beg, mid - 1, query);
    }
}

int main() {
    int arr[] = {1, 2, 4, 6, 7};
    int beg = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    int query = 3;

    int result = binSearch(arr, beg, end, query);
    if(result != -1) {
        std::cout << "The index of " << query << " is: " << result << std::endl;
    }
}