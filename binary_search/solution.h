#pragma once

#include <vector>
using namespace std;

class Solution {
public:
    // Problem 1300. Sum of Mutated Array Closest to Target
    int findBestValue(const vector<int>& arr, int target);
private:
    int findBestValueHelper_findSum(const vector<int> & arr, int mid);
};