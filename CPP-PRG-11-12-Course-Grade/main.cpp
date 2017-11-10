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
//  Input Validation: Be sure all the data for each student is entered. Do not accept negative
//  numbers for any test score.

#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

struct StructStudent
{
    string strName;
    string strIdnum;
    double *dblTests;
    double dblAverage;
    char chrGrade;
};

int *getTestsNumber();
int *getStudentsNumber();
StructStudent *allocateArraySize(StructStudent *, int *, int *);
StructStudent *requestIDAndTestScores(StructStudent *, int *, int*);
bool *validateIDNumber(string *);
bool *validateName(string *);
StructStudent *calculateAverageTestScore(StructStudent *, int *);
StructStudent *calculateLetterGrade(StructStudent *);
void displayResults(StructStudent *, int *, int *);


int main()
{
    int *intNumberTests = nullptr;
    intNumberTests = new int;
    
    int *intNumberStudents = nullptr;
    intNumberStudents = new int;
    
    intNumberTests = getTestsNumber();
    intNumberStudents = getStudentsNumber();
    
    StructStudent *ssStudents = nullptr;
    ssStudents = new StructStudent[*intNumberStudents];
    
    ssStudents = allocateArraySize(ssStudents, intNumberStudents, intNumberTests);
    
    ssStudents = requestIDAndTestScores(ssStudents, intNumberStudents, intNumberTests);
    
    for (int i = 0 ; i < *intNumberStudents ; i++)
    {
        ssStudents[i] = *calculateAverageTestScore(&ssStudents[i], intNumberTests);
        ssStudents[i] = *calculateLetterGrade(&ssStudents[i]);
    }
    
    displayResults(ssStudents, intNumberStudents, intNumberTests);
    
    return 0;
}

int *getTestsNumber()
{
    int *intTests = nullptr;
    intTests = new int;
    
    cout << "How many tests scores are there?\n";
    cin >> *intTests;
    while(!cin || *intTests <= 0 || *intTests > 10)
    {
        cout << "Please enter a number of tests between 1 and 10.\n";
        cin.clear();
        cin.ignore();
        cin >> *intTests;
    }
    
    return intTests;
}

int *getStudentsNumber()
{
    int *intStudents = nullptr;
    intStudents = new int;
    
    cout << "How many students are there?\n";
    cin >> *intStudents;
    while(!cin || *intStudents <= 0 || *intStudents > 10)
    {
        cout << "Please enter a number of tests between 1 and 10.\n";
        cin.clear();
        cin.ignore();
        cin >> *intStudents;
    }
    
    return intStudents;
}

StructStudent *allocateArraySize(StructStudent *ssStudents, int *intStudents, int *intTests)
{
    for (int i = 0 ; i < *intStudents ; i++)
    {
        ssStudents[i].dblTests = new double[*intTests];
    }
    
    return ssStudents;
}

StructStudent *requestIDAndTestScores(StructStudent *ssStudents, int *intStudents, int *intTests)
{
    string *strTemp = nullptr;
    strTemp = new string;
    
    double *dblTemp;
    dblTemp = new double;
    
    for (int i = 0 ; i < *intStudents ; i++)
    {
        cout << "Please enter student #" << (i + 1) << "\'s 4-digit ID number:\n";
        cin.clear();
        cin.ignore();
        getline(cin, *strTemp);
        while (strTemp->length() > 4 || !*validateIDNumber(strTemp))
        {
            cout << "Please enter a valid 4-digit ID number:\n";
            cin.clear();
            getline(cin, *strTemp);
        }
        ssStudents[i].strIdnum = *strTemp;
        
        cout << "Please enter the name for student ID #" << ssStudents[i].strIdnum << ".\n";
        cin.clear();
//        cin.ignore();
        getline(cin, *strTemp);
        while (!*validateName(strTemp))
        {
            cout << "Please enter a valid name:\n";
            cin.clear();
//            cin.ignore();
            getline(cin, *strTemp);
        }
        ssStudents[i].strName = *strTemp;
        
        for (int j = 0 ; j < *intTests ; j++)
        {
            cout << "Please enter test score #" << (j + 1) << ".\n";
            cin >> *dblTemp;
            while (!cin || *dblTemp < 0 || *dblTemp > 100)
            {
                cout << "Please enter a test score between 0 and 100.\n";
                cin.clear();
                cin.ignore();
                cin >> *dblTemp;
            }
            
            ssStudents[i].dblTests[j] = *dblTemp;
        }
    }
    
    return ssStudents;
}

