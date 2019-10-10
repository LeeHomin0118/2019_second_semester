#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
/*
덧셈:
a + b = a + b			0	solve
-a + b = b - a			1	solve
a + -b = a - b			1	solve
-a + -b = -(a + b)		0	solve
뺄셈
a - b = a - b			1	solve
-a - b = -(a + b)		0	solve
a - -b = a + b			0	solve
-a - -b = b - a			1	solve
*/
string sum(string x, string y, bool ckx, bool cky);
string sub(string x, string y, bool ckx, bool cky);
string multi(string x, string y, bool ckx, bool cky);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;
	string result;
	cout << "input X. ";
	cin >> a;
	cout << "input Y. ";
	cin >> b;
	bool cka = true, ckb = true;
	if (a[0] == '-') {
		a.erase(a.begin() + 0);
		cka = false;
	}
	if (b[0] == '-') {
		b.erase(b.begin() + 0);
		ckb = false;
	}
	//앞에 들어온 0을 지워줌
	while (1) {
		if (a.length() == 1) { break; }
		if (a[0] == '0') {
			a.erase(a.begin() + 0);
		}
		else { break; }
	}
	while (1) {
		if (b.length() == 1) { break; }
		if (b[0] == '0') {
			b.erase(b.begin() + 0);
		}
		else { break; }
	}
	if (cka == ckb) { result = sum(a, b, cka, ckb); }
	else { result = sub(a, b, cka, ckb); }
	cout << "X + Y = " << result << endl;
	if (cka == ckb) { result = sub(a, b, cka, ckb); }
	else { result = sum(a, b, cka, ckb); }
	cout << "X - Y = " << result << endl;
	result = multi(a, b, cka, ckb);
	cout << "X * Y = " << result << endl;
	return 0;
}

string sum(string x, string y, bool ckx, bool cky)			//더하기 함수
{
	int num;
	int carry = 0;
	string result;
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	while (x.length() < y.length()) {
		x += '0';
	}
	while (x.length() > y.length()) {
		y += '0';
	}
	for (int i = 0; i < x.length(); ++i) {
		num = (x[i] - '0' + y[i] - '0' + carry) % 10;
		result += to_string(num);
		carry = (x[i] - '0' + y[i] - '0' + carry) / 10;
		//cout << result << "   " << carry << "   " << i << endl;
	}
	if (carry != 0) {
		result += to_string(carry);
	}
	if (!ckx && !cky || ckx == false) {
		result += '-';
	}
	reverse(result.begin(), result.end());
	//printf("sum\n");
	return result;
}

string sub(string x, string y, bool ckx, bool cky)			//빼기 함수
{
	if (x == y && ckx == cky) {
		return "0";
	}
	string result;
	bool flag = false;
	bool flagneg = true;
	if ((ckx == false && cky == false) || (ckx == false)) {		//음수로 표기할것 flag 참
		flagneg = true;
	}
	//절댓값이 큰 수를 파악하고 위치를 잡아준다.
	//만약 위치가 바뀐다면 연산이 끝나고 -를 붙여준다.
	if (x.length() == y.length()) {
		for (int i = 0; i < x.length(); i++) {
			if (x[i] < y[i]) {
				string tmp = x;
				x = y;
				y = tmp;
				flag = true;	//끝나고 -를 붙인다는 flag
			}
		}
	}
	else {
		if (x.length() < y.length()) {
			string tmp = x;
			x = y;
			y = tmp;
			flag = true;
	}
	}
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	//cout << x << "   " << y << endl;
	int len = abs((int)(x.length() - y.length()));
	int lensave = x.length();
	for (int i = 0; i < len; i++) {
		y += '0';
	}
	for (int i = 0; i < y.length(); i++) {
		y[i] = '9' - y[i] + '0';
	}
	y[0]++;
	//cout << x << "   " << y << endl;
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	//cout << x << "   " << y << endl;
	result = sum(y, x, true, true);
	reverse(result.begin(), result.end());
	result.erase(lensave);
	reverse(result.begin(), result.end());
	while (1) {
		if (result.length() == 1) { break; }
		if (result[0] == '0') {
			result.erase(result.begin() + 0);
		}
		else { break; }
	}
	reverse(result.begin(), result.end());
	if (flag && flagneg) {
		result += '-';
	}
	reverse(result.begin(), result.end());
	//printf("sub-1\n");
	return result;
}

