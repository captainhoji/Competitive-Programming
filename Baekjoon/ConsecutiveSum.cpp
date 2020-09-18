//Code by captainhoji
//Baekjoon Problem #1912

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;


    int maxVal = -10000;
    int p;
    int v = 0;
    for (int i = 0; i < N; ++i) {
        cin >> p;
        if (v < 0) {
            v = p;
        }
        else {
            v += p;
        }
        maxVal = max(maxVal, v);
    }

    cout << maxVal;

    return 0;
}