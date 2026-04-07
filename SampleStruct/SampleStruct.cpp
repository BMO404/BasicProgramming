#include <cstdio>
#include "Student.h"


int main()
{
    printf("=== C++ 구조체와 멤버함수 예제 ===\n\n");

    // 학생 구조체 예제
    printf("[1. 학생 정보 구조체]\n");
    Student student1;
    student1.id = 20210001;
    snprintf(student1.name, sizeof(student1.name), "김철수");
    student1.gpa = 3.85;
    student1.age = 20;
    
    student1.printInfo();
    printf("\n");
    student1.checkHonors();
    
    // 다른 학생
    Student student2;
    student2.id = 20210002;
    snprintf(student2.name, sizeof(student2.name), "이영희");
    student2.gpa = 3.45;
    student2.age = 21;
    
    student2.printDetailedInfo();
    student2.checkHonors();

    // 상품 구조체 예제
    printf("[2. 상품 정보 구조체]\n");
    Product product1;
    product1.productId = 1001;
    snprintf(product1.productName, sizeof(product1.productName), "노트북");
    product1.price = 1500000.00;
    product1.quantity = 45;
    
    product1.printProduct();
    printf("\n");
    product1.calculateValue();
    printf("\n");
    product1.printStockStatus();
    printf("\n");
    
    // 다른 상품
    Product product2;
    product2.productId = 1002;
    snprintf(product2.productName, sizeof(product2.productName), "마우스");
    product2.price = 25000.00;
    product2.quantity = 150;
    
    product2.printProduct();
    printf("\n");
    product2.printStockStatus();
    printf("\n");

    // 직원 구조체 예제
    printf("[3. 직원 정보 구조체]\n");
    Employee employee1;
    employee1.employeeId = 5001;
    snprintf(employee1.employeeName, sizeof(employee1.employeeName), "박민준");
    snprintf(employee1.department, sizeof(employee1.department), "개발팀");
    employee1.salary = 4500000.00;
    employee1.yearsOfService = 8;
    
    employee1.printEmployee();
    printf("\n");
    employee1.calculateRaise();
    employee1.printCareerLevel();
    
    // 다른 직원
    Employee employee2;
    employee2.employeeId = 5002;
    snprintf(employee2.employeeName, sizeof(employee2.employeeName), "정수진");
    snprintf(employee2.department, sizeof(employee2.department), "마케팅팀");
    employee2.salary = 3800000.00;
    employee2.yearsOfService = 3;
    
    employee2.printEmployee();
    printf("\n");
    employee2.calculateRaise();
    employee2.printCareerLevel();

    // 책 구조체 예제
    printf("[4. 책 정보 구조체]\n");
    Book book1;
    book1.bookId = 101;
    snprintf(book1.title, sizeof(book1.title), "C++ 프로그래밍");
    snprintf(book1.author, sizeof(book1.author), "스콧 마이어스");
    book1.year = 2015;
    book1.rating = 4.7;
    
    book1.printBook();
    printf("\n");
    book1.printBookAge();
    printf("\n");
    book1.printRatingEvaluation();
    printf("\n");
    
    // 다른 책
    Book book2;
    book2.bookId = 102;
    snprintf(book2.title, sizeof(book2.title), "클린 코드");
    snprintf(book2.author, sizeof(book2.author), "로버트 C. 마틴");
    book2.year = 2008;
    book2.rating = 4.4;
    
    book2.printBook();
    printf("\n");
    book2.printBookAge();
    printf("\n");
    book2.printRatingEvaluation();
    printf("\n");

    // 배열로 여러 구조체 관리
    printf("[5. 구조체 배열]\n");
    Student students[3];
    
    students[0].id = 20210001;
    snprintf(students[0].name, sizeof(students[0].name), "학생1");
    students[0].gpa = 3.8;
    students[0].age = 20;
    
    students[1].id = 20210002;
    snprintf(students[1].name, sizeof(students[1].name), "학생2");
    students[1].gpa = 3.5;
    students[1].age = 21;
    
    students[2].id = 20210003;
    snprintf(students[2].name, sizeof(students[2].name), "학생3");
    students[2].gpa = 3.9;
    students[2].age = 20;
    
    printf("전체 학생 정보:\n");
    for (int i = 0; i < 3; i++) {
        printf("--- 학생 %d ---\n", i + 1);
        students[i].printInfo();
        printf("\n");
    }

    return 0;
}