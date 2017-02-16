//
//  main.cpp
//  8_Puzzle
//
//  Created by David Zhu on 2/14/17.
//  Copyright © 2017 David Zhu. All rights reserved.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Puzzle.hpp"
#include "Node.hpp"

using namespace std;


void intro();
Puzzle parsePuzzle(int x = 3);


int main(int argc, const char * argv[]) {
    cout << "how big yo?" << endl;
    int size = 0;
    cin >> size;
    Node root;
    root.state = parsePuzzle(size);
    if(root.state.validPuzzle())
        cout << "i am real" << endl;
    else
        cout << "fuck" << endl;
    root.state.print();
    root.state.moveBlankUp();
    root.state.print();
    root.state.moveBlankDown();
    root.state.print();
    root.state.moveBlankLeft();
    root.state.print();
    root.state.moveBlankRight();
    root.state.print();
    return 0;
}


//Program Greeting
void intro()
{
    cout << "Welcome to dzhu006's 8-Puzzle Solver!" << endl;
    cout << "Please enter '1' to use the default puzzle or '2' to enter your own!" << endl;
}

//Takes user input to generate a puzzle.  Converts 0 to be * character
Puzzle parsePuzzle(int length)
{
    Puzzle newPuzzle;
    char holder;
    cout << "To enter your puzzle, please type the numbers (seperated by spaces) that you want per row, with 0 indicating the blank space" << endl;
    for(int j = 0; j < length; j++)
    {
        cout << "Please enter row number " << j+1 << endl;
        for(int i = 0; i < length; i++)
        {
            cin >> holder;
            if(holder == '0')
            {
                holder = '*';
                newPuzzle.blankPos = (int)newPuzzle.grid.size();
            }
            newPuzzle.grid.push_back(holder);
        }
    }
    return newPuzzle;
}

