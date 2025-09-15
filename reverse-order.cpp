/*
    Author: Zhao Zhang
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Lab 3D

    Write a program reverse-order.cpp which asks the user to input two dates (earlier date then later date).
    The program should report the West basin elevation
    for all days in the interval in the reverse chronological order (from the later date to the earlier).
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

int main()
{
    std::string startDate, endDate, curDate, junk, wElevation;
    double eVol, wVol, eElevation;
    bool active;
    int count = 0;
    std::string set[365];
    std::cout << "Enter earlier date: ";
    std::cin >> startDate;
    std::cout << "Enter later date: ";
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
        if (curDate == startDate)
        {
            active = true;
        }
        if (active)
        {
            set[count] = curDate + " " + wElevation;
            count++;
        }
        if (curDate == endDate)
        {
            active = false;
        }
    }
    for (int i = count - 1; i >= 0; i--)
    {
        std::cout << set[i] << std::endl;
    }
    data.close();
    return 0;
}