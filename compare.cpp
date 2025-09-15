/*
    Author: Zhao Zhang
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Lab 3C

    Write a program compare.cpp that asks the user to input two dates (the beginning and the end of the interval).
    The program should check each day in the interval and report which basin had higher elevation
    on that day by printing “East” or “West”, or print “Equal” if both basins are at the same level.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

int main()
{
    // initialize variables
    std::string startDate, endDate, curDate, junk;
    double eVol, wVol, eElevation, wElevation;
    bool active = false;
    std::cout << "Enter starting date: ";
    std::cin >> startDate;
    std::cout << "Enter ending date: ";
    std::cin >> endDate;
    std::ifstream data("Current_Reservoir_Levels.tsv");
    if (data.fail())
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    getline(data, junk);
    while (data >> curDate >> eVol >> eElevation >> wVol >> wElevation)
    {
        data.ignore(INT_MAX, '\n');
        // sets active to true so while loop will start comparing elevation
        if (curDate == startDate)
        {
            active = true;
        }
        if (active)
        {
            // compare east elevation and west elevation for dates within start and end date
            if (eElevation > wElevation)
            {
                std::cout << "East is higher" << std::endl;
            }
            else if (wElevation > eElevation)
            {
                std::cout << "West is higher" << std::endl;
            }
            else
            {
                std::cout << "Equal" << std::endl;
            }
        }
        // sets active to false so the while loop will stop comparing elevation
        if (curDate == endDate)
        {
            active = false;
        }
    }
    data.close();
    return 0;
}