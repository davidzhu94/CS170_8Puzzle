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


int main(int argc, const char * argv[]) {
    cout << "how big yo?" << endl;
    int size = 0;
    cin >> size;
    Node root;
    root.parsePuzzle(size);
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


struct compareNode
{
    bool operator()(Node a, Node b)
    {
        return a.totalCost > b.totalCost;
    }
};
