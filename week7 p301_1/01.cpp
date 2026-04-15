class MyTime {
private:
    int hours, minutes, seconds, milliseconds;

public:
    inline void convert(double duration) {
        hours = (int)(duration / 3600);
        duration -= hours * 3600;
        minutes = (int)(duration / 60);
        duration -= minutes * 60;
        seconds = (int)duration;
        milliseconds = (int)((duration - seconds) * 1000);
    }

    inline void print(); // (3)에서 상세 구현
    
    inline MyTime add(MyTime t) {
        MyTime result;
        double t1_sec = hours * 3600 + minutes * 60 + seconds + milliseconds / 1000.0;
        double t2_sec = t.hours * 3600 + t.minutes * 60 + t.seconds + t.milliseconds / 1000.0;
        result.convert(t1_sec + t2_sec);
        return result;
    }

    inline void reset() {
        hours = minutes = seconds = milliseconds = 0;
    }
    
    inline void read(); // (4)에서 상세 구현
};