#include "list.h"
using namespace s21;

int main() {
  list<int> my_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  my_list.print();
  my_list.reverse();
  my_list.print();
  return 0;
}