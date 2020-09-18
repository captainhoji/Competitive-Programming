//Code by captainhoji
//Baekjoon Problem #9465

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N;
    cin >> N;
    int** p = new int*[2];
    p[0] = new int[N];
    p[1] = new int[N];

    for (int i = 0; i < N; ++i) {
        cin >> p[0][i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> p[1][i];
    }


    int** v = new int*[2];
    v[0] = new int[N];
    v[1] = new int[N];
    v[0][0] = p[0][0];
    v[1][0] = p[1][0];
    v[0][1] = p[1][0] + p[0][1];
    v[1][1] = p[1][0] + p[0][1];
    


    return 0;
}