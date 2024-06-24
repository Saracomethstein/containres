#include "s21_list.h"

namespace s21 {

// Functions //
// template <typename value_type>
// void list<value_type>::push_back(value_type value) {
//  Node *new_node = new Node(value);
//
//  if (empty()) {
//    head_ = new_node;
//    tail_ = new_node;
//  } else {
//    tail_->next_ = new_node;
//    new_node->next_ = tail_;
//    tail_ = new_node;
//  }
//  ++size_;
//}

// template <typename value_type>
// typename list<value_type>::size_type list<value_type>::size() {
//   return size_;
// }
//
// template <typename value_type>
// typename list<value_type>::size_type list<value_type>::max_size() {
//   return (std::numeric_limits<size_type>::max() / sizeof(Node) / 2);
// }

// Tools //
// template <typename value_type>
// bool list<value_type>::empty() {
//  return size_ == 0;
//}

// template <typename value_type>
// void list<value_type>::set_end() {
//   if (end_) {
//     end_->next_ = head_;
//     end_->prev_ = tail_;
//     end_->value_ = size();
//   }
//   if (head_) {
//     head_->prev_ = end_;
//   }
//   if (tail_) {
//     tail_->next_ = end_;
//   }
// }

}  // namespace s21