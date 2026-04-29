class MyTime {
private:
    int hour, minute, second, milsec;

public:
    // 매개변수가 없는 경우: 0으로 초기화
    MyTime() {
        hour = 0;
        minute = 0;
        second = 0;
        milsec = 0;
    }

    // 매개변수가 있는 경우: 전달받은 값으로 초기화
    MyTime(int h, int m, int s, int ms) {
        hour = h;
        minute = m;
        second = s;
        milsec = ms;
    }
};