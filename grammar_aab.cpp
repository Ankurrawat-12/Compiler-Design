#include <iostream>

using namespace std;

int check(string str){
    if(str.size() < 2){
        return 0;
    }

    if (str[0] == 'b')
    {
        return 0;
    }
    if (str[str.size ()] == 'a')
    {
        return 0;
    }

    for (int i = 0; i < str.size (); i++)
    {
        if (str[i] != 'a' && str[i] != 'b') return 0;
        if (str[i] == 'b' && str[i + 1] == 'a') return 0;
    }
return 1;
}

int main ()
{
    string lang;
    cout<<"Enter the language: - ";
    cin >> lang;
    cout<<"The entered language is :-   " << lang << endl;
    auto checked = check(lang);
    if(checked) cout<<"This String Follows the grammar";
    else cout<<"This string does not follow the grammar";
    return 1;
}