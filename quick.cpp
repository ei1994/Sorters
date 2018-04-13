
using namespace std;

void qswap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int *a, int low, int high)
{
	
	int p = a[low];
	while (low < high)
	{
		while (low < high && p < a[high])
		{
			high--;
		}
		if (low<high)
			qswap(a[low], a[high]);
		while (low<high && a[low]<=p)
		{
			low++;
		}
		if(low<high)
			qswap(a[low], a[high]);
	}
	return low;
}

//用替换取代交换，提高效率。
int partition1(int *a, int low, int high)
{
	int p = a[low];

	while (low < high)
	{
		while (low < high && p < a[high])
		{
			high--;
		}
		if (low < high)
			a[low] = a[high];
			//qswap(a[low], a[high]);
		while (low<high && a[low] <= p)
		{
			low++;
		}
		if (low < high)
			a[high] = a[low];
			//qswap(a[low], a[high]);
	}
	a[low] = p;
	return low;
}

//算法导论上的另一种形式
int partition2(int *a, int low, int high)
{
	int p = a[high];
	int  j, i = low - 1;
	for (j = low; j < high; j++)
	{
		if (a[j] <= p)
		{
			++i;
			qswap(a[i], a[j]);
		}
	}
	qswap(a[i + 1], a[high]);
	return i + 1;


}

void QSort(int *a, int low, int high)
{
	//可以通过判断，当待排序数组大于一定值（50）时就快速排序，
	//否则就采用直接插入排序。
	int p;
	if (low < high)
	{
		p = partition2(a, low, high);
		QSort(a, low, p - 1);
		QSort(a, p + 1, high);
	}
}

void quickSort(int *a, int len)
{
	QSort(a, 0, len - 1);
}

