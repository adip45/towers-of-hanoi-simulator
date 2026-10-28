#include <iostream>
using namespace std;

int rods[3][8];
int count[3] = {0, 0, 0};
char name[3] = {'A', 'B', 'C'};
int moves = 0;
int mode;

void print(char c, int times) {
    for (int i = 0; i < times; i++)
        cout << c;
}

void display(int n) {
    cout << endl;
    for (int h = n - 1; h >= 0; h--) {
        for (int r = 0; r < 3; r++) {
            if (h < count[r]) {
                int d = rods[r][h];
                print(' ', n - d);
                print('=', 2 * d + 1);
                print(' ', n - d);
            } else {
                print(' ', n);
                cout << '|';
                print(' ', n);
            }
            print(' ', 3);
        }
        cout << endl;
    }
    for (int r = 0; r < 3; r++) {
        print(' ', n);
        cout << name[r];
        print(' ', n);
        print(' ', 3);
    }
    cout << endl;
}

void moveDisk(int from, int to, int total) {
    int d = rods[from][count[from] - 1];
    count[from]--;
    rods[to][count[to]] = d;
    count[to]++;
    moves++;
    cout << "Move " << moves << ": Disk " << d << " from " << name[from] << " to " << name[to] << endl;
    display(total);
    if (mode == 2) {
        cout << "Press Enter for the next move...";
        cin.get();
    }
}

void hanoi(int n, int from, int aux, int to, int total) {
    if (n == 1) {
        moveDisk(from, to, total);
        return;
    }
    hanoi(n - 1, from, to, aux, total);
    moveDisk(from, to, total);
    hanoi(n - 1, aux, from, to, total);
}

int main() {
    cout << "=== TOWERS OF HANOI ===" << endl;
    int n;
    cout << "Enter number of disks (1-8): ";
    cin >> n;
    if (n < 1 || n > 8) {
        cout << "Invalid input. Enter a number from 1 to 8." << endl;
        return 1;
    }
    cout << "Choose mode: 1. Automatic  2. Step by step: ";
    cin >> mode;
    if (mode != 1 && mode != 2) {
        cout << "Invalid mode. Choose 1 or 2." << endl;
        return 1;
    }
    cin.ignore();
    for (int d = n; d >= 1; d--) {
        rods[0][count[0]] = d;
        count[0]++;
    }
    cout << "\nInitial arrangement:" << endl;
    display(n);
    hanoi(n, 0, 1, 2, n);
    int minMoves = 1;
    for (int i = 0; i < n; i++)
        minMoves = minMoves * 2;
    minMoves = minMoves - 1;
    cout << "Puzzle solved!" << endl;
    cout << "Moves performed: " << moves << endl;
    cout << "Minimum moves: " << minMoves << endl;
    cout << "Time complexity: O(2^n)" << endl;
    return 0;
}