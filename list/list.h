#ifndef S21_LIST_H
#define S21_LIST_H

#include <initializer_list>
#include <iostream>
#include <limits>

// TODO List functions:
//  [done] - list(const list &l);
//  [done] - list(list &&l);
//  [done] - operator=(list &&l);
//  - const_reference front();
//  - const_reference back();
//  - iterator begin();
//  - iterator end();
//  - iterator insert(iterator pos, const_reference value);
//  - void erase(iterator pos);
//  [done] - void swap(list& other);
//  - void merge(list& other);
//  - void splice(const_iterator pos, list& other);
//  - void reverse();
//  - void unique();
//  - void sort();

namespace s21 {
template <typename T>
class list {
  // List Member type //
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 private:
  struct Node {
    T value_;
    Node *next_;
    Node *prev_;

    explicit Node(const value_type &value)
        : value_(value), next_(nullptr), prev_(nullptr) {}
  };

  Node *head_;
  Node *tail_;
  Node *end_;
  size_type size_;

 public:
  // List Functions //
  list() : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {}

  explicit list(size_type count)
      : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
    for (size_type i = 0; i < count; ++i) {
      push_back(value_type());
    }
    set_end();
  }

  list(std::initializer_list<value_type> const &items)
      : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
    end_ = new Node(size_);
    for (const auto &item : items) {
      push_back(item);
      set_end();
    }
  }

  list(const list &other)
      : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
    end_ = other.size_;
    copy();
  }

  list(list &&other) noexcept
      : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
    swap();
  }

  list operator=(list &&other) noexcept {
    clear();
    swap(other);
    return *this;
  }

  ~list() {
    clear();
    delete end_;
  }

  // List Element access //
  const_reference front() { return !head_ ? end_->value_ : head_->value_; }

  const_reference back() { return !tail_ ? end_->value_ : tail_->value_; }

  // List Capacity //
  bool empty() { return size_ == 0; }

  size_type size() { return size_; }

  size_type max_size() {
    return (std::numeric_limits<size_type>::max() / sizeof(Node) / 2);
  }

  // List Modifiers //
  void clear() {
    while (!empty()) pop_back();
  }

  void push_back(value_type value) {
    Node *new_node = new Node(value);
    if (empty()) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      new_node->prev_ = tail_;
      tail_->next_ = new_node;
      tail_ = new_node;
    }
    ++size_;
    set_end();
  }

  void pop_back() {
    if (empty())
      throw std::out_of_range("List is empty.");
    else {
      Node *node = tail_;
      if (size_ == 1) {
        head_ = nullptr;
        tail_ = nullptr;
      } else {
        tail_ = node->prev_;
        tail_->next_ = nullptr;
      }
      delete node;
      --size_;
      set_end();
    }
  }

  void push_front(value_type value) {
    Node *new_node = new Node(value);
    if (empty()) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      new_node->next_ = head_;
      head_->prev_ = new_node;
      head_ = new_node;
    }
    ++size_;
    set_end();
  }

  void pop_front() {
    if (empty())
      throw std::out_of_range("List is empty.");
    else {
      Node *node = tail_;
      if (size_ == 1) {
        head_ = nullptr;
        tail_ = nullptr;
      } else {
        head_ = node->next_;
        head_->prev_ = nullptr;
      }
      delete node;
      --size_;
      set_end();
    }
  }

  void swap(list &other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(end_, other.end_);
    std::swap(size_, other.size_);
  }

  //  void merge(list &other);
  //  void reverse();
  //  void unique();
  //  void sort();

  // Tools //
  void set_end() {
    if (end_) {
      end_->value_ = size();
      end_->next_ = head_;
      end_->prev_ = tail_;
      if (head_) {
        head_->prev_ = end_;
      }
      if (tail_) {
        tail_->next_ = end_;
      }
    }
  }

  void copy(const list &other) {
    Node *copy = other.head_;
    for (size_type i = 0; i != other.size_; i++) {
      push_back(copy->value_);
      copy = copy->next_;
    }
  }

  // Iterator //
  template <typename value_type>
  class ListIterator {
   public:
    ListIterator() { current_ = nullptr; }

   private:
    Node *current_ = nullptr;
    friend class list<value_type>;
  };

  template <typename value_type>
  class ListConstIterator {};

  //  List Member type
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;

  // List Iterators
  //  iterator begin();
  //  iterator end();
  //  const_iterator begin() const;
  //  const_iterator end() const;

  // List Modifiers
  //  iterator insert(iterator pos, const_reference value);
  //  void erase(iterator pos);
  //  void splice(const_iterator pos, list &other);
};
}  // namespace s21
#endif
