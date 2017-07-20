#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>

#define DEFAULT_BUFF_SIZE 512

#define REALLOC_SAFE(arr, size)     \
    char *tmp = realloc(arr, size); \
    if (!tmp) {                     \
        free(arr);                  \
        ft_putendl("realloc error!"); \
        return NULL;                \
    } else {                        \
        arr = tmp;                  \
    }

#define INITIAL_ARG_CHECK(dest, src, n)	\
	if (!dest || !src) return NULL;		\
	if (!n) return dest;

#define MIN(a,b) ((a < b) ? a : b)


extern int ft_sign(int n);

extern void *ft_memset(void *s, int c, size_t n);
extern void ft_bzero(void *s, size_t n);
extern void *ft_memcpy(void *dest, const void *src, size_t n);
extern void *ft_memccpy(void *dest, const void *src, int c, size_t n);
extern void *ft_memblockcpy(void *dest, const void * const begin, const void * const end);
extern void *ft_memmove(void *dest, const void *src, size_t n);
extern void *ft_memchr(const void *s, int c, size_t n);
extern int ft_memcmp(const void *s1, const void *s2, size_t n);

extern size_t ft_strlen(const char *s);
extern char *ft_strdup(const char *s);
extern char *ft_strndup(const char *s, size_t n);
extern char *ft_strcpy(char *dest, const char *src);
extern char *ft_strncpy(char *dest, const char *src, size_t n);
extern char *ft_strcat(char *dest, const char *src);
extern char *ft_strncat(char *dest, const char *src, size_t n);
extern char *ft_strchr(const char *s, int c);
extern char *ft_strrchr(const char *s, int c);
extern char *ft_strchrnul(const char *s, int c);
extern char *ft_strstr(const char *haystack, const char *needle);
extern int ft_strcmp(const char *s1, const char *s2);
extern int ft_strncmp(const char *s1, const char *s2, size_t n);

extern int ft_isascii(int c);
extern int ft_isupper(int c);
extern int ft_islower(int c);
extern int ft_isalpha(int c);
extern int ft_isdigit(int c);
extern int ft_isxdigit(int c);
extern int ft_isalnum(int c);
extern int ft_isspace(int c);
extern int ft_isprint(int c);
extern int ft_toupper(int c);
extern int ft_tolower(int c);

extern int ft_atoi(const char *nptr);
extern long ft_atol(const char *nptr);

extern size_t ft_n_digits_int(int number);
extern size_t ft_n_digits_long(long number);

extern char *ft_itoa(int number);
extern char *ft_ltoa(long number);

extern void *ft_memalloc(size_t size);
extern void ft_memdel(void **ptr);
extern char *ft_strnew(size_t size);
extern void ft_strdel(char **as);
extern void ft_strclr(char *s);

extern void ft_striter(char *s, void (*f)(char *));
extern void ft_striteri(char *s, void (*f)(unsigned int, char *));
extern char *ft_strmap(char const *s, char (*f)(char));
extern char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
extern char *ft_strsub(char const *s, unsigned int start, size_t len);
extern char *ft_strjoin(char const *s1, char const *s2);
extern char *ft_strtrim(char const *s);
extern int ft_strequ(char const *s1, char const *s2);
extern int ft_strnequ(char const *s1, char const *s2, size_t n);

extern char *ft_strfind_char(const char const *s, const char c, size_t *n_conseq);
extern char *ft_strfind_str(const char const *s, const char const *cstr, size_t *n_conseq);

#define ft_strfind(s,X,n) _Generic((X), \
    const char: ft_strfind_char, \
    char: ft_strfind_char, \
    const char *: ft_strfind_str, \
    char *: ft_strfind_str, \
    default: ft_strfind_char \
    )(s,X,n)

extern char **ft_strsplit_char(char const *s, char c);
extern char **ft_strsplit_str(char const *s, const char const *cstr);

#define ft_strsplit(s,X) _Generic((X), \
    const char: ft_strsplit_char, \
    char: ft_strsplit_char, \
    const char *: ft_strsplit_str, \
    char *: ft_strsplit_str, \
    default: ft_strsplit_char \
    )(s,X)

extern void ft_free_strsplit(char *** const s);

extern void ft_putchar(char c);
extern void ft_putstr(char const *s);
extern void ft_putendl(char const *s);
extern void ft_putnbr(int n);
extern void ft_putchar_fd(char c, int fd);
extern void ft_putstr_fd(char const *s, int fd);
extern void ft_putendl_fd(char const *s, int fd);
extern void ft_putnbr_fd(int n, int fd);

extern char *ft_readAll(const int fd);
extern char *ft_getnextline(const int fd);
extern void ft_free_getnextline();

typedef struct s_list {
    void *content;
    size_t content_size;
    struct s_list *next;
} t_list;

extern t_list *ft_lstnew(void const *content, size_t content_size);
extern void ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
extern void ft_lstdel(t_list **alst, void (*del)(void *, size_t));
extern void ft_lstadd(t_list **alst, t_list *new);
extern void ft_lstpush_back(t_list **alst, t_list *new);
extern void ft_lstpush_front(t_list **alst, t_list *new);
extern void ft_lstiter(t_list *lst, void (*f)(t_list *elem));
extern t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif