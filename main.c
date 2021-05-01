#include "Rotation.h"
void gendata(char* CharArrayOfLength, int N); //���� ���ڿ��� �����ϴ� �Լ� 
void printHead(); //�׸���� ����ϴ� �Լ� 

int main()
{	
	int choice = 1; 
	while (choice == 1)
	{
		char *CharArrayOfLength; //������ ���ڿ��� ���� 
		char *str; //���纻 ���ڿ� ����� 
		int d = 0, N = 0;
		clock_t start, finish;
		double duration1 = 0, duration2 = 0, duration3 = 0, duration4 = 0; // �ɸ� �ð�
		printf("���α׷� ������ ���ϸ� 1, �ߴ��� ���ϸ� 0�� �Է��ϼ���:");
		scanf("%d", &choice);
		if (choice == 0)
			return 0;

		printf("Array size�� d�� �Է��ϼ��� :");
		scanf("%d %d", &N, &d);

		str = (char *)malloc(sizeof(char) * (N + 1));
		CharArrayOfLength = (char *)malloc(sizeof(char) * (N + 1));
		srand(time(NULL));
		gendata(CharArrayOfLength, N);
		
		strcpy(str, CharArrayOfLength);
		start = clock();
		trivial(str, N, d);
		finish = clock();
		duration1 = (double)(finish - start) / CLOCKS_PER_SEC;
		
		strcpy(str, CharArrayOfLength);
		start = clock();
		Juggling(str, N, d);
		finish = clock();
		duration2 = (double)(finish - start) / CLOCKS_PER_SEC;

		strcpy(str, CharArrayOfLength);
		start = clock();
		blockswap(str, N, d);
		finish = clock();
		duration3 = (double)(finish - start) / CLOCKS_PER_SEC;

		strcpy(str, CharArrayOfLength);
		start = clock();
		reverse(str, N, d);
		finish = clock();
		duration4 = (double)(finish - start) / CLOCKS_PER_SEC;

		printHead();
		printf("\n%d\t\t%d\t\t%f   %f   %f   %f\n", N, d, duration1, duration2, duration3, duration4);

		free(CharArrayOfLength);
	}

	return 0;
}

void gendata(char* CharArrayOfLength, int N)
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
		CharArrayOfLength[i] = (rand() % 26 + 'A');
	CharArrayOfLength[N] = NULL;
}

void printHead()
{
	printf("STRLength   ROTATEdistance\tT.trivial  T.juggle   T.bw      T.reverse");
}





















