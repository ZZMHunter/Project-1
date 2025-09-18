/*
    Author: Zhao Zhang
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Project 1C

    Write a C++ program named search_by_date.cpp that reads credit card transaction data from a CSV
    file, processes date formats, and calculates the total spending within a specified date range.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <iomanip>

std::string convert(const std::string &input)
{
    int monthSlash = input.find('/');
    int daySlash = input.find('/', monthSlash + 1);
    int month = std::stoi(input.substr(0, monthSlash));
    int day = std::stoi(input.substr(monthSlash + 1, daySlash - (monthSlash + 1)));
    int year = std::stoi(input.substr(daySlash + 1));

    std::ostringstream returnString;
    returnString << std::setfill('0') << std::setw(2) << month << "/"
                 << std::setfill('0') << std::setw(2) << day << "/"
                 << "20" << std::setw(4) << year;
    return returnString.str();
}

int main()
{
    std::string firstDate, secondDate, file, junk, description, category, date, amountStr;
    bool active = false;
    double sum = 0, amount = 0;
    std::cout << "Enter file name: ";
    std::cin >> file;
    std::ifstream data(file);
    if (data.fail())
    {
        std::cerr << "Error cannot open file" << std::endl;
        exit(1);
    }
    std::cout << "Enter start date: ";
    std::cin >> firstDate;
    std::cout << "Enter end date: ";
    std::cin >> secondDate;
    firstDate = convert(firstDate);
    secondDate = convert(secondDate);
    if (firstDate > secondDate)
    {
        std::swap(firstDate, secondDate);
    }
    getline(data, junk);
    while (getline(data, date, ','))
    {
        getline(data, description, ',');
        getline(data, category, ',');
        getline(data, amountStr);
        date = convert(date);
        if (date >= firstDate && date <= secondDate)
        {
            std::cout << date << ", " << description << ", " << category << ", " << amountStr << std::endl;
            amount = std::stod(amountStr);
            sum += amount;
        }
    }
    std::cout << "The sum is " << sum << std::endl;
    data.close();
    return 0;
}