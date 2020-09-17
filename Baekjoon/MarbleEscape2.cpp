#include <iostream>
#include <queue>

using namespace std;

enum Direction {
    Left,
    Right,
    Up,
    Down
};

struct Pos {
    char x;
    char y;
    bool slide(char** grid, Direction dir);
};

char** grid;
bool**** checked;
int N, M;

int main() {
    cin.tie(NULL)  ;
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    grid = new char*[N];
    for (int i = 0; i < N; ++i) {
        grid[i] = new char[M];
    }

    Pos red;
    Pos blue;
    Pos goal;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'R') {
                red.x = i;
                red.y = j;
                grid[i][j] = '.';
            }
            else if (grid[i][j] == 'B') {
                blue.x = i;
                blue.y = j;
                grid[i][j] = '.';
            }
            else if (grid[i][j] == 'O') {
                goal.x = i;
                goal.y = j;
            }
        }
    }

    checked = new bool***[N];
    for (int i = 0; i < N; ++i) {
        checked[i] = new bool**[M];
        for (int j = 0; j < M; ++j) {
            checked[i][j] = new bool*[N];
            for (int k = 0; k < N; ++k) {
                checked[i][j][k] = new bool[M];
            }
        }
    }
    memset(checked, 0, N * N * M * M);
    int ans = calc(red, blue, goal);
}

//TODO: 
int calc(Pos& red, Pos& blue, Pos& goal) {
    queue<Pos> redQ;
    queue<Pos> blueQ;
    return helper(red, blue, goal, redQ, blueQ);
}

int helper(Pos red, Pos blue, Pos& goal, queue<Pos>& redQ, queue<Pos>& blueQ) {

}
// returns: 0 if continuable
//          1 if red is out and blue is not out
//          -1 if blue is out
int turn(char** grid, Direction dir, Pos& red, Pos& blue) {
    bool redIn = false;
    bool blueIn = false;
    if (dir == Left) {
        if (red.y < blue.y) {
            redIn = red.slide(grid, dir);
            blueIn = blue.slide(grid, dir);
        }
        else {
            blueIn = blue.slide(grid, dir);
            redIn = red.slide(grid, dir);
        }
    }
    else if (dir == Right) {
        if (red.y < blue.y) {
            blueIn = blue.slide(grid, dir);
            redIn = red.slide(grid, dir);
        }
        else {
            redIn = red.slide(grid, dir);
            blueIn = blue.slide(grid, dir);
        }
    }
    else if (dir == Up) {
        if (red.x < blue.x) {
            redIn = red.slide(grid, dir);
            blueIn = blue.slide(grid, dir);
        }
        else {
            blueIn = blue.slide(grid, dir);
            redIn = red.slide(grid, dir);
        }
    }
    else if (dir == Down) {
        if (red.x < blue.x) {
            blueIn = blue.slide(grid, dir);
            redIn = red.slide(grid, dir);
        }
        else {
            redIn = red.slide(grid, dir);
            blueIn = blue.slide(grid, dir);
        }
    }
    if (redIn && !blueIn) {
        return 1;
    }
    else if (blueIn) {
        return -1;
    }
    else {
        return 0;
    }
}

bool Pos::slide(char** grid, Direction dir) {
    int N = sizeof(grid)/sizeof(grid[0]);
    int M = sizeof(grid[0])/sizeof(grid[0][0]);

    if (dir == Left) {
        for (char i = y - 1; i >= 0; --i) {
            if (grid[x][i] == 'O') {
                return true;
            }
            else if (grid[x][i] != '.') {
                y = i + 1;
                return false;
            }
        }
    }
    else if (dir == Right) {
        for (char i = y + 1; i < M; ++i) {
            if (grid[x][i] == 'O') {
                return true;
            }
            else if (grid[x][i] != '.') {
                y = i - 1;
                return false;
            }
        }
    }
    else if (dir == Up) {
        for (char i = x - 1; i >= 0; --i) {
            if (grid[i][y] == 'O') {
                return true;
            }
            else if (grid[i][y] != '.') {
                x = i + 1;
                return false;
            }
        }
    }
    else if (dir == Down) {
        for (char i = x + 1; i < N; ++i) {
            if (grid[i][y] == 'O') {
                return true;
            }
            else if (grid[i][y] != '.') {
                x = i - 1;
                return false;
            }
        }
    }
    return false;
}

void print(char** grid, Pos& red, Pos& blue, Pos& goal) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}