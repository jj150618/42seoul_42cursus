/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:09:10 by junghkim          #+#    #+#             */
/*   Updated: 2020/11/25 13:30:32 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef	struct		s_format
{
	char			conversion;
	char			*length;
	char			*suffix;
	int				is_minus;
	int				is_plus;
	int				is_space;
	int				is_sharp;
	int				is_zero;
	int				width;
	int				precision;
	int				error;
}					t_format;

size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strchr(const char *str, int tofind);
int					ft_isdigit(int value);
int					ft_toupper(int value);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_ulltoa(unsigned long long n);
char				*ft_ulltoa_base(unsigned long long n, unsigned int base);

void				init(t_format *t);
int					parse(char *format, va_list *lst, int *count, int end);
void				parse_flag(t_format *t, char c);
void				parse_star(t_format *t, va_list *lst, char *format, \
					int start);
void				parse_wp(t_format *t, char *format, int *start, int end);
void				parse_length(t_format *t, char *format, int *start);
char				*handle_con(t_format *t, va_list *lst, int *len, \
					int *count);
char				*handle_con1(t_format *t, va_list *lst, int *len);
char				*handle_con2(t_format *t, va_list *lst, int *len);
char				*handle_con3(t_format *t, va_list *lst, int *len);
int					handle_flag1(t_format *t, char *str);
void				handle_flag2(t_format *t, char *str, char **suffix, \
					int start);
void				handle_prec1(char **str, t_format *t, int *len, \
					int *s_len);
void				handle_prec2(char **str, t_format *t, int *len);
long long			handle_length1(t_format *t, va_list *lst);
unsigned long long	handle_length2(t_format *t, va_list *lst);
char				*handle_malloc_fail(t_format *t);
int					handle_return_fail(char *str, char *suffix);
void				handle_exception(t_format *t, char **str, int *len);
int					print_format(t_format *t, va_list *lst, int *count);
void				print_with_flag(t_format *t, char *str, int *len, \
					int s_len);
int					find_format(char *format, int i);
int					ft_printf(const char *format, ...);
#endif
