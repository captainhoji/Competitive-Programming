//Code by captainhoji
//Baekjoon Problem #1003

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K = 41;
    int* zeroes = new int[K];
    int* ones = new int[K];

    zeroes[0] = 1;
    ones[0] = 0;
    zeroes[1] = 0;
    ones[1] = 1;

    for (int i = 2; i < K; ++i) {
        zeroes[i] = zeroes[i-1] + zeroes[i-2];
        ones[i] = ones[i-1] + ones[i-2];
    }

    int T, N;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N;
        cout << zeroes[N] << " " << ones[N] << "\n";
    }

    return 0;
}