
using namespace std;

void shellSort(int *a, int arraySize)
{
	int i, j, k, temp;
	int gap = arraySize;
	for (gap = arraySize / 2; gap > 0; gap /= 2)
	{
		for (i = 0; i < gap; i++)
		{
			for (j = i ; j < arraySize-gap; j += gap)
			{
				if (a[j] > a[j + gap])
				{
					temp = a[j + gap];
					k = j ;
					while (k >= 0 && a[k] > temp)
					{
						a[k +gap] = a[k];
						k -= gap;
					}
					a[k + gap] = temp;
				}
			}
		}
	}
}	
/*
很明显，上面的shellsort1代码虽然对直观的理解希尔排序有帮助，
但代码量太大了，不够简洁清晰。因此进行下改进和优化，以第二次排序为例，
原来是每次从1A到1E，从2A到2E，可以改成从1B开始，先和1A比较，然后取2B与2A比较，
再取1C与前面自己组内的数据比较…….。这种每次从数组第gap个元素开始，
每个元素与自己组内的数据进行直接插入排序显然也是正确的。*/
void shellSort1(int *a, int n)
{
	int j, gap;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (j = gap; j < n; j++)//从数组第gap个元素开始
			if (a[j] < a[j - gap])//每个元素与自己组内的数据进行直接插入排序
			{
				int temp = a[j];
				int k = j - gap;
				while (k >= 0 && a[k] > temp)
				{
					a[k + gap] = a[k];
					k -= gap;
				}
				a[k + gap] = temp;
			}
}

//shellSort2与shellSort1相同，前者是后者的重写
void shellSort2(int *a, int arraySize)
{
	int i, k, gap, temp;
	for (gap = arraySize / 2; gap > 0; gap /= 2)
	{
		for (i = 0; i < arraySize-gap ; i++)
		{
			if (a[i] > a[i + gap])
			{
				temp = a[i + gap];
				k = i;
				while (k >= 0 && a[k]>temp)
				{
					a[k + gap] = a[k];
					k -= gap;
				}
				a[k + gap] = temp;
			}
			
		}
	}
}
	