string multi(string x, string y, bool ckx, bool cky)		//곱하기 함수
{
	string result;
	if (x == "0" || y == "0") {
		return "0";
	}
	string tmpx = x;
	reverse(tmpx.begin(), tmpx.end());
	//카라츠바 algorithm
	for (int i = 0; i < x.length(); i++) {
		int cnt = tmpx[i] - '0';
		for (int i = 0; i < cnt; i++) {
			result = sum(result, y, true, true);
		}
		//cout << cnt << "  +  " << result << endl;
		//cout << y << endl;
		//cout << y << endl;
		y += "0";
		// << y << endl;
	}
	reverse(result.begin(), result.end());
	if (ckx != cky) {
		result += '-';
	}
	reverse(result.begin(), result.end());
	return result;
}

/*
string sum(string x, string y)		//더하기 함수
{
	int num;
	int carry = 0;
	string result;
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	while (x.length() < y.length()) {
		x += '0';
	}
	while (x.length() > y.length()) {
		y += '0';
	}
	for (int i = 0; i < x.length(); ++i) {
		num = (x[i] - '0' + y[i] - '0' + carry) % 10;
		result += to_string(num);
		carry = (x[i] - '0' + y[i] - '0' + carry) / 10;
		//cout << result << "   " << carry << "   " << i << endl;
	}
	if (carry != 0) {
		result += to_string(carry);
	}
	reverse(result.begin(), result.end());
	return result;
}

string sub(string x, string y)		//빼기 함수
{
	int num;
	int carry = 0;
	string result;
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	while (x.length() < y.length()) {
		x += '0';
	}
	while (x.length() > y.length()) {
		y += '0';
	}
	cout << x << endl;
	cout << y << endl;
	for (int i = 0; i < x.length(); ++i) {
		cout << "x " << x[i] - '0' - carry << endl;
		cout << "y " << y[i] << endl;
		cout << "i " << i << endl;
		if (((x[i] - '0') - carry) == -1) {
			num = (10 - (y[i] - '0') - carry) % 10;
			if (num != 0) {
				result += to_string(num);
			}
			carry = 1;
			printf("[1]\n");
		}
		else if ((y[i] - '0') <= (x[i] - '0') - carry) {
			num = ((x[i] - '0') - (y[i] - '0') - carry) % 10;
			if (num != 0) {
				result += to_string(num);
			}
			printf("[2]\n");
		}
		else {
			num = (10 - ((y[i] - '0') - ((x[i] - '0') + carry))) % 10;
			if (num != 0) {
				result += to_string(num);
			}
			carry = 1;
			printf("[3]\n");
		}
		cout << num << "   " <<  result << "   " << carry << "   " << i << endl;
	}
	reverse(result.begin(), result.end());
	return result;
}
*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;
string sum(string x, string y) {
	int num;
	int carry = 0;
	string result;
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	while (x.length() < y.length()) {
		x += '0';
	}
	while (x.length() > y.length()) {
		y += '0';
	}
	for (int i = 0; i < x.length(); ++i) {
		num = (x[i] - '0' + y[i] - '0' + carry) % 10;
		result += to_string(num);
		carry = (x[i] - '0' + y[i] - '0' + carry) / 10;
	}
	if (carry != 0) {
		result += to_string(carry);
	}
	reverse(result.begin(), result.end());
	return result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;
	string result;
	cin >> a >> b;
	result = sum(a, b);
	cout << result << endl;
	return 0;
}
*/