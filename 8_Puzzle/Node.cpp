//
//  Node.cpp
//  8_Puzzle
//
//  Created by David Zhu on 2/16/17.
//  Copyright © 2017 David Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Puzzle.hpp"

#include <stdio.h>

using namespace std;
#include "Node.hpp"

int Node::uniform()
{
    return depth;
}

int Node::misplaced()
{
    int counter = 0;
    for(int i = 0; i < goalState.size(); i++)
    {
        if(state.grid[i] != goalState.size())
            counter++;
    }
    return counter;
}

int Node::manhattan()
{
    return 0;
}

int Node::getValue(int method)
{
    if(method == 0)
        return uniform();
    if(method == 1)
        return misplaced();
    return manhattan();
}

