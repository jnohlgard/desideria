/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/forward_list.hpp"

#include <functional>

namespace deri {

template <typename ValueType, class Compare = std::less<ValueType>>
class OrderedForwardList {
 public:
  using Value = ValueType;
  using Iterator = typename ForwardList<ValueType>::Iterator;
  using ConstIterator = typename ForwardList<ValueType>::ConstIterator;

  // We disallow copying because the heads of the lists would get out of sync.
  OrderedForwardList() : OrderedForwardList(Compare{}){};
  OrderedForwardList(const OrderedForwardList &) = delete;
  OrderedForwardList &operator=(const OrderedForwardList &) = delete;
  OrderedForwardList(OrderedForwardList &&) noexcept = default;
  OrderedForwardList &operator=(OrderedForwardList &&) noexcept = default;

  explicit OrderedForwardList(Compare compare) : compare(compare) {}
  Iterator begin() const { return list.begin(); }
  ConstIterator end() const { return ForwardList<ValueType>::end(); }

  Value &front() { return list.front(); }
  const Value &front() const { return list.front(); }
  [[nodiscard]] bool empty() const { return list.empty(); }

  void pop() { list.pop_front(); }

  void push(Value &to_insert) { push(to_insert, compare); }

  size_t remove(Value &to_remove) { return list.remove(to_remove); }

  template <class Callable>
  Iterator push(Value &to_insert, Callable do_compare) {
    auto iterator = list.begin();
    while (iterator != list.end() && do_compare(*iterator, to_insert)) {
      ++iterator;
    }
    iterator.insertBeforeMe(to_insert);
    return iterator;
  }

 private:
  ForwardList<Value> list{};
  [[no_unique_address]] Compare compare{};
};

}  // namespace deri
