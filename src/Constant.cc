#include "Constant.hh"
#include <vector>

NumberOfC14::NumberOfC14() {}
NumberOfC14::~NumberOfC14() {}



void NumberOfC14::push_back(const int& number)
{
    vecNumberOfC14.push_back(number);
}

std::vector<int>& NumberOfC14::GetNumberOfC14()
{
    return vecNumberOfC14;
}