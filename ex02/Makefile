NAME=bureaucrat
CC=c++
FLAGS=-Wall -Wextra -Werror -g3 -std=c++98

FILES =		main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyCreationForm.cpp \
			PresidentialPardonForm.cpp

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