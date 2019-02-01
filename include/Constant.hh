#ifndef CONSTANT_H
#define CONSTANT_H

#include <vector> 

class NumberOfC14
{
    public:
        NumberOfC14();
        ~NumberOfC14();

        void push_back(const int& number);
        std::vector<int>& GetNumberOfC14();

        static std::vector<int> vecNumberOfC14;

};

#endif