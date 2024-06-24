#include "list.h"
using namespace s21;

int main() {
  s21::list<int> my_list = {1, 2, 3, 4, 5, 6, 7, 7};
  my_list.print();
  my_list.push_back(234234);
  my_list.print();
  my_list.pop_back();
  my_list.print();
  my_list.pop_front();
  my_list.print();
  return 0;
}