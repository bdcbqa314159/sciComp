#ifndef RANGE_H
#define RANGE_H

#include <valarray>

std::slice range(size_t first, size_t last){
    return std::slice(first, last-first, 1);
}

std::slice range(size_t first, size_t step, size_t last){
    return std::slice(first, (last-first)/step, step);
}

#endif
