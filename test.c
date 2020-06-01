#include <stdio.h>
#include <stdlib.h>

char	*intToEnglish(int number);

int	main(int argc, char **argv)
{
	printf("%s = %s\n", argv[1], intToEnglish(atoi(argv[1])));
}
