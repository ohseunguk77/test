#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Monster {
    string name;
    char icon;
    int x, y;
    int nEnergy; // (1) 에너지 속성 추가
    static int nMonster; // (4) 정적 멤버 변수: 전체 몬스터 수

public:
    Monster(string n, char i, int px, int py) 
        : name(n), icon(i), x(px), y(py), nEnergy(100) { 
        nMonster++; // 생성 시 수 증가
    }
    
    virtual ~Monster() {
        nMonster--; // 소멸 시 수 감소
    }

    // (2) 에너지 반환 함수
    int getEnergy() { return nEnergy; }

    void eat() { nEnergy += 10; }
    
    // 에너지가 줄어드는 로직 (예시: 이동 시 감소)
    void decreaseEnergy() { nEnergy -= 5; }

    void print() {
        cout << name << icon << ":" << " E:" << nEnergy << " ";
    }

    // (4) 정적 멤버 함수: 현재 몬스터 수 출력
    static void printCount() {
        cout << "전체 몬스터의 수 : " << nMonster << endl;
    }
};

// 정적 변수 초기화
int Monster::nMonster = 0;

class MonsterWorld {
    Monster* pMon[100]; // 몬스터 포인터 배열
    int nMon;           // 현재 배열에 담긴 수

public:
    MonsterWorld() : nMon(0) {}

    // (3) 에너지가 0인 몬스터 체크 및 삭제
    void checkStarvation() {
        for (int i = 0; i < nMon; ) {
            if (pMon[i]->getEnergy() <= 0) {
                cout << "Monster 하나가 굶어죽습니다" << endl;
                delete pMon[i]; // 동적 해제

                // [Hint] k번째 항목 삭제 처리
                if (i != nMon - 1) {
                    pMon[i] = pMon[nMon - 1]; 
                }
                nMon--; 
                // 삭제 후 현재 인덱스(i)는 새로운 몬스터가 왔으므로 i를 증가시키지 않음
            } else {
                i++;
            }
        }
    }

    void display() {
        // ... 화면 그리기 로직 ...
        for(int i=0; i<nMon; i++) pMon[i]->print();
        cout << endl;
        Monster::printCount(); // (4) 정적 함수 호출
    }
};