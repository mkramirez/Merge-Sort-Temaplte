#include <cassert>
#include <iostream>
#include <vector>

template <class T>
class Merge {
public:
    Merge(int a[], int start, int mid, int end);
    static void merge_sort(int a[], int from, int to);
    static bool sorted (int a[], int n);
};
template <class T>
Merge::Merge(int a[], int start, int mid, int end) {
    int n = end - start + 1;
    std::vector<T> b(n);
    int i1 = start;
    int i2 = mid + 1;
    int j = 0;

    while (i1 <= mid && i2 <= end) {
        if (a[i1] < a[i2]) {
            b[j] = a[i1];
            i1++;
        }
        else {
            b[j] = a[i2];
            i2++;
        }
        j++;
    }

    while (i1 <= mid) {
        b[j] = a[i1];
        i1++;
        j++;
    }
    while (i2 <= end) {
        b[j] = a[i2];
        i2++;
        j++;
    }
    for (j = 0; j < n; j++)
        a[start + j] = b[j];
}

template <class T>
void Merge::merge_sort(int a[], int from, int to) {
    if (from == to) return;
    int mid = (from + to) / 2;
    merge_sort(a, from, mid);
    merge_sort(a, mid + 1, to);
    Merge(a, from, mid, to);
}

template <class T>
bool Merge::sorted(int a[], int n) {
    for (int i = 0; i < n -1; ++i) {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

int main (int argc, char * args[]) {
    int a[1000];
    for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
    Merge::merge_sort(a, 0, 999);
    assert(Merge::sorted(a, 1000));
    int b[1001];
    for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
    Merge::merge_sort(b, 0, 1000);
    assert(Merge::sorted(b, 1001));
    int c[] = { 2 };
    Merge::merge_sort(c, 0, 1);
    assert(Merge::sorted(c, 1));
    int d[] = { 1, 2, 3, 4, 5 };
    Merge::merge_sort(d, 0, 4);
    assert(Merge::sorted(d, 5));
    std::cout << "All tests passed." << std::endl;
}