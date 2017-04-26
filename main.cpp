#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void printMenu()
{
    cout<<"-------------|MENU|-------------\n";
    cout<<"1. Suma zbiorow.\n";
    cout<<"2. Przeciecie zbiorow.\n";
    cout<<"3. Roznica zbiorow.\n";
    cout<<"4. Roznica symetryczna zbiorow.\n";
    cout<<"5. Wyjscie.\n";
    cout<<"--------------------------------\n";
}

vector <int> createSet()
{
    vector <int> Set;
    int siz, elem;
    cout<<"Podaj rozmiar zbioru: ";
    cin >> siz;
    cout<<"\nPodaj elementy zbioru: ";
    for(int i=0; i<siz; i++)
    {
        cin>>elem;
        Set.push_back(elem);
    }
    cout << endl;
    return Set;
}

void printSet(vector <int> Set)
{
    for(auto i = Set.begin(); i != Set.end(); ++i)
        cout << *i << " ";

    cout<<endl;
}

vector <int> sum(vector <int>, vector <int>);
vector <int> intersection(vector <int>, vector <int>);
vector <int> diffrence(vector <int>, vector <int>);
vector <int> symetric(vector <int>, vector <int>);

int main()
{
    vector < int > A, B, C;
    int choice;

    while(true)
    {
        printMenu();
        cin>>choice;
        if(cin.fail())
        {
            cout<<"Nie liczba\n";
            break;
        }
        if(choice==5)
            break;

        switch(choice)
        {
        case 1:
            A=createSet();
            B=createSet();
            C=sum(A, B);
            printSet(C);
            break;

        case 2:
            A=createSet();
            B=createSet();
            C=intersection(A, B);
            printSet(C);
            break;

        case 3:
            A=createSet();
            B=createSet();
            C=diffrence(A, B);
            printSet(C);
            break;

        case 4:
            A=createSet();
            B=createSet();
            C=symetric(A, B);
            printSet(C);
            break;

        default:
            cout<<"Nie ma takiej opcji\n";
            break;
            break;
        }
    }
    return 0;
}

vector <int> sum(vector <int> A, vector <int> B)
{
    vector <int> Result = A;
    bool pass=false;
    for(auto b=B.begin(); b!=B.end(); ++b)
    {
        for(auto a=A.begin(); a!=A.end(); ++a)
        {
            if(*a == *b)
                pass=true;
        }
        if(pass==false)
            Result.push_back(*b);
        else
            pass=false;
    }
    return Result;
}

vector <int> intersection(vector <int> A, vector <int> B)
{
    vector <int> Mult;
    for(auto a=A.begin(); a!=A.end(); ++a)
    {
        for(auto b=B.begin(); b!=B.end(); ++b)
        {
            if(*a == *b)
            {
                Mult.push_back(*a);
            }
        }
    }
    return Mult;
}

vector <int> diffrence(vector <int> A, vector <int> B)
{
    vector <int> Diff;
    bool same=false;
    for(auto a=A.begin(); a!=A.end(); ++a)
    {
        for(auto b=B.begin(); b!=B.end(); ++b)
        {
            if(*a == *b)
            {
                same=true;
                break;
            }
        }
        if(same==false)
            Diff.push_back(*a);

        same=false;
    }
    return Diff;
}

vector <int> symetric(vector <int> A, vector <int> B)
{
    vector <int> Diff1, Diff2, Symet;
    Diff1=diffrence(A, B);
    Diff2=diffrence(B, A);
    Symet=sum(Diff1, Diff2);
    return Symet;
}
