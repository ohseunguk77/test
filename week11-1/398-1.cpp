#include <iostream>
#include <cstring>
using namespace std;

class Sample {
    char *name;
    static int count; // (1) 정적 변수 선언

public:
    Sample() {
        name = NULL;
        count++;
    }

    // (2) 생성자: this와 new 활용
    Sample(const char* name) {
        int len = strlen(name);
        this->name = new char[len + 1];
        strcpy(this->name, name);
        count++;
    }

    // (4) 복사 생성자
    Sample(const Sample& s) {
        int len = strlen(s.name);
        this->name = new char[len + 1];
        strcpy(this->name, s.name);
        count++;
    }

    // (3) 소멸자: 동적 메모리 해제
    ~Sample() {
        if (name != NULL) delete[] name;
        count--;
    }

    // (1) 정적 출력 함수
    static void printCount() {
        cout << "현재 객체 개수: " << count << endl;
    }
};

// 정적 변수 외부 초기화
int Sample::count = 0;

void main() {
    Sample a("sample");
    Sample b(a); // 복사 생성자 호출
    Sample::printCount();
}