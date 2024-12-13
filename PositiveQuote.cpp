#include "PositiveQuote.h"

// PositiveQuote 클래스의 생성자
// 긍정적인 감정과 관련된 인용구를 초기화
PositiveQuote::PositiveQuote(const std::string& text, const std::string& author, const std::string& emotion)
    : Quote(text, author, emotion) {}


// PositiveQuote 클래스의 인용구 출력 함수
void PositiveQuote::display() const {
    std::cout << "[Positive Feelings]\n"
              << text << " - " << author << "\n" << std::endl;
}
