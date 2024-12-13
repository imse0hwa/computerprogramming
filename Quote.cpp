#include "Quote.h"


// Quote 클래스의 생성자 구현
// 텍스트, 작성자, 감정을 초기화
Quote::Quote(const std::string& text, const std::string& author, const std::string& emotion)
    : text(text), author(author), emotion(emotion) {}


// Quote 클래스의 가상 소멸자
Quote::~Quote() {
     // 소멸자 내용 없음
}

// 감정을 반환하는 함수
std::string Quote::getEmotion() const {
    return emotion;
}
// 인용구 텍스트를 반환하는 함수
std::string Quote::getText() const {
    return text;
}
// 작성자를 반환하는 함수
std::string Quote::getAuthor() const {
    return author; 
}

// 두 Quote 객체가 동일한지 비교
bool Quote::operator==(const Quote& other) const {
    return text == other.text && author == other.author && emotion == other.emotion;
}

// Quote 객체를 출력하는 연산자 오버로딩
std::ostream& operator<<(std::ostream& os, const Quote& quote) {
    os << '"' << quote.text << '"' << " - " << quote.author << " [" << quote.emotion << "]";
    return os;
}