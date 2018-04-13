
using namespace std;

//½µÐò
void BubbleSort(int *a, int arraySize)
{
	int i, j, temp;
	typedef int Status;
	Status flag = 1;
	for (i = 1; i < arraySize && flag; i++)
	{
		flag = 0;
		for (j = arraySize - 1; j > i; j--)
		{
			if (a[j] > a[j - 1])
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				flag = 1;
			}
		}
	}
}

//ÉýÐò
void BubbleSort1(int *a, int arraySize)
{
	int i, j, temp;
	typedef int Status;
	Status flag = 1;
	for (i = 1; i < arraySize && flag; i++)
	{
		flag = 0;
		for (j = 0; j <arraySize - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}
	}
}

//ÉýÐò£¬ÓÅ»¯
void BubbleSort2(int *a, int arraySize)
{
	int i, j, temp, pos, bound;
	pos = arraySize - 1;

	while (pos)
	{
		bound = pos;
		pos = 0;
		for (j = 0; j <bound; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				pos = j;

			}
		}
	}
}
