#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid; // found
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // not found
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target = 9;
    int index = binarySearch(arr, target);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
