
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>

int ft_printf(const char *format, ...);
int ft_print_char(char c);
int ft_print_str(char *s);
int ft_print_ptr(unsigned long int p);
int ft_print_nbr(int n);
int ft_print_unsigned(unsigned int n);
int ft_print_hexa(unsigned long int n, char c);

#endif
