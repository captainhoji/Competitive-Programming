//Code by captainhoji
//Baekjoon Problem #2839

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int fives = N / 5;
    int rem = N - fives * 5;

    while (rem % 3 != 0) {
        fives--;
        rem = N - fives * 5;
        if (fives < 0) {
            cout << -1;
            return 0;
        }
    }

    int ans = fives + rem / 3;
    cout << ans;

    

    return 0;
}