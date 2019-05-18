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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == NULL && l2 == NULL) {
      return NULL;
    }
    ListNode *result = NULL;
    int carrier = 0;
    ListNode *current = NULL;

    while (l1 != NULL && l2 != NULL) {
      int x = l1->val + l2->val + carrier;
      carrier = x / 10;
      x = x % 10;
      ListNode *node = new ListNode(x);
      if (result == NULL) {
        result = node;
        current = result;
      } else {
        current->next = node;
        current = current->next;
      }

      l1 = l1->next;
      l2 = l2->next;
    }

    ListNode *remain = NULL;
    if (l1 == NULL && l2 != NULL) {
      remain = l2;
    } else if (l1 != NULL && l2 == NULL) {
      remain = l1;
    }

    while (remain != NULL) {
      int x = remain->val + carrier;
      carrier = x / 10;
      x = x % 10;
      ListNode *node = new ListNode(x);
      current->next = node;
      current = current->next;
      remain = remain->next;
    }

    if (carrier == 1) {
      ListNode *node = new ListNode(carrier);
      current->next = node;
    }

    return result;
  }

  ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
    ListNode *result = NULL;
    ListNode *current = NULL;
    int carrier = 0;
    while (l1 != NULL || l2 != NULL) {
      int val1 = 0;
      int val2 = 0;
      if (l1 != NULL) {
        val1 = l1->val;
        l1 = l1->next;
      }
      if (l2 != NULL) {
        val2 = l2->val;
        l2 = l2->next;
      }
      int x = val1 + val2 + carrier;
      carrier = x / 10;
      ListNode *node = new ListNode(x % 10);
      if (result == NULL) {
        result = node;
        current = result;
      } else{
        current->next = node;
        current = current->next;
      }

    }
    if (carrier == 1) {
      current->next = new ListNode(carrier);
    }
    return result;
  }

};

TEST(Solution, foobar)
{
  Solution solution;
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  ListNode *res = solution.addTwoNumbers2(l1, l2);
  while (res != NULL) {
    cout << res->val;
    cout << "<-";
    res = res->next;
  }
  cout << endl;

  l1 = new ListNode(9);
  l1->next = new ListNode(9);
  l1->next->next = new ListNode(9);

  l2 = new ListNode(1);

  res = solution.addTwoNumbers2(l1, l2);
  while (res != NULL) {
    cout << res->val;
    cout << "<-";
    res = res->next;
  }

  cout << endl;
}

