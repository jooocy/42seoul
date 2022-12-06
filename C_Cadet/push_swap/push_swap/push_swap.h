/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:39:52 by jojoo             #+#    #+#             */
/*   Updated: 2022/11/11 22:21:07 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define PA 0
# define PB 1
# define RA 2
# define RB 3
# define SA 4
# define SB 5
# define RRA 6
# define RRB 7

# define INT_MAX 2147483647
# define INT_MIN 2147483648

typedef struct s_node
{
	int				value;
	int				id;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_master
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
}	t_master;

void	ft_exit(char *error);
void	check_input(int argc, char **argv);
void	sort_id(t_master *stack_ma);
int		is_sorted(t_master *stack_ma);

void	operation(t_master *stack_ma, t_master *stack_mb, int command);
void	printf_command(int command);
void	ft_swap(t_master *stack_m);
void	ft_push(t_master *to, t_master *from);
void	ft_push_two(t_master *to, t_master *from);
void	ft_rotate(t_master *stack_m);
void	ft_rrotate(t_master *stack_m);

void	initialization(t_master *stack_ma, t_master *stack_mb, \
int argc, char **argv);
void	init_master(t_master *stack_m);
void	push_data_stack_a(t_master *stack_ma, int argc, char **argv);
void	push_element(t_master *stack_ma, int num);

int		ft_isdigit(int a);
int		ft_strlen(const char *str);

void	do_algorithm(t_master *stack_ma, t_master *stack_mb);
void	size_three_sort(t_master *stack_ma);
void	size_four_sort(t_master *stack_ma, t_master *stack_mb);
void	size_five_sort(t_master *stack_ma, t_master *stack_mb);

void	size_any_sort(t_master *stack_ma, t_master *stack_mb);
void	make_clock_hours(t_master *stack_ma, t_master *stack_mb);
void	sort_b_to_a(t_master *stack_ma, t_master *stack_mb);

int		is_target_in_top_exactly(t_master *stack_ma, int target);
int		is_target_in_down_exactly(t_master *stack_ma, int target);
void	rotate_stack_exactly(t_master *stack_m, int target, int command);

#endif
