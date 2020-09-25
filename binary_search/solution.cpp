#include "solution.h"
#include <unordered_map>
#include <iterator>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

// Problem 1300. Sum of Mutated Array Closest to Target
int Solution::findBestValue(const vector<int>& arr, int target) {  
    int l = 0;
    int r = 0, sum = 0;
    for(auto i: arr){
        r = max(r, i);
        sum += i;
    }
    if(sum == target)
        return r; 

    int mid = 0;
    int cur_sum = 0;
    while(l < r){
        mid = l + (r - l ) / 2;
        cur_sum =  findBestValueHelper_findSum(arr, mid);
        if(cur_sum == target)
            return mid;
        if(cur_sum < target)
        {
            l = mid + 1;
        }
        else{
            r = mid;

        }

    }
    int s1 = 0, s2 = 0;
    for(auto i: arr){
        s1 += min(i, l - 1);
        s2 += min(i, l);
    }
    return (abs(s1 - target) <= abs(s2 - target) ? l - 1 : l);
}

int Solution::findBestValueHelper_findSum(const vector<int> & arr, int mid){
    size_t res = 0;
    for(auto i: arr){
        res += min(i, mid);
    }
    return res;
}
