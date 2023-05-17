#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "WELCOME TO DICTIONARY" << endl;
    cout << endl;
    int flag = 0;
    map<string, string> mp;
    ofstream file;
    while (true)
    {
        cout << "OPTION 1 - Press 1 for creating file" << endl;
        cout << "OPTION 2 - Press 2 for adding word and meaning" << endl;
        cout << "OPTION 3 - Press 3 for finding the meaning of the word" << endl;
        cout << "OPTION 4 - Press 4 for removing the word and meaning of the word" << endl;
        cout << "enter the option :" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            {
                flag = 1;
                file.open("shabdkosh.txt");
                file << "Word\tMeaning\n";
                file.close();
                cout << "Dictionary file generated as 'shabdkosh.txt'" << endl;
                break;
            }
        case 2:
        {
            if (flag == 0)
            {
                cout << "kindly select the option-1 first in order to create a file:)" << endl;
                break;
            }
            string word;
            string mean;
            cout << "enter the word:" << endl;
            cin >> word;
            cout << "enter the meaning of the word:" << endl;
            cin >> mean;
            if (mp.find(word) != mp.end())
            {
                cout << "word already exits:(" << endl;
                break;
            }
            mp[word] = mean;
            ofstream file("shabdkosh.txt");
            if (file.is_open())
            {
                for (auto i : mp)
                {
                    file << i.first << "\t" << i.second << endl;
                }
                file.close();
                cout << "words written in dictionary:)" << endl;
            }
            else
            {
                cout << "unable to open file:(" << endl;
            }
            break;
        }
        case 3:
        {
            if (flag == 0)
            {
                cout << "kindly select the option-1 first" << endl;
                break;
            }
            string search;
            cout << "enter the word for finding the meaning:" << endl;
            cin >> search;
            if (mp.find(search) != mp.end())
                cout << "meaning of the " << search << " is " << mp[search] << endl;
            else
                cout << search << " word is not present in the dictionary" << endl;
            break;
        }
        case 4:
        {
            if (flag == 0)
            {
                cout << "kindly select the option-1 first" << endl;
                break;
            }
            string word;
            cout << "enter word to delete:" << endl;
            cin >> word;
            if (mp.find(word) != mp.end())
            {
                mp.erase(word);
                string line;
                ifstream infile("shabdkosh.txt");
                ofstream outfile("temp.txt");
                while (getline(infile, line))
                {
                    if (line.find(word + "\t") == string::npos)
                    {
                        outfile << line << endl;
                    }
                }
                infile.close();
                outfile.close();
                remove("shabdkosh.txt");
                rename("temp.txt", "shabdkosh.txt");
                cout << "Word and meaning removed successfully!" << endl;
            }
            else
                cout << "word not present in dictionary:(" << endl;
            break;
        }
        }
    }
}