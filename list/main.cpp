#include "list.h"
using namespace s21;

int main() {
  s21::list<int> myList = {1, 2, 3};
  s21::list<int> copy;
  copy.copy(myList);
  return 0;
}