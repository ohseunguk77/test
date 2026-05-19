#include <iostream>

class Point {
protected:
    int x, y;
public:
    Point(int xx, int yy) : x(xx), y(yy) { }
    void draw() {
        std::cout << x << "," << y << "에 점을 그려라.\n";
    }
};

// (1) Point 클래스를 상속받은 Rectangle 클래스 정의
class Rectangle : public Point {
private:
    int width;  // 가로 길이 멤버 추가
    int height; // 세로 길이 멤버 추가

public:
    // (2) 생성자에서 부모 클래스(Point)의 x, y와 자식 클래스의 width, height를 멤버 초기화 리스트로 초기화
    Rectangle(int xx, int yy, int w, int h) : Point(xx, yy), width(w), height(h) { }

    // (3) Point 클래스의 draw 함수를 재정의(오버라이딩)
    void draw() {
        std::cout << x << "," << y << "에 가로 " << width << " 세로 " << height << "인 사각형을 그려라\n";
    }
};