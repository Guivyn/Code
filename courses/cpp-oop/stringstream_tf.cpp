#include<iostream>
#include<sstream>
#include<map>
#include<algorithm>
using namespace std;
int termFrequency(const string& content , map<string, unsigned>& msu)
{
    string m;
    for (char c : content)
    {
        if (c==','||c=='.'||c=='"'||c=='!')
        {
            continue;
        }
        m+=tolower(c);
    }
    istringstream iss(m);
    string word;
    while (iss>>word)
    {
    if(!word.empty())
        {
            msu[word]++;
        }    
    }
    return msu.size();
}
int main() {

    // 从标准输入获取文本串
    std::string content;
    std::getline(std::cin, content, '\n');

    map<string, unsigned> msu;

    // 要求termFrequency实现分词，去掉标点
    // 获取单词存放在map中，记录词频（出现次数）
    // 最后返回不重复的单词数量    
    unsigned nWords = termFrequency(content, msu);
    cout << nWords;
    // 按首字母A-Z排序一行一词输出词频
    //alphabetSortedFrequency(msu);

    return 0;
}