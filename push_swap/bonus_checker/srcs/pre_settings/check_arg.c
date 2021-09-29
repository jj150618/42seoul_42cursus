

#include "push_swap.h"

static int	is_numeric(char *arg)
{
	int	i;

	if (!arg)
		return (0);
	i = -1;
	if (arg[0] == '+' || arg[0] == '-')
		i++;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
	}
	return (1);
}

int			check_arg(char *arg)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (arg[0] == '+' || arg[0] == '-')
	{
		i++;
		len--;
	}
	while (arg[i] == '0')
		i++;
	while (arg[i++])
		len++;
	if (!is_numeric(arg) || len > 11 || len < 0)
		return (0);
	else
		return (1);
}

void		check_duplicate(t_node *a)
{
	int		cur_value;
	t_node	*temp;

	while (a->next)
	{
		temp = a->next;
		cur_value = a->value;
		while (temp)
		{
			if (temp->value == cur_value)
				print_error();
			if (temp->next)
				temp = temp->next;
			else
				break ;
		}
		a = a->next;
	}
	while (a->prev)
		a = a->prev;
}

int	ft_atoi(char *arg)
{
	int			i;
	int			sign;
	long long	value;

	if (!check_arg(arg))
		print_error();
	i = 0;
	sign = 1;
	value = 0;
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i++] == '-')
			sign = -1;
	}
	while (arg[i])
		value = value * 10 + (arg[i++] - '0');
	value = value * sign;
	if (value > 2147483647 || value < -2147483648)
		print_error();
	return (value);
}