/*
    Author: Zhao Zhang
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Lab 3A

    Write a program east-storage.cpp that asks the user to input a string
    representing the date (in MM/DD/YYYY format), and prints out the East basin storage on that day.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

int main()
{
    // create variables
    std::string date;
    std::string inputDate;
    std::string junk;
    double AUGEVolume;
    // prompts user to input date and opens file
    std::cout << "Enter date: ";
    std::cin >> inputDate;
    std::ifstream data("./Current_Reservoir_Levels.tsv");
    if (data.fail())
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    // gets rid of the first line
    getline(data, junk);
    while (data >> date >> AUGEVolume)
    {
        data.ignore(INT_MAX, '\n');
        if (inputDate == date)
        {
            std::cout << "East basin storage: " << AUGEVolume << " billion gallons" << std::endl;
            data.close();
            return 0;
        }
    }
}