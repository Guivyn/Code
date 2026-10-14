#include <iostream>
#include <string>
using namespace std;

class Score
{
private:
    string name;
    double s[4];
    double total;
    char grade;

public:
    Score()
    {
        total = 0;
        grade = 'B';
    }

    void Input()
    {
        cin >> name;
        for (int i = 0; i < 4; i++)
        {
            cin >> s[i];
        }
    }

    void Evalauate()
    {
        for (int i = 0; i < 2; i++)
        {
            if (s[i] < 0 || s[i] > 50)
            {
                cout << "error" << endl;
                exit(0);
            }
        }
        for (int i = 2; i < 4; i++)
        {
            if (s[i] < 0 || s[i] > 100)
            {
                cout << "error" << endl;
                exit(0);
            }
        }

        double attendance1 = (s[0] / 50.0) * 100;
        double attendance2 = (s[1] / 50.0) * 100;
        total = attendance1 * 0.125 + attendance2 * 0.125 + s[2] * 0.25 + s[3] * 0.5;

        if (total >= 90 && total <= 100)
            grade = 'A';
        else if (total >= 80 && total <= 89)
            grade = 'B';
        else if (total >= 70 && total <= 79)
            grade = 'C';
        else if (total >= 60 && total <= 69)
            grade = 'D';
        else if (total >= 0 && total < 60)
            grade = 'E';
    }

    void Output()
    {
        cout << "name: " << name << ", total: " << total << ", grade: " << grade << endl;
    }
};

int main()
{
    Score *s1 = new Score;
    s1->Input();
    s1->Evalauate();
    s1->Output();
    return 0;
}