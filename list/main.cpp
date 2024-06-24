#include "s21_list.h"
using namespace s21;

int main() {
  s21::list<int> myList = {1, 2, 3};
  myList.pop_back();
  return 0;
}