#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

class inf_int
{
private:
	void Add(const char, const unsigned int);
	char* digits;
	unsigned int length;
	bool thesign;   // true if positive , false if negative.
					// ex) 15311111111111111 -> digits="1111 1111 1111 1135 1", length=17, thesign=true;
					// ex) -12345555555555 -> digits="5555 5555 5543 21", length=14, thesign=false
					// you may insert additional private members here.

public:
	inf_int();               // assign 0 as a default value
	inf_int(int);
	inf_int(const char*);
	inf_int(const inf_int&); // copy constructor
	~inf_int(); // destructor

	inf_int& operator=(const inf_int&); // assignment operator

	friend bool operator==(const inf_int&, const inf_int&);
	friend bool operator!=(const inf_int&, const inf_int&);
	friend bool operator>(const inf_int&, const inf_int&);
	friend bool operator<(const inf_int&, const inf_int&);

	friend inf_int operator+(const inf_int&, const inf_int&);
	friend inf_int operator-(const inf_int&, const inf_int&);
	friend inf_int operator*(const inf_int&, const inf_int&);
	// friend inf_int operator/(const inf_int& , const inf_int&); // not required

	friend std::ostream& operator<<(std::ostream&, const inf_int&);
	// friend istream& operator>>(istream& , inf_int&);    // not required
};

inf_int::inf_int()
{
	this->digits = new char[2];	// 동적할당

	this->digits[0] = '0';		// default 값 0 설정
	this->digits[1] = '\0';
	this->length = 1;
	this->thesign = true;
}

inf_int::inf_int(int n) {
	char buf[100];

	if (n < 0) {		// 음수 처리
		this->thesign = false;
		n = -n;
	}
	else {
		this->thesign = true;
	}

	int i = 0;
	while (n > 0) {			// 숫자를 문자열로 변환하는 과정
		buf[i] = n % 10 + '0';

		n /= 10;
		i++;
	}

	if (i == 0) {	// 숫자의 절댓값이 0일 경우
		new (this) inf_int();	// 생성자 재호출...gcc에서 컴파일에러가 있다고 함. inf_int()의 경우 별개의 인스턴스가 생성됨. 
	}
	else {
		buf[i] = '\0';

		this->digits = new char[i + 1];
		this->length = i;
		strcpy(this->digits, buf);
	}
}

inf_int::inf_int(const char* str)
{
	std::string s(str);
	if (s[0] == '-') {
		thesign = false;
		s.erase(s.begin() + 0);	//-일경우 없애줌
	}
	else {
		thesign = true;
	}

	std::reverse(s.begin(), s.end());
	length = s.length();
	const char* temp_str = s.c_str();
	digits = new char[length + 1];
	strcpy(digits, temp_str);

}

inf_int::inf_int(const inf_int& source) {
	this->digits = new char[source.length + 1];

	strcpy(this->digits, source.digits);
	this->length = source.length;
	this->thesign = source.thesign;
}

inf_int::~inf_int() {
	delete digits;		// 메모리 할당 해제
}

inf_int& inf_int::operator=(const inf_int& source)
{
	if (this->digits) {
		delete this->digits;		// 이미 문자열이 있을 경우 제거.
	}
	this->digits = new char[source.length + 1];

	strcpy(this->digits, source.digits);
	this->length = source.length;
	this->thesign = source.thesign;

	return *this;
}

bool operator==(const inf_int& source, const inf_int& dest)
{
	if (!strcmp(source.digits, dest.digits) && (source.thesign == dest.thesign)) {
		return true;
	}

	return false;
}

bool operator!=(const inf_int& source, const inf_int& dest)
{
	return !operator==(source, dest);
}

bool operator>(const inf_int& left, const inf_int& right)
{
	bool is_left_abs_big = false;
	//same
	if (operator==(left, right)) {
		return false;
	}

	//absolute value
	if (strlen(left.digits) > strlen(right.digits)) {
		is_left_abs_big = true;
	}
	else if (strlen(left.digits) == strlen(right.digits)) {
		int idx = strlen(left.digits);

		while (idx--) {
			int abs_judge = left.digits[idx] - right.digits[idx];
			if (abs_judge > 0) {
				is_left_abs_big = true;
				break;
			}
			else if (abs_judge == 0) {
				continue;
			}
			else {
				is_left_abs_big = false;
				break;
			}
		}
	}

	//sign
	if (left.thesign == right.thesign) {
		if (left.thesign == 0) {
			return !is_left_abs_big;
		}
		else {
			return is_left_abs_big;
		}
	}
	else {
		if (left.thesign == 1) {
			return is_left_abs_big;
		}
		else {
			return !is_left_abs_big;
		}
	}
}

bool operator<(const inf_int& left, const inf_int& right)
{
	if (operator>(left, right) || operator==(left, right)) {
		return false;
	}
	else {
		return true;
	}
}


inf_int operator+(const inf_int& a, const inf_int& b)
{
	inf_int c;
	unsigned int i;

	if (a.thesign == b.thesign) {	// 이항의 부호가 같을 경우 + 연산자로 연산
		for (i = 0; i < a.length; i++) {
			c.Add(a.digits[i], i + 1);
		}
		for (i = 0; i < b.length; i++) {
			c.Add(b.digits[i], i + 1);
		}

		c.thesign = a.thesign;

		return c;
	}
	else {	// 이항의 부호가 다를 경우 - 연산자로 연산
		c = b;
		c.thesign = a.thesign;

		return a - c;
	}
}

