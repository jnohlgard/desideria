/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once
#include <concepts>
#include <cstddef>
#include <type_traits>

namespace deri {

template <typename ValueType>
class ForwardList;

// Use CRTP to include this class in the ValueType class.
template <class ValueType>
class ForwardListNode {
 public:
  using Value = ValueType;

  class Iterator {
   public:
    using ValuePtr =
        std::conditional_t<std::is_const_v<Value>, Value *const, Value *>;
    Iterator() = default;

    // Compare between both const and non-const Value iterators.
    bool operator==(
        const typename ForwardListNode<const Value>::Iterator &other) const {
      return *before == *other.before;
    };
    bool operator==(
        const typename ForwardListNode<std::remove_const_t<Value>>::Iterator
            &other) const {
      return *before == *other.before;
    };
    Iterator(const Iterator &) = default;
    Iterator(Iterator &&) noexcept = default;
    Iterator &operator=(const Iterator &) = default;
    Iterator &operator=(Iterator &&) noexcept = default;
    Iterator &operator=(
        const typename ForwardListNode<std::remove_const_t<Value>>::Iterator
            &other) requires(std::is_const_v<Value>) {
      before = other.before;
    }
    Iterator(ValuePtr &current) : before(&current) {}

    explicit operator Value *() const { return *before; }
    Value &operator*() const { return **before; }
    Value *operator->() const { return &operator*(); }

    Iterator &operator++(/* prefix increment */) {
      before = &(*before)->next;
      return *this;
    }
    Iterator operator++(int /* postfix increment */) {
      Iterator old{*this};
      operator++();
      return old;
    }

    constexpr static typename ForwardListNode<const Value>::Iterator end() {
      return {end_sentinel};
    }

   private:
    void remove() requires(!std::is_const_v<Value>) {
      auto *removed = *before;
      *before = next();
      removed->next = nullptr;
    }

    void insertBeforeMe(Value &element) {
      element.next = *before;
      *before = &element;
    }

    ValuePtr next() const { return (*before)->next; }
    // We keep a pointer to the ::next member of the element before this element
    // in order to allow us to insert before the given item
    ValuePtr *before{};
    constexpr static const Value *end_sentinel{nullptr};

    // Let const and non-const iterators access each other's before pointers:
    friend typename ForwardListNode<std::remove_const_t<Value>>::Iterator;
    friend typename ForwardListNode<const Value>::Iterator;
    friend ForwardList<Value>;
  };

  friend ForwardList<Value>;

 private:
  Value *next;
};

/**
 * Intrusive forward-linked list
 *
 * @tparam ValueType Type of the list elements, must have a ValueType * next
 * member.
 */
template <typename ValueType>
class ForwardList {
  static_assert(requires(ValueType element) {
    { element.next } -> std::convertible_to<ValueType *>;
  });

 public:
  using Value = ValueType;
  using Iterator = typename ForwardListNode<Value>::Iterator;
  using ConstIterator = typename ForwardListNode<const Value>::Iterator;

  // We disallow copying because the heads of the lists would get out of sync.
  ForwardList() = default;
  ForwardList(const ForwardList &) = delete;
  ForwardList &operator=(const ForwardList &) = delete;
  ForwardList(ForwardList &&) noexcept = default;
  ForwardList &operator=(ForwardList &&) noexcept = default;
  Iterator begin() { return {head}; }
  ConstIterator end() { return Iterator::end(); }

  Value &front() { return *head; }
  const Value &front() const { return *head; }
  [[nodiscard]] bool empty() const { return head == nullptr; }

  void pop_front() { begin().remove(); }

  void push_front(Value &to_insert) { begin().insertBeforeMe(to_insert); }

  size_t remove(Value &to_remove) {
    for (auto iterator = begin(); iterator != end(); ++iterator) {
      // Compare object addresses to find identically the right element
      if (&to_remove == &*iterator) {
        iterator.remove();
        return 1;
      }
    }
    // Not found in list
    return 0;
  }

  Iterator insert(Iterator pos, Value &element) {
    pos.insertBeforeMe(element);
    return pos;
  }

 private:
  Value *head{nullptr};
};
}  // namespace deri
