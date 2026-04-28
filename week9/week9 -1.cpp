#include <iostream>
#include <string>

// 복소수 클래스 정의
class Complex {
public:
    double real; // 실수부
    double imag; // 허수부

    // 생성자: 기본값은 0 + 0i
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 복소수 출력 함수
    void print() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }

    // -------------------------------------------------------------------------
    // 구현 방식 3: 멤버 함수, void, 참조 전달 (Image 0 참조)
    // 특징: 결과를 호출 객체(this) 자체에 저장합니다.
    // 장점: 불필요한 객체 복사가 발생하지 않아 성능이 좋습니다.
    // 단점: chaining (a.add(b).add(c)) 이 불가능하고 가독성이 낮습니다.
    // -------------------------------------------------------------------------
    void add_member_void(const Complex& a, const Complex& b) {
        this->real = a.real + b.real;
        this->imag = a.imag + b.imag;
    }

    // -------------------------------------------------------------------------
    // 구현 방식 4: 멤버 함수, return, 참조 전달 (Image 0 참조)
    // 특징: 'this' 객체와 인자로 받은 'b' 객체를 더해 새로운 Complex 객체를 반환합니다.
    // 장점: a.add(b) 형태로 직관적이며, chaining이 가능합니다.
    // 단점: 반환 시 새로운 객체 생성 및 복사가 발생할 수 있습니다.
    // -------------------------------------------------------------------------
    Complex add_member_return(const Complex& b) const {
        return Complex(this->real + b.real, this->imag + b.imag);
    }

    // -------------------------------------------------------------------------
    // 구현 방식 5: 연산자 오버로딩 (Image 0 참조)
    // 특징: '+' 연산자를 사용하여 a + b 형태로 자연스럽게 복소수 덧셈을 수행합니다.
    // 장점: 코드 가독성이 가장 좋고, 가장 직관적입니다. 컴파일러 최적화가 잘 됩니다.
    // 단점: 구현 및 이해에 연산자 오버로딩 지식이 필요합니다.
    // -------------------------------------------------------------------------
    Complex operator+(const Complex& b) const {
        return Complex(this->real + b.real, this->imag + b.imag);
    }
};

// -------------------------------------------------------------------------
// 구현 방식 1: 일반 함수, void, 참조 전달 (Image 0 참조)
// 특징: 세 번째 인자인 'result'에 덧셈 결과를 저장합니다.
// 장점: 불필요한 객체 복사가 최소화됩니다.
// 단점: 함수 호출 형태가 add(a, b, c)로 가독성이 낮습니다.
// -------------------------------------------------------------------------
void add_global_void(const Complex& a, const Complex& b, Complex& result) {
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
}

// -------------------------------------------------------------------------
// 구현 방식 2: 일반 함수, return, 값 전달 (Image 0 참조)
// 특징: 인자 'a'와 'b'가 값으로 전달되어 함수 내부에서 복사본이 생성됩니다.
// 장점: 함수 내부에서 원본 객체를 수정할 위험이 없습니다.
// 단점: 인자 전달 및 반환 시 객체 복사 비용이 가장 많이 듭니다.
// -------------------------------------------------------------------------
Complex add_global_return(Complex a, Complex b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

int main() {
    // [이미지 2의 실습 문제 조건]
    // a = 1+2i, b = 3+4i 로 설정
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c; // 결과를 저장할 객체

    std::cout << "--- 입력 값 ---" << std::endl;
    std::cout << "a = "; a.print();
    std::cout << "b = "; b.print();
    std::cout << "---------------" << std::endl << std::endl;


    // 각 구현 방식 테스트 및 결과 출력
    std::cout << "[1] 일반 함수, void, 참조 전달 (add(a, b, result))" << std::endl;
    add_global_void(a, b, c); // 결과는 c에 저장됨
    std::cout << "결과 c = "; c.print();
    std::cout << std::endl;


    std::cout << "[2] 일반 함수, return, 값 전달 (c = add(a, b))" << std::endl;
    c = add_global_return(a, b); // 반환값이 c에 대입됨
    std::cout << "결과 c = "; c.print();
    std::cout << std::endl;


    std::cout << "[3] 멤버 함수, void, 참조 전달 (c.add(a, b))" << std::endl;
    // 이 방식은 결과를 'this' 객체에 저장하므로, c 객체 자체의 함수를 호출해야 함
    c.add_member_void(a, b); 
    std::cout << "결과 c = "; c.print();
    std::cout << std::endl;


    std::cout << "[4] 멤버 함수, return, 참조 전달 (c = a.add(b))" << std::endl;
    c = a.add_member_return(b); // a와 b를 더한 새 객체가 c에 대입됨
    std::cout << "결과 c = "; c.print();
    std::cout << std::endl;


    std::cout << "[5] 연산자 오버로딩 (c = a + b)" << std::endl;
    c = a + b; // 가장 직관적이고 가독성이 좋음
    std::cout << "결과 c = "; c.print();
    std::cout << std::endl;

    return 0;
}