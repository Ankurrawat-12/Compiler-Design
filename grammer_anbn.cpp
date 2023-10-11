#include <iostream>

using namespace std;

int check(string str)
{

    if (str.size() < 2 || str[str.size() - 1] != 'b' || str[0] == 'b' || str.size() % 2 != 0)
    {
        return 0;
    }

    int countOfA = 0;
    int countOfB = 1;

    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] != 'a' && str[i] != 'b')
            return 0;
        if (str[i] == 'b' && str[i + 1] == 'a')
            return 0;

        if (str[i] == 'a')
            countOfA++;
        else if (str[i] == 'b')
            countOfB++;
    }

    if (countOfB != countOfA)
        return 0;

    return 1;
}

int main()
{
    string lang;
    cout << "Enter the language: - ";
    cin >> lang;
    cout << "The entered language is :-   " << lang << endl;
    auto checked = check(lang);
    if (checked)
        cout << "This String Follows the grammar";
    else
        cout << "This string does not follow the grammar";
    return 1;
}