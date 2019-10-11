#pragma once

#include <stdexcept>

template<class T>
class linked_list {

public:
  
  linked_list() {
    head_ = nullptr;
    size_ = 0;
  }

  ~linked_list() {
    clear();
  }

  int size() {
    return size_;
  }

  bool empty() {
    return !size_;
  }

  void push(T data) {
    node *tmp = new node(data);
    tmp->next = head_;
    head_ = tmp;
    size_++;
  }

  void append(T data) {
    node *tmp = head_;
    while (tmp->next != nullptr) {
      tmp = tmp->next;
    }
    tmp->next = new node(data);
    size_++;
  }

  T operator [](int idx) {
    if (idx >= size_) {
      throw std::out_of_range("Index out of bounds");
    }
    node *tmp = head_;
    for (int i = 0; i < idx; i++) {
      tmp = tmp->next;
    }
    return tmp->data;
  }

  void clear() {
    while (head_ != nullptr) {
      node *tmp = head_->next;
      delete head_;
      head_ = tmp;
    }
  }

private:

  struct node { 
    T data;
    node* next;
    node(T value) {
      data = value;
      next = nullptr;
    }
  }

  node *head_;
  int size_;

}


