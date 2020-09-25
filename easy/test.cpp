#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file
#include <boost/test/unit_test.hpp>
#include "solution.h"
using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE( decompressRLElist_test ){
    Solution sol;
    auto res = sol.decompressRLElist(vector({1,2,3,4}));
    vector<int> exp{2, 4, 4, 4};
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.decompressRLElist(vector({1,1,2,3}));
     exp = vector({1, 3, 3});
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.decompressRLElist(vector({1,1,1,2}));
     exp = vector({1, 2});
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.decompressRLElist(vector({1,1,5,1}));
     exp = vector({1, 1,1,1,1,1});
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());
}

BOOST_AUTO_TEST_CASE( numberOfSteps_test )
{
    Solution sol;
    BOOST_CHECK_EQUAL(sol.numberOfSteps(0), 0);
    BOOST_CHECK_EQUAL(sol.numberOfSteps(1), 1);
    BOOST_CHECK_EQUAL(sol.numberOfSteps(2), 2);
    BOOST_CHECK_EQUAL(sol.numberOfSteps(3), 3);
    BOOST_CHECK_EQUAL(sol.numberOfSteps(4), 3);
    BOOST_CHECK_EQUAL(sol.numberOfSteps(5), 4);
    BOOST_CHECK_EQUAL(sol.numberOfSteps(6), 4);
    BOOST_CHECK_EQUAL(sol.numberOfSteps(7), 5);
    BOOST_CHECK_EQUAL(sol.numberOfSteps(8), 4);
    BOOST_CHECK_EQUAL(sol.numberOfSteps(9), 5);
    BOOST_CHECK_EQUAL(sol.numberOfSteps(10), 5);
    BOOST_CHECK_EQUAL(sol.numberOfSteps(11), 6);
    BOOST_CHECK_EQUAL(sol.numberOfSteps(12), 5);
    BOOST_CHECK_EQUAL(sol.numberOfSteps(14), 6);
    BOOST_CHECK_EQUAL(sol.numberOfSteps(123), 12); 
}


BOOST_AUTO_TEST_CASE( smallerNumbersThanCurrent2_test )
{
    Solution sol;
    auto res = sol.smallerNumbersThanCurrent(vector({0}));
    vector exp{0};
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end()); 

    res = sol.smallerNumbersThanCurrent(vector({0, 1}));
    exp = vector({0, 1});
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.smallerNumbersThanCurrent(vector({4, 4, 4, 4}));
    exp = vector{0, 0, 0, 0};
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.smallerNumbersThanCurrent(vector({8,1,2,2,3}));
    exp = vector{4,0,1,1,3};
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.smallerNumbersThanCurrent(vector({6,5,4,8}));
    exp = vector{2, 1, 0, 3};
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.smallerNumbersThanCurrent(vector({1, 2, 3, 4, 5, 6, 7, 8}));
    exp = vector{0, 1, 2, 3, 4, 5, 6, 7};
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());
}

BOOST_AUTO_TEST_CASE( createTargetArray_test ){
    Solution sol;
    auto res = sol.createTargetArray(vector({0,1,2,3,4}), vector({0,1,2,2,1}));
    vector<int> exp{0,4,1,3,2};
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.createTargetArray(vector({1,2,3,4,0}), vector({0,1,2,3,0}));
    exp = vector({0,1,2,3,4});
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());
   
    res = sol.createTargetArray(vector({4,2,4,3,2}), vector({0,0, 1, 3, 1}));
    exp = vector({2,2,4,4,3});
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());
}

BOOST_AUTO_TEST_CASE( kidsWithCandies_test )
{
    Solution sol;
    auto res = sol.kidsWithCandies(vector({2,3,5,1,3}), 3);
    vector exp{true, true, true, false, true};
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end()); 

    res = sol.kidsWithCandies(vector({4,2,1,1,2}), 1);
    exp = vector({true,false,false,false,false});
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end()); 

    res = sol.kidsWithCandies(vector({12,1,12}), 10);
    exp = vector({true,false,true});
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end()); 
}

BOOST_AUTO_TEST_CASE( shuffle_test )
{
    Solution sol;
    auto res = sol.shuffle(vector{1, 2}, 1);
    vector exp{1, 2};
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.shuffle(vector{0,1,2,3}, 2);
    exp = vector{0, 2, 1, 3};
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.shuffle(vector{2,5,1,3,4,7}, 3);
    exp = vector{2, 3, 5, 4, 1, 7};
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.shuffle(vector{1,2,3,4,4,3,2,1}, 4);
    exp = vector{1,4,2,3,3,2,4,1};
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.shuffle(vector{1,1,2,2}, 2);
    exp = vector{1, 2, 1, 2};
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());
}

BOOST_AUTO_TEST_CASE( runningSum_test )
{
    Solution sol;
    auto res = sol.runningSum({1, 2, 3, 4});
    vector exp{1,3,6,10};
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.runningSum({1,1,1,1,1});
    exp = vector({1,2,3,4,5});
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.runningSum({3,1,2,10,1});
    exp = vector({3,4,6,16,17});
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.runningSum({3});
    exp = vector({3});
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());

    res = sol.runningSum({0,0,0,0,1});
    exp = vector({0,0,0,0,1});
    BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), exp.begin(), exp.end());
}

BOOST_AUTO_TEST_CASE( findLeastNumOfUniqueInts_test ){
    Solution sol;
    auto res = sol.findLeastNumOfUniqueInts(vector({5,5,4}), 1);
    BOOST_CHECK_EQUAL(res, 1);

    res = sol.findLeastNumOfUniqueInts(vector({4,3,1,1,3,3,2}), 3);
    BOOST_CHECK_EQUAL(res, 2);

    res = sol.findLeastNumOfUniqueInts(vector({1,1,1,1,1,1}), 3);
    BOOST_CHECK_EQUAL(res, 1);

    res = sol.findLeastNumOfUniqueInts(vector({1,1,1,2}), 3);
    BOOST_CHECK_EQUAL(res, 1);

    res = sol.findLeastNumOfUniqueInts(vector({1,1,1,2,2}), 3);
    BOOST_CHECK_EQUAL(res, 1);

    res = sol.findLeastNumOfUniqueInts(vector({1,1,1,2,2}), 4);
    BOOST_CHECK_EQUAL(res, 1);

    res = sol.findLeastNumOfUniqueInts(vector({1,1,1,2}), 4);
    BOOST_CHECK_EQUAL(res, 0);

    res = sol.findLeastNumOfUniqueInts(vector({1,1,1,2,3,4,5,6}), 7);
    BOOST_CHECK_EQUAL(res, 1);
}

BOOST_AUTO_TEST_CASE( numberOfGoodPairs_test ){
    Solution sol;
    auto res = sol.numberOfGoodPairs(vector({1,2,3,1,1,3}));
    BOOST_CHECK_EQUAL(res, 4);

    res = sol.numberOfGoodPairs(vector({1,1,1,1}));
    BOOST_CHECK_EQUAL(res, 6);

    res = sol.numberOfGoodPairs(vector({1,2,3}));
    BOOST_CHECK_EQUAL(res, 0);

     res = sol.numberOfGoodPairs(vector({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}));
    BOOST_CHECK_EQUAL(res, 153);
}