#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	unsigned long int	i;

	/* On demande 'a' et 'b' a l'utilisateur. */
	printf("Enter int a = ");
	scanf("%d", &a);
	printf("Enter int b = ");
	scanf("%d", &b);
	printf("\nDec a = %d\n", a);

	/* On affiche a en binaire avec le calcul "(a>>i) & 0b00000001)" */
	i = 0;
	printf("Bin a = ");
	while (i < sizeof(int) * 8)
	{
		printf("%d", (a>>i) & 0b00000001);
		++i;
	}

	/* On affiche b en binaire avec le calcul "(b>>i) & 1)" */
	printf("\n\nDec b = %d\n", b);
	i = 0;
	printf("Bin b = ");
	while (i < sizeof(int) * 8)
	{
		printf("%d", (b>>i) & 1);
		++i;
	}
	printf("\n\nATTENTION: la representation binaire est inversee a cause de la boucle\n");
	return (0);
}
