/*
    Author: Zhao Zhang
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Project 1D

    You are given credit card transactions covering at most 12 months. Write code to calculate the total
    spending for each month.
*/

#include <iostream>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <iomanip>

int month(std::string input){
    int monthSlash = input.find('/');
    return (std::stoi(input.substr(0, monthSlash)));
}

int main(){
    std::string date, description, category, amount, junk, file;
    double array[12];
    std::string monthArr[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int index;
    for (int i = 0; i < 12; i++){
        array[i] = 0;
    }
    std::cout << "Enter a csv file name for credit card information: ";
    std::cin >> file;
    std::ifstream data(file);
     if (data.fail())
    {
        std::cerr << "Error cannot open file" << std::endl;
        exit(1);
    }
    getline(data, junk);
    while(getline(data, date, ',')){
        getline(data, description, ',');
        getline(data, category, ',');
        getline(data, amount);
        array[month(date)] += std::stod(amount);
    }
    for (int i = 0; i < 12; i++){
        std::cout << monthArr[i] << ", $" << array[i] << std::endl;
    }
    data.close();
    return 0;
}