#include <stdio.h>

#define EXPONENT_SIZE 8
#define MANTISSA_SIZE 23

union				u_double
{
	float		dbl;
	int			i;
};

void				print_bits_dbl(union u_double d)
{
	int			n;

	n = sizeof(d.dbl) * 8 - 1;
	while (n >= 0)
	{
		if (1 << n & d.i)
			printf("1");
		else
			printf("0");
		n--;
	}
	printf("\n");
}

void				print_bits_int(int i)
{
	int			n;

	//n = sizeof(i) * 8 - 1;
	n = MANTISSA_SIZE - 1;
	while (n >= 0)
	{
		if (1 << n & i)
			printf("1");
		else
			printf("0");
		n--;
	}
	printf("\n");
}

void				print_sign(union u_double d)
{
	if (d.i & 1 << (sizeof(d.dbl) * 8 - 1))
		printf("negative\n");
	else
		printf("positive\n");
}

unsigned int		get_exponent(union u_double d)
{
	int					exponent;
	int					exponent_n;
	int					d_n;


	exponent = 0;
	exponent_n = EXPONENT_SIZE - 1;
	d_n = sizeof(d.dbl) * 8 - 2;
	while (exponent_n >= 0)
	{
		if (d.i & 1 << d_n)
			exponent |= 1 << exponent_n;
		d_n--;
		exponent_n--;
	}
	exponent -= 0x7f;
	return (exponent);
}

unsigned int		get_mantissa(union u_double d)
{
	unsigned int		mantissa;
	int					mantissa_n;

	mantissa = 0;
	mantissa_n = MANTISSA_SIZE - 1;
	while (mantissa_n >= 0)
	{
		if (1 << mantissa_n & d.i)
			mantissa |= 1 << mantissa_n;
		mantissa_n--;
	}
	return (mantissa);
}

void				print_float(union u_double d)
{
	unsigned int			exponent;
	unsigned int			mantissa;

	print_sign(d);
	exponent = get_exponent(d);
	mantissa = get_mantissa(d);
}

int					main(void)
{
	union u_double			d;

	d.dbl = 85.125;
	print_float(d);

	return (0);
}
