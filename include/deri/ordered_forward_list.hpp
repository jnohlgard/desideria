/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/forward_list.hpp"

#include <functional>

namespace deri {

template <typename ValueType, class Compare = std::less<ValueType>>
class OrderedForwardList : public ForwardList<ValueType> {
 public:
  using Value = ValueType;
  using Node = ForwardListNode<Value>;
  using Iterator = typename Node::Iterator;

  // We disallow copying because the heads of the lists would get out of sync.
  OrderedForwardList() : OrderedForwardList(Compare{}){};
  OrderedForwardList(const OrderedForwardList &) = delete;
  OrderedForwardList &operator=(const OrderedForwardList &) = delete;
  OrderedForwardList(OrderedForwardList &&) noexcept = default;
  OrderedForwardList &operator=(OrderedForwardList &&) noexcept = default;
  explicit OrderedForwardList(Compare compare) : compare(compare) {}

  void pop() { this->pop_front(); }

  void push(ValueType &to_insert) { push(to_insert, compare); }

  template <class Callable>
  Iterator push(ValueType &to_insert, Callable do_compare) {
    auto iterator = this->begin();
    for (; iterator != this->end(); ++iterator) {
      if (!do_compare(*iterator, to_insert)) {
        iterator.insertBeforeMe(to_insert);
        return iterator;
      }
    }
    // The new element is at the end of the list
    iterator.insertBeforeMe(to_insert);
    return iterator;
  }

 private:
  [[no_unique_address]] Compare compare{};
};

}  // namespace deri
