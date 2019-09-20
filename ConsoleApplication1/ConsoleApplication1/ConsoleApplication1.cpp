#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	const int num = 100;
	vector <pair<int, int>> arr[num];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	sort(arr, arr + n);
	printf("%d %d", arr[n - 1].first, arr[n - 1].second);
}






/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main() {
	char a, b;
	string str1, str2, str3;
	scanf("%s %s", &str1, &str2);
	str3 = str1[str1.size() - 1] - '0' + str2[str2.size() - 1] - '0';
	str1.pop_back();
	str2.pop_back();
	a = str3[0] / 10;
	str3[0] = (str3[0] % 10) + '0';
	while (str1.size() > 0 || str2.size() > 0) {
		b = 0;
		if (str1.size()) {
			b = str1[str1.size() - 1] - '0';
			str1.pop_back();
		}
		if (str2.size()) {
			b = b + str2[str2.size() - 1] - '0';
			str2.pop_back();
		}
		b = b + a;
		a = b / 10;
		b = (b % 10) + '0';
		str3 = b + str3;
	}
	if (a > 0) {
		a = a + '0';
		str3 = a + str3;
	}
	printf("%s", str3);
	return 0;
}
*/