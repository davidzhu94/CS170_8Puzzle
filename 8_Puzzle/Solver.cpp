//
//  Solver.cpp
//  8_Puzzle
//
//  Created by David Zhu on 2/16/17.
//  Copyright © 2017 David Zhu. All rights reserved.
//

#include "Solver.hpp"
#include <vector>

void Solver::getGoal()
{
    int method;
    char hold;
    cout << "What goal state?" << endl;
    for(int i = 0; i < root.state.grid.size(); i++)
    {
        cin >> hold;
        if(hold == '0')
        {
            hold = '*';
            goal.state.blankPos = (int)goal.state.grid.size();
        }
        goalState.push_back(hold);
    }
    goal.state.grid = goalState;
    root.goalState = goal.state;
    cout << "What kind of method?" << endl;
    cout << "1 for Uniform" << endl;
    cout << "2 for Misplaced" << endl;
    cout << "3 for Manhattan" << endl;
    cin >> method;
    heuristic = method;
}

bool Solver::checkGoal(Node checkMe)
{
    for(int i = 0; i < checkMe.state.grid.size(); i++)
    {
        if(checkMe.state.grid[i] != goalState[i])
            return false;
    }
    return true;
}

void Solver::expand(Node roots)
{
    Node moveUp = roots;
    Node moveDown = roots;
    Node moveLeft = roots;
    Node moveRight = roots;
    if(!traveledBefore(roots))
    {
        if(moveUp.state.moveBlankUp())
        {
            moveUp.gn++;
            moveUp.goalState = goal.state;
            moveUp.getValue(heuristic);
            frontier.push(moveUp);
        }
        if(moveDown.state.moveBlankDown())
        {
            moveDown.gn++;
            moveDown.goalState = goal.state;
            moveDown.getValue(heuristic);
            frontier.push(moveDown);
        }
        if(moveLeft.state.moveBlankLeft())
        {
            moveLeft.gn++;
            moveLeft.goalState = goal.state;
            moveLeft.getValue(heuristic);
            frontier.push(moveLeft);
        }
        if(moveRight.state.moveBlankRight())
        {
            moveRight.gn++;
            moveRight.goalState = goal.state;
            moveRight.getValue(heuristic);
            frontier.push(moveRight);
        }
    }
    traveled.push_back(roots.state);
}

void Solver::solve()
{
    expand(root);
    while(!frontier.empty())
    {
        frontier.top().state.print();
        cout << "gn is equal to " << frontier.top().gn << "hn is equal to " << frontier.top().hn << endl;
        if(checkGoal(frontier.top()))
           break;
        expand(frontier.top());
        frontier.pop();
    }
   /* while(!frontier.empty())
    {
        frontier.top().state.print();
        frontier.pop();
    }
        */
    cout << "i am done" << endl;
 /*   for(int i = 0; i < traveled.size(); i++)
    {
        traveled[i].print();
    }*/
    /*expand(frontier.top());
    while(!frontier.empty())
    {
        frontier.top().state.print();
        cout << frontier.top().depth << endl;
        //frontier.pop();
    }*/
    
}

bool Solver::traveledBefore(Node check)
{
    for(int i = 0; i < traveled.size(); i++)
    {
        if(check.state.grid == traveled[i].grid)
            return true;
    }
    return false;
}
