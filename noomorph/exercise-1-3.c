#define DEG (wint_t)176
#define safe_run(exitcode, expression) if (exitcode == 0) { exitcode = expression(); };

#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int repeat(char* s, int count) {
	for (int i = 0; i < count; i++) {
		printf("%s", s);
	}
}

float convert_to_celsius(int degree_in_fahrengeit) {
	return 5.0 * (degree_in_fahrengeit - 32.0) / 9.0;
}

int print_conversion_table_header() {
	printf("%20s|%20s\n", "Fahrenheit", "Celsius");
	repeat("=", 41);
	printf("\n");
	return 0;
}

int print_conversion_table_body() {
	const float lower = 0, upper = 300, step = 20;
	float fahr = lower, celsius = 0.0;

	setlocale(LC_ALL, "");

	while (fahr <= upper) {
		celsius = convert_to_celsius(fahr);
		printf("%18.0f%lcF|%18.1f%lcC\n", fahr, DEG, celsius, DEG);
		fahr += step;
	}

	return 0;
}

int main()
{
	int code = 0;
	safe_run(code, print_conversion_table_header);
	safe_run(code, print_conversion_table_body);
	return code;
}
