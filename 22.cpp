//
// Created by zj on 5/11/19.
//


/*
 *
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]

 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
 public:
  int n_;
  vector<string> results_;
  string res_;
  vector<string> generateParenthesis(int n) {
    n_ = n;
//    gen(0, 0);
    string res;
    gen2(0, 0, res);
    return results_;
  }

  void gen(int l, int r) {
    if (l == n_ && r == n_) {
      results_.push_back(res_);
      return;
    }
    if (l == r) {
      res_.push_back('(');
      gen( l + 1, r);
      res_.pop_back();
    } else if (l > r && l == n_) {
      res_.push_back(')');
      gen(l, r + 1);
      res_.pop_back();
    } else if (l > r && l < n_) {
      res_.push_back('(');
      gen(l + 1, r);
      res_.pop_back();
      res_.push_back(')');
      gen(l, r + 1);
      res_.pop_back();
    }
  }

  void gen1(int l, int r, string res) {
    if (l == n_ && r == n_) {
      results_.push_back(res);
      return;
    }
    if (l < n_) {
      gen1(l + 1, r, res + "(");
    }

    if (l > r && r < n_) {
      gen1(l, r + 1, res + ")");

    }
  }

  void gen2(int l, int r, string &res) {
    if (l == n_ && r == n_) {
      results_.push_back(res);
      return;
    }

    if (l < n_) {
      res.push_back('(');
      gen2(l + 1, r, res);
      res.pop_back();
    }

    if (r < n_ && r < l) {
      res.push_back(')');
      gen2(l, r + 1, res);
      res.pop_back();
    }
  }
};

int main() {
  Solution solution;
  vector<string> res = solution.generateParenthesis(3);
  for (auto a : res) {
    cout << a;
    cout << "\n";
  }
  return 0;
}
