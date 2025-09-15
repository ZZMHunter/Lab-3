/*
    Author: Zhao Zhang
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Lab 3B

    Write a program minmax.cpp that finds the minimum and maximum storage in East basin in 2018.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

int main()
{
    //create variables
    std::string junk;
    std::string date;
    double max;
    double min;
    double AUGEVolume;
    std::ifstream data("./Current_Reservoir_Levels.tsv");
    if (data.fail())
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    //gets rid of the first line
    getline(data, junk);
    max = INT_MIN;
    min = INT_MAX;
    //replaces variables if they are greater or less
    while (data >> date >> AUGEVolume)
    {
        data.ignore(INT_MAX, '\n');
        if (AUGEVolume > max) {
            max = AUGEVolume;
        }
        if (AUGEVolume < min) {
            min = AUGEVolume;
        }
    }
    data.close();
    std::cout << "Minimum storage in East basin: " << min << " billion gallons" << std::endl;
    std::cout << "Maximum storage in East basin: " << max << " billion gallons" << std::endl;
    return 0;
}