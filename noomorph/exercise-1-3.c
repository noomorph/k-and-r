#define DEG (wint_t)176

#include <locale.h>
#include <stdio.h>
#include <wchar.h>

float convert_to_celsius(int degree_in_fahrengeit) {
	return 5.0 * (degree_in_fahrengeit - 32.0) / 9.0;
}

int print_conversion_table() {
	const float lower = 0, upper = 300, step = 20;
	float fahr = lower, celsius = 0.0;

	setlocale(LC_ALL, "");

	while (fahr <= upper) {
		celsius = convert_to_celsius(fahr);
		printf("%3.0f%lcF\t%6.1f%lcC\n", fahr, DEG, celsius, DEG);
		fahr += step;
	}

	return 0;
}

int main()
{
	return print_conversion_table();
}
