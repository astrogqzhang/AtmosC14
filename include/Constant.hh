#ifndef CONSTANT_H
#define CONSTANT_H

#include <vector> 

class NumberOfC14
{
    public:
        NumberOfC14() = default;
        ~NumberOfC14() = default;
        void push_back(const int& number);
        std::vector<int>& GetNumberOfC14();

    private:
        static std::vector<int> vecNumberOfC14;

}