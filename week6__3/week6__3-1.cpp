MyTime addTime(MyTime t1, MyTime t2) {
    MyTime result;
    result.minutes = (t1.minutes + t2.minutes) % 60;
    result.hours = t1.hours + t2.hours + (t1.minutes + t2.minutes) / 60;
    return result;
}