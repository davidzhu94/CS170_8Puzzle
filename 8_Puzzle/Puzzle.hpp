//
//  Puzzle.hpp
//  8_Puzzle
//
//  Created by David Zhu on 2/16/17.
//  Copyright © 2017 David Zhu. All rights reserved.
//

#ifndef Puzzle_hpp
#define Puzzle_hpp

#include <stdio.h>
//#include <vector>

using namespace std;

class Puzzle
{
public:
    vector<char> grid;
    void operator=(const Puzzle& p);
    bool validPuzzle();
    void print();
    bool moveBlankUp();
    bool moveBlankDown();
    bool moveBlankLeft();
    bool moveBlankRight();
    
    int blankPos;
};


#endif /* Puzzle_hpp */
