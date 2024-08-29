CC=g++
CFLAGS=-std=c++17 -Wpedantic -Wall -Werror -Wextra -Wshadow
SANFLAG=#-fsanitize=address -g
COVFLAGS=-fprofile-arcs -ftest-coverage

# Директории и исходники
LIBRARY = s21_matrix_oop.a
TARGET = matrixcpp

BACK_DIR = ./
BACK_FILES = $(wildcard $(BACK_DIR)*.cc)
BACK_O_FILES = $(subst .cc,.o, $(BACK_FILES))
O_GCOV_FILES = $(addsuffix .gcov, $(BACK_O_FILES))

TEST_DIR = ./tests/
C_TEST_FILES = $(wildcard $(TEST_DIR)*.cc)
O_TEST_FILES = $(subst .cc,.o, $(C_TEST_FILES))
OUT_TEST=$(TEST_DIR)test.out

# Флаги для тестов
TEST_FLAGS=-lgtest -lgtest_main
# Если компилятор clang ему нужна другая стандартная библиотека для линковки
# временно кидаю к флагам тестовым, не вижу пока что смысла отдельный флаг делать
ifeq ($(CC),clang)
	TEST_FLAGS+=-lc++
endif

all: $(LIBRARY)

# Собираем библиотеку
$(LIBRARY): $(BACK_O_FILES)
	ar rcs $@ $^
	ranlib $@

# Компилируем объектные файлы функций библиотеки с профилир/покрытием
%.o.gcov: %.cc
	$(CC) $(CFLAGS) -c $(SANFLAG) $(COVFLAGS) $< -o $(addprefix $(TEST_DIR), $@)

# Компилируем объектные файлы библиотеки и тестов
%.o: %.cc
	$(CC) $(CFLAGS) -c $(SANFLAG) $< -o $@

test: $(O_GCOV_FILES) $(O_TEST_FILES)
	echo $(BACK_FILES)
	$(CC) $(CFLAGS) $(SANFLAG) $(COVFLAGS) $(O_TEST_FILES) $(addprefix $(TEST_DIR), $(O_GCOV_FILES)) \
	-o $(OUT_TEST) $(TEST_FLAGS)

	$(OUT_TEST)

gcov_report:
	(cd $(TEST_DIR) && gcov *.o.gcov)
	@echo ""
# тут я пытался удалить файлы от стандартной библиотеки - нам не нужно покрывать их
# {} - find заменяет его на текущий найденный элемент
#  + - find передаст все найденное в команду rm -rf одним вызовом, как rm -rf file1 dir2
#find tests -maxdepth 1 -type f -name '*gcov*' ! -name 's21*' -exec rm {} +
	lcov -t "test" -o $(TEST_DIR)report.info -c -d $(TEST_DIR)
	genhtml -o $(TEST_DIR)report $(TEST_DIR)report.info
	open $(TEST_DIR)report/index.html

clang:
	clang-format -n $(BACK_DIR)*.cc $(TEST_DIR)*.cc $(BACK_DIR)*.h $(TEST_DIR)*.h
	clang-format -i $(BACK_DIR)*.cc $(TEST_DIR)*.cc $(BACK_DIR)*.h $(TEST_DIR)*.h

clean:
	find . -type f -name "*.o" -delete
	find . -type f -name "*.gc*" -delete
	rm -rf $(TEST_DIR)report*
	rm -f $(LIBRARY) $(OUT_TEST)

rebuild: clean all

# Докер и валгринд
NAME = chickpet$(TARGET)
docker:
	docker build -t $(NAME):v1 .
	docker run -it --name $(NAME) $(NAME):v1 /bin/bash

renew_docker: clean
	docker start $(NAME)
	docker exec $(NAME) rm -rf /code
	docker cp . $(NAME):/code
	docker exec -it $(NAME) /bin/bash

delete_docker:
	docker stop $(NAME)
	docker rm $(NAME)
	docker rmi $(NAME):v1

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	--log-file=leaks_log.txt $(OUT_TEST); vim leaks_log.txt
