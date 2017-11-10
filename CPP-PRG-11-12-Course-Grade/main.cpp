//
//  main.cpp
//  CPP-PRG-11-12-Course-Grade
//
//  Created by Keith Smith on 11/10/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that uses a structure to store the following data:
//
//      Member Name             Description
//      -------------------------------------------------------
//      Name                    Student name
//      Idnum                   Student ID number
//      Tests                   Pointer to an array of test scores
//      Average                 Average test score
//      Grade                   Course grade
//
//  The program should keep a list of test scores for a group of students. It should ask the
//  user how many test scores there are to be and how many students there are. It should
//  then dynamically allocate an array of structures. Each structure's Tests number
//  should point to a dynamically allocated array that will hold the test scores.
//
//  After the arrays have been dynamically allocated, the program should ask for the ID
//  number and all the test scores for each student. The average test score should be
//  calculated and stored in the average member of each structure. The course grade should
//  be computed on the basis of the following grading scale:
//
//      Average Test Grade          Course Grade
//      ----------------------------------------
//      91-100                      A
//      81-90                       B
//      71-80                       C
//      61-70                       D
//      60 or below                 F
//
//  The course grade should then be stored in the Grade member of each structure. Once
//  all this data is calculated, a table should be displayed on the screen listing each
//  student's name, ID number, average test score, and course grade.
//

#include <iostream>

using namespace std;

int main()
{
    return 0;
}
