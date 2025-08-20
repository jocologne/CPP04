CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -Iincludes

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SRCS			= $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAMES	= $(notdir $(SRCS:.cpp=.o))
OBJS			= $(addprefix $(OBJ_DIR)/, $(OBJ_NAMES))

NAME = Animal

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re