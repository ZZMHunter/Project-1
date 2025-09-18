/*
    Author: Zhao Zhang
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Project 1E

    Read a csv file, and list all available categories labelled 0 through x, and ask the user to
    input a category by the label, and calculate the monthly totals for that category.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <algorithm>

int month(std::string input){
    int monthSlash = input.find('/');
    return std::stoi(input.substr(0, monthSlash));
}

std::string categorySeperator(std::string input){
    int period = input.find('.');
    return input.substr(period+1);
}

int main(){
    std::string monthArr[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    std::string day, store, category, cost, junk, file, chosenCategory, line;
    std::string categoryArray[20];
    std::vector<std::string> categories;
    double total, monthArray[12] = {0};
    int count, choice;
    bool active = false;
    count = 0;
    std::cout << "Enter a csv file name: ";
    std::cin >> file;
    std::ifstream data(file);
    if(data.fail()){
        std::cerr << "Error, cannot open file" << std::endl;
        exit(1);
    }
    getline(data,junk);
    while(getline(data,day,',')){
        getline(data,store,',');
        getline(data,category,',');
        getline(data,cost);
        for (int i = 0; i < 20; i ++){
            if (category == categorySeperator(categoryArray[i])){
                active = false;
            }
        }
        if (active) {
            categories.push_back(category);
            categoryArray[count] = category;
            count++;
        }
        active = true;
    }
    std::cout << std::endl; 
    std::sort(categories.begin(), categories.end());
    for (int i = 0; i < count; i++){
        categoryArray[i] = categories[i];
        categoryArray[i] = std::to_string(i)+"."+categoryArray[i];
        std::cout << categoryArray[i] << std::endl;
    }
    std::cout << "Choose a number in " << "[0, " << count-1 << "]: ";
    std::cin >> choice;
    data.close();
    data.open(file);
    getline(data, junk);
    while(getline(data,day,',')){
        getline(data,store,',');
        getline(data,category,',');
        getline(data,cost);
        if(category == categorySeperator(categoryArray[choice])){
            monthArray[month(day)-1] += std::stod(cost);
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < 12; i++){
        std::cout << monthArr[i] <<  monthArray[i] << std::endl;
    }
    data.close();
    return 0;
}