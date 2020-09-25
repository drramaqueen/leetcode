#pragma once

#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    //problem 1313. Decompress Run-Length Encoded List
    vector<int> decompressRLElist(const vector<int>& nums);

    // Problem 1342. Number of Steps to Reduce a Number to Zero
    int numberOfSteps (int num);

    // Problem 1365. How Many Numbers Are Smaller Than the Current Number
    vector<int> smallerNumbersThanCurrent(const vector<int>& nums);
    vector<int> smallerNumbersThanCurrent2(const vector<int>& nums);

    // Problem 1389. Create Target Array in the Given Order
    vector<int> createTargetArray(const vector<int>& nums, const vector<int>& index); 
    vector<int> createTargetArray2(const vector<int>& nums, const vector<int>& index);

    // Problem 1431. Kids With the Greatest Number of Candies
    vector<bool> kidsWithCandies(const vector<int>& candies, int extraCandies);

    // Problem 1470. Shuffle the Array
    vector<int> shuffle(const vector<int>& nums, int n);

    // Problem 1480. Running Sum of 1d Array
    vector<int> runningSum (const vector<int>& nums);

    // Problem 1481. Least Number of Unique Integers after K Removals
    int findLeastNumOfUniqueInts(const vector<int>& arr, int k);

    // Problem 1512. Number of Good Pairs
    int numberOfGoodPairs(const vector<int>& nums);

    // Problem 1528. Shuffle String
    string restoreString(const string& s, const vector<int>& indices);

};