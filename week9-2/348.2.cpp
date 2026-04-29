class MyTime {
private:
    int hour;
    int minute;
    int second;

public:
    // 기본 생성자 (필요 시)
    MyTime() : hour(0), minute(0), second(0) {}

    // 문제에서 요구하는 생성자 구현
    MyTime(double duration) {
        // 전체 초를 정수형으로 변환
        int totalSeconds = (int)duration;

        // 시, 분, 초 계산
        hour = totalSeconds / 3600;           // 1시간 = 3600초
        minute = (totalSeconds % 3600) / 60;  // 남은 초에서 분 계산
        second = totalSeconds % 60;           // 최종 남은 초 계산
    }

    void show() {
        cout << hour << "시 " << minute << "분 " << second << "초" << endl;
    }
};