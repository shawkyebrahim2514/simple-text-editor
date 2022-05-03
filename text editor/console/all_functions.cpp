#include <bits/stdc++.h>
#include <conio.h>
#include "text_managing.cpp"
using namespace std;
int cnt_lines = 0, cnt_words = 0, cnt_characters = 0;


void add_content(){
    string tmp = file_content.str();
    if(file_content.str().size()){
        tmp += '\n';
    }
    char c;
    separated_line(" add your text here ");
    while (true){
        c = getch();
        if(c == 13){
            // if the user press enter
            cout << '\n';
        }else if(c == 8 && tmp.size()){
            // if user press backspace
            tmp.pop_back();
            wcout << '\b' << ' ' << '\b';
        }else if(c == 26){
            break;
        }else{
            cout << c;
            tmp.push_back(c);
        }
    }
    cout << '\n';
    update_file_content(tmp);
}

void display_content(){
    separated_line(" Your file context ");
    cout << file_content.str() << '\n';
}

void empty_content(){
    update_file_content("");
}

void encrypt_content(){
    string tmp = file_content.str();
    for(auto& val : tmp) val += 1;
    update_file_content(tmp);
}

void decrypt_content(){
    string tmp = file_content.str();
    for(auto& val : tmp) val -= 1;
    update_file_content(tmp);
}

void merge_files(){
    string new_file_name;
    separated_line(" Enter the name of the file you want to merge with ");
    cout << "Enter here: ";
    cin >> new_file_name;
    if(!check_file_exist(new_file_name)){
        separated_line(" Invalid File Name ");
        merge_files();
        return;
    }
    fstream new_file;
    new_file.open(new_file_name + ".txt", ios::in);
    file_content << '\n' << new_file.rdbuf();
}

// size of file_content contain letters and spaces and new lines ASCII
// to obtain the number of characters and spaces, subtract the above with (the number of lines - 1)
void file_counting(){
    istringstream tmp(file_content.str());
    string line, word;
    while (getline(tmp,line)){
        istringstream sep_line(line);
        while (sep_line >> word){
            cnt_words ++;
        }
        cnt_lines ++;
    }
    cnt_characters = file_content.str().size() - cnt_lines + 1;
}

void count_lines(){
    file_counting();
    separated_line(" Number of lines are: " + to_string(cnt_lines) + ' ');
}

void count_words(){
    file_counting();
    separated_line(" Number of words are: " + to_string(cnt_words) + ' ');
}

void count_characters(){
    file_counting();
    separated_line(" Number of characters are: " + to_string(cnt_characters) + ' ');
}

void get_repeated_word(){
    // take user word
    string target;
    cout << "Enter the word: ";
    cin >> target;
    // fill repeated words map with all lowercase words
    string word;
    istringstream tmp(file_content.str());
    while (tmp >> word){
        transform(word.begin(),word.end(),word.begin(),::tolower);
        repeated_words[word] ++;
    }
    separated_line(" The number of times of " + target + " = " + to_string(repeated_words[target]) + ' ');
}

void search_word(){
    // take user word
    string target;
    cout << "Enter the word: ";
    cin >> target;
    // fill all words set with each lowercase word
    string word;
    istringstream tmp(file_content.str());
    while (tmp >> word){
        transform(word.begin(),word.end(),word.begin(),::tolower);
        all_words.insert(word);
    }
    if(all_words.count(target)){
        separated_line(" Word was found in the file ");
    }else{
        separated_line(" Word was not found in the file ");
    }
}

void content_to_upper(){
    string tmp = file_content.str();
    transform(tmp.begin(),tmp.end(),tmp.begin(), ::toupper);
    update_file_content(tmp);
}

void content_to_lower(){
    string tmp = file_content.str();
    transform(tmp.begin(),tmp.end(),tmp.begin(), ::tolower);
    update_file_content(tmp);
}

void content_to_caps(){
    content_to_lower();
    string tmp = file_content.str();
    for (int i = 0; i < tmp.size(); ++i) {
        if(!i || tmp[i-1] == ' ' || tmp[i-1] == '\n'){
            tmp[i] = toupper(tmp[i]);
        }
    }
    update_file_content(tmp);
}

void save_file_name(){
    char choice;
    cout << "How dow you want to save changes\n";
    cout << "1- In the same file\n";
    cout << "2- In another file\n";
    cin >> choice;
    if(choice != '1' && choice != '2'){
        separated_line(" Enter correct choice ");
        save_file_name();
        return;
    }
    if(choice == '2'){
        cout << "Enter the new file name: ";
        cin >> file_name;
    }
    save_file();
}
