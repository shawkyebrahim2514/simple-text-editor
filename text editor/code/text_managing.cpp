#include <bits/stdc++.h>
using namespace std;
string file_name;
ostringstream file_content;
map<string, int> repeated_words;
set<string> all_words;


void separated_line(string paragraph){
    // centre each paragraph with (-) in each part of this paragraph
    int width = 80;
    char symbol = '-';
    int part = (width/2) - ((int)paragraph.size()/2);
    cout << string(part,symbol) + paragraph + string(part,symbol) << '\n';
}

bool check_file_exist(string name){
    fstream file;
    file.open(name + ".txt",ios::in);
    if(file.fail()){
        return 0;
    }else{
        return 1;
    }
}

void take_file_name(){
    cout << "Enter the file name: ";
    cin >> file_name;
    if(check_file_exist(file_name)){
        separated_line(" This File Already Exists ");
    }else{
        separated_line(" This is a new file. I created it for you ");
    }
}

void load_file(){
    fstream file;
    file.open(file_name + ".txt",ios::in);
    file_content << file.rdbuf();
    file.close();
}


void update_file_content(string tmp){
    file_content.str("");
    file_content.clear();
    file_content << tmp;
}

void save_file(){
    cout << "from save file\n";
    cout << file_content.str();
    fstream file;
    file.open(file_name + ".txt", ios::out);
    file << file_content.str();
    file.close();
}