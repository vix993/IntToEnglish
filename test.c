#include <stdio.h>
#include <stdlib.h>

char	*intToEnglish(int number);

int	main(int argc, char **argv)
{
	printf("%s = %s\n", argv[1], intToEnglish(atoi(argv[1])));
	printf("%d = %s\n", 1000, intToEnglish(1000));
	printf("%d = %s\n", 100000002, intToEnglish(100000002));
	printf("%d = %s\n", 234657388, intToEnglish(234657388));
	printf("%d = %s\n", 18589, intToEnglish(18589));
}
