void addTime(MyTime t1, MyTime t2, MyTime& t3) {
    t3.minutes = (t1.minutes + t2.minutes) % 60;
    t3.hours = t1.hours + t2.hours + (t1.minutes + t2.minutes) / 60;
}