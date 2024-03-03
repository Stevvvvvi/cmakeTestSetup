#pragma once
#include <iostream>

class swap
{
private:
    int m_a;
    int m_b;
public:
    swap(int a, int b)
    {
        this->m_a=a;
        this->m_b=b;
    }
    void run();
    void printInfo();
    void processJson();
};
