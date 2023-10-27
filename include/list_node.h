#ifndef _list_node_h_
#define _list_node_h_

class List_node {  // Node of the list class
 private:
  List_node* prev;
  List_node* next;

  int value;

 public:
  List_node(int value_ = 0); // default value 0

  void set_prev(List_node* prev_);

  List_node* get_prev() const;

  void set_next(List_node* next_);

  List_node* get_next() const;

  void set_value(int value_);

  int get_value() const;
};

#endif