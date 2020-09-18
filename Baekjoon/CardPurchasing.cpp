//Code by captainhoji
//Baekjoon Problem #11052

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int* p = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }

    int* v = new int[N];
    v[0] = p[0];

    int lmax;
    for (int i = 1; i < N; ++i) {
        lmax = p[i];
        for (int j = i - 1; j >= 0; --j) {
            lmax = max(lmax, v[j] + p[i - j - 1]);
        }
        v[i] = lmax;
    }

    cout << v[N-1];

    return 0;
}