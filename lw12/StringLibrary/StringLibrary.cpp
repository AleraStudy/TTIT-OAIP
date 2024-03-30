#include "StringLibrary.h"
#include <sstream>
#include <unordered_set>
#include <cctype>

int substringOccurrences(const std::string& str, const std::string& substr) {
    int count = 0;
    size_t pos = 0;
    while ((pos = str.find(substr, pos)) != std::string::npos) {
        count++;
        pos += substr.length();
    }
    return count;
}

std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<std::string> findUniqueWords(const std::string& str) {
    std::unordered_set<std::string> wordSet;
    std::vector<std::string> uniqueWords;
    std::string word;
    std::istringstream iss(str);
    while (iss >> word) {
        std::string lowercaseWord;
        for (char c : word) {
            if (std::isalpha(c) || c == '-') {
                lowercaseWord += std::tolower(c);
            }
        }
        if (wordSet.find(lowercaseWord) == wordSet.end()) {
            wordSet.insert(lowercaseWord);
            uniqueWords.push_back(lowercaseWord);
        }
    }
    return uniqueWords;
}