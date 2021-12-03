/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include <functional>

namespace deri {

// Use CRTP to include this class in the ValueType class.
template <class ValueType>
class ForwardListNode {
 public:
  using Value = ValueType;
  class Iterator {
   public:
    Iterator() = default;
    Iterator(Value *current) : current(current) {}
    Value *operator->() { return current; }
    const Value *operator->() const { return current; }
    Value &operator*() { return *operator->(); }
    const Value &operator*() const { return *operator->(); }
    Iterator operator++(int /* postfix */) {
      Iterator old = current;
      operator++();
      return old;
    }
    Iterator &operator++() {
      current = current->next;
      return *this;
    }
    explicit operator Value *() const { return current; }
    bool operator==(const Iterator &other) const = default;

   private:
    Value *current{};
  };

  // private:
  Value *next{nullptr};
};

template <class ValueType, class Compare = std::less<ValueType>>
class OrderedForwardList {
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

  Iterator begin() { return {head}; }
  Iterator end() { return {.current = nullptr}; }

  Value &front() { return *head; }
  const Value &front() const { return *head; }
  [[nodiscard]] bool empty() const { return head == nullptr; }
  void pop() {
    if (head != nullptr) {
      head = head->next;
    }
  }

  void push(ValueType &to_insert) { push(to_insert, compare); }

  template <class Callable>
  void push(ValueType &to_insert, Callable do_compare) {
    if (head == nullptr) {
      head = &to_insert;
      return;
    }
    ValueType *before = nullptr;
    ValueType *after = nullptr;
    for (auto &element : *this) {
      if (!do_compare(element, to_insert)) {
        after = &element;
        break;
      }
      before = &element;
    }
    to_insert.next = after;
    if (before == nullptr) {
      head = &to_insert;
    } else {
      before->next = &to_insert;
    }
  }

  void remove(ValueType &to_remove) {
    ValueType *before = nullptr;
    for (auto &element : *this) {
      // Compare object addresses to find identically the right element
      if (&to_remove == &element) {
        if (before == nullptr) {
          head = element.next;
        } else {
          before->next = element.next;
        }
        element.next = nullptr;
        return;
      }
      before = &element;
    }
    // Not found in list
  }

 private:
  Compare compare{};
  ValueType *head{nullptr};
};

template <class Value>
class ListNode {
  ListNode *prev{nullptr};
  ListNode *next{nullptr};
  class Iterator {
   public:
    Value *operator->() { return current; }
    const Value *operator->() const { return current; }
    Value &operator*() { return *operator->(); }
    const Value &operator*() const { return *operator->(); }
    Iterator operator++(int /* postfix */) {
      Iterator old = current;
      operator++();
      return old;
    }
    Iterator &operator++() {
      current = current->next;
      return *this;
    }
    Iterator operator--(int /* postfix */) {
      Iterator old = current;
      operator--();
      return old;
    }
    Iterator &operator--() {
      current = current->prev;
      return *this;
    }

    bool operator==(const Iterator &other) const {
      return current == other.current;
    }

   private:
    Value *current{};
  };

  Iterator begin() { return Iterator{next}; }
  Iterator end() { return Iterator{nullptr}; }

  void insertBefore(ListNode &other) {
    prev = other.prev;
    other.prev = this;
    next = other;
    if (prev) {
      prev->next = this;
    }
  }
};
}  // namespace deri
