//
// Created by zj on 5/11/19.
//

/*
 *
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
*/

#include <unordered_map>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::ElementsAre;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    //测试
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); ++i) {
        int delta = target - nums[i];
        auto it = numMap.find(delta);
        if (it != numMap.end()) {
            // 找到
            return vector<int>{i, it->second};
        } else {
            numMap[nums[i]] = i;
        }
    }
  }
};

TEST(Solution, foobar)
{
  Solution solution;
  vector<int> nums{2, 7, 11, 15};
  vector<int> res = solution.twoSum(nums, 9);
  for (auto x : res) {
    cout << x << ",";
  }
  ASSERT_THAT(res, ElementsAre(0, 1));
}

