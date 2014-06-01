void sort(int *a, int l, int r)
{
    int i = l, j = r, m = a[(l + r) >> 1];
    while (i < j)
    {
        while (a[i] < m)
            ++i;
        while (a[j] > m)
            j--;
        if (i < j + 1)
        {
            int m = a[i];
            a[i] = a[j];
            a[j] = m;
            i++, --j;
        }
    }
    if (i < r)
        sort(a, i, r);
    if (j > l)
        sort(a, l, j);
}

int main()
{
	int n = 0, i;
	int *a = 0;
	while (n < 1)
	{
        printf("Please enter number of digits to be sorted:\n");
        scanf("%d", &n);
        if (n < 1)
            printf("Number of digits should be larger than zero!\n\n");
	}
	a = (int*)malloc(sizeof(int)*i);
	printf("Please enter %d digits:\n", n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}
    printf("Sorting...\n");
    sort(a, 0, n - 1);
    printf("Result:\n");
    for (i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}