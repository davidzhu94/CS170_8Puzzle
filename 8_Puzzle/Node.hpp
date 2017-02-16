//
//  Node.hpp
//  8_Puzzle
//
//  Created by David Zhu on 2/16/17.
//  Copyright © 2017 David Zhu. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include "Puzzle.hpp"

#include <stdio.h>

using namespace std;

class Node
{
public:
    vector<char> goalState;
    int depth;
    Puzzle state;
    int getValue(int method);

    int uniform();
    int misplaced();
    int manhattan();
};

#endif /* Node_hpp */
