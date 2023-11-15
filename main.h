#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/*__________________________________________________________________________________________________*/
#define MINUS_FLAG 1
#define PLUS_FLAG 2
#define ZERO_FLAG 4
#define HASH_FLAG 8
#define SPACE_FLAG 16
/*flags*/
/*___________________________________________________________________________________________________*/
#define S_LONG 2
#define S_SHORT 1
/* SIZES */
/*___________________________________________________________________________________________________*/ 
/**
 * struct specifier - Struct op
 *
 * @specifier: The format.
 * @fun_associated: The function associated.
 */
struct specifier
{
	char specifier;
	int (*fun_associated)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct specifier specifier_type - Struct op
 *
 * @specifier: The format.
 * @specifier_type: The function associated.
 */
typedef struct specifier specifier_type;
/*________________________________________________________________________________________________*/
int _printf(const char *format, ...);
/*________________________________________________________________________________________________*/
int _specifier(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
/*________________________________________________________________________________________________*/
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
/*buffer*/
/*_____________________________________TASK : 0__________________________________________________________*/
int _char(va_list specifier, char buff[],
	int _flags, int _width, int _precision, int _size);
int _string(va_list specifier, char buff[],
	int _flags, int _width, int _precision, int _size);
int _percent(va_list specifier, char buff[],
	int _flags, int _width, int _precision, int _size);
/*______________________________________TASK : 1__________________________________________________________*/
int _int(va_list forme, char buff[],
	int _flag, int _width, int _precision, int _size);
/*______________________________________TASK : 2__________________________________________________________*/
int _binary(va_list args, char buff[],
	int _flag, int _width, int _precision, int _size);
/*______________________________________TASK : 3 __________________________________________________________*/
int _unsigned(va_list args, char buff[],
	int _flag, int _width, int _precision, int _size);
int _octal(va_list args, char buff[],
	int _flag, int _width, int _precision, int _size);
int _hexadecimal_low(va_list args, char buff[],
    int _flag, int _width, int _precision, int _size);
int _hexa_upper(va_list args, char buff[],
    int _flag, int _width, int _precision, int _size);
/*______________________________________TASK : 5_6 __________________________________________________________*/
int _non_printable(va_list args, char buff[],
    int _flag, int _width, int _precision, int _size);
int _pointer(va_list args, char buff[],
	int _flag, int _width, int _precision, int _size);
/*______________________________________TASK : 13_14 __________________________________________________________*/
int _reverse(va_list args, char buff[],
	int _flag, int _width, int _precision, int _size);
int _rot13string(va_list args, char buff[],
	int _flag, int _width, int _precision, int _size);
/*_____________________________________files__________________________________________________________*/
int call_flag(const char *format, int *position);
int call_width(const char *forme, int *a, va_list printed_args);
int call_precision(const char *format, int *a, va_list printed_args);
int call_size(const char *format, int *a);
/*_______________________________________extra_funcs_______________________________________________________________*/
long int convert_num(long int num, int size);
void _buff(char buffer[], int *buff_ind);
int digit(char c);
int write_num(int id, char buff[],
	int _flag, int _width, int _prec,
	int len, char p, char c);
/*________________________________________extra_funcs1_________________________________________________________*/
long int convert_unsgnd(unsigned long int number, int _size);
int write_unsgnd(int negative, int id, char buff[],
    int _flag, int _width, int _precision, int _size);
int write_hexa_up(va_list args, char map_to[], char buff[],
	int _flag, char _flag2, int _width, int _precision, int _size);
/*________________________________________extra_funcs2_________________________________________________________*/
int write_p(char buff[], int id, int len,
	int _width, int _flag, char p, char c, int p_start);
/*____________________________________________________________________________________________*/
int write_number(int negative, int id, char buff[],
	int _flag, int _width, int _precision, int _size);
int write_char(char c, char buff[],
	int _flag, int _width, int _precision, int _size);
#endif /* MAIN_H */
