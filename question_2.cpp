#include <iostream>
using namespace std;
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}
void rearrangeArray(int arr[], int n) {
    int p[100], npp[100];
    int pc = 0, nppc = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            p[pc++] = arr[i];
        } else {
            npp[nppc++] = arr[i];
        }
    }
    for (int i = 0; i < pc; i++) {
        for (int j = i + 1; j < pc; j++) {
            if (p[i] < p[j]) {
                int temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    arr[0] = p[0];
    arr[n - 1] = p[pc - 1];
}
int main() {
    int arr[] = {5, 1, 8, 11, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrangeArray(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
