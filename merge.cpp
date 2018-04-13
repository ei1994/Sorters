
#include "SortAll.h";
using namespace std;

void merge(int *sr, int *tr, int i, int m, int t)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m&&j <= t; ++k)
	{
		if (sr[i] < sr[j])
		{
			tr[k] = sr[i++];
		}
		else
		{
			tr[k] = sr[j++];
		}
	}
	if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
		{
			tr[k + l] = sr[i + l];
		}
	}
	if (j <= t)
	{
		for (l = 0; l <= t - j; l++)
		{
			tr[k + l] = sr[j + l];
		}
	}
}

void Msort(int *sr,int *tr1,int s, int t )
{
	int m;
	int tr2[MAXSIZE];
	if (s == t)
	{
		tr1[s] = sr[s];
	}
	else
	{
		m = (t+s) / 2;
		Msort(sr, tr2, s, m);
		Msort(sr, tr2, m + 1, t);
		merge(tr2, tr1, s, m, t);
	}

}

void mergeSort(int *a, int len)
{
	Msort(a, a, 0, len-1);
}


void mergePass(int *sr, int*tr, int s, int n)
{
	int i = 0;
	int j;
	while (i <= n - 2 * s + 1)
	{
		merge(sr, tr, i, i + s - 1, i + 2 * s - 1);
		i = i + 2 * s;
	}
	if (i < n - s + 1)
	{
		merge(sr, tr, i, i + s - 1, n);
	}
	else
	{
		for (j = i; j <= n; j++)
		{
			tr[j] = sr[j];
		}
	}
}

void mergeSort1(int *a, int len) //非递归
{
	int *tr = new int[MAXSIZE];//申请动态数组，也称堆内存
	int k = 1;
	while (k < len)
	{
		mergePass(a, tr, k, len-1);
		k = 2*k;
		mergePass(tr, a, k, len-1);//怎么样都把最后的排序结果放到原数组中了
		k = 2*k;
	}
	delete[]tr;
}