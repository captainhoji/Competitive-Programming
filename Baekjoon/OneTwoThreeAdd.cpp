//Code by captainhoji
//Baekjoon Problem #9095

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int* v = new int[10];
    v[0] = 1;
    v[1] = 2;
    v[2] = 4;
    for (int i = 3; i <= 10; ++i) {
        v[i] = v[i-1] + v[i-2] + v[i-3];
    }

    int T;
    int N;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        cin >> N;
        cout << v[N-1] << "\n";
    }

    return 0;
}