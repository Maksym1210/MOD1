#include <iostream>

using namespace std;

class Bird
{
protected:
    char* song ;
    virtual void sing() = 0;
};

class Nightingale : public Bird
{
public:
    Nightingale(char* a)
    {
        song = a;
    }
    void sing()
    {
        cout << song << endl;
    }

};

class Sparrow : public Bird
{
public:
    Sparrow(char* a)
    {
        song = a;
    }
    void sing()
    {
        int i = 0;
        while(i<3)
        {
            cout << song[i] ;
            i++;
        }
        cout << endl;
    }
};

int main()
{
    Nightingale a("alalalalalong");
    Sparrow b("alalalalalong");
    a.sing();
    b.sing();
    return 0;
}
