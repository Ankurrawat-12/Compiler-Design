#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool isKeyword(string word)
{
    string keywords[] = {"int", "float", "double", "char", "string", "bool", "void", "long", "short", "signed", "unsigned", "auto", "const", "extern", "register", "static", "volatile", "struct", "union", "enum", "typedef", "sizeof", "if", "else", "switch", "case", "default", "break", "continue", "for", "do", "while", "goto", "return", "using", "namespace", "std", "cout", "cin", "endl", "main"};
    for (int i = 0; i < 40; i++)
    {
        if (word == keywords[i])
        {
            return true;
        }
    }
    return false;
}

string readFile(string fileName)
{

    ifstream file(fileName);

    if (!file.is_open())
    {
        cerr << "Error: Could not open the file." << endl;
        return "File Not Found";
    }

    string fileContents((istreambuf_iterator<char>(file)),
                        istreambuf_iterator<char>());

    file.close();

    return fileContents;
}

int main()
{
    unordered_map<string, int> keywords;
    string fileName = "";
    cout << "Enter the File Name :- ";
    cin >> fileName;
    string fileContents = readFile(fileName);
    if (fileContents == "File Not Found")
    {
        cout << "No file Named " << fileName << " Found";
        return 0;
    }
    istringstream iss(fileContents);
    string word;

    while (iss >> word)
    {
        if (isKeyword(word))
        {
            keywords[word]++;
        }
    }
    for (auto i : keywords)
    {
        cout << i.first << " " << i.second << endl;
    }
}