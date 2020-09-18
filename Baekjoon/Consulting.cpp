//Code by captainhoji
//Baekjoon Problem #14501

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int* t = new int[N];
    int* p = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> t[i];
        cin >> p[i];
    }

    int* v = new int[N+1];
    v[0] = 0;

    int localMaxV;
    int maxV = 0;
    for (int i = 1; i <= N; ++i) {// iterate through whole v
        localMaxV = v[i-1];
        for (int j = 0; j < i; ++j) { // iterate through previous v's
            if (j + t[j] == i) {
                localMaxV = max(localMaxV, v[j] + p[j]);
            }
        }
        v[i] = localMaxV;
        maxV = max(maxV, localMaxV);
    }

    cout << maxV;

    return 0;
}