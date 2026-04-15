#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAXWORDS = 100;

struct WordPair {
    string eng;
    string kor;
};

class MyDic {
    WordPair words[MAXWORDS]; // 저장된 단어 배열
    int nWords;               // 현재 등록된 단어의 수

public:
    // 생성자: 단어 수를 0으로 초기화
    MyDic() : nWords(0) {}

    // add(): 하나의 단어를 배열에 추가
    inline void add(string eng, string kor) {
        if (nWords < MAXWORDS) {
            words[nWords].eng = eng;
            words[nWords].kor = kor;
            nWords++;
        } else {
            cout << "단어장이 가득 찼음." << endl;
        }
    }

    // load(): 파일에서 단어 읽기 (영어 한글 순서)
    inline void load(string filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "파일을 열 수 없음." << endl;
            return;
        }
        while (nWords < MAXWORDS && fin >> words[nWords].eng >> words[nWords].kor) {
            nWords++;
        }
        fin.close();
        cout << "파일 로드 완료." << endl;
    }

    // store(): 파일에 모든 단어 저장
    inline void store(string filename) {
        ofstream fout(filename);
        for (int i = 0; i < nWords; i++) {
            fout << words[i].eng << " " << words[i].kor << endl;
        }
        fout.close();
        cout << "파일 저장 완료." << endl;
    }

    // print(): 모든 단어를 화면에 출력
    inline void print() {
        cout << "--- 단어장 목록 ---" << endl;
        for (int i = 0; i < nWords; i++) {
            cout << setw(10) << words[i].eng << " : " << words[i].kor << endl;
        }
        cout << "------------------" << endl;
    }

    // getEng(): id번째 영어 단어 반환
    inline string getEng(int id) {
        if (id >= 0 && id < nWords) return words[id].eng;
        return "범위 초과";
    }

    // getKor(): id번째 한글 설명 반환
    inline string getKor(int id) {
        if (id >= 0 && id < nWords) return words[id].kor;
        return "범위 초과";
    }
};

int main() {
    MyDic myDic;

    // 1. 단어 등록 테스트
    myDic.add("apple", "사과");
    myDic.add("banana", "바나나");
    myDic.add("robot", "로봇");

    // 2. 출력 테스트
    myDic.print();

    // 3. 파일 저장 테스트
    myDic.store("dic.txt");

    // 4. 파일 읽기 테스트 (새로운 객체 생성)
    MyDic newDic;
    newDic.load("dic.txt");
    cout << "불러온 데이터 출력:" << endl;
    newDic.print();

    // 5. 개별 반환 기능 테스트
    cout << "0번 인덱스 단어: " << newDic.getEng(0) << " (" << newDic.getKor(0) << ")" << endl;

    return 0;
}