bool *validateIDNumber(string *strID)
{
    bool *booIsValid = nullptr;
    booIsValid = new bool;
    *booIsValid = false;
    
    if (strID->length() == 4)
    {
        for (int i = 0 ; i < strID->length() ; i++)
        {
            if(isdigit(strID->at(i)) == true)
            {
                *booIsValid = true;
            }
            else if(isdigit(strID->at(i)) == false)
            {
                *booIsValid = false;
                break;
            }
        }
    }
    
    return booIsValid;
}

bool *validateName(string *strName)
{
    bool *booIsValid = nullptr;
    booIsValid = new bool;
    *booIsValid = false;
    
    for (int i = 0 ; i < strName->length() ; i++)
    {
        if (isalpha(strName->at(i)) == false)
        {
            *booIsValid = false;
            break;
        }
        else if (isalpha(strName->at(i)) == true)
        {
            *booIsValid = true;
        }
    }
    
    return booIsValid;
}

StructStudent *calculateAverageTestScore(StructStudent *ssStudent, int *intTests)
{
    double *dblRunningTotal = nullptr;
    dblRunningTotal = new double;
    *dblRunningTotal = 0.0;
    
    for (int i = 0 ; i < *intTests ; i++)
    {
        *dblRunningTotal += ssStudent->dblTests[i];
    }
    
    *dblRunningTotal /= *intTests;
    
    ssStudent->dblAverage = *dblRunningTotal;
    
    return ssStudent;
}

StructStudent *calculateLetterGrade(StructStudent *ssStudent)
{
    if (ssStudent->dblAverage >= 91 && ssStudent->dblAverage <= 100)
    {
        ssStudent->chrGrade = 'A';
    }
    else if (ssStudent->dblAverage >= 81 && ssStudent->dblAverage < 91)
    {
        ssStudent->chrGrade = 'B';
    }
    else if (ssStudent->dblAverage >= 71 && ssStudent->dblAverage < 81)
    {
        ssStudent->chrGrade = 'C';
    }
    else if (ssStudent->dblAverage >= 61 && ssStudent->dblAverage < 71)
    {
        ssStudent->chrGrade = 'D';
    }
    else if (ssStudent->dblAverage >= 0 && ssStudent->dblAverage < 61)
    {
        ssStudent->chrGrade = 'F';
    }
    else
    {
        cout << "ERROR CALCULATING LETTER GRADE\n";
        exit(1);
    }
    
    return ssStudent;
}

void displayResults(StructStudent *ssStudents, int *intStudents, int *intTests)
{
    int intName = 10;
    int intID = 7;
    int intAverage = 7;
    int intGrade = 7;
    
    cout << fixed << showpoint << setprecision(1);
    
    cout << "\nHere are the results from the " << *intStudents << "\'s " << *intTests << " tests.\n";
    
    cout << left << setw(intName) << "Name";
    cout << left << setw(intID) << "ID#";
    cout << left << setw(intAverage) << "Avg.";
    cout << left << setw(intGrade) << "Grade" << endl;
    cout << "-----------------------------\n";
    
    for (int i = 0 ; i < *intStudents ; i++)
    {
        cout << left << setw(intName) << ssStudents[i].strName;
        cout << left << setw(intID) << ssStudents[i].strIdnum;
        cout << left << setw(intAverage) << ssStudents[i].dblAverage;
        cout << left << setw(intGrade) << ssStudents[i].chrGrade;
        cout << endl;
    }
}
