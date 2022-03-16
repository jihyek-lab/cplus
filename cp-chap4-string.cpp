// ���� 4?11 string Ŭ������ �̿��� ���ڿ� ���� �� ���
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	// ��Ʈ�� ����
	string str; // �� ���ڿ��� ���� ��Ʈ�� ��ü ����
	string address("Seoul Korea");
	string copyAddress(address); // address�� ���ڿ��� ������ ��Ʈ�� ��ü ����

	char text[] = {'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0'}; // C-��Ʈ��
	string title(text); // "Love C++" ���ڿ��� ���� ��Ʈ�� ��ü ����

	// ��Ʈ�� ���
	cout << str << endl; // �� ��Ʈ��. �ƹ� ���� ��µ��� ����
	cout << address << endl;
	cout << copyAddress << endl;
	cout << text << ',' << title << endl;
} */

// ���� 4-12 string �迭 ����� ���ڿ� Ű �Է� ����
// 5 ���� string �迭�� �����ϰ� getline()�� �̿��Ͽ� ���ڿ��� �Է� �޾� ���� ������ ���� �ڿ� ������ ���ڿ��� ����϶�. ���ڿ� �񱳴� <, > �����ڸ� ������ �̿��ϸ� �ȴ�.

/*
-------- cin.getline()
public member function

�Ҽ��� std::istream::getline�̴�. �� istream Ŭ������ ����Լ��ν� getline�� �����Ѵ�. 
���� istream�� ��ü���� getline ����Լ��� ȣ���ؼ� ����� �� �ִ�.

����
istream& getline (char* s, streamsize n );
istream& getline (char* s, streamsize n, char delim );
ù��° �Ķ���ͷ� c-string�� ���ڵ��� ������ �� �ִ� char�� �迭�� �����ּҸ� �䱸�Ѵ�.
�ι�° �Ķ���ͷ�, s�� �ּҿ� ã�ư��� ������ ���ڵ��� �뷮�� ���ؾ��Ѵ�.(10�̶� ������ 9���� ���ڵ��� ����� �� �ִ� �������� \0 ���� ���� �ϹǷ�)
����° �Ķ���ͷ�, ������(delim)�� �Է��� �� �ִ�. cin ��ü�κ��� ���� �Է¹޾Ƽ� ��Ʈ���� ���� �迭�� ���� �Է��� ��, �����ڸ� ������ �����ڱ����� ���� �־��ش�.


-------- getline()
�׳� getline()�� �Ϲ��Լ�
�Ҽ��� std::getline(string)�̴�. std namespace�� ����� �Ϲ��Լ��̴�.
����
(1)
istream& getline (istream&  is, string& str, char delim);
istream& getline (istream&& is, string& str, char delim);
(2)
istream& getline (istream&  is, string& str);
istream& getline (istream&& is, string& str);
�����ε��� �Լ��� ������ �پ������� ũ�� ���캸��.
ù��° �Ķ���ͷ� istream ��ü�� ������ ���·� �޴´�. ���ͳݿ� �ִ� �����鿡 ù��° �Ķ���ͷ� �ַ� cin�� �ִµ� cin�� istream Ŭ������ ��ü�̹Ƿ� cin�� �� �� �ִ� ���̴�. (�ֿܼ��� �Է� ���� ���� �����ϴ� ������ ������)
�ι�° �Ķ���ͷ� cin.getline()�� ���̴� getline()�� �޸� �ڷ����� std::string�� ��ü�� �޴´�. cin.getline()�� ��� ���� �����ϴ� ������ char �� �迭�̾�����, �Ϲ��Լ��� getline()�� string ��ü�� ���� �����Ѵ�. (�̰� ū �����ΰ� ����)
����° �Ķ���ͷ� �����ڸ� �޴� �ٴ� ���� �����ϴ�
*/


/* 
#include <iostream>
#include <string>
using namespace std;

int main() {
	string names[5]; // ���ڿ� �迭 ����

	for(int i=0; i<5; i++) {
		cout << "Name" << i << " >> ";
		getline(cin, names[i], '\n');
	}
	
	string latter = names[0];
	for(int i=1; i<5; i++) {
		if(latter < names[i]) { // ���� ������ latter ���ڿ��� �տ� �´ٸ�
			latter = names[i]; // latter ���ڿ� ����
		}
	}
	cout << "The biggest string is " << latter << endl;
}
*/

// ���� 4-13 ���ڿ��� �Է� �ް� ȸ����Ű��
// ��ĭ�� �����ϴ� ���ڿ��� �Է� �ް�, �� ���ھ� �������� ȸ���ϵ��� ���ڿ��� �����ϰ� ����϶�. 
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;

	cout << "string >>  ";
	getline(cin, s, '\n'); // ���ڿ� �Է�
	int len = s.length(); // ���ڿ��� ����

	for(int i=0; i<len; i++) {
		string first = s.substr(0,1); // �� ���� ���� 1���� ���ڿ��� �и�
		string sub = s.substr(1, len-1); // ������ ���ڵ��� ���ڿ��� �и�
		s = sub + first; // �� ���ڿ��� �����Ͽ� ���ο� ���ڿ��� ����
		cout << s << endl;
	}
}
*/

// ���� 4-14 ���ڿ� ó�� ���� - ���� ���ڿ��� �Է� �޾� ���� ����
// 4+125+4+77+102 ������ ǥ���� �������� ���ڿ��� �Է¹޾� ����ϴ� ���α׷� �ۼ��϶�
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "string (ex. 7+23+5+100+25) >> ";
	getline(cin, s, '\n'); // ���ڿ� �Է�
	int sum = 0;
	int startIndex = 0; // ���ڿ� ���� �˻��� ���� �ε���
	while(true) {
		int fIndex = s.find('+', startIndex);
		if(fIndex == -1) { // '+' ���� �߰��� �� ����
			string part = s.substr(startIndex);
			//if(part == "") break; // "2+3+", �� +�� ������ ���
			cout << part << endl;
			sum += stoi(part); // ���ڿ��� ���� ��ȯ�Ͽ� ���ϱ�
			break;
		}
		int count = fIndex - startIndex; // ���꽺Ʈ������ �ڸ� ���� ����
		string part = s.substr(startIndex, count); // startIndex���� count ���� ���ڷ� ���꽺Ʈ�� �����
		cout << part << endl;
		sum += stoi(part); // ���ڿ��� ���� ��ȯ�Ͽ� ���ϱ�
		startIndex = fIndex+1; // �˻��� ������ �ε��� ������Ŵ
	}
	cout << "The sum is " << sum << endl;
}


