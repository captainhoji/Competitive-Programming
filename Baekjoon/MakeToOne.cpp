//Code by captainhoji
//Baekjoon Problem #1463

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int count = 0;
    int* v = new int[N];

    v[0] = 0;
    int k = 0;
    for (int i = 1; i < N; ++i) {
        k = v[i-1];
        if ((i + 1) % 3 == 0) {
            if (v[i/3] < k)
                k = v[i/3];
        }
        if ((i + 1) % 2 == 0) {
            if (v[i/2] < k) 
                k = v[i/2];
        }
        v[i] = k + 1;
    }

    cout << v[N-1];
  
    return 0;
}