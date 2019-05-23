//
// Created by zj on 5/18/19.
//

/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"


using namespace std;
using ::testing::ElementsAre;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int count = 0;
    if (s.length() == 0) {
      return 0;
    }
    int dp[s.length()];
    for (int i = 0; i < s.length(); i++) {
        dp[i] = 0;
    }

    unordered_map<char, int> charmap;
    dp[0] = 1;
    charmap[s[0]] = 0;

    for (int i = 1; i < s.length(); i++) {
      if (charmap.find(s[i]) == charmap.end()) {
        charmap[s[i]] = i;
        dp[i] = max(dp[i - 1], int(charmap.size()));
      } else{
        int k = charmap[s[i]] - 1;
        int len = charmap.size();
        for (int k = charmap[s[i]] - 1; k >= i - len; k--) {
          charmap.erase(s[k]);
        }
        charmap[s[i]] = i;
        dp[i] = dp[i - 1];
      }
    }

    for (int i = 0; i < s.length(); i++) {
      cout << i << ":" << dp[i] << endl;
    }

    return dp[s.length() - 1];
  }
};

TEST(Solution, lengthOfLongestSubstring)
{
  Solution solution;

  int res = solution.lengthOfLongestSubstring("qrsvbspk");
  EXPECT_EQ(res, 5);

  res = solution.lengthOfLongestSubstring("bpfbhmipx");
  EXPECT_EQ(res, 7);

  res = solution.lengthOfLongestSubstring("aabaab!bb");
  EXPECT_EQ(res, 3);

  res = solution.lengthOfLongestSubstring("bbbbb");
  EXPECT_EQ(res, 1);

  res = solution.lengthOfLongestSubstring("pwwkew");
  EXPECT_EQ(res, 3);
}
