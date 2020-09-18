//Code by captainhoji
//Baekjoon Problem #11053

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p[1000] = {0};
    int v[1000] = {0};

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }

    int maxVV = 1;
    int maxV;
    v[0] = 1;
    for (int i = 1; i < N; ++i) {
        maxV = 0;
        for (int j = 0; j < i; ++j) {
            if (p[j] < p[i]) {
                maxV = max(maxV, v[j]);
            }
        }
        v[i] = maxV + 1;
        maxVV = max(maxVV, v[i]);
    }

    cout << maxVV;

    return 0;
}