#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
    string name;
    string spec;
    float mark;
    void ft_define()
    {
        cout << "\nIntroduceti datele studentului " << endl;
        cout << "Numele >> " << name << endl;
        cin >> name;
        cout << "Specialitatea >> " << endl;
        cin >> spec;
        cout << "Balul mediu >> " << endl;
        cin >> mark;
    }
    void ft_del()
    {
        name = '0';
        spec = '0';
        mark = 0;
    }
    friend ostream &operator<<(ostream &os, Student &s)
    {
        return os << "\nNumele studentului : " << s.name << endl
                  << "Specialitatea : " << s.spec << endl
                  << "Balul mediu : " << s.mark << endl;
    }
};
class Group : public Student
{
public:
    Student *group;
    int count;
    int index;
    Group() : group(NULL),
              count(0), index(0) {}
    Group(int count)
    {
        group = new Student[count];
        this->count = count;
        index = 0;
    }
    ~Group()
    {
        delete[] group;
        count = 0;
    }
    void ft_add()
    {
        group[index].ft_define();
        index++;
    }
    void ft_delete()
    {
        int i;
        cout << "Introduce indexul studentului pentru stergere" << endl;
        cin >> i;
        group[i].ft_del();
    }
    void ft_modify()
    {
        int i;
        cout << "Introduceti indexul studentului pentru modificare dateleor" << endl;
        cin >> i;
        group[i].ft_define();
    }
    float ft_medmark()
    {
        float sum = 0;
        float med = 0;
        int i = -1;
        while (++i < count)
            sum += group[i].mark;
        return (med = sum / count);
    }
    friend ostream &operator<<(ostream &out, Group &g)
    {
        int i = 0;
        float sum = 0;
        float med = 0;
        out << "Show:" << endl;
        while (i < g.index)
        {
            if (g.group[i].name == "0" && g.group[i].spec == "0" && g.group[i].mark == 0)
            {
                i++;
                continue;
            }
            cout << "**Studentul > " << i << endl;
            out << g.group[i] << endl;
            i++;
        }
        out << "Media:" << endl;
        i = -1;
        while (++i < g.index)
            sum += g.group[i].mark;
        med = sum / g.index;
        out << med << endl;
        return out;
    }
};
int main()
{
    int choice;
    int n;
    cout << "**Crearea grupei de studenti:" << endl;
    cout << "Introduceti marimea grupei" << endl;
    cin >> n;
    Group group(n);
    while (1)
    {
        cout << "[1]. Adaugati cite un student." << endl;
        cout << "[2]. Eliminati cite un student." << endl;
        cout << "[3]. Modificati datele unui student." << endl;
        cout << "[4]. Afisarea grupei." << endl;
        cout << "[0]. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                group.ft_add();
                break;
            case 2:
                group.ft_delete();
                break;
            case 3:
                group.ft_modify();
                break;
            case 4:
                cout << group;
                break;
            case 0:
                exit(0);
            default:
                cout << "Nu exista asa optiune !!!" << endl;
                break;
        }
    }

}
