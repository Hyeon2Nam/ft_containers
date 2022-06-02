#include "stack.hpp"
#include "map.hpp"
#include <algorithm>
#include <list>
#include <map>
#include "vector.hpp"
#include "leak_test/map/allMap.hpp"
#include "leak_test/stack/allStack.hpp"
#include "leak_test/vector/allVector.hpp"

void do_map_test(void)
{
	t_bounds();
	t_comp();
	t_copy_construct();
	t_empty();
	t_erase();
	t_erase2();
	t_find_count();
	t_insert();
	t_insert2();
	t_ite_arrow();
	t_ite_n0();
	t_more();
	t_op_sqbr();
	t_relational_ope();
	t_rev_ite_construct();
	t_rite_arrow();
	t_rite();
	t_swap();
	t_tricky_construct();
	t_tricky_erase();
}

void do_stack_test(void)
{
	s_default();
	s_default_copy();
	s_list_copy();
	s_relational_ope_list();
	s_relational_ope();
}

void do_vector_test(void)
{
	v_assign();
	v_at_const();
	v_at();
	v_bidirect_it();
	v_copy_construct();
	v_erase();
	v_insert();
	v_insert2();
	v_ite_arrow();
	v_ite_eq_ope();
	v_ite();
	v_push_pop();
	v_relational_ope();
	v_rev_ite_construct();
	v_rite_arrow();
	v_rite_eq_ope();
	v_rite();
	v_rite2();
	v_size();
	v_swap();
}

int main(void)
{
	do_vector_test();
	do_stack_test();
	do_map_test();
	
	while (1)
		;
	return (0);
}
