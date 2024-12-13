#include "QuoteManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

// QuoteManager 클래스의 소멸자
QuoteManager::~QuoteManager() {
     // 할당된 동적 메모리 해제
    for (auto quote : positiveQuotes) {
        delete quote;
    }
    for (auto quote : negativeQuotes) {
        delete quote;
    }
}

// 긍정적인 감정에 관한 인용구를 파일에서 읽어오는 함수
void QuoteManager::loadPositiveQuotesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t firstComma = line.find(',');
        size_t secondComma = line.rfind(',');
         // 유효하지 않은 형식은 건너뜀
        if (firstComma == std::string::npos || secondComma == std::string::npos || firstComma == secondComma) {
            continue;
        }

        // 감정, 텍스트, 작성자 정보 추출
        std::string emotion = line.substr(0, firstComma);
        std::string text = line.substr(firstComma + 1, secondComma - firstComma - 1);
        std::string author = line.substr(secondComma + 1);

        emotion = trim(emotion);
        text = trim(text);
        author = trim(author);

        // 유효한 데이터만 추가
        if (!emotion.empty() && !text.empty() && !author.empty()) {
            positiveQuotes.push_back(new PositiveQuote(text, author, emotion));
        }
    }
    file.close();
}


// 부정적인 감정에 관한 인용구를 파일에서 읽어오는 함수
void QuoteManager::loadNegativeQuotesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t firstComma = line.find(',');
        size_t secondComma = line.rfind(',');

        if (firstComma == std::string::npos || secondComma == std::string::npos || firstComma == secondComma) {
            continue;
        }

        std::string emotion = line.substr(0, firstComma);
        std::string text = line.substr(firstComma + 1, secondComma - firstComma - 1);
        std::string author = line.substr(secondComma + 1);

        emotion = trim(emotion);
        text = trim(text);
        author = trim(author);

        if (!emotion.empty() && !text.empty() && !author.empty()) {
            negativeQuotes.push_back(new NegativeQuote(text, author, emotion));
        }
    }
    file.close();
}

// 문자열에서 공백을 제거하는 함수
std::string QuoteManager::trim(const std::string& str) const {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}


// 사용자의 감정에 따라 적절한 인용구를 추천하는 함수
void QuoteManager::recommendQuote(const std::string& emotion) const {
    const auto& quotes = isPositiveEmotion(emotion) ? positiveQuotes : negativeQuotes;

    bool found = false;
    for (const auto& quote : quotes) {
        if (quote->getEmotion() == emotion) {
            quote->display();
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "No quote found for the given emotion. Please try again." << std::endl;
    }
}
