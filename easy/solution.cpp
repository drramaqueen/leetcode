#include "solution.h"
#include <unordered_map>
#include <iterator>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

// Problem 1313. Decompress Run-Length Encoded List
vector<int> Solution::decompressRLElist(const vector<int>& nums) {
        vector<int> res;
    for(int i = 0; i < nums.size(); i += 2){
        for(int j = 0; j < nums[i]; ++j)
            res.emplace_back(nums[i + 1]);
    }
    return res;
}

// Problem 1342. Number of Steps to Reduce a Number to Zero
int Solution::numberOfSteps (int num) {
    int result = 0;
    int tmp;
    while(num != 0){
        tmp = num;
        num /= 2; 
        if(tmp % 2 == 1 && tmp != 1){
            result += 2;
        }
        else{
            result += 1;
        }
    }
    return result;
}

// Problem 1365. How Many Numbers Are Smaller Than the Current Number
vector<int> Solution::smallerNumbersThanCurrent(const vector<int>& nums){
    vector result(nums.size(), 0);

    vector count(101, 0);
    for(int i = 0; i < nums.size(); ++i){
        count[nums[i]]++;
    }
    int i = 0;
    while(count[i] == 0)
        ++i;
    int prev = count[0];
    count[0] = 0;
    int tmp = 0;
    for(int j = 1; j <= 100; ++j){
        tmp = count[j];
        count[j] = count[j - 1] + prev;        
        prev = tmp;
    }
    for(i = 0; i < nums.size(); ++i){
        result[i] = count[nums[i]];
    }
    return result;
}

// Problem 1365 (2). How Many Numbers Are Smaller Than the Current Number
vector<int> Solution::smallerNumbersThanCurrent2(const vector<int>& nums){
    vector result(nums.size(), 0);
    vector sorted(nums);
    if(nums.empty())
        return {};
    sort(sorted.begin(), sorted.end());
    unordered_map<int, int> m;
    int prev = 0;
    for(int i = 0; i < sorted.size(); ++i){
        if(m.count(sorted[i]) == 0){
            m[sorted[i]] = i;
        }
    }
    for(int i = 0; i < nums.size(); ++i){
            result[i] = m[nums[i]];
    }
    return result;
}

// Problem 1389. Create Target Array in the Given Order
vector<int> Solution::createTargetArray(const vector<int>& nums, const vector<int>& index){
    vector<int> res;
    for(int i = 0; i < index.size(); ++i){
        res.insert(res.begin() + index[i], nums[i]);
    }
    return res;
}

// Problem 1389 (2). Create Target Array in the Given Order
vector<int> Solution::createTargetArray2(const vector<int>& nums, const vector<int>& index){
    vector<int> res(index.size());
    set<int> has_met;
    vector<int> modified_index(index.size());
    for(int i = 0; i < index.size(); ++i){
        modified_index[i] = index[i];
        if(has_met.count(index[i]))
            for(int j = 0; j < i; ++j){
                if(index[i] <= modified_index[j])
                    has_met.insert(++modified_index[j]);
            }
        else
            has_met.insert(index[i]);        
    }
    for(int i = 0; i < index.size(); ++i)
        res[modified_index[i]] = nums[i];
    return res;
}

// Problem 1431. Kids With the Greatest Number of Candies
vector<bool> Solution::kidsWithCandies(const vector<int>& candies, int extraCandies) {
    vector<bool> res;
    int max = *std::max_element(candies.begin(), candies.end());
    for(auto e: candies){
        if(e + extraCandies >= max)
            res.emplace_back(true);
        else 
            res.emplace_back(false);
    }
    return res;
}

// Problem 1470. Shuffle the Array
vector<int> Solution::shuffle(const vector<int>& nums, int n) {
    vector<int> result(n * 2);
    for(int i = 0; i < n; ++i){
        result[i * 2] = nums[i];
        result[i * 2 + 1] = nums[n + i];
    }
    return result;
}

// Problem 1480. Running Sum of 1d Array
vector<int> Solution::runningSum(const vector<int>& nums) {
    vector<int> res(nums.size());
    res[0] = nums[0];
    for(int i = 1; i < res.size(); ++i){
        res[i] = nums[i] + res[i - 1];
    }
    return res;        
}

// Problem 1481. Least Number of Unique Integers after K Removals
int Solution::findLeastNumOfUniqueInts(const vector<int>& arr, int k) {
    if(k == arr.size())
        return 0;
    unordered_map<int, int> hash_count;
    for(auto s: arr){
        hash_count[s]++;
    }
    multimap<int, int> m;
    for(auto& p: hash_count){
        m.insert(pair(p.second, p.first));
    }
    for(auto it = m.begin(); it != m.end(); ){
        if( k >= it->first){
            k -= it->first;
            m.erase(it++);   
        }
        else{
            return m.size();
        }
    }
    return 0;
}

// Problem 1512. Number of Good Pairs
int Solution::numberOfGoodPairs(const vector<int>& nums){
    map<int, int> count;
    for(auto n: nums){
        count[n]++;
    }
    size_t res = 0;
    for(auto&[n, c]: count){
        if(c % 2 == 0){
            res += c / 2 * (c - 1);
        }
        else{
            res += (c - 1) / 2 * c;
        }
    }
    return res; 
}

// Problem 1528. Shuffle String
string Solution::restoreString(const string& s, const vector<int>& indices){
    vector<char> res(indices.size());
    for(int i = 0; i < indices.size(); ++i){
        res[indices[i]] = s[i];
    }
    return string(res.begin(), res.end());
}

