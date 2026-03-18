#include <iostream>
#include <string>
using namespace std;

/*
[Lab03] 생성자 매개변수 전달: TV -> WideTV -> SmartTV
------------------------------------------------------------
문제 설명
1) 파생 클래스가 초기화 리스트로 부모 생성자를 선택하는 과정을 확인한다.
2) 다단계 상속에서도 동일 규칙이 적용됨을 확인한다.
------------------------------------------------------------
핵심 요약
- 파생 생성자 : Base(...)로 기본 클래스 초기화
- 상속 단계가 많아도 "부모 -> 자식" 순서로 초기화
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
