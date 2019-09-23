#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> arr;
int arr[1000000];
int main() {
	int n, m, c1, c2;
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr[i] = { tmp, 0 };
	}
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr[n + i] = { tmp, 1 };
	}
}
