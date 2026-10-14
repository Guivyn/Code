#include <iostream>
#include <string>
using namespace std;
class Subject // 选课类
{
private:
    double score[3];             // 3门课成绩
    const int SMath, SEng, SCpp; // 3门课的学分，分别为4、2、2
public:
    Subject(double score_math = 0, double score_eng = 0, double score_cpp = 0);
    void Input();         // 输入3门课的成绩
    friend class Student; // 友元类
};

Subject::Subject(double score_math, double score_eng, double score_cpp) : SMath(4), SEng(2), SCpp(2)
{
    score[0] = score_math;
    score[1] = score_eng;
    score[2] = score_cpp;
}

void Subject::Input()
{
    cin >> score[0] >> score[1] >> score[2];
}

class Student
{
private:
    string ID;   // 学号
    string name; // 姓名
    double GPA;  // 平均学分积=（成绩1x学分1+成绩2x学分2+成绩3x学分3）/（学分1+学分2+学分3）
public:
    Student(string id = "00000", string na = "Noname");
    void CalculateGPA(const Subject &sub); // 计算平均学分积
    void Input();                          // 输入学号和姓名
    void Show(const Subject &sub) const;   // 输出所有信息
};

Student::Student(string id, string na)
{
    ID = id;
    name = na;
}

void Student::Input()
{
    cin >> ID >> name;
}

void Student::CalculateGPA(const Subject &sub)
{
    GPA = (sub.score[0] * sub.SMath + sub.score[1] * sub.SEng + sub.score[2] * sub.SCpp) / (sub.SMath + sub.SEng + sub.SCpp);
}

void Student::Show(const Subject &sub) const
{
    cout << "ID: " << ID << ", Name: " << name << endl;
    cout << "Math Eng Cpp" << endl;
    for (int i = 0; i <= 2; i++)
    {
        cout << sub.score[i] << " ";
    }
    cout << endl;
    cout << "GPA: " << GPA << endl;
}

int main()
{
    int n; // 学生人数
    cin >> n;
    Student *stu = new Student[n];
    Subject *sub = new Subject[n];
    for (int i = 0; i < n; i++)
    {
        stu[i].Input();
        sub[i].Input();
    }
    for (int i = 0; i < n; i++)
    {
        stu[i].CalculateGPA(sub[i]);
        stu[i].Show(sub[i]);
    }
    delete[] stu;
    delete[] sub;
    return 0;
}