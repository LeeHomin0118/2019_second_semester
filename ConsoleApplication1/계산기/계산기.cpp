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
a + b = a + b			0	solve
-a + b = b - a			1
a + -b = a - b			1
-a + -b = -(a + b)		0	solve

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
	if (cka == ckb) {
		result = sum(a, b, cka, ckb);
	}
	else {
		result = sub(a, b, cka, ckb);
	}
	cout << "X + Y = " << result << endl;
	if (cka == ckb) {
		result = sub(a, b, cka, ckb);
	}
	else {
		result = sum(a, b, cka, ckb);
	}
	cout << "X - Y = " << result << endl;
	return 0;
}

string sum(string x, string y, bool ckx, bool cky)			//더하기 함수
{
	if (x == y && ckx != cky) {
		return "0";
	}
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
	return result;
}

string sub(string x, string y, bool ckx, bool cky)			//빼기 함수
{
	if (x == y && ckx == cky) {
		return "0";
	}
	string result;
	bool flag = false;
	if ((ckx && cky) || (ckx == false && cky == false)) {		//두 수가 모두 양수 or 음수인 경우
		bool flagneg = true;
		if (ckx == false && cky == false) {		//음수의 경우 두 flag 참
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
				y = x;
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
			if (result[0] == '0') {
				result.erase(result.begin() + 0);
			}
			else {
				break;
			}
		}
		reverse(result.begin(), result.end());
		if (flag && flagneg) {
			result += '-';
		}
		reverse(result.begin(), result.end());
		return result;
	}
}

string multi(string x, string y, bool ckx, bool cky)		//곱하기 함수
{
	if (x == "0" || y == "0") {
		return "0";
	}
	return x;
}


/*
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAX 256 //최대 자릿수 
int main()
{
	int count, len1, len2;
	char *ptr1, *ptr2;
	char num1[MAX + 1], num2[MAX + 1], sum[MAX + 2];

	cout << "input X. ";
	cin >> num1;
	cout << "input Y. ";
	cin >> num2;
	//큰수를 ptr1 으로 작은수를 ptr2 로 설정 
	if (strlen(num1) < strlen(num2)) { ptr1 = num2; ptr2 = num1; }
	else { ptr1 = num1; ptr2 = num2; }

	len1 = strlen(ptr1); len2 = strlen(ptr2);
	// sum 배열은 올림값으로 인해.. 큰수보다 1자리 크게 설정.. 
	sum[0] = '0'; sum[len1 + 1] = 0x00;
	// string 상태에서 더함, ptr2 - '0' 은.. ptr2만 문자를 수치로 변환.. 이중으로 더해짐을 방지. 
	for (count = 0; count < len2; count++)
		sum[len1 - count] = ptr1[len1 - count - 1] - (ptr2[len2 - count - 1] - '0');
	for (; count < len1; count++) sum[len1 - count] = ptr1[len1 - count - 1];

	// 내림값 처리부분 

	for (count = len1; count > 0; count--)
		if (sum[count] < '0') { sum[count - 1]--; sum[count] += 10; }
	if (sum[0] < '0') sum[0] = '-';
	printf("%s - %s = %s\n", num1, num2, (sum[0] == '0') ? &sum[1] : &sum[0]);

	return 0;
}




//[[[[ 추가사항 : 이 소스를 뺄셈으로 바꾸는 방법 ]]]]
  for ( count = 0; count < len2; count++ )
	sum[len1-count] = ptr1[len1-count-1] - (ptr2[len2-count-1] - '0');
  for ( ; count < len1; count++ ) sum[len1-count] = ptr1[len1-count-1];
  
// 내림값 처리부분 

  for ( count = len1; count > 0; count-- )
	if ( sum[count] < '0' ) { sum[count-1]--; sum[count] += 10; }
  if ( sum[0] < '0' ) sum[0] = '-';
  printf ( "%s - %s = %s\n", num1, num2, (sum[0] == '0') ? &sum[1] : &sum[0] );
  */



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