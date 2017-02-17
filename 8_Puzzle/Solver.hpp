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
        return a.totalCost > b.totalCost;
    }
};

class Solver
{
public:
    Node root;
    priority_queue<Node, vector<Node>, compareNode> frontier;
    void expand(Node root);
    void solve();

};

#endif /* Solver_hpp */
