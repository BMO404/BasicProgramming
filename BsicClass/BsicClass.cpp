/*
#include <cstdio>
#include <string>

// 간단한 학생 클래스
class Student {
private:
    int studentId;
    std::string name;
    double gpa;

public:
    // 생성자
    Student(int id, const std::string& studentName, double score)
        : studentId(id), name(studentName), gpa(score) {
        printf("[생성] 학생 '%s' 객체가 생성되었습니다 (ID: %d)\n", name.c_str(), studentId);
    }

    // 소멸자: 객체가 파괴될 때 이 소멸자 함수가 호출이 된다. 매인 함수가 끝날 때 호출됨
    ~Student() {
        printf("[소멸] 학생 '%s' 객체가 소멸됩니다\n", name.c_str());
    }

    // getter 메서드
    int getStudentId() const {
        return studentId;
    }

    std::string getName() const {
        return name;
    }

    double getGpa() const {
        return gpa;
    }

    // setter 메서드
    void setGpa(double newGpa) {
        if (newGpa >= 0.0 && newGpa <= 4.5) {
            gpa = newGpa;
            printf("[수정] %s의 GPA를 %.2f로 업데이트했습니다\n", name.c_str(), gpa);
        } else {
            printf("[오류] GPA 범위가 잘못되었습니다 (0.0 ~ 4.5)\n");
        }
    }

    // 정보 출력 메서드
    void displayInfo() const {
        printf("┌─ 학생 정보 ─────────────────────┐\n");
        printf("│ ID: %d\n", studentId);
        printf("│ 이름: %s\n", name.c_str());
        printf("│ GPA: %.2f\n", gpa);
        printf("└────────────────────────────────┘\n");
    }

    // 학점 평가 메서드
    const char* getGrade() const {
        if (gpa >= 4.0) return "A+";
        else if (gpa >= 3.5) return "A";
        else if (gpa >= 3.0) return "B+";
        else if (gpa >= 2.5) return "B";
        else if (gpa >= 2.0) return "C";
        else return "F";
    }
};

// 강사 클래스
class Instructor {
private:
    std::string instructorName;
    std::string subject;
    int yearsOfExperience;

public:
    // 생성자
    Instructor(const std::string& name, const std::string& subj, int years)
        : instructorName(name), subject(subj), yearsOfExperience(years) {
        printf("[생성] 강사 '%s' 객체가 생성되었습니다\n", instructorName.c_str());
    }

    // 소멸자
    ~Instructor() {
        printf("[소멸] 강사 '%s' 객체가 소멸됩니다\n", instructorName.c_str());
    }

    // 정보 출력
    void displayInfo() const {
        printf("┌─ 강사 정보 ─────────────────────┐\n");
        printf("│ 이름: %s\n", instructorName.c_str());
        printf("│ 과목: %s\n", subject.c_str());
        printf("│ 경력: %d년\n", yearsOfExperience);
        printf("└────────────────────────────────┘\n");
    }

    // 수업 시작
    void startClass() const {
        printf("[수업] %s 강사의 %s 수업이 시작됩니다!\n", 
               instructorName.c_str(), subject.c_str());
    }
};

int main() {
    printf("╔════════════════════════════════════════╗\n");
    printf("║    C++ 20 클래스 예시 애플리케이션     ║\n");
    printf("╚════════════════════════════════════════╝\n\n");

    // 1. Student 객체 생성
    printf("--- 1단계: 학생 객체 생성 ---\n");
    Student student1(1001, "Kim Min-jun", 3.85);
    Student student2(1002, "Lee Ji-woo", 3.45);
    printf("\n");

    // 2. Instructor 객체 생성
    printf("--- 2단계: 강사 객체 생성 ---\n");
    Instructor instructor1("Park Jung-ho", "C++ Programming", 8);
    printf("\n");

    // 3. 정보 표시
    printf("--- 3단계: 객체 정보 표시 ---\n");
    student1.displayInfo();
    printf("\n");
    student2.displayInfo();
    printf("\n");
    instructor1.displayInfo();
    printf("\n");

    // 4. 메서드 호출
    printf("--- 4단계: 메서드 호출 ---\n");
    instructor1.startClass();
    printf("\n");

    // 5. getter를 통한 정보 조회
    printf("--- 5단계: Getter를 통한 정보 조회 ---\n");
    printf("%s 학생의 GPA: %.2f (학점: %s)\n", 
           student1.getName().c_str(), 
           student1.getGpa(), 
           student1.getGrade());
    printf("%s 학생의 GPA: %.2f (학점: %s)\n\n", 
           student2.getName().c_str(), 
           student2.getGpa(), 
           student2.getGrade());

    // 6. setter를 통한 데이터 수정
    printf("--- 6단계: Setter를 통한 데이터 수정 ---\n");
    student1.setGpa(3.95);
    student2.setGpa(3.70);
    printf("\n");

    // 7. 수정 후 정보 재표시
    printf("--- 7단계: 수정 후 정보 재표시 ---\n");
    printf("%s 학생의 업데이트된 GPA: %.2f (학점: %s)\n", 
           student1.getName().c_str(), 
           student1.getGpa(), 
           student1.getGrade());
    printf("%s 학생의 업데이트된 GPA: %.2f (학점: %s)\n\n", 
           student2.getName().c_str(), 
           student2.getGpa(), 
           student2.getGrade());

    // 8. 동적 메모리 할당 예시
    printf("--- 8단계: 동적 메모리 할당 ---\n");
    Student* pStudent = new Student(2001, "Choi Soo-jin", 3.55);
    printf("동적 할당된 학생 정보:\n");
    pStudent->displayInfo();
    printf("동적 할당된 학생의 학점: %s\n\n", pStudent->getGrade());
    delete pStudent;
    printf("\n");

    printf("╔════════════════════════════════════════╗\n");
    printf("║         프로그램 종료 (소멸자 호출)     ║\n");
    printf("╚════════════════════════════════════════╝\n");

    return 0;
}
*/

