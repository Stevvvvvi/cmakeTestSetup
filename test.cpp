#include <stdio.h>
#include "swap.h"
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include <iostream>



int main() {
    int m_a = 1;
    printf("hello linux c++ m_a=%d\n", m_a);
    swap testSwap(m_a, 2);
    testSwap.run();
    testSwap.printInfo();
    testSwap.processJson();
    printf("     /\n");
    printf("    /\n");
    printf("   /\n");
    printf("  /\n");
    printf(" /\n");
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    std::cout << uuid << std::endl;
    return 0;
}
