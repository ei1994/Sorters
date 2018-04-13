
using namespace std;
 
void SelectSort(int *a, int arraySize)
{
	int i, j, min,temp;
	for (i = 0; i < arraySize-1; i++)
	{
		min = i;
		for (j = i + 1; j < arraySize; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}





