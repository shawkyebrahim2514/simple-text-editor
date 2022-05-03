#include <bits/stdc++.h>
#include "all_functions.cpp"
using namespace std;
void show_menu(){
    separated_line(" Choose what you want to do ");
    cout << "1- Add new text to the end of the file\n";
    cout << "2- Display the content of the file\n";
    cout << "3- Empty the file content\n";
    cout << "4- Encrypt the file content\n";
    cout << "5- Decrypt the file content\n";
    cout << "6- Merge another file\n";
    cout << "7- Count the number of words in the file\n";
    cout << "8- Count the number of characters in the file\n";
    cout << "9- Count the number of lines in the file\n";
    cout << "10- Search for a word in the file\n";
    cout << "11- Count the number of times a word exists in the file\n";
    cout << "12- Turn the file content to upper case\n";
    cout << "13- Turn the file content to lower case\n";
    cout << "14- Capitalize all words\n";
    cout << "15- Save\n";
    cout << "16- Exit\n";
}

void take_choice(){
    int choice;
    cout << "Enter your choice number: ";
    cin >> choice;
    if(choice < 1 || choice > 16){
        separated_line(" Enter correct choice ");
        take_choice();
        return;
    }
    switch (choice) {
        case 1:
            add_content();
            break;
        case 2:
            display_content();
            break;
        case 3:
            empty_content();
            break;
        case 4:
            encrypt_content();
            break;
        case 5:
            decrypt_content();
            break;
        case 6:
            merge_files();
            break;
        case 7:
            count_words();
            break;
        case 8:
            count_characters();
            break;
        case 9:
            count_lines();
            break;
        case 10:
            search_word();
            break;
        case 11:
            get_repeated_word();
            break;
        case 12:
            content_to_upper();
            break;
        case 13:
            content_to_lower();
            break;
        case 14:
            content_to_caps();
            break;
        case 15:
            save_file_name();
            break;
        case 16:
            return;
    }
    show_menu();
    take_choice();
}

int main() {
    take_file_name();
    load_file();
    show_menu();
    take_choice();
}
