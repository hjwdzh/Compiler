int main()
{
	int n, i;
	int *a;
start:
	printf("Please enter number of digits to be sorted:\n");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("Number of digits should be larger than zero!\n\n");
        goto start;
	}
	a = (int*)malloc(sizeof(int)*i);
	printf("Please enter %d digits:\n", n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}
    printf("Sorting...\n");
    printf("Result:\n");
    for (i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
