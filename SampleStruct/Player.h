// 학생 정보 구조체
struct Student {
    int id;
    char name[50];
    double gpa;
    int age;
    
    // 멤버함수: 학생 정보 출력
    void printInfo() {
        printf("학번: %d\n", id);
        printf("이름: %s\n", name);
        printf("학점: %.2f\n", gpa);
        printf("나이: %d\n", age);
    }
    
    // 멤버함수: 학생 정보 상세 출력
    void printDetailedInfo() {
        printf("========== 학생 정보 ==========\n");
        printf("학번: %d\n", id);
        printf("이름: %s\n", name);
        printf("GPA: %.2f\n", gpa);
        printf("나이: %d세\n", age);
        printf("===============================\n");
    }
    
    // 멤버함수: 우등생 판정
    void checkHonors() {
        if (gpa >= 3.8) {
            printf("%s 학생은 우등생입니다 (GPA: %.2f)\n\n", name, gpa);
        } else {
            printf("%s 학생은 일반 학생입니다 (GPA: %.2f)\n\n", name, gpa);
        }
    }
};

// 상품 정보 구조체
struct Product {
    int productId;
    char productName[100];
    double price;
    int quantity;
    
    // 멤버함수: 상품 정보 출력
    void printProduct() {
        printf("상품ID: %d\n", productId);
        printf("상품명: %s\n", productName);
        printf("가격: %.2f원\n", price);
        printf("재고: %d개\n", quantity);
    }
    
    // 멤버함수: 총 재고 가치 계산
    void calculateValue() {
        double totalValue = price * quantity;
        printf("총 재고 가치: %.2f원\n", totalValue);
    }
    
    // 멤버함수: 재고 상태 출력
    void printStockStatus() {
        if (quantity > 100) {
            printf("재고 상태: 많음\n");
        } else if (quantity > 50) {
            printf("재고 상태: 중간\n");
        } else if (quantity > 0) {
            printf("재고 상태: 적음\n");
        } else {
            printf("재고 상태: 없음\n");
        }
    }
};

// 직원 정보 구조체
struct Employee {
    int employeeId;
    char employeeName[50];
    char department[50];
    double salary;
    int yearsOfService;
    
    // 멤버함수: 직원 정보 출력
    void printEmployee() {
        printf("직원ID: %d\n", employeeId);
        printf("이름: %s\n", employeeName);
        printf("부서: %s\n", department);
        printf("급여: %.2f원\n", salary);
        printf("근무 연수: %d년\n", yearsOfService);
    }
    
    // 멤버함수: 급여 인상 계산
    void calculateRaise() {
        double raise = salary * 0.05;
        double newSalary = salary + raise;
        printf("현재 급여: %.2f원\n", salary);
        printf("5%% 인상액: %.2f원\n", raise);
        printf("인상 후 급여: %.2f원\n\n", newSalary);
    }
    
    // 멤버함수: 경력 수준 판정
    void printCareerLevel() {
        if (yearsOfService >= 10) {
            printf("%s 직원의 경력 수준: 높음 (%d년)\n\n", 
                   employeeName, yearsOfService);
        } else if (yearsOfService >= 5) {
            printf("%s 직원의 경력 수준: 중간 (%d년)\n\n", 
                   employeeName, yearsOfService);
        } else {
            printf("%s 직원의 경력 수준: 신입 (%d년)\n\n", 
                   employeeName, yearsOfService);
        }
    }
};

// 책 정보 구조체
struct Book {
    int bookId;
    char title[100];
    char author[50];
    int year;
    double rating;
    
    // 멤버함수: 책 정보 출력
    void printBook() {
        printf("책ID: %d\n", bookId);
        printf("제목: %s\n", title);
        printf("저자: %s\n", author);
        printf("출판년도: %d\n", year);
        printf("평점: %.1f점\n", rating);
    }
    
    // 멤버함수: 책의 나이 계산
    void printBookAge() {
        int age = 2026 - year;
        printf("출판 이후 %d년 경과\n", age);
    }
    
    // 멤버함수: 평점 평가
    void printRatingEvaluation() {
        if (rating >= 4.5) {
            printf("평점 평가: 매우 훌륭함 (%.1f점)\n", rating);
        } else if (rating >= 4.0) {
            printf("평점 평가: 훌륭함 (%.1f점)\n", rating);
        } else if (rating >= 3.0) {
            printf("평점 평가: 보통 (%.1f점)\n", rating);
        } else {
            printf("평점 평가: 낮음 (%.1f점)\n", rating);
        }
    }
};