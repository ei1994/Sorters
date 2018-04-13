
using  namespace std;

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void heapBuild(int *a, int r, int len)
{
	int i, temp;
	temp = a[r];
	for (i = 2 * r; i < len; i *= 2)
	{
		if (i <len-1 && a[i] < a[i + 1])
		{
			i = i + 1;
		}
		if (a[i] <= temp)
		{
			break;
		}
		a[r] = a[i];
		r = i;
	}
	a[r] = temp;
}

void headSort(int *a, int len)
{
	int i;
	for (i = len / 2; i >= 0; --i) //use nodes(have child) creat heap
	{
		heapBuild(a, i, len);
	}

	for (i = len-1; i > 0; --i)
	{
		swap(a[0], a[i]);
		heapBuild(a, 0, i); //将调整后剩下的点调整为大根堆
	}
}



