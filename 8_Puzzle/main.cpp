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
#include <queue>
#include "Puzzle.hpp"
#include "Solver.hpp"


using namespace std;


void intro();


int main(int argc, const char * argv[]) {
    cout << "how big yo?" << endl;
    int size = 0;
    cin >> size;
    Solver me;
    me.root.parsePuzzle(size);
    me.solve();
    return 0;
}


//Program Greeting
void intro()
{
    cout << "Welcome to dzhu006's 8-Puzzle Solver!" << endl;
    cout << "Please enter '1' to use the default puzzle or '2' to enter your own!" << endl;
}

