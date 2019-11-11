#include <iostream>
#include <string.h>
#include <vector>

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

class SpellChecker
{
public:
    vector <char*> a = { "aa", "bbb", "cccc" };
    char* method(char* word, int &dif)
    {
        int coincidences[a.size()] = {};
        for(size_t j = 0; j < a.size(); j++)
        for(size_t i = 0; i < min(strlen(word), strlen(a[j])); i++)
        {
            if(word[i] == a[j][i])coincidences[j]++;
        }
        int ind_max = 0;
        for(size_t i = 1; i < a.size(); i++)
        {
            if(coincidences[i] > coincidences[i-1])ind_max = i;
        }
        dif = (max(strlen(word), strlen(a[ind_max])) - coincidences[ind_max]);
        return a[ind_max];
    }
};

int main()
{
    Nightingale a("alalalalalong");
    Sparrow b("alalalalalong");
    a.sing();
    b.sing();
    SpellChecker c;
    int dif;
    cout << c.method("bcac", dif) << endl;
    cout << "differences : " << dif << endl;
    return 0;
}
