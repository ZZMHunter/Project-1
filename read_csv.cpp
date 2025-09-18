/*
    Author: Zhao Zhang
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Project 1B

    A credit card report has four columns: Date, Description, Category, and Amount.
    In the following example, date is August 6, 2025, description is XYZ Clinic, where the service was
    performed, category is Healthcare, and amount is 10 dollars.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

int main()
{
    std::string file, description, category, date, junk, amount;
    double total = 0;
    std::cout << "Enter a csv file: ";
    std::cin >> file;
    std::ifstream data(file);
    if (data.fail())
    {
        std::cerr << "Failed to open file";
        exit(1);
    }
    getline(data, junk);
    while (getline(data, date, ','))
    {
        getline(data, description, ',');
        getline(data, category, ',');
        getline(data, amount);
        total += std::stod(amount);
    }
    std::cout << "sum = " << total << std::endl;
    data.close();
    return 0;
}