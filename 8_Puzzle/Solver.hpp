//
//  Solver.hpp
//  8_Puzzle
//
//  Created by David Zhu on 2/16/17.
//  Copyright © 2017 David Zhu. All rights reserved.
//

#ifndef Solver_hpp
#define Solver_hpp

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include "Node.hpp"
#include <stdio.h>

struct compareNode
{
    bool operator()(Node a, Node b)
    {
        return (a.gn+a.hn) > (b.gn+b.hn);
    }
};

class Solver
{
public:
    Node root;
    Node goal;
    int heuristic = 1;
    int misplaced();
    int assignValue();
    void getGoal();
    bool checkGoal(Node checkMe);
    priority_queue<Node, vector<Node>, compareNode> frontier;
    vector<Puzzle> traveled;
    vector<char> goalState;
    bool traveledBefore(Node check);
    void expand(Node root);
    void solve();

};

#endif /* Solver_hpp */
