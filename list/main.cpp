#include "list.h"
using namespace s21;

int main() {
  list<int> my_list = {1, 2, 3, 345, 345, 234};
  list<int> new_list = {4, 5, 6};
  my_list.print();
  new_list.print();
  my_list.merge(new_list);
  my_list.print();
  new_list.print();
  return 0;
}