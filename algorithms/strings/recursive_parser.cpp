#include<iostream>
#include<vector>
#include<string>
using namespace std;
//递归解析
vector<string> tokens;
int pos = 0;

string next() {
    return tokens[pos++];
}

void build(int count)
{
    cout << "{";

    for (int i = 0; i < count; i++)
    {
        if (i > 0) cout << ",";
        
        string name = next();
        
        if (name == "cat")
        {
            cout << "cat";
        }
        else
        {
            int num_ori = stoi(name);
            build(num_ori);
        }
    }
    
    cout << "}";
}

int main()
{
    string name;
    while (cin >> name)
    {
        tokens.push_back(name);
    }
    
    int first_count = stoi(tokens[0]);
    pos = 1;
    
    build(first_count);
    
    return 0;
}