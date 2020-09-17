//Code by captainhoji
//Baekjoon Problem #1932

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int K = N * (N + 1) / 2;
    int* p = new int[K];
    int* v = new int[N];

    for (int i = 0; i < K; ++i) {
        cin >> p[i];
    }

    v[0] = p[0];
    int c = 1;
    for (int i = 1; i < N; ++i) {
        v[i] = v[i-1] + p[c + i];
        for (int j = i - 1; j > 0; --j) {
            v[j] = max(v[j], v[j-1]) + p[c + j];
        }
        v[0] = v[0] + p[c];
        c += i + 1;
    }

    int mx = 0;
    for (int i = 0; i < N; ++i) {
        mx = max(mx, v[i]);
    }

    cout << mx;

    return 0;
}