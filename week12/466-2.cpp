#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// --- 교재에 있다고 가정한 기존 베이스 클래스들 ---
class Monster {
protected:
    string name;
    int x, y;
public:
    Monster(string n, int x, int y) : name(n), x(x), y(y) {}
    virtual void move() = 0;
    virtual void print() {
        cout << name << " 위치: (" << x << ", " << y << ")" << endl;
    }
};

class Jiangshi : public Monster {
protected:
    bool moveHorizontal; // true면 가로, false면 세로 이동
public:
    Jiangshi(string n, int x, int y) : Monster(n, x, y), moveHorizontal(true) {}
    void move() override {
        int d = (rand() % 2 == 0) ? 1 : -1;
        if (moveHorizontal) x += d;
        else y += d;
    }
};
// --------------------------------------------------


// (1) 대각선으로만 움직이는 스좀비(Smombi) 클래스 추가
class Smombi : public Monster {
public:
    Smombi(string n, int x, int y) : Monster(n, x, y) {}
    void move() override {
        // x, y 각각 -1 또는 1만큼 동시에 이동하여 대각선 구현
        int dx = (rand() % 2 == 0) ? 1 : -1;
        int dy = (rand() % 2 == 0) ? 1 : -1;
        x += dx;
        y += dy;
    }
};

// (2) 일정 시간마다 방향을 바꾸는 수퍼 강시, 샹시(Siangshi) 클래스 추가
// 단, 반드시 기존 강시(Jiangshi) 클래스를 상속해서 구현함.
class Siangshi : public Jiangshi {
private:
    int timeCount;
    int changeInterval;
public:
    Siangshi(string n, int x, int y, int interval = 3)
        : Jiangshi(n, x, y), timeCount(0), changeInterval(interval) {}

    void move() override {
        timeCount++;
        if (timeCount >= changeInterval) {
            moveHorizontal = !moveHorizontal; // 가로/세로 방향 토글
            timeCount = 0; // 타이머 초기화
        }
        // 부모 클래스인 강시의 move()를 호출해 실제 이동 처리
        Jiangshi::move(); 
    }
};

// (3) 다른 몬스터 클래스를 상속한 자신만의 몬스터: 고스트 (순간이동)
class Ghost : public Monster {
public:
    Ghost(string n, int x, int y) : Monster(n, x, y) {}
    void move() override {
        // -2 ~ +2 칸씩 무작위 순간이동 (Teleport)
        x += (rand() % 5 - 2);
        y += (rand() % 5 - 2);
    }
};

// (4) main() 함수에서 테스트
int main() {
    srand((unsigned int)time(NULL));

    // 다형성을 위해 부모 클래스 포인터 배열 사용
    Monster* world[3];
    world[0] = new Smombi("스좀비", 0, 0);
    world[1] = new Siangshi("샹시", 5, 5, 3); // 3턴마다 방향 바뀜
    world[2] = new Ghost("고스트(텔레포트)", 10, 10);

    cout << "--- 몬스터 월드 시뮬레이션 시작 ---" << endl;
    
    // 5턴 동안 몬스터들의 움직임 테스트
    for (int i = 1; i <= 5; i++) {
        cout << "\n[ " << i << "턴 ]" << endl;
        for (int j = 0; j < 3; j++) {
            world[j]->move();
            world[j]->print();
        }
    }

    // 메모리 해제
    for (int i = 0; i < 3; i++) delete world[i];
    return 0;
}