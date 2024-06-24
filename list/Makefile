CC = g++
FLAGS = -Wall -Werror -Wextra

all: main

main: list.h main.cpp
	@$(CC) $(FLAGS) list.h main.cpp  -o main
	@./main
	@rm main

style:
	@clang-format --style=Google -i list.h *.cpp

clang:
	@clang-format --style=Google -n list.h *.cpp

clean:
	@rm *.o main *.gch