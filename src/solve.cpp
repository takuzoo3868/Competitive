#include "main.h"
#include <iostream>

int solve(int num) {
    switch (num) {
        case 1:
            solution001();
            break;
        case 2:
            solution002();
            break;
        case 3:
            solution003();
            break;
        case 4:
            solution004();
            break;
        case 5:
            solution005();
            break;
        case 6:
            solution006();
            break;
        case 7:
            solution007();
            break;
        case 8:
            solution008();
            break;
        case 9:
            solution009();
            break;
        case 10:
            solution010();
            break;
        case 11:
            solution011();
            break;
        default:
            std::cout << "have not solved it yet!!!" << std::endl;
            break;
    }
    return 0;
}