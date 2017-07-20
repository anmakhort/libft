#include "libft.h"

char *ft_strfind_str(const char const *s, const char const *cstr, size_t *n_conseq) {
	if (!s || !cstr) return NULL;
	size_t len = ft_strlen(cstr);
	if (len == 1) return ft_strfind_char(s, cstr[0], n_conseq);
	char *found = ft_strstr(s, cstr);
	if (!found || !n_conseq) return found;
	*n_conseq = 1;
	char *ptr = found;
	while (ft_strnequ(ptr+len, cstr, len) != 0) {
		++(*n_conseq);
		ptr += len;
	}
	return found;
}