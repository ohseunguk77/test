void addTime(MyTime t1, MyTime t2, MyTime* pt) {
    if (pt != nullptr) {
        pt->minutes = (t1.minutes + t2.minutes) % 60;
        pt->hours = t1.hours + t2.hours + (t1.minutes + t2.minutes) / 60;
    }
}