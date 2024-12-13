#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

// Quote 클래스 정의
// 인용구의 기본 구조를 나타내는 추상 클래스

class Quote {
protected:
    std::string text;   //텍스트
    std::string author; //작성자
    std::string emotion; //관련 감정

public:
    // Quote 생성자
    // 텍스트, 작성자, 감정을 받아 초기화
    Quote(const std::string& text, const std::string& author, const std::string& emotion);
    
    virtual ~Quote();  // 가상 소멸자 선언

    virtual void display() const = 0; // 순수 가상 함수

    
    //감정,텍스트,작성자를 반환하는 함수
    std::string getEmotion() const;
    std::string getText() const;
    std::string getAuthor() const;

    // 연산자 오버로딩
    bool operator==(const Quote& other) const; // 두 Quote 객체 비교
    friend std::ostream& operator<<(std::ostream& os, const Quote& quote); // Quote 객체 출력
};

#endif
