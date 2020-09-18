//Code by captainhoji
//Baekjoon Problem #2748

#include <iostream>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 21;

    long long int* fib = new long long int[k];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < k; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    cin >> N;
    cout << fib[N];

    return 0;
}