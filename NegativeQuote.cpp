#include "NegativeQuote.h"

// NegativeQuote 클래스의 생성자
NegativeQuote::NegativeQuote(const std::string& text, const std::string& author, const std::string& emotion)
    : Quote(text, author, emotion) {}


// NegativeQuote 클래스의 인용구를 출력하는 함수
void NegativeQuote::display() const {
    std::cout << "[Negative Feelings]\n"
              << text << " - " << author << "\n" << std::endl;
}
