#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int num;
    cin>>num;
    struct Ranking
    {
        string name;
        int rating;
        string title;
    };
    Ranking equation[100];
    for (int i = 0; i < num; i++)
    {
        cin>>equation[i].name>>equation[i].rating;
        if (1400<=equation[i].rating&&equation[i].rating<=1599)
        {
            equation[i].title="Specialist";
        }
        if (1600<=equation[i].rating&&equation[i].rating<=1899)
        {
            equation[i].title="Expert";
        }
        if (1900<=equation[i].rating&&equation[i].rating<=2299)
        {
            equation[i].title="Master";
        }
        if (2300<=equation[i].rating&&equation[i].rating<=2600)
        {
            equation[i].title="GrandMaster";
        }
    }
    sort(equation, equation + num, [](const Ranking& r1, const Ranking& r2)
    {
    if (r1.rating != r2.rating) return r1.rating > r2.rating;
    if (r1.title != r2.title) return r1.title < r2.title;
    return r1.name < r2.name;
    });
    for (int i = 0; i < num; i++)
    {
        cout<<equation[i].name<<" "<<equation[i].rating<<" "<<equation[i].title<<endl;
    }
}