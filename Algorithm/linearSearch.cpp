#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target)
            return i; // found at index i
    }
    return -1; // not found
}

int main() {
    vector<int> arr = {4, 2, 7, 1, 9, 5};
    int target = 9;

    int index = linearSearch(arr, target);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
