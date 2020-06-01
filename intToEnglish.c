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

int		my_pow(int num, int pow)
{
	int	temp;

	temp = 1;
	while (--pow)
	{
		temp *= num;
	}
	return (temp);
}

char		*intToEnglish(int number)
{
	int	i;
	int	j;
	int	sign;
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
		"", "", "", "hundred ", "thousand ", "million ", "billion "
	};
	number < 0 ? (sign = -1) : (sign = 1);
	number *= sign;
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
		i = num_size(number);
		printf("num_size %d\n", i);
		j = my_pow(10, num_size(number));
		switch(i)
		{
			case 1:
				ret = write_mem(ret, digit[number], my_strlen(ret));
				break;
			case 2:
				isteen = number > 19 ? tens[number / 10] : teens[number % 10];
				ret = write_mem(ret, isteen, my_strlen(ret));
				if (number > 19)
					ret = write_mem(ret, digit[number % 10], my_strlen(ret));
				break;
			case 3:
				printf("in here\n");
				ret = write_mem(ret, digit[number / 100], my_strlen(ret));
				ret = write_mem(ret, beyond[i], my_strlen(ret));
				break;
		}
		if (number < 100)
			break;
		printf("number end = %d\n", number);
		number %= my_pow(10, num_size(number));
		printf("number end = %d\n", number);
	}
	return (ret);
}
