#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// The three rods are represented as stacks (vectors).
vector<int> rods[3];
const char rodName[] = {'A', 'B', 'C'};
long long moveCount = 0;
bool stepByStep = false;

void displayRods(int n) {
    cout << "\n";
    for (int height = n - 1; height >= 0; --height) {
        for (int r = 0; r < 3; ++r) {
            if (height < static_cast<int>(rods[r].size())) {
                int disk = rods[r][height];
                cout << string(n - disk, ' ')
                     << string(2 * disk + 1, '=')
                     << string(n - disk, ' ');
            } else {
                cout << string(n, ' ') << '|' << string(n, ' ');
            }
            cout << "   ";
        }
        cout << '\n';
    }
    for (int r = 0; r < 3; ++r) {
        cout << string(n, ' ') << rodName[r] << string(n, ' ') << "   ";
    }
    cout << "\n";
}

void moveDisk(int source, int destination, int n) {
    int disk = rods[source].back();
    rods[source].pop_back();
    rods[destination].push_back(disk);
    ++moveCount;

    cout << "Move " << moveCount << ": Disk " << disk
         << " from " << rodName[source]
         << " to " << rodName[destination] << '\n';
    displayRods(n);

    if (stepByStep) {
        cout << "Press Enter for the next move...";
        cin.get();
    }
}

// Recursive Towers of Hanoi solution.
void solveHanoi(int n, int source, int auxiliary,
                int destination, int totalDisks) {
    if (n == 1) { // Base case
        moveDisk(source, destination, totalDisks);
        return;
    }

    solveHanoi(n - 1, source, destination, auxiliary, totalDisks);
    moveDisk(source, destination, totalDisks);
    solveHanoi(n - 1, auxiliary, source, destination, totalDisks);
}

int main() {
    cout << "=== TOWERS OF HANOI: C++ DATA STRUCTURES PROJECT ===\n";
    int n;
    cout << "Enter number of disks (1-8): ";
    if (!(cin >> n) || n < 1 || n > 8) {
        cout << "Invalid input. Enter a whole number from 1 to 8.\n";
        return 1;
    }

    int mode;
    cout << "Choose mode: 1. Automatic  2. Step by step: ";
    if (!(cin >> mode) || (mode != 1 && mode != 2)) {
        cout << "Invalid mode. Choose 1 or 2.\n";
        return 1;
    }
    stepByStep = (mode == 2);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int disk = n; disk >= 1; --disk) {
        rods[0].push_back(disk);
    }

    cout << "\nInitial arrangement (all disks on rod A):\n";
    displayRods(n);
    solveHanoi(n, 0, 1, 2, n);

    cout << "Puzzle solved!\n";
    cout << "Moves performed: " << moveCount << '\n';
    cout << "Minimum moves: 2^" << n << " - 1 = "
         << ((1LL << n) - 1) << '\n';
    cout << "Time complexity: O(2^n)\n";
    cout << "Auxiliary recursion-stack space: O(n)\n";
    return 0;
}
