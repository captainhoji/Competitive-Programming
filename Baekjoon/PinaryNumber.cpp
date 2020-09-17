//Code by captainhoji
//Baekjoon Problem #2193

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int v[91] = {0};
    v[0] = 0;
    v[1] = 1;
    v[2] = 1;
    for (int i = 3; i <= 90; ++i) {
        v[i] = 2 * v[i-1] - v[i-3];
    }

    int N;
    cin >> N;
    cout << v[N];

    return 0;
}