#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void print_hangman(int try_num)
{
    string file = "./data/hang_try_0";

    switch (try_num)
    {
        case 0:
            file.append("0.txt");
            break;
        case 1:
            file.append("1.txt");
            break;
        case 2:
            file.append("2.txt");
            break;
        case 3:
            file.append("3.txt");
            break;
        case 4:
            file.append("4.txt");
            break;
        case 5:
            file.append("5.txt");
            break;
        case 6:
            file.append("6.txt");
            break;
    }
    ifstream in(file);
    if (!in)
    {
        cout << "Cannot open file" << endl;
        return;
    }
    char str[50];
    int i = 50;

    while (in)
    {
        in.getline(str, i);
        if (in) cout << str << endl;
    }
    in.close();
}

void print_guess(vector<string> &guess)
{
    cout << endl;
    for (int i = 0; i < guess.size(); i++) cout << guess[i];
    cout << endl << endl;
}

int main(int argc, char *argv[])
{
    cout << ">> ";
    string word;
    cin >> word;

    vector<string> guess(word.length());
    char first = word[0];
    guess[0].append("  ");
    guess[0] += toupper(first);
    guess[0].append("  ");

    cout << "The word you must guess has a length of " << word.length() << " characters" << endl;
    for (int i = 1; i < word.length(); i++)
    {
        if (tolower(word[i]) == tolower(first))
        {
            guess[i].append("  ");
            guess[i] += tolower(first);
            guess[i].append("  ");
        }
        else guess[i] = " ___ ";
    }
    
    first = tolower(first); 
    unordered_map<char, vector<int>> mymap;
    unordered_set<char> myset;
    myset.insert(first);

    for (int i = 1; i < word.length(); i++)
    {
        if (tolower(word[i]) == first) continue;
        mymap[tolower(word[i])].push_back(i);
    }

    // for (auto it : mymap)
    // {
    //     cout << it.first << " >> ";
    //     for (int i = 0; i < it.second.size(); i++)
    //         cout << it.second[i] << ", ";
    //     cout << endl;
    // }
    // cout << endl << endl;

    print_guess(guess);

    int try_num = 0;
    while (try_num <= 6)
    {
        char tmp;
        cout << "What is your character guess >> ";
        cin >> tmp;
        tmp = tolower(tmp);

        if (myset.count(tmp))
        {
            cout << "It seems like you already guessed this character (or was provided for you). Try again!" << endl;
            print_guess(guess);
            continue;
        }
        else if (mymap[tmp].size() >= 1)
        {
            myset.insert(tmp);
            for (int i : mymap[tmp])
            {
                guess[i] = "  ";
                guess[i] += tmp;
                guess[i].append("  ");
            }
        }
        else if (try_num == 6)
        {
            print_hangman(try_num);
            cout << endl;
            return 0;
        }
        else
        {
            myset.insert(tmp);
            print_hangman(try_num);
            try_num++;
            if (try_num == 6) cout << "WRONG GUESS :). You only have one try left!" << endl;
            else cout << "WRONG GUESS. You have " << 7 - try_num << " tries left!" << endl;
        }
        mymap.erase(tmp);
        print_guess(guess);

        if (mymap.size() == 0 && try_num == 6)
        {
            cout << "	---YOU WON, BUT THAT WAS CLOSE!---" << endl << endl;
            return 0;           
        }
        else if (mymap.size() == 0)
        {
            cout << "	---YOU WON. CONGRATS!---" << endl << endl;
            return 0;
        }
    }
}
