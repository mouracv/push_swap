/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:05:03 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/19 12:07:24 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack	t_stack;
typedef struct s_table	t_table;

struct					s_stack
{
	struct s_stack		*prev;
	int					value;
	struct s_stack		*next;
};

struct					s_table
{
	int					num;
	int					bf;
	int					move_cost;
};

/*******check arguments*******/
void					check_arg(char **argv, t_stack **stack_a);
int						ft_is_digit(char c);
int						ft_atoi(char *str);
int						c_dup(long nb, char **argv, int i);
void					check_limits(long int nb);
void					ft_error(void);
int						check_arg_2(char *str);

/*******stack utils*******/

int						stack_size(t_stack **node);
int						check_stack_sort(t_stack **stack_sort);
void					lst_adbeg(t_stack **head, int nb);
void					lst_adend(t_stack **head, int nb);
void					delete_first_node(t_stack **stack_d);
void					delete_last_node(t_stack **stack_d);
void					lst_free(t_stack **node);

/*******MOVES*******/

void					rotate(t_stack **stack_r);
void					ra(t_stack **stack_a);
void					rb(t_stack **stack_b);
void					rr(t_stack **stack_a, t_stack **stack_b);
void					push(t_stack **stack_org, t_stack **stack_dest);
void					pa(t_stack **stack_b, t_stack **stack_a);
void					pb(t_stack **stack_a, t_stack **stack_b);
void					reverse_rotate(t_stack **stack_rr);
void					rra(t_stack **stack_a);
void					rrb(t_stack **stack_b);
void					rrr(t_stack **stack_a, t_stack **stack_b);
void					swap(t_stack **stack_sw);
void					sa(t_stack **stack_a);
void					sb(t_stack **stack_b);
void					ss(t_stack **stack_a, t_stack **stack_b);
void					move_a_top(t_stack **stack_t, int pos);
void					move_b_top(t_stack **stack_t, int pos);
int						move_count(t_stack **stack_m, int num);

/*******sort algorithm*******/
void					esc_sort(int len, t_stack **stack_a, t_stack **stack_b);
void					sort_2_num(t_stack **stack_a);
void					sort_3_num(t_stack **stack_a);
void					sort_4_num(t_stack **stack_a, t_stack **stack_b);
void					sort_5_num(t_stack **stack_a, t_stack **stack_b);
void					big_sort(t_stack **stack_a, t_stack **stack_b);
void					brain(t_stack **stack_a, t_stack **stack_b,
							t_table *box);

/*******utils*******/
int						look_max(t_stack **stack_m);
int						look_mini(t_stack **stack_m);
int						med_a(t_stack **stack_a);
int						look_pos(t_stack **stack_p, int num);

#endif