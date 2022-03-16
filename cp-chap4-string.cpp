// 예제 4?11 string 클래스를 이용한 문자열 생성 및 출력
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	// 스트링 생성
	string str; // 빈 문자열을 가진 스트링 객체 생성
	string address("Seoul Korea");
	string copyAddress(address); // address의 문자열을 복사한 스트링 객체 생성

	char text[] = {'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0'}; // C-스트링
	string title(text); // "Love C++" 문자열을 가진 스트링 객체 생성

	// 스트링 출력
	cout << str << endl; // 빈 스트링. 아무 값도 출력되지 않음
	cout << address << endl;
	cout << copyAddress << endl;
	cout << text << ',' << title << endl;
} */

// 예제 4-12 string 배열 선언과 문자열 키 입력 응용
// 5 개의 string 배열을 선언하고 getline()을 이용하여 문자열을 입력 받아 사전 순으로 가장 뒤에 나오는 문자열을 출력하라. 문자열 비교는 <, > 연산자를 간단히 이용하면 된다.

/*
-------- cin.getline()
public member function

소속이 std::istream::getline이다. 즉 istream 클래스의 멤버함수로써 getline이 존재한다. 
따라서 istream의 객체들은 getline 멤버함수를 호출해서 사용할 수 있다.

정의
istream& getline (char* s, streamsize n );
istream& getline (char* s, streamsize n, char delim );
첫번째 파라미터로 c-string의 문자들을 저장할 수 있는 char형 배열의 시작주소를 요구한다.
두번째 파라미터로, s의 주소에 찾아가서 저장할 문자들의 용량을 정해야한다.(10이라 적으면 9개의 문자들이 저장될 수 있다 마지막은 \0 널이 들어가야 하므로)
세번째 파라미터로, 제한자(delim)을 입력할 수 있다. cin 객체로부터 값을 입력받아서 스트림을 통해 배열에 값을 입력할 때, 제한자를 만나면 제한자까지만 값을 넣어준다.


-------- getline()
그냥 getline()은 일반함수
소속은 std::getline(string)이다. std namespace에 선언된 일반함수이다.
정의
(1)
istream& getline (istream&  is, string& str, char delim);
istream& getline (istream&& is, string& str, char delim);
(2)
istream& getline (istream&  is, string& str);
istream& getline (istream&& is, string& str);
오버로딩된 함수의 종류가 다양하지만 크게 살펴보자.
첫번째 파라미터로 istream 객체를 참조의 형태로 받는다. 인터넷에 있는 예제들에 첫번째 파라미터로 주로 cin을 넣는데 cin은 istream 클래스의 객체이므로 cin이 들어갈 수 있는 것이다. (콘솔에서 입력 받은 값을 저장하는 목적도 있지만)
두번째 파라미터로 cin.getline()에 쓰이는 getline()과 달리 자료형이 std::string인 객체를 받는다. cin.getline()의 경우 값을 저장하는 공간이 char 형 배열이었지만, 일반함수인 getline()은 string 객체에 값을 저장한다. (이게 큰 차이인것 같다)
세번째 파라미터로 제한자를 받는 다는 점은 동일하다
*/


/* 
#include <iostream>
#include <string>
using namespace std;

int main() {
	string names[5]; // 문자열 배열 선언

	for(int i=0; i<5; i++) {
		cout << "Name" << i << " >> ";
		getline(cin, names[i], '\n');
	}
	
	string latter = names[0];
	for(int i=1; i<5; i++) {
		if(latter < names[i]) { // 사전 순으로 latter 문자열이 앞에 온다면
			latter = names[i]; // latter 문자열 변경
		}
	}
	cout << "The biggest string is " << latter << endl;
}
*/

// 예제 4-13 문자열을 입력 받고 회전시키기
// 빈칸을 포함하는 문자열을 입력 받고, 한 문자씩 왼쪽으로 회전하도록 문자열을 변경하고 출력하라. 
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;

	cout << "string >>  ";
	getline(cin, s, '\n'); // 문자열 입력
	int len = s.length(); // 문자열의 길이

	for(int i=0; i<len; i++) {
		string first = s.substr(0,1); // 맨 앞의 문자 1개를 문자열로 분리
		string sub = s.substr(1, len-1); // 나머지 문자들을 문자열로 분리
		s = sub + first; // 두 문자열을 연결하여 새로운 문자열로 만듦
		cout << s << endl;
	}
}
*/

// 예제 4-14 문자열 처리 응용 - 덧셈 문자열을 입력 받아 덧셈 실행
// 4+125+4+77+102 등으로 표현된 덧셈식을 문자열로 입력받아 계산하는 프로그램 작성하라
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "string (ex. 7+23+5+100+25) >> ";
	getline(cin, s, '\n'); // 문자열 입력
	int sum = 0;
	int startIndex = 0; // 문자열 내에 검색할 시작 인덱스
	while(true) {
		int fIndex = s.find('+', startIndex);
		if(fIndex == -1) { // '+' 문자 발견할 수 없음
			string part = s.substr(startIndex);
			//if(part == "") break; // "2+3+", 즉 +로 끝나는 경우
			cout << part << endl;
			sum += stoi(part); // 문자열을 수로 변환하여 더하기
			break;
		}
		int count = fIndex - startIndex; // 서브스트링으로 자를 문자 개수
		string part = s.substr(startIndex, count); // startIndex부터 count 개의 문자로 서브스트링 만들기
		cout << part << endl;
		sum += stoi(part); // 문자열을 수로 변환하여 더하기
		startIndex = fIndex+1; // 검색을 시작할 인덱스 전진시킴
	}
	cout << "The sum is " << sum << endl;
}


