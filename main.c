#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	printf("REAL: Character: %c CH2: %c\n", 78, 'O');
	ft_printf("FAKE: Character: %c CH2: %c\n", 78, 'O');

	printf("REAL: String: %s\n", "Hello, World!");
	ft_printf("FAKE: String: %s\n", "Hello, World!");

	printf("REAL: Digit: %d\n", 42);
	ft_printf("FAKE: Digit: %d\n", 42);

	printf("REAL: Digit: %i\n", 021);
	ft_printf("FAKE: Digit: %i\n", 021);
	return (0);
}
