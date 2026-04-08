#pragma once
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>

using namespace std;

class Game {
private:
    Player player;
    vector<Monster> monsters;
    bool isRunning;
    
    void SetConsoleColor(int color);
    void ClearConsole();
    void DisplayGameTitle();
    void DisplayPlayerStatus();
    void DisplayBattleUI(const Monster& monster);
    void DisplayHPBar(int current, int max);
    void DisplayMPBar(int current, int max);
    void ProcessPlayerTurn(Monster& monster, int choice);
    void ProcessMonsterTurn(Monster& monster);
    bool BattleSequence(Monster& monster);
    void CreateMonsters();
    void DisplayVictoryMessage(const Monster& monster);
    void DisplayDefeatMessage();
    void DisplayGameOver();
    
public:
    Game();
    void Run();
};

// 색상 설정 함수
void Game::SetConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 콘솔 클리어
void Game::ClearConsole() {
    system("cls");
}

// 게임 제목 표시
void Game::DisplayGameTitle() {
    SetConsoleColor(10); // 초록색
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║        C++ 텍스트 RPG 게임              ║" << endl;
    cout << "║     [마물을 물리치고 강해지세요!]        ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    SetConsoleColor(7); // 흰색
}

// 플레이어 상태 표시
void Game::DisplayPlayerStatus() {
    SetConsoleColor(11); // 밝은 파란색
    cout << "\n┌─────────────────────────────────────────┐" << endl;
    cout << "│        [플레이어 정보]                   │" << endl;
    cout << "├─────────────────────────────────────────┤" << endl;
    
    SetConsoleColor(7);
    cout << "│ 이름: " << player.GetName() << endl;
    cout << "│ 레벨: " << player.GetLevel() << " │ 경험치: " << player.GetExp() << "/" << player.GetMaxExp() << endl;
    
    SetConsoleColor(11);
    cout << "├─────────────────────────────────────────┤" << endl;
    
    SetConsoleColor(7);
    cout << "│ HP: ";
    DisplayHPBar(player.GetHP(), player.GetMaxHP());
    cout << endl;
    cout << "│ MP: ";
    DisplayMPBar(player.GetMP(), player.GetMaxMP());
    cout << endl;
    
    SetConsoleColor(11);
    cout << "├─────────────────────────────────────────┤" << endl;
    
    SetConsoleColor(7);
    cout << "│ 공격력: " << player.GetAttack() << " │ 방어력: " << player.GetDefense() << endl;
    cout << "│ 속도: " << player.GetSpeed() << endl;
    
    SetConsoleColor(11);
    cout << "└─────────────────────────────────────────┘" << endl;
    SetConsoleColor(7);
}

// 전투 UI 표시
void Game::DisplayBattleUI(const Monster& monster) {
    ClearConsole();
    DisplayGameTitle();
    DisplayPlayerStatus();
    
    SetConsoleColor(12); // 빨간색
    cout << "\n┌─────────────────────────────────────────┐" << endl;
    cout << "│        [전투 중!]                        │" << endl;
    cout << "├─────────────────────────────────────────┤" << endl;
    
    SetConsoleColor(7);
    cout << "│ 마물: " << monster.GetName() << endl;
    cout << "│ 레벨: " << monster.GetLevel() << endl;
    cout << "│ HP: ";
    DisplayHPBar(monster.GetHP(), monster.GetMaxHP());
    cout << endl;
    
    SetConsoleColor(12);
    cout << "└─────────────────────────────────────────┘" << endl;
    SetConsoleColor(7);
}

// HP 바 표시
void Game::DisplayHPBar(int current, int max) {
    int barLength = 20;
    int filledLength = (current * barLength) / max;
    
    SetConsoleColor(12); // 빨간색
    cout << "[";
    for (int i = 0; i < barLength; ++i) {
        if (i < filledLength) cout << "█";
        else cout << "░";
    }
    cout << "] " << current << "/" << max;
    SetConsoleColor(7);
}

// MP 바 표시
void Game::DisplayMPBar(int current, int max) {
    int barLength = 20;
    int filledLength = (current * barLength) / max;
    
    SetConsoleColor(9); // 파란색
    cout << "[";
    for (int i = 0; i < barLength; ++i) {
        if (i < filledLength) cout << "█";
        else cout << "░";
    }
    cout << "] " << current << "/" << max;
    SetConsoleColor(7);
}

// 플레이어 턴 처리
void Game::ProcessPlayerTurn(Monster& monster, int choice) {
    SetConsoleColor(10); // 초록색
    
    switch (choice) {
        case 1: { // 공격
            int damage = player.Attack();
            int realDamage = max(1, damage - monster.GetDefense() / 2);
            monster.TakeDamage(realDamage);
            cout << "► 플레이어가 " << monster.GetName() << "에게 " << realDamage << "의 피해를 입혔다!" << endl;
            break;
        }
        case 2: { // 방어
            cout << "► 플레이어가 몸을 날려 방어 자세를 취했다!" << endl;
            cout << "► 다음 턴 받는 피해가 50% 감소합니다!" << endl;
            player.Defense();
            break;
        }
        case 3: { // 스킬
            if (player.GetMP() >= 30) {
                int skillDamage = player.GetAttack() * 2;
                int realDamage = max(1, skillDamage - monster.GetDefense() / 2);
                monster.TakeDamage(realDamage);
                player.UseMana(30);
                cout << "► 플레이어가 강력한 스킬을 시전했다!" << endl;
                cout << "► " << monster.GetName() << "에게 " << realDamage << "의 치명적 피해!" << endl;
            } else {
                cout << "► MP가 부족합니다! (필요: 30, 현재: " << player.GetMP() << ")" << endl;
            }
            break;
        }
        case 4: { // 회복약
            cout << "► 플레이어가 회복약을 마셨다!" << endl;
            player.Heal(50);
            cout << "► HP가 50 회복되었습니다!" << endl;
            break;
        }
        default:
            cout << "► 잘못된 선택입니다!" << endl;
    }
    
    SetConsoleColor(7);
    cout << "\n[계속하려면 아무 키나 누르세요...]";
    _getch();
}

