#include "libft.h"
#include <stdio.h>

static char *summer(t_list *nums)
{
	char *result;
	t_list *temp;
	size_t index;

	temp = nums;
	index = 0;
	result = ft_strnew_filler(1, '0');
	while (nums)
	{
		if (nums->content)
		{
			result = ft_math_long_arithmetic_string_add_free_1(result, \
				(char *)nums->content);
			index++;
		}
		nums = nums->next;
	}
	ft_lst_free_chain(temp);
	return (result);
}

static char *ft_math_la_multiplication_one_to_one(char n1, char n2, \
	size_t nulles)
{
	char *num;

	if (nulles)
		num = ft_strjoin_fr_both(ft_itoa(((n1 - '0') * (n2 - '0'))), \
		ft_strnew_filler(nulles, '0'));
	else
		num = ft_itoa(((n1 - '0') * (n2 - '0')));
	return (num);
}

static char *ft_math_la_multiplication_one_num(char *n1, char n2)
{
	t_list *result;
	size_t index;
	char *temp;

	result = NULL;
	index = 0;
	ft_str_reverse(n1);
	while (n1[index])
	{
		temp = ft_math_la_multiplication_one_to_one(n1[index], n2, index);
		ft_lstadd(&result, ft_lstnew_without_copy(temp, 1));
		index++;
	}
	ft_str_reverse(n1);
	if (!(temp = summer(result)))
		return (ft_strnew_filler(1, '0'));
	return (temp);
}

static char *ft_math_la_multiplication_work(char *n1, char *n2)
{
  size_t residue;
	size_t index;
	t_list *result;
	char *temp;

  residue = 0;
	index = 0;
	result = NULL;
	ft_str_reverse(n2);
	while (n2[index])
	{
		if (!index)
			temp = ft_math_la_multiplication_one_num(n1, n2[index]);
		else
			temp = ft_strjoin_fr_both(ft_math_la_multiplication_one_num(n1, \
				n2[index]), ft_strnew_filler(index, '0'));
		ft_lstadd(&result, ft_lstnew_without_copy(temp, 1));
		index++;
	}
	ft_str_reverse(n2);
	if (!(temp = summer(result)))
		return (ft_strnew_filler(1, '0'));
	return (temp);
}

char *ft_math_long_arithmetic_string_multiplication(char *n1, char *n2)
{
	size_t minuses;
	char *result;
	char *s1;
	char *s2;

	minuses = 0;
	if (!n1 || !n2)
		return (NULL);
	if (n1[0] == '-' && n1[1] != '0')
	{
		minuses++;
		n1++;
	}
	if (n2[0] == '-' && n2[1] != '0')
	{
		minuses++;
		n2++;
	}
	s1 = ft_strdup(n1);
	s2 = ft_strdup(n2);
	if (!(result = ft_math_la_multiplication_work(s1, s2)))
	{
		ft_free_both(s1, s2);
		return (NULL);
	}
	ft_free_both(s1, s2);
	if (minuses == 1)
		result = ft_strjoin_free_2("-", result);
	return (result);
}
