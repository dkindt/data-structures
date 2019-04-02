#pragma once

#include <stdexcept>

template<class T>
class LinkedList {

public:
  
  LinkedList() {
    this->head_ = nullptr;
    this->size_ = 0;
  }

  ~LinkedList() {
  
  }

  int size() {
    return this->size_;
  }

  bool empty() {
    return this->size_ == 0;
  }

  void push(T data) {
    Node *tmp = new Node(data);
    tmp->next = this->head_;
    this->head_ = tmp;
    this->size_++;
  }

  void append(T data) {
    Node *tmp = this->head_;
    while (tmp->next != nullptr) {
      tmp = tmp->next;
    }
    tmp->next = new Node(data);
    this->size_++;
  }

  T operator [](int idx) {
    if (idx >= this->size_) {
      throw std::out_of_range("Index too large");
    }
    Node *tmp = this->head_;
    for (int i = 0; i < idx; i++) {
      tmp = tmp->next;
    }
    return tmp->data;
  }

private:

  struct Node {
  
    T data;
    Node* next;
    Node(T value) {
      data = value;
      next = nullptr;
    }
  }

  Node *head_;
  int size_;

}


