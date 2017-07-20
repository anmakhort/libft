#include "libft.h"

char **ft_strsplit_char(char const *s, char c) {
	if (!s) return NULL;
	// remove c chars from the beginning of s:
	size_t offset = 0, idx_end = ft_strlen(s)-1;
	char *last = (char *)s;
	while (s[offset] == c) offset++;
	last += offset;
	// the same thing, but for the end of s:
	while (s[idx_end] == c) --idx_end;
	// counters, pointers, splitted strings:
	size_t nfound = 0, c_count = 0;
	char *found = NULL, **splitted = NULL;
	// main loop through substrings of s:
	while ((found = ft_strfind_char(s+offset, c, &c_count)) != NULL \
		&& offset <= idx_end) {
		// indexes to cut some substring:
		ssize_t block_sz = (size_t)(found - last);
		size_t idx_start = (size_t)(last - (char *)s);
		// check if we are at the end,
		// or there are no parts left:
		if (block_sz <= 0) {
			if (!nfound) {
				offset += c_count;
				last = found + c_count;
				continue;
			} else break;
		}
		// current substring of s:
		char *sub = ft_strsub(s, idx_start, block_sz);
		if (!sub) { // clean-up and return NULL:
			ft_free_strsplit(&splitted);
			return NULL;
		}
		// check if memory to hold substrings was allocated:
		if (!splitted) {
			ALLOCATE_2D(splitted, char*, (++nfound))
			if (!splitted) {
				free(sub);
				return NULL;
			}
		} else { // if yes - reallocate to hold additional item:
			REALLOC_2D_SAFE(splitted, char*, \
				(++nfound), ft_free_strsplit, free(sub);)
		}
		// shift offset to the beginning of the
		// next substring (or to end of string s):
		offset += c_count + ft_strlen(sub);
		// remember the beginning of the last read substring:
		last = found + c_count;
		// set pointer to substring:
		splitted[nfound-1] = sub;
	}
	// realloc to add one additional 'char*' to hold
	// end of array 'NULL' symbol:
	REALLOC_2D_SAFE(splitted, char*, (++nfound), ft_free_strsplit)
	splitted[nfound-1] = NULL;
	return splitted;
}