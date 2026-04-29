class Monster {
    int nEnergy; // (1) 에너지 속성 추가
    // ... 기존 멤버 변수 (name, x, y 등) ...

public:
    // (2) 멤버 초기화 리스트를 이용한 에너지 100 초기화
    Monster(string n, int px, int py) 
        : name(n), x(px), y(py), nEnergy(100) { }
    
    // ... 이하 생략 ...
};