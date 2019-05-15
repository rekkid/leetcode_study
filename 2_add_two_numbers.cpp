//
// Created by zj on 5/15/19.
//

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
    */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::ElementsAre;

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

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
  cout << endl;
  ASSERT_THAT(res, ElementsAre(0, 1));
}