#include <cstdio>

// 접근 지정자 예시 클래스
class Account {
private:
    // private: 클래스 내부에서만 접근 가능, 접근 지정자가 없으면 자동으로 private으로 선언됨
    double balance;

protected:
    // protected: 클래스 내부와 상속 클래스에서 접근 가능
    const char* accountType;

public:
    // public: 외부에서 접근 가능
    const char* owner;

    Account(const char* o, const char* type, double b) 
        : owner(o), accountType(type), balance(b) {
        printf("[생성] 계좌: %s (%s)\n", owner, accountType);
    }

    ~Account() {
        printf("[소멸] 계좌: %s\n", owner);
    }

    // public 메서드
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            printf("입금: %.2f원 (잔액: %.2f원)\n", amount, balance);
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            printf("출금: %.2f원 (잔액: %.2f원)\n", amount, balance);
        } else {
            printf("출금 실패: 잔액 부족\n");
        }
    }

    double getBalance() const {
        return balance;
    }

    void displayInfo() const {
        printf("소유자: %s, 유형: %s, 잔액: %.2f원\n", owner, accountType, balance);
    }
};

// 상속 클래스 (protected 접근 가능)
class PremiumAccount : public Account {
private:
    double interestRate;

public:
    PremiumAccount(const char* o, double b, double rate) 
        : Account(o, "Premium", b), interestRate(rate) {
        printf("[생성] 프리미엄 계좌 생성됨\n");
    }

    ~PremiumAccount() {
        printf("[소멸] 프리미엄 계좌\n");
    }

    void applyInterest() {
        // protected 멤버 접근 가능
        printf("%s 계좌에 이자율 %.2f%% 적용됨\n", accountType, interestRate);
    }
};

int main() {
    printf("=== C++ 20 접근 지정자 예시 ===\n\n");

    // 일반 계좌
    printf("--- 일반 계좌 ---\n");
    Account acc1("Kim", "Savings", 10000);
    acc1.owner = "Kim";  // public 접근 가능
    acc1.deposit(5000);
    acc1.withdraw(3000);
    // acc1.balance = 50000;  // 오류! private 접근 불가
    acc1.displayInfo();
    printf("\n");

    // 프리미엄 계좌
    printf("--- 프리미엄 계좌 ---\n");
    PremiumAccount premAcc("Lee", 50000, 3.5);
    premAcc.deposit(10000);
    premAcc.applyInterest();  // protected 멤버 접근 가능
    premAcc.displayInfo();
    printf("\n");

    printf("=== 프로그램 종료 ===\n");
    return 0;
}