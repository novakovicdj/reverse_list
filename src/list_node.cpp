#include "list_node.h"

List_node::List_node(int value_) {
  this->value = value_;
  this->prev = this->next = nullptr;
}

// Getters and setters for prev, next, and value of the node

void List_node::set_prev(List_node* prev_) { this->prev = prev_; }

List_node* List_node::get_prev() const { return this->prev; }

void List_node::set_next(List_node* next_) { this->next = next_; }

List_node* List_node::get_next() const { return this->next; }

void List_node::set_value(int value_) { this->value = value_; }

int List_node::get_value() const { return this->value; }