//Code by captainhoji
//Baekjoon Problem #11727

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int* v = new int[1000];
    v[0] = 1;
    v[1] = 3;
    for (int i = 2; i < 1000; ++i) {
        v[i] = (2* v[i-2] + v[i-1]) % 10007;
    }


    int N;
    cin >> N;
    cout << v[N-1];
    return 0;
}