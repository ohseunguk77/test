--- 입력 값 ---
a = 1 + 2i
b = 3 + 4i
---------------

[1] 일반 함수, void, 참조 전달 (add(a, b, result))
결과 c = 4 + 6i

[2] 일반 함수, return, 값 전달 (c = add(a, b))
결과 c = 4 + 6i

[3] 멤버 함수, void, 참조 전달 (c.add(a, b))
결과 c = 4 + 6i

[4] 멤버 함수, return, 참조 전달 (c = a.add(b))
결과 c = 4 + 6i

[5] 연산자 오버로딩 (c = a + b)
결과 c = 4 + 6i