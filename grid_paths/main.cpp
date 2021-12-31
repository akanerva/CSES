#include <bits/stdc++.h>

using namespace std;

/**
 * akanerva
 *
 * https://cses.fi/problemset/task/1625
 *
 * Ratkaistaan peruuttavalla haulla jota optimoidaan tarpeeksi paljon
 * rikkomaan rekursio mahdollisimman aikaisin (=pruning).
 */


#define N 7
string input;
bool grid[N][N];
int c = 0;
//string reitti(48, '?'); //debuggaus
map<char, int> valr;

//peruuttava haku
void haku(int x, int y, int z) {
    //cout << reitti << "\n";
    if (x == 6 && y == 0 && z < 48) return; //maalissa liian aikaisin
    if (z == N*N-1 && x == N-1 && y == 0) {
        c++;
        return;
    }
    switch(valr[input[z]]) {
        case 1: //'U'
            if (x > 0 && !grid[x-1][y]) {
                if (y > 0 && y < N-1 && (x == 1 || grid[x-2][y]) && !grid[x-1][y-1] && !grid[x-1][y+1])
                    return;
                //reitti[z] = input[z];
                grid[x-1][y] = true;
                haku(x-1, y, z+1);
                //reitti[z] = '?';
                grid[x - 1][y] = false;
            }
            break;

        case 2: //'R'
            if (y < N-1 && !grid[x][y+1]) {
                if (x > 0 && x < N-1 && (y == N-2 || grid[x][y+2]) && !grid[x-1][y+1] && !grid[x+1][y+1])
                    return;
                //reitti[z] = input[z];
                grid[x][y+1] = true;
                haku(x, y+1, z+1);
                //reitti[z] = '?';
                grid[x][y + 1] = false;
            }
            break;

        case 3: //'D'
            if (x < N-1 && !grid[x+1][y]) {
                if (y > 0 && y < N-1 && (x == N-2 || grid[x+2][y]) && !grid[x+1][y-1] && !grid[x+1][y+1])
                    return;
                //reitti[z] = input[z];
                grid[x+1][y] = true;
                haku(x+1, y, z+1);
                //reitti[z] = '?';
                grid[x+1][y] = false;
            }
            break;

        case 4: //'L'
            if (y > 0 && !grid[x][y-1]) {
                if (x > 0 && x < N-1 && (y == 1 || grid[x][y-2]) && !grid[x-1][y-1] && !grid[x+1][y-1]) {}
                //reitti[z] = input[z];
                grid[x][y-1] = true;
                haku(x, y-1, z+1);
                //reitti[z] = '?';
                grid[x][y-1] = false;
            }
            break;

        case 5:
            if (x > 0 && !grid[x-1][y]) {
                if (y > 0 && y < N-1 && (x == 1 || grid[x-2][y]) && !grid[x-1][y-1] && !grid[x-1][y+1]) {}
                else {
                    //reitti[z] = input[z];
                    grid[x - 1][y] = true;
                    haku(x - 1, y, z + 1);
                    //reitti[z] = '?';
                    grid[x - 1][y] = false;
                }

            }
            if (y < N-1 && !grid[x][y+1]) {
                if (x > 0 && x < N-1 && (y == N-2 || grid[x][y+2]) && !grid[x-1][y+1] && !grid[x+1][y+1]) {}
                else {
                    //reitti[z] = input[z];
                    grid[x][y + 1] = true;
                    haku(x, y + 1, z + 1);
                    //reitti[z] = '?';
                    grid[x][y + 1] = false;
                }

            }
            if (x < N-1 && !grid[x+1][y]) {
                if (y > 0 && y < N-1 && (x == N-2 || grid[x+2][y]) && !grid[x+1][y-1] && !grid[x+1][y+1]) {}
                else {
                    //reitti[z] = input[z];
                    grid[x + 1][y] = true;
                    haku(x + 1, y, z + 1);
                    //reitti[z] = '?';
                    grid[x + 1][y] = false;
                }

            }
            if (y > 0 && !grid[x][y-1]) {
                if (x > 0 && x < N-1 && (y == 1 || grid[x][y-2]) && !grid[x-1][y-1] && !grid[x+1][y-1]) {}
                else {
                    //reitti[z] = input[z];
                    grid[x][y - 1] = true;
                    haku(x, y - 1, z + 1);
                    //reitti[z] = '?';
                    grid[x][y - 1] = false;
                }
            }
            break;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    valr['U'] = 1;
    valr['R'] = 2;
    valr['D'] = 3;
    valr['L'] = 4;
    valr['?'] = 5;
    cin >> input;

    //ei voi päätyä vasempaan alakulmaan
    if (input[N*N-1] == 'R' || input[N*N-1] == 'U' || input[N*N-2] == 'R' || input[N*N-2] == 'U') {
        cout << 0;
        return 0;
    }

    grid[0][0] = true;
    haku(0, 0, 0);

    cout << c;


    return 0;
}