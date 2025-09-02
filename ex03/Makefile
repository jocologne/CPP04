NAME = Materia

SRC_DIR = src
SRCS = $(SRC_DIR)/AMateria.cpp $(SRC_DIR)/Ice.cpp $(SRC_DIR)/Cure.cpp \
		 $(SRC_DIR)/Character.cpp $(SRC_DIR)/MateriaSource.cpp $(SRC_DIR)/main.cpp

OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re