#include <iostream>
using namespace std;
/*
## 7. 상속 방식에 따른 접근 수준 변화

### public 상속
- 기반 클래스의 `public`은 파생 클래스에서도 `public`
- 기반 클래스의 `protected`는 파생 클래스에서도 `protected`

### protected 상속
- 기반 클래스의 `public`과 `protected`가 파생 클래스에서 `protected`

### private 상속
- 기반 클래스의 `public`과 `protected`가 파생 클래스에서 `private`

핵심:
- 상속 방식은 "파생 클래스 안에서 쓸 수 있느냐"보다
- "외부에서 그 멤버가 어떤 수준으로 보이느냐"를 바꾼다.

예:
```cpp
class D1 : public Base {};
class D2 : protected Base {};
class D3 : private Base {};
```

- `D1` 객체는 외부에서 `pub()` 호출 가능
- `D2`, `D3` 객체는 외부에서 `pub()` 호출 불가
*/
/*
[Lab09] 상속 접근 지정자

이 예제는 "파생 클래스 내부에서는 무엇이 보이는지"와
"외부(main)에서는 무엇을 호출할 수 있는지"를 분리해서 보여준다.

정리
- public 상속: Base의 public -> public, protected -> protected
- protected 상속: Base의 public/protected -> protected
- private 상속: Base의 public/protected -> private
- Base의 private 멤버는 어떤 상속 방식이어도 파생 클래스에서 직접 접근 불가

주의
- private 상속은 "Base의 멤버 자체가 전부 private 멤버로 바뀐다"는 뜻이 아니다.
- 정확히는 Derived의 관점에서 Base의 public/protected 멤버가 private처럼 보이게 된다.
- 그래서 Derived 내부에서는 여전히 사용할 수 있지만, Derived 외부에서는 직접 접근할 수 없다.
*/

class Base {
public:
    void publicFunc() {
        cout << "Base::publicFunc()\n";
    }

protected:
    void protectedFunc() {
        cout << "Base::protectedFunc()\n";
    }

private:
    int secret = 1234;
};

class PublicDerived : public Base {
public:
    void showInsideAccess() {
        cout << "[Inside PublicDerived]\n";
        publicFunc();
        protectedFunc();
        cout << "public stays public\n";
        cout << "protected stays protected\n";
        cout << '\n';
    }
};

class ProtectedDerived : protected Base {
public:
    void showInsideAccess() {
        cout << "[Inside ProtectedDerived]\n";
        publicFunc();
        protectedFunc();
        cout << "public becomes protected\n";
        cout << "outside access is blocked\n";
        cout << '\n';
    }

    void callBasePublicFromWrapper() {
        cout << "wrapper call\n";
        publicFunc();
        cout << '\n';
    }
};

class PrivateDerived : private Base {
public:
    void showInsideAccess() {
        cout << "[Inside PrivateDerived]\n";
        publicFunc();
        protectedFunc();
        cout << "public/protected become private\n";
        cout << "outside access is hidden\n";
        cout << "Base private is still inaccessible\n";
        cout << '\n';
    }

    void callBasePublicFromWrapper() {
        cout << "wrapper call\n";
        publicFunc();
        cout << '\n';
    }
};

int main() {
    PublicDerived pubObj;
    ProtectedDerived protObj;
    PrivateDerived privObj;

    cout << "1. Access inside derived classes\n\n";
    pubObj.showInsideAccess();
    protObj.showInsideAccess();
    privObj.showInsideAccess();

    cout << "2. Access from main\n\n";

    cout << "[PublicDerived]\n";
    pubObj.publicFunc();
    cout << "direct access allowed\n\n";

    cout << "[ProtectedDerived]\n";
    cout << "protObj.publicFunc(); // compile error\n";
    cout << "reason: now protected\n";
    protObj.callBasePublicFromWrapper();

    cout << "[PrivateDerived]\n";
    cout << "privObj.publicFunc(); // compile error\n";
    cout << "reason: now private\n";
    privObj.callBasePublicFromWrapper();

    /*
    아래 코드는 일부러 주석 처리했다.

    protObj.publicFunc();   // 에러: protected 멤버가 됨
    privObj.publicFunc();   // 에러: private 멤버가 됨

    pubObj.protectedFunc(); // 에러: protected는 원래부터 외부 접근 불가
    */

    return 0;
}
