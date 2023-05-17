#include <bits/stdc++.h>

using namespace std;
map<string,int>mp;
// Function to generate the .txt file
void generate_file() {
ofstream file;
file.open("dictionary.txt");
file << "Word\tMeaning\n";
file.close();
cout << "Dictionary file generated as 'dictionary.txt'" << endl;
}

// Function to add word and meaning to the .txt file
void add_word() {
string word, meaning;
cout << "Enter the word: ";
cin>>word;
if(mp.find(word)!=mp.end()){
    cout<<"word already exits";
    return;
}
mp[word]++;
cout << "Enter the meaning: ";
getline(cin, meaning);
ofstream file;
file.open("dictionary.txt", ios::app);
file << word << "\t" << meaning << endl;
file.close();
cout << "Word and meaning added successfully!" << endl;
}

// Function to search for a word in the .txt file
void search_word() {
string word, line;
bool found = false;
cout << "Enter the word to search: ";
getline(cin, word);
ifstream file("dictionary.txt");
if (file.is_open()) {
while (getline(file, line)) {
if (line.find(word + "\t") != string::npos) {
cout << line << endl;
found = true;
break;
}
}
file.close();
}
if (!found) {
cout << "Word not found in the dictionary." << endl;
}
}

// Function to remove a word and its meaning from the .txt file
void remove_word() {
string word, line;
cout << "Enter the word to remove: ";
getline(cin, word);
ifstream infile("dictionary.txt");
ofstream outfile("temp.txt");
while (getline(infile, line)) {
if (line.find(word + "\t") == string::npos) {
outfile << line << endl;
}
}
infile.close();
outfile.close();
remove("dictionary.txt");
rename("temp.txt", "dictionary.txt");
cout << "Word and meaning removed successfully!" << endl;
}

// Main loop for the dictionary tool
void dictionary_tool() {
cout << "Welcome to the Dictionary Console Tool!" << endl;
while (true) {
cout << "1. Generate Dictionary File" << endl;
cout << "2. Add Word and Meaning" << endl;
cout << "3. Search Word" << endl;
cout << "4. Remove Word" << endl;
cout << "5. Exit" << endl;
string choice;
cout << "Enter your choice: ";
getline(cin, choice);
if (choice == "1") {
generate_file();
}
else if (choice == "2") {
add_word();
}
else if (choice == "3") {
search_word();
}
else if (choice == "4") {
remove_word();
}
else if (choice == "5") {
cout << "Thank you for using the Dictionary Console Tool!" << endl;
break;
}
else {
cout << "Invalid choice. Please try again." << endl;
}
}
}

// Start the dictionary tool
int main() {
dictionary_tool();
return 0;
}