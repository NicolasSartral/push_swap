/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 02:16:04 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/30 01:00:46 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printing(t_list *bluepill, t_list *redpill)
{
	t_list	*tmp_blue;
	t_list	*tmp_red;

	tmp_blue = bluepill;
	tmp_red = redpill;
	while (bluepill != NULL || redpill != NULL)
	{
		if (bluepill != NULL && redpill != NULL)
		{
			ft_printf("%d //  %d\n", bluepill->content, redpill->content);
			bluepill = bluepill->next;
			redpill = redpill->next;
		}
		if (bluepill != NULL && redpill == NULL)
		{
			ft_printf("%d\n", bluepill->content);
			bluepill = bluepill->next;
		}
		if (redpill != NULL && bluepill == NULL)
		{
			ft_printf("  //  %d\n", redpill->content);
			redpill = redpill->next;
		}
	}
	ft_printf ("- -\na b");
	bluepill = tmp_blue;
	redpill = tmp_red;
}

int	parsing_two(char **argv, t_list **bluepill)
{
	int			i;
	t_list		*tmp;

	*bluepill = ft_lstnew(ft_atoi(argv[1]));
	tmp = *bluepill;
	i = 2;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == 0 && (argv[i][0] != '0'
			|| ft_strlen(argv[i]) != 1))
			return (0);
		(*bluepill)->next = ft_lstnew(ft_atoi(argv[i]));
		if ((*bluepill)->next == NULL)
			return (0);
		(*bluepill) = (*bluepill)->next;
		i++;
	}
	*bluepill = tmp;
	return (1);
}