inf_int operator-(const inf_int& source, const inf_int& dest)
{
	inf_int left(source);
	inf_int right(dest);

	if (left == right) {
		return inf_int(0);
	}

	std::string str_normal;
	std::string str_complement;
	bool sign_flag = false;
	//+ - + (+a-b)
	if (source.thesign == 1 && dest.thesign == 1) {
		//작은수에서 큰 수를 뺄 경우, 자리를 바꾸고, 나중에 부호 변경
		if (operator<(left, right)) {
			right = source;
			left = dest;
			sign_flag = true;
		}
		std::string str_normal = left.digits;
		std::string str_complement = right.digits;

		//자릿수 보정
		int len_abs = abs((int)(str_normal.length() - str_complement.length()));
		for (int i = 0; i < len_abs; i++) {
			str_complement += '0';
		}

		//10의보수 만들기
		for (int i = 0; i < str_complement.length(); i++) {
			str_complement[i] = '9' - str_complement[i] + '0';
		}
		str_complement[0]++;

		reverse(str_complement.begin(), str_complement.end());
		reverse(str_normal.begin(), str_normal.end());

		inf_int a(str_complement.c_str());
		inf_int b(str_normal.c_str());
		inf_int result = a + b;

		//보수연산으로 인한 자리수 보정
		std::string cut(result.digits);
		reverse(cut.begin(), cut.end());
		cut.erase(cut.begin());

		for (int i = 0;;) {
			if (cut[i] == '0') {
				cut.erase(cut.begin());
			}
			else if (cut[i] != '0') {
				break;
			}
		}

		inf_int ret(cut.c_str());
		//작은수에서 큰 수를 빼는 경우였으면, 부호를 바꿔준다.
		if (sign_flag) {
			ret.thesign = false;
		}
		return ret;
	}

	//(-a+b) = -(+a-b)
	//- - - 이것은 -에 +를 더하는 것 --> +에서 -를 더하는 것
	if (source.thesign == 0 && dest.thesign == 0) {
		right = source;	left = dest;
		left.thesign = 1;
		right.thesign = 1;
		inf_int ret = left - right;

		return ret;
	}

	//(+a+b)
	//+ - -
	if (source.thesign == 1 && dest.thesign == 0) {
		right.thesign = 1;
		inf_int ret = left + right;
		ret.thesign = 1;
		return ret;
	}

	//(-a-b) = -(a+b)
	//- - +
	if (source.thesign == 0 && dest.thesign == 1) {
		left.thesign = 1;
		inf_int ret = left + right;
		ret.thesign = 0;
		return ret;
	}
}

inf_int operator*(const inf_int& cand, const inf_int& plier)
{
	inf_int mulcand = cand;
	inf_int mulplier = plier;
	inf_int result(0);
	mulcand.thesign = true;
	mulplier.thesign = true;

	for (int i = 0; i < strlen(cand.digits); i++) {
		int pluscnt = cand.digits[i] - '0';
		for (int i = 0; i < pluscnt; i++) {
			result = result + mulplier;
		}
		std::string plier_plus_0(mulplier.digits);
		if (strcmp(plier_plus_0.c_str(), "0")) {
			plier_plus_0 = "0" + plier_plus_0;
		}
		std::reverse(plier_plus_0.begin(), plier_plus_0.end());
		mulplier = *(new inf_int(plier_plus_0.c_str()));
	}

	if (cand.thesign ^ plier.thesign) {
		result.thesign = false;
	}

	if (!strcmp(result.digits, "0")) {
		result.thesign = true;
	}

	return result;
}


std::ostream& operator<<(std::ostream& out, const inf_int& source)
{
	int i;

	if (source.thesign == false) {
		out << '-';
	}
	for (i = source.length - 1; i >= 0; i--) {
		out << source.digits[i];
	}
	return out;
}

void inf_int::Add(const char num, const unsigned int index)	// a의 index 자리수에 n을 더한다. 0<=n<=9, ex) a가 391일때, Add(a, 2, 2)의 결과는 411
{
	if (this->length < index) {
		this->digits = (char*)realloc(this->digits, index + 1);

		if (this->digits == NULL) {		// 할당 실패 예외처리
			std::cout << "Memory reallocation failed, the program will terminate." << std::endl;
			exit(0);
		}

		this->length = index;					// 길이 지정
		this->digits[this->length] = '\0';	// 널문자 삽입
	}

	if (this->digits[index - 1] < '0') {	// 연산 전에 '0'보다 작은 아스키값인 경우 0으로 채움. 쓰여지지 않았던 새로운 자리수일 경우 발생
		this->digits[index - 1] = '0';
	}

	this->digits[index - 1] += num - '0';	// 값 연산


	if (this->digits[index - 1] > '9') {	// 자리올림이 발생할 경우
		this->digits[index - 1] -= 10;	// 현재 자릿수에서 (아스키값) 10을 빼고
		Add('1', index + 1);			// 윗자리에 1을 더한다
	}
}

int main()
{
	std::string a;
	std::string b;
	cin >> a >> b;
	inf_int aa(a.c_str());
	inf_int bb(b.c_str());
	cout << (aa + bb) << endl;
	cout << (aa - bb) << endl;
	cout << (aa * bb) << endl;
	return 0;
}

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