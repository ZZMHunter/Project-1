/*
    Author: Zhao Zhang
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Project 1A

    Add the data in a Text File with Only One column
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

int main(){
    std::string file;
    double sum;
    double num;
    std::cout << "Enter a file name: ";
    std::cin >> file;
    std::ifstream data(file);
    while(data>>num){
        sum+=num;
    }
    std::cout << "sum = " << sum << std::endl;
    return 0;
}