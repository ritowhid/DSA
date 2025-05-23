#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void heapify(vector<ll>& v, ll n, ll i) {
  ll largest = i, left = 2 * i + 1, right = 2 * i + 2;
  if (left < n && v[left] > v[largest]) largest = left;
  if (right < n && v[right] > v[largest]) largest = right;
  if (largest != i) {
    swap(v[i], v[largest]);
    heapify(v, n, largest);
  }
}

void heapSort(vector<ll>& v) {
  ll n = v.size();
  for (ll i = n / 2 - 1; i >= 0; i--) heapify(v, n, i);
  for (ll i = n - 1; i > 0; i--) {
    swap(v[0], v[i]);
    heapify(v, i, 0);
  }
}

int main() {
  vector<ll> v = {6, 5, 12, 10, 9, 1};
  heapSort(v);
  cout << "Sorted array:\n";
  for (auto u : v) cout << u << " ";
  return 0;
}
