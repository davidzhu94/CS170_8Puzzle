//
//  Solver.cpp
//  8_Puzzle
//
//  Created by David Zhu on 2/16/17.
//  Copyright © 2017 David Zhu. All rights reserved.
//

#include "Solver.hpp"

void Solver::expand(Node root)
{
    Node moveUp = root;
    Node moveDown = root;
    Node moveLeft = root;
    Node moveRight = root;
    if(moveUp.state.moveBlankUp())
    {
        frontier.push(moveUp);
    }
    if(moveDown.state.moveBlankDown())
    {
        frontier.push(moveDown);
    }
    if(moveLeft.state.moveBlankLeft())
    {
        frontier.push(moveLeft);
    }
    if(moveRight.state.moveBlankRight())
    {
        frontier.push(moveRight);
    }
}

void Solver::solve()
{
    expand(root);
    while(!frontier.empty())
    {
        frontier.top().state.print();
        frontier.pop();
    }
    
    
}
