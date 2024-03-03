#include <stdio.h>
#include "swap.h"



int main() {
    int m_a = 1;
    printf("hello linux c++ m_a=%d\n", m_a);
    swap testSwap(m_a, 2);
    testSwap.run();
    testSwap.printInfo();
    testSwap.processJson();
    return 0;
}
