//Code by captainhoji
//Baekjoon Problem #2156

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p[10001] = {0};
    int v[10001] = {0};

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> p[i];
    }

    v[1] = p[1];
    v[2] = p[1]+p[2];
    v[3] = max(p[1] + p[3], p[2] + p[3]);
    for (int i = 4; i <=N; ++i) {
        v[i] = max(max(v[i-4], v[i-3]) + p[i-1], v[i-2]) + p[i];
    }


    cout << max(v[N-1], v[N]);

    return 0;
}