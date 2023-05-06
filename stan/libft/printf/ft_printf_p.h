/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:40:17 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/17 00:53:52 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_P_H
# define FT_PRINTF_P_H

# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

# include <libft.h>
# include "ft_printf.h"

/*
 *	Private part
 */

typedef union u_arg
{
	char				as_char;
	wint_t				as_wint_t;
	short				as_short;
	long				as_long;
	long long			as_longlong;
	int					as_int;
	intmax_t			as_intmax_t;
	size_t				as_size_t;
	ptrdiff_t			as_ptrdiff_t;
	unsigned char		as_uchar;
	unsigned short		as_ushort;
	unsigned long		as_ulong;
	unsigned long long	as_ulonglong;
	unsigned int		as_uint;
	char				*as_char_p;
	wchar_t				*as_wchar_p;
	void				*as_void_p;
	double				as_double;
}	t_arg;

typedef struct s_printf
{
	int		hash;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		apostrophe;
	int		upper_i;
	int		field_width;
	int		precision;
	int		_precision;
	char	length[3];
	char	conversion;
	t_arg	arg;
	int		fd;
}	t_printf;

int		_leftpadd(char **p, char c, size_t n);
int		_rightpadd(char **p, char c, size_t n);

int		arg_is_negative(t_printf *spec);
int		arg_is_zero(t_printf *spec);

char	*load(int fd, t_printf *spec, char *s);
int		flag_apostrophe(t_printf *spec, char **s);
int		flag_minus(t_printf *spec, char **s);
int		flag_hash(t_printf *spec, char **s);
int		flag_plus(t_printf *spec, char **s);
int		flag_space(t_printf *spec, char **s);
int		flag_upper_i(t_printf *spec, char **s);
int		flag_zero(t_printf *spec, char **s);
int		load_conversion(t_printf *spec, char **s);
int		load_field_width(t_printf *spec, char **s);
int		load_length(t_printf *spec, char **s);
int		load_precision(t_printf *spec, char **s);

int		flags_char(t_printf *spec, char **p);
int		flags_double(t_printf *spec, char **p);
int		flags_int(t_printf *spec, char **p);
int		flags_percent(t_printf *spec, char **p);
int		flags_pointer(t_printf *spec, char **p);
int		flags_string(t_printf *spec, char **p);
int		flags_uint(t_printf *spec, char **p);

int		spec_field_width(t_printf *spec, char **p);
int		spec_hash(t_printf *spec, char **p);
int		spec_plus(t_printf *spec, char **p);
int		spec_precision(t_printf *spec, char **p);
int		spec_space(t_printf *spec, char **p);

int		print(t_printf *spec, va_list vargs, int *cnt);
int		print_char(t_printf *spec, va_list vargs, int *cnt);
int		print_count(t_printf *spec, va_list vargs, int *cnt);
int		print_count_char(t_printf *spec, va_list vargs, int *cnt);
int		print_count_int(t_printf *spec, va_list vargs, int *cnt);
int		print_count_short(t_printf *spec, va_list vargs, int *cnt);
int		print_double(t_printf *spec, va_list vargs, int *cnt);
int		print_int(t_printf *spec, va_list vargs, int *cnt);
int		print_int_int(t_printf *spec, va_list vargs, int *cnt);
int		print_int_intmax_t(t_printf *spec, va_list vargs, int *cnt);
int		print_int_ptrdiff_t(t_printf *spec, va_list vargs, int *cnt);
int		print_int_size_t(t_printf *spec, va_list vargs, int *cnt);
int		print_pointer(t_printf *spec, va_list vargs, int *cnt);
int		print_percent(t_printf *spec, va_list vargs, int *cnt);
int		print_size_t_hex(t_printf *spec, va_list vargs, int *cnt);
int		print_size_t_hexx(t_printf *spec, va_list vargs, int *cnt);
int		print_string(t_printf *spec, va_list vargs, int *cnt);
int		print_uint(t_printf *spec, va_list vargs, int *cnt);
int		print_uint_dec(t_printf *spec, va_list vargs, int *cnt);
int		print_uint_oct(t_printf *spec, va_list vargs, int *cnt);
int		print_uint_hex(t_printf *spec, va_list vargs, int *cnt);
int		print_uint_hexx(t_printf *spec, va_list vargs, int *cnt);
int		print_uint_uint(t_printf *spec, va_list vargs, int *cnt);
int		print_uint_uint_hex(t_printf *spec, va_list vargs, int *cnt);
int		print_uint_uint_hexx(t_printf *spec, va_list vargs, int *cnt);
int		print_uint_uint_oct(t_printf *spec, va_list vargs, int *cnt);
int		print_uint_size_t(t_printf *spec, va_list vargs, int *cnt);
int		print_uint_size_t_oct(t_printf *spec, va_list vargs, int *cnt);

int		print_final(char *s, int *cnt, int fd);
int		print_final_buf(char *s, int *cnt, int fd);
int		print_final_sz(char *s, size_t sz, int *cnt, int fd);

# ifndef NDEBUG

void	specdebug(t_printf *spec);

# endif

#endif // ndef FT_PRINTF_P_H
