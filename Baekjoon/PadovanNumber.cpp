//Code by captainhoji
//Baekjoon Problem #9461

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int v[100];
    v[0] = 1;
    v[1] = 1;
    v[2] = 1;
    v[3] = 2;
    v[4] = 2;

    for (int i = 5; i < 100; ++i) {
        v[i] = v[i-1] + v[i-5];
    }

    int T, n;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> n;
        cout << v[n-1] << "\n";
    }

    return 0;
}