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
    gn = n.gn;
    state = n.state;
}

int Node::uniform()
{
    return 0;
}

int Node::misplaced()
{
    int counter = 0;
    for(int i = 0; i < state.grid.size(); i++)
    {
        if(state.grid[i] != goalState.grid[i])
            counter++;
        cout << "i am looking at " << state.grid[i] << " and comparing to  " << goalState.grid[i] << endl;
            
    }
    cout << "MISPLACED TILE COUNT == " << counter << endl;
    return counter;
}

int Node::manhattan()
{
    return 0;
}

void Node::getValue(int method)
{
    if(method == 1)
        hn = uniform();
    else if(method == 2)
    {
        hn = misplaced();
    }
    else hn = manhattan();
    //totalCost = hn + gn;
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


