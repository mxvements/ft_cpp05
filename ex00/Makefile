NAME=bureaucrat
CC=c++
FLAGS=-Wall -Wextra -Werror -g3 -std=c++98

#compilers- c++, g++, clang++
#c1r12s4% c++ -v      
#Ubuntu clang version 12.0.1-19ubuntu3
#Target: x86_64-pc-linux-gnu
#Thread model: posix
#InstalledDir: /usr/bin
#Found candidate GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/10
#Found candidate GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/11
#Found candidate GCC installation: /usr/lib/gcc/x86_64-linux-gnu/10
#Found candidate GCC installation: /usr/lib/gcc/x86_64-linux-gnu/11
#Selected GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/11
#Candidate multilib: .;@m64
#Selected multilib: .;@m64


FILES =		main.cpp \
			Bureaucrat.cpp
OBJ_PATH =	.obj/
OBJ =		$(FILES:%.cpp=$(OBJ_PATH)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(FLAGS) $^ -o $(NAME)

$(NAME): $(OBJ)
$(OBJ_PATH)%.o: %.cpp
	@mkdir -p $(OBJ_PATH)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean