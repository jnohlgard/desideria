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
    "Empty list"_test = [&] { check % my_list.empty(); };
    "Adding items"_test = [&] {
      TestListNode item{.value = 1234};
      my_list.push_front(item);
      check % !my_list.empty();
      check % &my_list.front() == &item;
      check % my_list.front().value == 1234;
    };
  };
}

}  // namespace deri::test
