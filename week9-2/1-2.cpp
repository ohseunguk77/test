class MyTime {
private:
    int hour, minute, second, milsec;

public:
    // 멤버 초기화 리스트 사용 (매개변수 없는 경우)
    MyTime() : hour(0), minute(0), second(0), milsec(0) {
    }

    // 멤버 초기화 리스트 사용 (매개변수 있는 경우)
    MyTime(int h, int m, int s, int ms) : hour(h), minute(m), second(s), milsec(ms) {
    }
};