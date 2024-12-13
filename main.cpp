//감정 기반 명언 추천 프로그램
//사용자가 입력한 감정에 따라 적합한 명언을 추천하여, 긍정적인 에너지나 위로를 제공하는 것을 목표로 한다.


#include "QuoteManager.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; // std:: 생략 가능


// 감정이 긍정적인지 확인하는 함수
bool isPositiveEmotion(const string& emotion) {
    static const vector<string> positiveEmotions = {
        "happy", "joyful", "peaceful", "grateful", "loved", "loving", "curious"};
    string lowerEmotion = emotion;
    transform(lowerEmotion.begin(), lowerEmotion.end(), lowerEmotion.begin(), ::tolower);
    return find(positiveEmotions.begin(), positiveEmotions.end(), lowerEmotion) != positiveEmotions.end();
}

int main() {
    QuoteManager manager;

   // 긍정적 및 부정적 인용구를 파일에서 로드
    manager.loadPositiveQuotesFromFile("positive.txt");
    manager.loadNegativeQuotesFromFile("negative.txt");

    string emotion;
    while (true) {
        // 사용자로부터 현재 감정을 입력받음
        cout << "Enter your current emotion (e.g., Nervous, Happy, Sad, etc.): ";
        getline(cin, emotion);

        if (emotion.empty()) {
            cout << "Input is empty. Please try again." << endl;
            continue;
        }

         // 감정이 긍정적인지 또는 부정적인지 판별
        bool positive = isPositiveEmotion(emotion);
        cout << "\nDetected emotion type: "
             << (positive ? "Positive" : "Negative") << "\n";

         // 감정에 따라 적절한 인용구를 추천
        cout << "\nRecommending a quote for your emotion...\n";
        manager.recommendQuote(emotion);

        char retry;
        cout << "\nWould you like to enter another emotion? (y/n): ";
        cin >> retry;
        if (retry == 'n' || retry == 'N') {
            break;
        }
        cin.ignore(); // 입력 버퍼 비우기
    }

    cout << "Program terminated." << endl;
    return 0;
}

