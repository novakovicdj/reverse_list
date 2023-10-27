#include <iostream>
#include <list>

#include "list_node.h"

#define NUM_OF_ELEMS rand() % 10 + 1

using namespace std;

void delete_list(List_node* head);

void create_list(List_node** head_) {
  if (*head_) {
    // if create_list is called twice when head passed isn't
    // nullptr
    delete_list(*head_);
    *head_ = nullptr;
  }

  List_node *last, *new_node;
  srand(time(NULL));
  int num = rand() % 10 + 1;  // how much elements list will have
  cout << "Creating new list with " << num << " elements." << endl;

  // create each node, and connect it to the list
  for (int i = 0; i < num; i++) {
    new_node = new List_node(rand() % 100);
    if (!*head_) {  // if it is first element
      *head_ = new_node;
      last = new_node;
    } else {
      last->set_next(new_node);
      new_node->set_prev(last);
      last = new_node;
    }
  }
}

void reverse_list(List_node** head) {
  cout << "Reversing list..." << endl;
  List_node *prev, *next;
  next = (*head)->get_next();
  prev = nullptr;

  while (next) {  // reverse everything up to last node
    (*head)->set_next(prev);
    (*head)->set_prev(next);
    prev = *head;
    *head = next;
    next = next->get_next();
  }

  // reversing last node
  (*head)->set_next(prev);
  (*head)->set_prev(next);
}

void print_list(List_node* head) {
  List_node* tmp = head;
  // print all nodes
  while (tmp) {
    cout << " " << tmp->get_value() << " ";
    if (tmp->get_next()) {
      cout << "->";
    }
    tmp = tmp->get_next();
  }
  cout << endl;
}

void delete_list(List_node* head) {
  List_node* next = head->get_next();
  // deletes all nodes
  while (head) {
    delete head;
    head = next;
    if (next) next = next->get_next();
  }
}

int main() {
  List_node* head = nullptr;
  cout << "\t Implemented list\n";
  // create list, print it, reverse it, print again, and delete
  create_list(&head);
  print_list(head);
  reverse_list(&head);
  print_list(head);
  delete_list(head);
  cout << endl << "\t Built-in list\n";

  list<int> l;
  // creating implemented list
  for (int i = 0; i < NUM_OF_ELEMS; i++) {
    l.push_back(rand() % 100);
  }

  for (auto& el : l) {
    cout << " " << el << " ->";
  }
  cout << "\b\b  " << endl;  // to delete '->' after last node
  cout << "Reversing list..." << endl;
  l.reverse();

  for (auto& el : l) {
    cout << " " << el << " ->";
  }
  cout << "\b\b  " << endl;

  return 0;
}