#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

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

int		count_beyond(int pow)
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
	char	*ret;
	char	*isteen;
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

	if (!(number > INT_MIN && number <= INT_MAX))
		return ("I'm afraid I am unable to process your selected number.");
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
			ret = write_mem(ret, "negative ", my_strlen(ret));
			sign *= sign;
		}
		i = num_size(number) % 3;
		j = my_pow(10, num_size(number));
		count = number > 10 ? count_beyond(num_size(number)) + 1: count_beyond(num_size(number));
		switch(i)
		{
			case 0:
				ret = write_mem(ret, digit[number / j], my_strlen(ret));
				ret = write_mem(ret, beyond[1], my_strlen(ret));
				if (number % j < 100 && number > 999)
					ret = write_mem(ret, beyond[count - 1], my_strlen(ret));
				break;
			case 1:
				if(checkifteen == 0)
					ret = write_mem(ret, digit[number / j], my_strlen(ret));
				ret = write_mem(ret, beyond[count], my_strlen(ret));
				break;
			case 2:
				isteen = number > ((2 * j) - 1) ? tens[number / j] : teens[(number % j) / (j / 10)];
				ret = write_mem(ret, isteen, my_strlen(ret));
				checkifteen = (number < (2 * j) - 1) && (number > j) ? 1 : 0;
				if (number % j < 100 && number > 100)
					ret = write_mem(ret, beyond[count - 1], my_strlen(ret));
				break;
		}
		lastnumber = number;
		number %= j;
	}
	return (ret);
}
