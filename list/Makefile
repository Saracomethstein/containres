CC = g++
FLAGS = -Wall -Werror -Wextra -W
SRCS_TEST = list.h test.cpp

all: main

main: list.h main.cpp
	@$(CC) $(FLAGS) list.h main.cpp  -o main
	@./main
	@rm main

leaks: test
	@leaks -atExit -- ./test

test: $(SRCS_TEST)
	@$(CC) $(FLAGS) $(SRCS_TEST) -o test -lgtest -lgmock -pthread
	@./test

style:
	@clang-format --style=Google -i list.h *.cpp

clang:
	@clang-format --style=Google -n list.h *.cpp

clean:
	@rm *.o main *.gch *.gcno test