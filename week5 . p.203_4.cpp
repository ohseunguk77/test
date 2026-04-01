#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;

// 1. 퍼즐 크기 확장 및 상태 구조체
struct GameState {
    int size;
    vector<vector<int>> board;
    int moves;
    double playTime;
};

// 6. 랭킹 정보 구조체
struct Ranker {
    char name[20];
    int moves;
    double time;
};

class PuzzleGame {
private:
    GameState current;
    vector<vector<vector<int>>> history; // 2. 리플레이용 이력 저장

public:
    // (1) 맵 크기 확장 설정
    void initBoard(int s) {
        current.size = s;
        current.moves = 0;
        // 보드 초기화 및 셔플 로직...
        history.push_back(current.board); 
    }

    // (3) 게임 저장 기능 (텍스트/이진 혼합 가능하나 여기선 데이터 저장 위주)
    void saveGame() {
        ofstream outFile("savegame.dat", ios::binary);
        outFile.write((char*)&current.size, sizeof(int));
        for(int i=0; i<current.size; i++) {
            for(int j=0; j<current.size; j++) {
                outFile.write((char*)&current.board[i][j], sizeof(int));
            }
        }
        outFile.write((char*)&current.moves, sizeof(int));
        outFile.close();
        cout << "게임 저장 완료." << endl;
    }

    // (4) 이어가기 기능
    void loadGame() {
        ifstream inFile("savegame.dat", ios::binary);
        if(!inFile) return;
        inFile.read((char*)&current.size, sizeof(int));
        // 보드 크기에 맞춰 데이터 복구...
        inFile.close();
    }

    // (5) 그림 퍼즐 (아스키 아트 출력)
    void displayAsAscii() {
        for (auto& row : current.board) {
            for (int val : row) {
                if (val == 0) cout << "  "; // 빈칸
                else cout << (char)(val + 64) << " "; // 숫자를 알파벳 등으로 치환
            }
            cout << endl;
        }
    }

    // (6) 랭킹 저장 (이진 모드)
    void saveRanking(Ranker newRank) {
        vector<Ranker> rankings;
        // 기존 10개 읽어오기 (이진 모드)
        FILE* fp = fopen("ranking.bin", "rb");
        if(fp) {
            Ranker temp;
            while(fread(&temp, sizeof(Ranker), 1, fp)) rankings.push_back(temp);
            fclose(fp);
        }

        rankings.push_back(newRank);
        // 정렬 후 상위 10개 절삭
        sort(rankings.begin(), rankings.end(), [](Ranker a, Ranker b) {
            return a.moves < b.moves; 
        });

        fp = fopen("ranking.bin", "wb");
        for(int i=0; i < min((int)rankings.size(), 10); i++) {
            fwrite(&rankings[i], sizeof(Ranker), 1, fp);
        }
        fclose(fp);
    }

    // (2) 리플레이 기능
    void replay() {
        cout << "리플레이 시작..." << endl;
        for (const auto& step : history) {
            // step 출력 및 sleep 처리
        }
    }
};