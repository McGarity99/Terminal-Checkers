#include <cstdlib>
#include <string>
#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include <tuple>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <unordered_map>
//#include <unistd.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::tuple;
using std::make_tuple;

/* Global Definitions*/
char blackCommonPiece = 'b';
char redCommonPiece = 'r';
char blackKingPiece = 'B';
char redKingPiece = 'R';
char gameBoard[8][8]; // represents the game board for player & comp
vector<tuple<int, int>> blackPresets; // collection of starting locations for "black" pieces

vector<tuple<int, int>> redPresets; // collection of starting locations for "red" pieces
std::unordered_map<char, int> letterMap = {
    {0, 'a'},
    {1, 'b'},
    {2, 'c'},
    {3, 'd'},
    {4, 'e'},
    {5, 'f'},
    {6, 'g'},
    {7, 'h'}
};

/* Function Declarations*/
void printWelcome();
void setupPresets();
void setupBoard();
void printBoard();
char presetsContains(tuple<int, int>);
/* Function Definitions*/
int main() {

    cout << "Welcome to Command Line Checkers!" << endl;
    setupPresets();
    setupBoard();
    printBoard();

    return 0;
} // main()

void setupPresets() {
    blackPresets.push_back(make_tuple(0, 1));
    blackPresets.push_back(make_tuple(0, 3));
    blackPresets.push_back(make_tuple(0, 5));
    blackPresets.push_back(make_tuple(0, 7));
    blackPresets.push_back(make_tuple(1, 0));
    blackPresets.push_back(make_tuple(1, 2));
    blackPresets.push_back(make_tuple(1, 4));
    blackPresets.push_back(make_tuple(1, 6));
    blackPresets.push_back(make_tuple(2, 1));
    blackPresets.push_back(make_tuple(2, 3));
    blackPresets.push_back(make_tuple(2, 5));
    blackPresets.push_back(make_tuple(2, 7));

    redPresets.push_back(make_tuple(5, 0));
    redPresets.push_back(make_tuple(5, 2));
    redPresets.push_back(make_tuple(5, 4));
    redPresets.push_back(make_tuple(5, 6));
    redPresets.push_back(make_tuple(6, 1));
    redPresets.push_back(make_tuple(6, 3));
    redPresets.push_back(make_tuple(6, 5));
    redPresets.push_back(make_tuple(6, 7));
    redPresets.push_back(make_tuple(7, 0));
    redPresets.push_back(make_tuple(7, 2));
    redPresets.push_back(make_tuple(7, 4));
    redPresets.push_back(make_tuple(7, 6));
}

/*
    Set up the game board's initial state with blank spaces and starting pieces
*/
void setupBoard() {
    tuple<int, int> tempTuple;
    for (int i = 0; i < 8; i++) {
        for (int ii = 0; ii < 8; ii++) {
            tempTuple = make_tuple(i, ii);
            // If tempTuple is contained in black/red presets, mark it accordingly, otherwise leave its space blank
            gameBoard[i][ii] = presetsContains(tempTuple);
        }
    }
}

/*
    Test if a given coordinate point is a preset point for red or black.
    If it is, then return the corresponding symbol, otherwise return a blank space.
*/
char presetsContains(tuple<int, int> target) {
    char result;
    for (auto it = blackPresets.begin(); it != blackPresets.end(); ++it) {
        if (*it == target) {
            result = blackCommonPiece;
            return result;
        }
    }
    for (auto it = redPresets.begin(); it != redPresets.end(); ++it) {
        if (*it == target) {
            result = redCommonPiece;
            return result;
        }
    }
    return ' ';
}

/*
    Print the game board in an elegant fashion
    Ideal appearance for each space:

    ----- x 8 = 40 total
    |   |
    ----- x 8 = 40 total
*/
void printBoard() {
    int currentRow = 0;
    int currentCol = 0;
    int count = 0;

    // Print top row of board
    for (int t = 0; t < 37; t++) {
        if (count % 4 == 0 && count != 0 && count < 34) {
            cout << currentCol;
            currentCol++;
        } else {
        cout << "-";
        }
        count++;
    }
    cout << endl;

    // Want to print letter coordinates at start of each row
    for (int i = 0; i < 8; i++) {
        cout << static_cast<char>(letterMap[i]) << " | ";
        for (int ii = 0; ii < 8; ii++) {
            cout << gameBoard[i][ii] << " | ";
        }
        cout << endl;
    }
}