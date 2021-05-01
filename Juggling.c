void Juggling(char *ary, int n, int d)
{
	char temp;
	int i, j = 0;
	int jug_index;
	int GCD;

	if (d < 0)
	{
		GCD = gcd(-d, n);
		d *= -1;

		for (i = 0; i < GCD; i++)
		{
			temp = ary[i];
			j = i;
			while (1)
			{
				jug_index = (j + d) % n;

				if (jug_index == i)
					break;


				ary[j] = ary[jug_index];

				j = jug_index;
			}
			ary[j] = temp;

		}


	}
	else
	{
		GCD = gcd(d, n);
		for (i = 0; i < GCD; i++)
		{
			temp = ary[n - i - 1];
			j = n - i - 1;
			int temp_2 = i;
			while (1)
			{
				jug_index = j - d;

				if (jug_index < 0)
					jug_index += n;

				if (jug_index == n - i - 1)
					break;



				ary[j] = ary[jug_index];

				j = jug_index;
			}
			ary[j] = temp;

		}

	}
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);

}
