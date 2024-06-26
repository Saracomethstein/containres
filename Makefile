CC = g++
FLAGS = -Wall -Werror -Wextra -W

ALL_FILES = list/list.h list/test.cpp queue/queue.h queue/test.cpp

LIST_SRC = list/list.h
LIST_TEST_SRC = list/list.h list/test.cpp

QUEUE_SRC = queue/queue.h
QUEUE_TEST_SRC = queue/queue.h queue/test.cpp

all: leaks_list

leaks_list: test_list
	@leaks -atExit -- ./test_list

test_list: $(LIST_TEST_SRC)
	@$(CC) $(FLAGS) $(LIST_TEST_SRC) -o test_list -lgtest -lgmock -pthread
	@./test_list

leaks_queue: test_queue
	@leaks -atExit -- ./test_queue

test_queue: $(QUEUE_TEST_SRC)
	@$(CC) $(FLAGS) $(QUEUE_TEST_SRC) -o test_queue	 -lgtest -lgmock -pthread
	@./test_queue

style:
	@clang-format --style=Google -i $(ALL_FILES)

clang:
	@clang-format --style=Google -n $(ALL_FILES)

clean:
	@rm *.o *.gch *.gcno test_list test_queue