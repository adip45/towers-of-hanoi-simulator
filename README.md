TOWERS OF HANOI — DATA STRUCTURES MINI PROJECT

FILES
1. towers_of_hanoi_simulator.html
   Interactive visual simulator. Open it directly in Google Chrome, Microsoft Edge,
   or another modern browser. No installation or internet connection is required.

2. towers_of_hanoi.cpp
   C++ implementation for the Data Structures submission. It uses recursion and
   represents rods as stacks implemented with std::vector.

HOW TO RUN THE VISUAL SIMULATOR
1. Open towers_of_hanoi_simulator.html in a browser.
2. Select 1 to 8 disks and click New game.
3. Use Play to animate automatically, Next move to step forward, Undo to go back,
   Reset to restart, and the Speed control to change animation speed.

HOW TO RUN THE C++ PROGRAM
Open a terminal in this folder and compile:
    g++ towers_of_hanoi.cpp -o hanoi

Run on Windows:
    .\hanoi.exe

Run on Linux/macOS:
    ./hanoi

PROJECT CONCEPTS
- Recursion and the base case
- Stack operations (push_back and pop_back)
- Minimum moves: T(n) = 2^n - 1
- Time complexity: O(2^n)
- Auxiliary recursion-stack space: O(n)

NOTE
The browser simulator is implemented in HTML, CSS, and JavaScript. The separate C++
file is included for courses that require the algorithm implementation in C++.
