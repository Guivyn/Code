#include <iostream>
#include <string>
using namespace std;

class TableTennisPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;

public:
    TableTennisPlayer(const string &n, const string &m, bool z)
    {
        firstname = n;
        lastname = m;
        hasTable = z;
    }
    string FirstName() const
    {
        return firstname;
    }
    string LastName() const
    {
        return lastname;
    }
    bool HasTable() const
    {
        return hasTable;
    }
};

class RatedPlayer : public TableTennisPlayer
{
private:
    int rating;

public:
    RatedPlayer(int a, string n, string m, bool z) : TableTennisPlayer(n, m, z)
    {
        rating = a;
    }
    int Rating()
    {
        return rating;
    }
};

int main()
{
    string firstname, lastname;
    bool hasTable;
    int rating;
    char flag;

    while (cin >> flag)
    {
        if (flag == 'T')
        {
            cin >> firstname >> lastname >> hasTable;
            TableTennisPlayer tp(firstname, lastname, hasTable);

            if (tp.HasTable())
                cout << tp.FirstName() << " " << tp.LastName() << " has a table.\n";
            else
                cout << tp.FirstName() << " " << tp.LastName() << " hasn't a table.\n";
        }
        else if (flag == 'R')
        {
            cin >> firstname >> lastname >> hasTable >> rating;
            RatedPlayer rp(rating, firstname, lastname, hasTable);

            if (rp.HasTable())
                cout << rp.FirstName() << " " << rp.LastName() << " has a table. The rating is " << rp.Rating() << ".\n";
            else
                cout << rp.FirstName() << " " << rp.LastName() << " hasn't a table. The rating is " << rp.Rating() << ".\n";
        }
    }

    return 0;
}