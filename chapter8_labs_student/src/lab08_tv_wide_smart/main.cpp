#include <iostream>
#include <string>
using namespace std;

/*
[Lab08] 생성자 매개변수 전달: TV -> WideTV -> SmartTV
------------------------------------------------------------
핵심
- 파생 클래스 생성자에서 초기화 리스트로 부모 생성자를 호출해
  "기본 클래스 부분"을 원하는 값으로 초기화한다.
- 상속이 여러 단계여도 똑같이 적용된다.

관찰 포인트
- SmartTV 생성자는 WideTV(...)를 선택하고,
  WideTV는 TV(size)를 선택한다.
------------------------------------------------------------
*/

class TV {
    int size;
public:
    TV() : size(20) {}
    TV(int size) : size(size) {}
    int getSize() const { return size; }
};

class WideTV : public TV {
    bool videoIn;
public:
    WideTV(int size, bool videoIn) : TV(size), videoIn(videoIn) {}
    bool getVideoIn() const { return videoIn; }
};

class SmartTV : public WideTV {
    string ipAddr;
public:
    SmartTV(string ip, int size) : WideTV(size, true), ipAddr(ip) {}
    string getIpAddr() const { return ipAddr; }
};

int main() {
    SmartTV htv("192.0.0.1", 32);
    cout << "size=" << htv.getSize() << "\n";
    cout << "videoIn=" << boolalpha << htv.getVideoIn() << "\n";
    cout << "IP=" << htv.getIpAddr() << "\n";
}
