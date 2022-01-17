/*
 * Copyright (c) 2022 Joakim Nohlgård
 */

#include "deri/forward_list.hpp"
#include "deri/unit_test.hpp"

using namespace deri::literals;

namespace deri::test {

struct TestListNode : deri::ForwardListNode<TestListNode> {
  int value{};
};
using TestList = ForwardList<TestListNode>;

void test_forward_list() {
  "ForwardList"_test = [] {
    TestList my_list{};
    std::array<TestListNode, 5> items;
    "Empty list"_test = [&] { check % my_list.empty(); };
    "Pushing/popping"_test = [&] {
      "Single item"_test = [&] {
        TestListNode item{.value = 1234};
        my_list.push_front(item);
        check % !my_list.empty();
        check % &my_list.front() == &item;
        check % my_list.front().value == 1234;
        my_list.pop_front();
        check % my_list.empty();
        check % item.value == 1234;
      };
      "Multiple items"_test = [&] {
        check % my_list.empty();
        for (auto &&item : items) {
          my_list.push_front(item);
          check % !my_list.empty();
        }
        // popping in reverse order
        for (auto it = rbegin(items); it != rend(items); ++it) {
          check % &my_list.front() == &(*it);
          my_list.pop_front();
        }
        check % my_list.empty();
      };
    };
    "Iterating"_test = [&] {
      for (auto &&item : items) {
        my_list.push_front(item);
      }
      "Iteration order is reverse insertion order"_test = [&] {
        // We are replacing the head of the list with each push, so the
        // iteration order will be reversed.
        int k = 0;
        for (auto &&node : my_list) {
          check % k < items.size();
          check % &node == &items[items.size() - 1 - k];
          ++k;
        }
      };
    };
    "Removing"_test = [&] {
      auto k = 0;
      for (auto &&item : items) {
        item.value = k++;
        my_list.push_front(item);
      }
      // [4, 3, 2, 1, 0]
      "Remove inner element"_test = [&] {
        // [4, 2, 1, 0]
        my_list.remove(items[3]);
        check % !my_list.empty();
        check % &my_list.front() == &items[4];
        check % &*(my_list.begin() + 1) == &items[2];
        check % &*(my_list.begin() + 2) == &items[1];
        check % &*(my_list.begin() + 3) == &items[0];
        check % &*(my_list.begin() + 4) == my_list.end();
      };
      "Remove head element"_test = [&] {
        my_list.remove(items[4]);
        // [3, 2, 1, 0]
        check % !my_list.empty();
        check % &my_list.front() == &items[3];
        check % &*(my_list.begin() + 1) == &items[2];
        check % &*(my_list.begin() + 2) == &items[1];
        check % &*(my_list.begin() + 3) == &items[0];
        check % &*(my_list.begin() + 4) == my_list.end();
      };
      "Remove tail element"_test = [&] {
        my_list.remove(items[0]);
        // [4, 3, 2, 1]
        check % !my_list.empty();
        check % &my_list.front() == &items[4];
        check % &*(my_list.begin() + 1) == &items[3];
        check % &*(my_list.begin() + 2) == &items[2];
        check % &*(my_list.begin() + 3) == &items[1];
        check % &*(my_list.begin() + 4) == my_list.end();
      };
      "Remove already removed element"_test = [&] {
        my_list.remove(items[1]);
        // [4, 3, 2, 0]
        my_list.remove(items[1]);
        check % !my_list.empty();
        check % &my_list.front() == &items[4];
        check % &*(my_list.begin() + 1) == &items[3];
        check % &*(my_list.begin() + 2) == &items[2];
        check % &*(my_list.begin() + 3) == &items[0];
        check % &*(my_list.begin() + 4) == my_list.end();
      };
    };
  };
}

}  // namespace deri::test
