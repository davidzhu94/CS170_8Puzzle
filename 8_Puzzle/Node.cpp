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

void Node::operator=(const Node& n)
{
    depth = n.depth;
    state = n.state;
}

int Node::uniform()
{
    return 0;
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

void Node::getValue(int method)
{
    if(method == 0)
        totalCost = uniform() + depth;
    else if(method == 1)
        totalCost = misplaced() + depth;
    else totalCost = manhattan() + depth;
}

//Takes user input to generate a puzzle.  Converts 0 to be * character
void Node::parsePuzzle(int length)
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
    state = newPuzzle;
}


