#include "Constant.hh"
#include <vector>

std::vector<int> NumberOfC14::vecNumberOfC14;

NumberOfC14::NumberOfC14() {}
NumberOfC14::~NumberOfC14() {}



void NumberOfC14::push_back(const int& number)
{
    this->vecNumberOfC14.push_back(number);
}

std::vector<int>& NumberOfC14::GetNumberOfC14()
{
    return this->vecNumberOfC14;
}