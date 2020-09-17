//Code by captainhoji
//Baekjoon Problem #2579

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

    int* v = new int[N + 1];
    bool* t = new bool[N];
    for (int i = 0; i < N; ++i) {
        t[i] = false;
    }

    v[0] = p[0];
    v[1] = p[0] + p[1];
    t[1] = true;
    if (p[1] > p[0]) {
        t[2] = true;
        v[2] = p[1] + p[2];
    }
    else {
        v[2] = p[0] + p[2];
    }

    int x;
    for (int i = 3; i < N; ++i) {
        if (t[i-1]) {
            x = v[i-3] + p[i-1];
        }
        else {
            x = v[i-1];
        }
        if (x > v[i-2]) {
            t[i] = true;
            v[i] = x + p[i];
        }
        else {
            v[i] = v[i-2] + p[i];
        }
    }

    cout << v[N-1];

    return 0;
}