#include <stdlib.h>

int	ft_isdigit(int c)
{
	return (c >= 0x30 && c <= 0x39);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n != 0 && (*s1 != 0 || *s2 != 0))
	{
		if (*s1 != *s2)
		{
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		}
		n--;
		s1++;
		s2++;
	}
	return (0);
}

char*	ft_spelledout(const char *c)
{
	while (*c)
	{
		if (ft_isdigit(*c))
			break;
		if (!ft_strncmp(c, "one", 3))
			return ("1");
		else if (!ft_strncmp(c, "two", 3))
			return ("2");
		else if (!ft_strncmp(c, "three", 5))
			return ("3");
		else if (!ft_strncmp(c, "four", 4))
			return ("4");
		else if (!ft_strncmp(c, "five", 4))
			return ("5");
		else if (!ft_strncmp(c, "six", 3))
			return ("6");
		else if (!ft_strncmp(c, "seven", 5))
			return ("7");
		else if (!ft_strncmp(c, "eight", 5))
			return ("8");
		else if (!ft_strncmp(c, "nine", 4))
			return ("9");
		c++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strnum(const char *s)
{
	while (*s)
	{
		if (ft_isdigit(*s))
			return ((char *)s);
		else
		{
			if (ft_spelledout(s))
				return (ft_spelledout(s));
		}
		s++;
	}
	if (ft_isdigit(*s))
		return ((char *)s);
	return (NULL);
}

char	*ft_strrnum(const char *s)
{
	size_t	strl;

	strl = ft_strlen(s);
	while (strl)
	{
		if (ft_isdigit(s[strl]))
			return ((char *)(&s[strl]));
		else
		{
			if (ft_spelledout(&s[strl]))
				return (ft_spelledout(&s[strl]));
		}
		strl--;
	}
	if (ft_isdigit((int)s[strl]))
		return ((char *)s);
	return (NULL);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	i;
	int	sign;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]) == 1)
	{
		i++;
	}
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (nptr[i] == '+' || nptr[i] == '0')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - '0';
		i++;
	}
	return (nbr * sign);
}
