//
//  main.cpp
//  8_Puzzle
//
//  Created by David Zhu on 2/14/17.
//  Copyright © 2017 David Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Puzzle
{
public:
    vector<char> grid;
    void operator=(const Puzzle& p);
    bool validPuzzle();
    void print();
    bool moveBlankDown();
    bool moveBlankLeft();
    bool moveBlankRight();
    bool moveBlankUp();
    
    int blankPos;
};

void Puzzle::operator=(const Puzzle& p)
{
    grid = p.grid;
}


//checks to see if the number of blanks are valid
//Also checks whether or not the puzzle is solvable through the number of inversions done and on what row the blank is on
//Source for puzzle solvability:
bool Puzzle::validPuzzle()
{
    int inversion = 0;
    int sumOfInversions = 0;
    int blankPos = 0;
    int rowPos = sqrt(grid.size());
    bool oddRow = false;
    int blankCount = 0;
    vector<char> dupeCheck = this->grid;
    sort(dupeCheck.begin(), dupeCheck.end());
    for(int i = 0; i < dupeCheck.size()-1; i++)
        if(dupeCheck[i] == dupeCheck[i+1])
            return false;
    for(int i = 0; i < grid.size(); i++)
    {
        if(grid[i] == '*')
            blankCount++;
    }
    if(blankCount != 1)
        return false;
    for(int i = 0; i < grid.size()-1; i++)
    {
        if(grid[i] == '*')
            blankPos = i;
        for(int j = i+1; j < grid.size(); j++)
        {
            if(grid[i] != '*' && grid[j] != '*')
                if(grid[i] > grid[j])
                    inversion++;
        }
        sumOfInversions += inversion;
        inversion = 0;
    }
    for(int i = 0; i < sqrt(grid.size()); i++)
    {
        if(blankPos < rowPos)
            break;
        rowPos += sqrt(grid.size());
        oddRow = !oddRow;
    }
    if(sqrt(grid.size()%2 != 0))
    {
        if(sumOfInversions%2 == 0)
            return true;
    }
    else
    {
        if(oddRow == true)
        {
           if(sumOfInversions%2 == 0)
               return true;
        }
        else
        {
            if(sumOfInversions%2 != 0)
                return true;
        }
    }
    return false;
}

void Puzzle::print()
{
    int endLine = 0;
    for(int i = 0; i < grid.size(); i++)
    {
        cout << grid[i] << " ";
        endLine++;
        if(endLine == (int)sqrt(grid.size()))
        {
            cout << endl;
            endLine = 0;
        }
    }
    cout << endl;
}

bool Puzzle::moveBlankUp()
{
    if(blankPos < (int)sqrt(grid.size()))
        return false;
    swap(grid[blankPos], grid[blankPos-(int)sqrt(grid.size())]);
    blankPos = blankPos - (int)sqrt(grid.size());
    return true;
}

bool Puzzle::moveBlankDown()
{
    if(blankPos > 5)
        return false;
    swap(grid[blankPos], grid[blankPos + (int)sqrt(grid.size())]);
    blankPos = blankPos + (int)sqrt(grid.size());
    return true;
}

bool Puzzle::moveBlankLeft()
{
    if(blankPos == 0 || blankPos == 3 || blankPos == 6)
        return false;
    swap(grid[blankPos], grid[blankPos-1]);
    blankPos--;
    return true;
}

bool Puzzle::moveBlankRight()
{
    if(blankPos == 2 || blankPos == 5 || blankPos == 8)
        return false;
    swap(grid[blankPos], grid[blankPos+1]);
    blankPos++;
    return true;
}

void intro();
Puzzle parsePuzzle(int x = 3);


int main(int argc, const char * argv[]) {
    cout << "how big yo?" << endl;
    int size = 0;
    cin >> size;
    Puzzle myPuzzle = parsePuzzle(size);
    if(myPuzzle.validPuzzle())
        cout << "i am real" << endl;
    else
        cout << "fuck" << endl;
    myPuzzle.print();
    myPuzzle.moveBlankUp();
    myPuzzle.print();
    myPuzzle.moveBlankDown();
    myPuzzle.print();
    myPuzzle.moveBlankLeft();
    myPuzzle.print();
    myPuzzle.moveBlankRight();
    myPuzzle.print();
    return 0;
}


//Program Greeting
void intro()
{
    cout << "Welcome to dzhu006's 8-Puzzle Solver!" << endl;
    cout << "Please enter '1' to use the default puzzle or '2' to enter your own!" << endl;
}

//Takes user input to generate a puzzle.  Converts 0 to be * character
Puzzle parsePuzzle(int length)
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
    return newPuzzle;
}

