#pragma once
#include <vector>

template<typename T>
int FibonacciSearch(const std::vector<T>& list, const T& element, int(*pEqual)(const T&, const T&));