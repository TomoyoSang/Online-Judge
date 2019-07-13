#include <iostream>
#include <cstdio>

#include <cstring>

using namespace std;

int paint[1200][1200] = { 0 };
int tuzhang[1200000][2] = { 0 };

int main()
{
	int T = 0;
	scanf("%d", &T);
	int m, n, p, q;

	for (; T > 0; --T)
	{
		memset(paint, 0, sizeof(paint));
		memset(tuzhang, 0, sizeof(tuzhang));

		scanf("%d%d%d%d", &m, &n, &p, &q);
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				scanf("%d", &paint[j][k]);
			}
		}

		int s = 0, counter = 0;
		for (int j = 0; j < p; j++)
		{
			for (int k = 0; k < q; k++)
			{
				scanf("%d", &s);
				if (s == 1)
				{
					tuzhang[counter][0] = j; tuzhang[counter][1] = k; counter++;
				}
			}
		}

		bool flag = true;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (paint[i][j])
				{
					for (int r = 0; r < counter; ++r) {
						int tuzhang1 = tuzhang[r][0] - tuzhang[0][0] + i,
							tuzhang2 = tuzhang[r][1] - tuzhang[0][1] + j;
						if (tuzhang1 < m&&tuzhang2 < n&&tuzhang1 >= 0 && tuzhang2 >= 0
							&& paint[tuzhang1][tuzhang2]) {
							paint[tuzhang1][tuzhang2] = 0;
						}
						else {
							flag = false;
							break;
						}
					}
				}
			}
			if (!flag)
				break;
		}

		
		if (!flag)cout << "No\n";
		else cout << "Yes\n";
	}
	
	return 0;


}