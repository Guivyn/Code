#include <iostream>
#include <sstream>
#include <string>

void readPapers(const std::string& content) {
    std::stringstream ss(content);
    std::string word;
    int wordCount = 0;
    int punctCount = 0;

    // 统计标点：句号、逗号、双引号
    for (char ch : content) {
        if (ch == '.' || ch == ',' || ch == '\"') {
            punctCount++;
        }
    }

    // 统计单词：用字符串流按空格分割
    while (ss >> word) {
        // 只统计非空的 token
        if (!word.empty()) {
            wordCount++;
        }
    }

    std::cout << wordCount << "," << punctCount << std::endl;
}
int main() 
{
    std::string content;
    std::getline(std::cin, content, '\n');
    readPapers(content);
    return 0;
}
