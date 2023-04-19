#include <unistd.h>
#include <stdio.h>

void	set_bit(char *ptr, short idx, short value)
{
	if (value == 1)
		(*ptr) |= (1<<idx);
	else
		(*ptr) &= ~(1<<idx);
}

int main(int argc, char const *argv[])
{
	char	ascii = 1;
	char	idx = 7;

	set_bit(&ascii, idx--, 0);
	set_bit(&ascii, idx--, 1);
	set_bit(&ascii, idx--, 0);
	set_bit(&ascii, idx--, 0);
	set_bit(&ascii, idx--, 0);
	set_bit(&ascii, idx--, 0);
	set_bit(&ascii, idx--, 0);
	set_bit(&ascii, idx--, 1);
	printf("%d", ascii);
	write(1, &ascii, 1);
	return 0;
}
