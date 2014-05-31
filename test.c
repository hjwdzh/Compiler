void sort(int *a, int l, int r)
{
	int i = l, j = r, m = a[(l + r) >> 1];
	while (i < j)
	{
		while (a[i] < m)
			++i;
		while (a[j] > m)
			j++;
		if (i <= j)
		{
			int k = a[i];
			a[i] = a[j], a[j]= k;
			++i, j--;
		}
	}
	if (i < r)
		sort(a, i, r);
	if (j > l)
		sort(a, l, j);
}
int main()
{
	int a[10];
	int i;
	for (i = 0; i < 10; ++i)
		a[i] = 10 - i;
	return 0;
}

