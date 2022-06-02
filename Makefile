NAME = ft_containers
CXX := c++
RM := rm -rf
CXXFLAGS := -Wall -Werror -Wextra -std=c++98
SRCS = 	./src/main.cpp \
		./src/leak_test/vector/assign.cpp \
		./src/leak_test/vector/at_const.cpp \
		./src/leak_test/vector/at.cpp \
		./src/leak_test/vector/bidirect_it.cpp \
		./src/leak_test/vector/copy_construct.cpp \
		./src/leak_test/vector/erase.cpp \
		./src/leak_test/vector/insert.cpp \
		./src/leak_test/vector/insert2.cpp \
		./src/leak_test/vector/ite_arrow.cpp \
		./src/leak_test/vector/ite_eq_ope.cpp \
		./src/leak_test/vector/ite.cpp \
		./src/leak_test/vector/push_pop.cpp \
		./src/leak_test/vector/relational_ope.cpp \
		./src/leak_test/vector/rev_ite_construct.cpp \
		./src/leak_test/vector/rite_arrow.cpp \
		./src/leak_test/vector/rite_eq_ope.cpp \
		./src/leak_test/vector/rite.cpp \
		./src/leak_test/vector/rite2.cpp \
		./src/leak_test/vector/size.cpp \
		./src/leak_test/vector/swap.cpp \
		./src/leak_test/map/bounds.cpp \
		./src/leak_test/map/comp.cpp \
		./src/leak_test/map/copy_construct.cpp \
		./src/leak_test/map/empty.cpp \
		./src/leak_test/map/erase.cpp \
		./src/leak_test/map/erase2.cpp \
		./src/leak_test/map/find_count.cpp \
		./src/leak_test/map/insert.cpp \
		./src/leak_test/map/insert2.cpp \
		./src/leak_test/map/ite_arrow.cpp \
		./src/leak_test/map/ite_n0.cpp \
		./src/leak_test/map/more.cpp \
		./src/leak_test/map/op_sqbr.cpp \
		./src/leak_test/map/relational_ope.cpp \
		./src/leak_test/map/rev_ite_construct.cpp \
		./src/leak_test/map/rite_arrow.cpp \
		./src/leak_test/map/rite.cpp \
		./src/leak_test/map/swap.cpp \
		./src/leak_test/map/tricky_construct.cpp \
		./src/leak_test/map/tricky_erase.cpp \
		./src/leak_test/stack/default.cpp \
		./src/leak_test/stack/default_copy.cpp \
		./src/leak_test/stack/list_copy.cpp \
		./src/leak_test/stack/relational_ope_list.cpp \
		./src/leak_test/stack/relational_ope.cpp 


OBJS = $(SRCS:%.cpp=%.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all