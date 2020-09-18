//Code by captainhoji
//Baekjoon Problem #10844

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int prev[10];
    int curr[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    int N;
    cin >> N;

    for (int i = 1; i < N; ++i) {
        memcpy(prev, curr, sizeof(prev[0]) * 10);

        curr[0] = prev[1];
        for (int j = 1; j <= 8; ++j) {
            curr[j] = (prev[j-1] + prev[j+1]) % 1000000000;
        }
        curr[9] = prev[8];

    }

    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += curr[i];
        sum %= 1000000000;
    }   

    cout << sum;

    return 0;
}