
using namespace std;
#include <vector>;

void radix(int* a, int len ) {//times指最大值的位数
	int i, j, temp, l, base = 1, t, index;
	int times = 2;
	for (t = 1; t <= times; t++) { //个位、十位、百位、千位...
								   //内部使用的稳定排序为桶排序
		vector<int> v[10];//桶[0][1][2][3][4][5][6][7][8][9]
		for (i = 0; i < len; i++) {
			l = a[i] / base % 10;//取出当前位数的值，对应桶的位置
			v[l].push_back(a[i]);
			if (v[l].size() > 1) {
				for (j = v[l].size() - 1; j > 0; j--) {
					if (v[l][j] >= v[l][j - 1]) break; //等号可保证稳定排序,很重要
					temp = v[l][j];
					v[l][j] = v[l][j - 1];
					v[l][j - 1] = temp;
				}
			}
		}
		index = 0;
		for (i = 0; i < 10; i++) {
			for (j = 0; j < v[i].size(); j++) {
				a[index++] = v[i][j];
			}
		}
		base *= 10;
	}
}
