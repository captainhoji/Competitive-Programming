//Code by captainhoji
//Baekjoon Problem #1149

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    // Init cost array
    int** cost = new int*[N];
    for (int i = 0; i < N; ++i) {
        cost[i] = new int[3];
        for (int j = 0; j < 3; ++j) {
            cin >> cost[i][j];
        }
    }

    int** v = new int*[N];
    for (int i = 0; i < N; ++i) {
        v[i] = new int[3];
    }
    v[0][0] = cost[0][0];
    v[0][1] = cost[0][1];
    v[0][2] = cost[0][2];

    for (int i = 1; i < N; ++i) {
        v[i][0] = min(v[i-1][1], v[i-1][2]) + cost[i][0];
        v[i][1] = min(v[i-1][0], v[i-1][2]) + cost[i][1];
        v[i][2] = min(v[i-1][0], v[i-1][1]) + cost[i][2];
    }

    cout << min(v[N-1][0], min(v[N-1][1], v[N-1][2]));

    return 0;
}