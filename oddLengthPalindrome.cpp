#include<bits/stdc++.h>

using namespace std;

bool check(string lang){
    if(lang.size() == 1){
        return true;
    }
    
    if(lang.size()%2 == 0){
        return false;
    }

    int left = 0;
    int right = lang.size() - 1;

    while(left < right){
        if(lang[left] == lang[right]){
            right--;
            left++;
        }
        else{
            return false;
        }
    }
    return true;

}

int main(){
    string lang;
    cout<<"Enter the language: - ";
    cin >> lang;
    cout<<"The entered language is :-   " << lang << endl;
    auto checked = check(lang);
    if(checked) cout<<"This String Follows the grammar";
    else cout<<"This string does not follow the grammar";
    return 1;
}