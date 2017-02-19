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
    Node(){gn = 0;}
    Node(int deep){gn = deep;}
    void operator=(const Node& n);
    int gn;
    int hn;
    Puzzle state;
    Puzzle goalState;
    void getValue(int method);
    int uniform();
    int misplaced();
    int manhattan();
    int totalCost;
    void parsePuzzle(int x = 3);
};

#endif /* Node_hpp */
