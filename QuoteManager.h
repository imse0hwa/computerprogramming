#ifndef QUOTEMANAGER_H
#define QUOTEMANAGER_H

#include <vector>
#include <string>
#include "Quote.h"
#include "PositiveQuote.h"
#include "NegativeQuote.h"

// 감정이 긍정적인지 확인하는 함수 선언
bool isPositiveEmotion(const std::string& emotion);

// QuoteManager 클래스 정의
class QuoteManager {
private:
    std::vector<Quote*> positiveQuotes;
    std::vector<Quote*> negativeQuotes;

public:
    ~QuoteManager(); // 소멸자
     // 긍정적 인용구 파일 로드 함수
    void loadPositiveQuotesFromFile(const std::string& filename);
    // 부정적 인용구 파일 로드 함수
    void loadNegativeQuotesFromFile(const std::string& filename);
    // 감정에 따라 적절한 인용구를 추천하는 함수
    void recommendQuote(const std::string& emotion) const;

private:
    // 문자열 공백 제거를 위한 유틸리티 함수
    std::string trim(const std::string& str) const;
};

#endif
