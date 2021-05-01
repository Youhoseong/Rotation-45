void swap(char arr[], int a, int b, int d)
{
	for (int i = 0; i < d; ++i)
	{
		char temp = arr[a + i];
		arr[a + i] = arr[b + i];
		arr[b + i] = temp;
	}
}

void blockswap(char arr[], int n, int d)
{
	int temp = 0, pos_d = 0, temp_d = 0;
	if (d == 0 || d == n)
		return;
	else if (d < 0)	
	{
		pos_d = -d;
		int A_Block = pos_d;
		int B_Block = n - pos_d;
		while (A_Block != B_Block)
		{
			if (A_Block < B_Block)
			{
				swap(arr, pos_d - A_Block, pos_d + B_Block - A_Block, A_Block);
				B_Block -= A_Block;
			}
			else
			{
				swap(arr, pos_d - A_Block, pos_d, B_Block);
				A_Block -= B_Block;
			}
		}
		swap(arr, pos_d - A_Block, pos_d, A_Block);
	}
	else			
	{
		temp_d = (n - d);
		int A_Block = temp_d;
		int B_Block = n - temp_d;
		while (A_Block != B_Block)
		{
			if (A_Block < B_Block)
			{
				swap(arr, temp_d - A_Block, temp_d + B_Block - A_Block, A_Block);
				B_Block -= A_Block;
			}
			else
			{
				swap(arr, temp_d - A_Block, temp_d, B_Block);
				A_Block -= B_Block;
			}
		}
		swap(arr, temp_d - A_Block, temp_d, A_Block);
	}
}
