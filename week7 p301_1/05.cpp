#ifndef MYTIME_H
#define MYTIME_H

class MyTime {
private:
    int hours, minutes, seconds, milliseconds;
public:
    void convert(double duration);
    void print();
    MyTime add(MyTime t);
    void reset();
    void read();
};

#endif