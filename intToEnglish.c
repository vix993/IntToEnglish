#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

unsigned int	num_size(int number)
{
	unsigned int	i;

	i = 0;
	while (number > 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

char		*write_mem(char *str, char *num, int pos)
{
	int	i;

	str = (char *)realloc(str,
			sizeof(char) * (my_strlen(str) + my_strlen(num) + 1));
	i = 0;
	while (num[i] != 0)
	{
		str[pos] = num[i];
		i++;
		pos++;
	}
	str[pos] = 0;
	return (str);
}

int		my_pow(int pow, int num_size)
{
	int	temp;

	temp = 1;
	while (--num_size)
	{
		temp *= pow;
	}
	return (temp);
}

int		count_beyond(int num, int pow)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (--pow)
	{

		if (i % 3 == 0)
			ret++;
		i++;
	}
	return (ret);
}

char		*intToEnglish(int number)
{
	int	i;
	int	j;
	int	count;
	int	checkifteen;
	int	sign;
	int	lastnumber;
	int	string_size;
	char	*ret;
	char	*isteen;
	char negative[] = "negative ";
	char *digit[] = {
		"", "one ", "two ", "three ", "four ", "five ",
		"six ", "seven ", "eight ", "nine "
	};
	char *teens[] = {
		"ten ", "eleven ", "twelve ", "thirteen ",
		"fourteen ", "fifteen ", "sixteen ", "seventeen ",
		"eighteen ", "nineteen "
	};
	char *tens[] = {
		"", "", "twenty ", "thirty ", "fourty ", "fifty ",
		"sixty ", "seventy ", "eighty ", "ninety "
	};
	char *beyond[] = {
		"", "hundred ", "thousand ", "million ", "billion ", "trillion "
	};
	number < 0 ? (sign = -1) : (sign = 1);
	number *= sign;
	checkifteen = 0;
	lastnumber = 0;
	if (number == 0)
		return ("zero");
	ret = (char *)malloc(sizeof(char) * 1);
	ret[0] = 0;
	while (number)
	{
		if (sign == -1)
		{
			ret = write_mem(ret, negative, my_strlen(ret));
			sign *= sign;
		}
		i = num_size(number) % 3;
		j = my_pow(10, num_size(number));
		count = number > 10 ? count_beyond(10, num_size(number)) + 1: count_beyond(10, num_size(number));
		printf("num_size %d\n", num_size(number));
		printf("my_pow %d\n", j);
		printf("i %d\n", i);
		printf("count %d\n", count);
		printf("is teen? %d\n", ((2 * j) - 1));
		switch(i)
		{
	//		case 0:
	//			if ((num_size(number) % 3) == 1)
	//				ret = write_mem(ret, digit[number / j], my_strlen(ret));
	//			ret = write_mem(ret, beyond[count], my_strlen(ret));
	//			break;
			case 0:
				ret = write_mem(ret, digit[number / j], my_strlen(ret));
				ret = write_mem(ret, beyond[1], my_strlen(ret));
				break;
			case 1:
				printf("%d\n", checkifteen);
				//if (checkifteen == 0)
				//	break;
				printf("in here");
				if(checkifteen == 0)
					ret = write_mem(ret, digit[number / j], my_strlen(ret));
				ret = write_mem(ret, beyond[count], my_strlen(ret));
				break;
			case 2:
				//if (my_strlen(ret) > 0)
				//	ret = write_mem(ret, "and ", my_strlen(ret));
				isteen = number > ((2 * j) - 1) ? tens[number / j] : teens[(number % j) / (j / 10)];
				ret = write_mem(ret, isteen, my_strlen(ret));
				checkifteen = (number < (2 * j) - 1) && (number > j) ? 1 : 0;
				printf("%d\n", checkifteen);
				//if (checkifteen == 1)
				//	ret = write_mem(ret, digit[number % 10], my_strlen(ret));
				break;
		}
		printf("number end = %d\n", number);
		lastnumber = number;
		number %= j;
		if (num_size(lastnumber) - num_size(number) > 2)
			ret = write_mem(ret, beyond[count - 1], my_strlen(ret));
		printf("number end = %d\n", number);
	}
	return (ret);
}
