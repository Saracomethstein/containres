CC = g++
FLAGS = -Wall -Werror -Wextra

all: main

main: s21_list.h list_constructors.cpp main.cpp
	@$(CC) $(FLAGS) s21_list.h list_constructors.cpp main.cpp  -o main
	@./main
	@rm main

style:
	@clang-format --style=Google -i s21_list.h *.cpp

clang:
	@clang-format --style=Google -n s21_list.h *.cpp

clean:
	@rm *.o main *.gch