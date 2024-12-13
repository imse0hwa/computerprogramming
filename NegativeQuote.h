#ifndef NEGATIVEQUOTE_H
#define NEGATIVEQUOTE_H

#include "Quote.h"


// NegativeQuote 클래스 정의
// 부정적인 감정과 관련된 인용구를 나타내는 클래스
class NegativeQuote : public Quote {
public:
    // NegativeQuote 생성자
    // 인용구 텍스트, 작성자, 감정을 받아 초기화
    NegativeQuote(const std::string& text, const std::string& author, const std::string& emotion);

    // 인용구를 출력하는 함수 (오버라이딩)
    void display() const override;
};

#endif
