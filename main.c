#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;

	len = _printf("Test Case 1: Character - %c\n", 'A');
	_printf("Number of characters printed: %d\n\n", len);

	len = _printf("Test Case 2: String - %s\n", "Hello, World!");
	_printf("Number of characters printed: %d\n\n", len);

	len = _printf("Test Case 3: Percent - %%\n");
	_printf("Number of characters printed: %d\n\n", len);

	len = _printf("Test Case 4: Multiple Specifiers - %c, %s, %%, %i\n", 'B', "Testing", -6058);
	_printf("Number of characters printed: %d\n\n", len);

	len = _printf("Test Case 5: Empty String - %s\n", "");
	_printf("Number of characters printed: %d\n\n", len);

	return (0);
}