// 몬스터 턴 처리
void Game::ProcessMonsterTurn(Monster& monster) {
    if (monster.GetHP() <= 0) return;
    
    SetConsoleColor(12); // 빨간색
    int damage = monster.Attack();
    int realDamage = max(1, damage - player.GetDefense() / 2);
    player.TakeDamage(realDamage);
    cout << "► " << monster.GetName() << "이(가) 플레이어에게 " << realDamage << "의 피해를 입혔다!" << endl;
    SetConsoleColor(7);
    
    cout << "[계속하려면 아무 키나 누르세요...]";
    _getch();
}

// 전투 시퀀스
bool Game::BattleSequence(Monster& monster) {
    while (player.GetHP() > 0 && monster.GetHP() > 0) {
        DisplayBattleUI(monster);
        
        SetConsoleColor(14); // 노란색
        cout << "\n[선택]" << endl;
        cout << "1. 공격" << endl;
        cout << "2. 방어" << endl;
        cout << "3. 스킬 (MP 30 소비)" << endl;
        cout << "4. 회복약" << endl;
        cout << "Q. 도망치기" << endl;
        cout << "> ";
        
        SetConsoleColor(7);
        char input;
        cin >> input;
        
        if (input == 'Q' || input == 'q') {
            cout << "전투에서 도망쳤습니다!" << endl;
            return false;
        }
        
        int choice = input - '0';
        ProcessPlayerTurn(monster, choice);
        
        if (monster.GetHP() <= 0) {
            DisplayVictoryMessage(monster);
            player.GainExp(monster.GetExp());
            return true;
        }
        
        ProcessMonsterTurn(monster);
        
        if (player.GetHP() <= 0) {
            DisplayDefeatMessage();
            return false;
        }
    }
    
    return false;
}

// 몬스터 생성
void Game::CreateMonsters() {
    monsters.push_back(Monster("고블린", 1, 10, 5, 3, 1, 20));
    monsters.push_back(Monster("오크", 2, 20, 8, 5, 2, 50));
    monsters.push_back(Monster("드래곤", 5, 100, 20, 10, 5, 500));
    monsters.push_back(Monster("좀비", 1, 15, 4, 2, 1, 30));
    monsters.push_back(Monster("마법사", 3, 30, 12, 4, 3, 100));
}

// 승리 메시지
void Game::DisplayVictoryMessage(const Monster& monster) {
    SetConsoleColor(10); // 초록색
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║           ★ 승 리 ★                   ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "► " << monster.GetName() << "을(를) 물리쳤습니다!" << endl;
    cout << "► " << monster.GetExp() << "의 경험치를 획득했습니다!" << endl;
    
    if (player.GetLevel() > 1) {
        SetConsoleColor(14); // 노란색
        cout << "\n★ 레벨 업! ★" << endl;
        cout << "► 레벨: " << player.GetLevel() << endl;
        cout << "► 최대 HP: " << player.GetMaxHP() << endl;
        cout << "► 최대 MP: " << player.GetMaxMP() << endl;
        cout << "► 공격력: " << player.GetAttack() << endl;
        cout << "► 방어력: " << player.GetDefense() << endl;
    }
    
    SetConsoleColor(7);
}

// 패배 메시지
void Game::DisplayDefeatMessage() {
    SetConsoleColor(12); // 빨간색
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║           ✗ 패 배 ✗                   ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    SetConsoleColor(7);
}

// 게임 오버 메시지
void Game::DisplayGameOver() {
    SetConsoleColor(12); // 빨간색
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║       게임을 종료합니다. 안녕히!         ║" << endl;
    cout << "║  최종 레벨: " << player.GetLevel() << "  최종 경험치: " << player.GetExp() << "║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    SetConsoleColor(7);
}

// 게임 생성자
Game::Game() : isRunning(true) {
    player.SetName("플레이어");
    CreateMonsters();
}

// 게임 실행
void Game::Run() {
    while (isRunning) {
        DisplayGameTitle();
        DisplayPlayerStatus();
        
        SetConsoleColor(14); // 노란색
        cout << "\n[선택]" << endl;
        cout << "1. 전투 시작" << endl;
        cout << "Q. 게임 종료" << endl;
        cout << "> ";
        
        SetConsoleColor(7);
        char input;
        cin >> input;
        
        if (input == 'Q' || input == 'q') {
            isRunning = false;
            DisplayGameOver();
            break;
        }
        
        if (input == '1') {
            int monsterIndex = rand() % monsters.size();
            Monster monster = monsters[monsterIndex];
            BattleSequence(monster);
        }
        
        if (player.GetHP() <= 0) {
            isRunning = false;
            DisplayGameOver();
            break;
        }
    }
}