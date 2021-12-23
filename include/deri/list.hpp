/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include <type_traits>

namespace deri {

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
