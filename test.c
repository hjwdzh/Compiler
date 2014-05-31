const int c = 0;
int hello(int x, int y, int z)
{
	int d = x + 3;
	{
	   int d = x + 4;
	}
	{
	   int d = x + 5;
	}
	return 0;
	}
int main()
{
	return hello(1, 2, 3);
}
