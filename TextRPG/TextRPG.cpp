#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void clearScreen() { system("cls || clear"); }
void pauseScreen() {
    cout << "\n[Enter를 누르면 계속합니다...]";
    cin.ignore(10000, '\n');
    cin.get();
}

// ================= Character 클래스 (부모) =================
class Character {
protected:
    string name;
    int hp, maxHp, mp, maxMp, attackPower;

public:
    Character(string n, int h, int m, int atk) 
        : name(n), hp(h), maxHp(h), mp(m), maxMp(m), attackPower(atk) {}

    virtual void displayStatus() const = 0; // 순수 가상 함수
    void takeDamage(int damage) { hp = max(0, hp - damage); }
    bool isDead() const { return hp <= 0; }
    string getName() const { return name; }
    int getHp() const { return hp; }
    int getMp() const { return mp; }
    int getAtk() const { return attackPower; }
};

// ================= 몬스터 클래스들 (다양화) =================
class Monster : public Character {
protected:
    int expReward;
    string art;
public:
    Monster(string n, int h, int m, int atk, int exp, string a) 
        : Character(n, h, m, atk), expReward(exp), art(a) {}
    
    int getExpReward() const { return expReward; }
    void displayStatus() const override {
        cout << art << "\n [" << name << "] HP: " << hp << "/" << maxHp << " | 공격력: " << attackPower << endl;
    }
};

class Slime : public Monster {
public:
    Slime() : Monster("슬라임", 30, 0, 5, 10, R"(
      _    _
     (o)  (o)
    (        )
     '------' )") {}
};

class Orc : public Monster {
public:
    Orc() : Monster("오크", 80, 0, 15, 40, R"(
     (o  o)
      (vv)
     /|--|\
    / |  | \ )") {}
};

class Dragon : public Monster {
public:
    Dragon() : Monster("드래곤", 250, 100, 40, 150, R"(
       <>=======()
     _/-_/  _ \(
    (oo )__/ _  \_
    ^^      ^^  ^^ )") {}
};

// ================= 플레이어 클래스 (스킬 및 MP 추가) =================
class Player : public Character {
private:
    int level, exp, maxExp;

public:
    Player(string n) : Character(n, 100, 60, 15), level(1), exp(0), maxExp(50) {}

    void levelUp() {
        level++; exp -= maxExp; maxExp += 30;
        maxHp += 30; hp = maxHp;
        maxMp += 20; mp = maxMp;
        attackPower += 7;
        cout << "\n✨ LEVEL UP! 현재 레벨: " << level << " ✨\n";
    }

    void gainExp(int e) {
        exp += e;
        cout << "경험치 " << e << " 획득! (" << exp << "/" << maxExp << ")\n";
        while (exp >= maxExp) levelUp();
    }

    // 3, 4번 조건: 다양한 스킬 및 MP 소모
    bool useSkill(int choice, Monster& target) {
        switch (choice) {
            case 1: // 일반 공격
                cout << "⚔️ 기본 공격! " << target.getName() << "에게 " << attackPower << " 데미지!\n";
                target.takeDamage(attackPower);
                return true;
            case 2: // 파워 스트라이크
                if (mp >= 15) {
                    int dmg = attackPower * 2;
                    mp -= 15;
                    cout << "🔥 [파워 스트라이크] (MP 15) 소모! 강한 일격: " << dmg << " 데미지!\n";
                    target.takeDamage(dmg);
                    return true;
                }
                break;
            case 3: // 힐 (자신)
                if (mp >= 20) {
                    mp -= 20;
                    int heal = 40;
                    hp = min(maxHp, hp + heal);
                    cout << "✨ [신성한 빛] (MP 20) 소모! 체력을 " << heal << " 회복했습니다!\n";
                    return true;
                }
                break;
        }
        cout << "❌ MP가 부족합니다!\n";
        return false;
    }

    void displayStatus() const override {
        cout << "==========================================\n";
        cout << " " << name << " (Lv." << level << ")\n";
        cout << " HP: " << hp << "/" << maxHp << " | MP: " << mp << "/" << maxMp << "\n";
        cout << " ATK: " << attackPower << " | EXP: " << exp << "/" << maxExp << "\n";
        cout << "==========================================\n";
    }
};

// ================= 게임 로직 =================
int main() {
    // 랜덤 seed를 생성하는 함수
    srand(time(NULL));
    cout << "용사의 이름: ";
    string name; cin >> name;
    Player player(name);

    while (!player.isDead()) {
        clearScreen();
        // 몬스터 랜덤 생성 (1, 2번 조건)
        int randMon = rand() % 3;
        Monster* monster;
        if (randMon == 0) monster = new Slime();
        else if (randMon == 1) monster = new Orc();
        else monster = new Dragon();

        cout << "\n⚠️ " << monster->getName() << "이(가) 나타났습니다!\n";
        pauseScreen();

        while (!monster->isDead() && !player.isDead()) {
            clearScreen();
            monster->displayStatus();
            player.displayStatus();

            cout << "\n[행동 선택]\n1. 공격 (MP 0)\n2. 파워 스트라이크 (MP 15)\n3. 힐 (MP 20)\nQ. 종료\n>> ";
            string input; cin >> input;
            if (input == "Q" || input == "q") { delete monster; return 0; }

            int choice = atoi(input.c_str());
            if (choice >= 1 && choice <= 3) {
                if (player.useSkill(choice, *monster)) {
                    // 몬스터 사망 체크
                    if (monster->isDead()) {
                        cout << "\n🎊 " << monster->getName() << " 처치!\n";
                        player.gainExp(monster->getExpReward());
                        pauseScreen();
                        break;
                    }
                    // 몬스터 반격
                    cout << "\n👹 " << monster->getName() << "의 반격! " << monster->getAtk() << " 데미지!\n";
                    player.takeDamage(monster->getAtk());
                    pauseScreen();
                } else {
                    pauseScreen();
                }
            }
        }
        delete monster;
        if (player.isDead()) cout << "당신은 쓰러졌습니다... Game Over.\n";
    }
    return 0;
}