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

# define TYPE "cspdiuxX%"

typedef	struct		s_info
{
	char			conversion;
	char			*suffix;
	int				is_minus;
	int				is_zero;
	int				width;
	int				precision;
	int				error;
}					t_info;

void				init_info(t_info *info);
int					parse(char *format, va_list *ap, int *count, int end);
void				parse_flag(t_info *info, char c);
void				parse_star(t_info *info, va_list *ap, char *format, \
					int start);
void				parse_wp(t_info *info, char *format, int *start, int end);
char				*handle_con(t_info *info, va_list *ap, int *len, \
					int *count);
char				*handle_con1(t_info *info, va_list *ap, int *len);
char				*handle_con2(t_info *info, va_list *ap, int *len);
char				*handle_con3(t_info *info, va_list *ap, int *len);
int					handle_flag(t_info *info, char *str);
void				handle_prec1(char **str, t_info *info, int *len, \
					int *s_len);
void				handle_prec2(char **str, t_info *info, int *len);
char				*handle_malloc_fail(t_info *info);
int					handle_return_fail(char *str, char *suffix);
void				handle_exception(t_info *info, char **str, int *len);
int					print_info(t_info *info, va_list *ap, int *count);
void				print_with_flag(t_info *info, char *str, int *len, \
					int s_len);
int					check_format(const char *format, int i);
int					ft_printf(const char *format, ...);

size_t				ft_size_count(long long lln);
char				*ft_uitoa(unsigned int n);
size_t				ft_size_count_base(unsigned long long lln, unsigned int base);
char				*ft_uitoa_base(unsigned int n, unsigned int base);
char				*ft_ulltoa_base(unsigned long long n, unsigned int base);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_ulltoa(unsigned long long n);
size_t				ft_size_ucount(unsigned long long lln);
double				ft_pow(double num, int pow);
double				ft_floor(double num);
double				ft_round(double num, int digit);
int					ft_strcmp(const char *s1, const char *s2);
#endif
