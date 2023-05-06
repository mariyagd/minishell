/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:37:34 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/24 19:55:14 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <assert.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

# ifndef NDEBUG
#  include <stdio.h>
# endif

/*
 *	misc stuff...
 */

typedef void				(*t_fn1)(void *);
typedef void				(*t_fn2)(void *, void *);
typedef void				(*t_fn3)(char *, void *);
typedef void				(*t_fn4)(char *, void *, void *);

typedef int					(*t_compar)(void *, void *);

typedef unsigned long		t_ulong;
typedef unsigned long long	t_ullong;

/*
 *	misc functions
 */

int			ft_abs(int num);
char		*ft_abspath_of_cmd(const char *cmd, char *dirs[]);
int			ft_append(char **sp, const char *suffix);
char		*ft_atod(const char *s, double *ret);
char		*ft_atoi(const char *s, int *ret);
int			ft_atoi_ex(const char *s, int *ret, int spec);
char		*ft_atol(const char *s, long *ret);
char		*ft_atoll(const char *s, long long *ret);
char		*ft_atosz(const char *s, size_t *ret);
int			ft_atosz_ex(const char *s, size_t *ret, int spec);
char		*ft_atoui(const char *s, unsigned int *ret);
int			ft_atoui_ex(const char *s, unsigned int *ret, int spec);
char		*ft_atoul(const char *s, unsigned long *ret);
int			ft_atoul_ex(const char *s, unsigned long *ret, int spec);
char		*ft_atoull(const char *s, t_ullong *ret);
char		*ft_basename(const char *path, char *bname);
void		ft_bsort(void *a, size_t n, size_t sz, t_compar f);
int			ft_chrstr(char c, size_t n, char **ret);
size_t		ft_count_arr(void *a);
void		ft_del(void *p);
void		ft_del_arr(void *p);
char		*ft_dirname(const char *path, char *dname);
char		*ft_dtoa(double d, size_t precision, char ret[]);
char		*ft_dtoa_e(double d, size_t precision, char ret[]);
char		*ft_dtoa_ee(double d, size_t precision, char ret[]);
int			ft_endswith(const char *s, const char *suffix);
char		*ft_env_var(const char *varname, char *env[]);
t_ullong	ft_fibonacci(size_t n);
int			ft_file_executable(const char *path);
int			ft_file_exists(const char *path);
int			ft_file_directory(const char *path);
int			ft_file_readable(const char *path);
int			ft_file_writable(const char *path);
pid_t		ft_fork(pid_t *ret);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isprint(int c);
int			ft_isprime(unsigned long n);
int			ft_isspace(int c);
int			ft_isupper(int c);
char		*ft_itoa(int n, char ret[12]);
char		*ft_lltoa(long long n, char ret[21]);
long		ft_labs(long num);
long		ft_lmax(long a, long b);
long		ft_lmin(long a, long b);
int			ft_max(int a, int b);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
int			ft_min(int a, int b);
int			ft_multovf(size_t a, size_t b);
int			ft_pow(int a, size_t x);
int			ft_putchar(char c, int fd);
int			ft_putstr(const char *s, int fd);
int			ft_putstr_sz(const char *s, size_t sz, int fd);
int			ft_prepend(char **sp, const char *prefix);
void		ft_qsort(void *a, size_t n, size_t sz, t_compar f);
char		*ft_replace(char **s, const char *this, const char *that);
char		**ft_split(const char *s, char c);
int			ft_startswith(const char *s, const char *prefix);
char		*ft_stpcpy(char *dst, const char *src);
int			ft_strcasecmp(const char *s1, const char *s2);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strcatchr(char *dest, char c, size_t n);
size_t		ft_strccpy(char *dst, const char *src, size_t n);
char		*ft_strchr(const char *s, char c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcut(char *s, size_t n);
size_t		ft_strcspn(const char *s, const char *reject);
char		*ft_strdup(const char *s);
char		*ft_strdup2(const char *s, char **ret);
char		*ft_strip(const char *s);
int			ft_strisspace(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
size_t		ft_strlen2(const char *s, size_t *sz);
int			ft_strncasecmp(const char *s1, const char *s2, size_t n);
char		*ft_strncat(char *dst, const char *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t n);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strndup2(const char *s, size_t n, char **ret);
char		*ft_strnew(char **ps, const char *s);
size_t		ft_strnlen(const char *s, size_t maxlen);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strpbrk(const char *s, const char *accept);
char		*ft_strrchr(const char *s, int c);
size_t		ft_strspn(const char *s, const char *accept);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strtrim(const char *s, const char *set);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_ulltoa(unsigned long long n, char ret[21]);
char		*ft_ulltoa_oct(unsigned long long n, char ret[23]);
char		*ft_ulltoa_hex(unsigned long long n, char ret[17]);
char		*ft_ulltoa_hexx(unsigned long long n, char ret[17]);
t_ulong		ft_ulmax(t_ulong a, t_ulong b);
t_ulong		ft_ulmin(t_ulong a, t_ulong b);

/*
 *	singly-linked list
 */

typedef struct s_sllist
{
	struct s_sllist	*next;
}	t_sllist;

void		*ft_sllist_pull(void *lst);
void		ft_sllist_push(void *lst, void *elem);
void		ft_sllist_take(void *lst, void *elem, void *previous);

/*
 *	doubly-linked list
 */

typedef struct s_dllist
{
	struct s_dllist	*next;
	struct s_dllist	*prev;
}	t_dllist;

void		*ft_dllist_pull(void *lst);
void		ft_dllist_push(void *lst, void *elem);
void		ft_dllist_pushback(void *lst, void *elem, void *previous);
void		ft_dllist_take(void *lst, void *elem, void *previous);

/*
 *	memory management
 */

typedef struct s_memlist
{
	struct s_memlist	*next;
	size_t				sz;
	void				*data[];
}	t_memlist;

void		*ft_memlist(void);
void		ft_memtrash(void);
size_t		ft_memusage(void);

void		*ft_calloc(size_t nmemb, size_t size);
void		ft_free(void *p);
void		*ft_malloc(size_t sz);

void		*ft_buffer(void *newbuf);
ptrdiff_t	*ft_bufptr(void);

# ifndef NMEMLIST

void		*ft_realloc(void *ptr, size_t sz);
void		*ft_reallocarray(void *ptr, size_t nmemb, size_t size);

# else

void		*ft_realloc(void *ptr, size_t sz, size_t psz);
void		*ft_reallocarray(void *ptr, size_t nmemb, size_t size, size_t psz);

# endif // ndef NMEMLIST

#endif
