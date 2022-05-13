#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

// Declaring variables
string fileName1, fileName2;
int choice;

int nextChoice() {
    cout << "What do you want to do next?" << endl;
    cout << "Please enter the name of the file you want to deal with: ";
    fstream file;
    cin >> fileName1;
    fileName1 += ".txt";
    file.open(fileName1, ios::in);
    while (file.fail()){
        cout << "Failed to open; please check if file exists. \n";
        file.close();
        cout << "File name: ";
        cin >> fileName1;
        fileName1 += ".txt";
        file.open(fileName1, ios::in);
    }
    if (!file.fail()) {
        cout << "File is opened successfully.\n";
    }
    return 0;
}

void openingSecondFile() {
    fstream file;
    cin >> fileName2;
    fileName2 += ".txt";
    file.open(fileName2, ios::in);
}

void saveFile() {

}

void checkFileExistence(){
    ifstream file;
    file.open (fileName2);
    while (file.fail()){
        cout << "Failed to open; please check if file exists. \n";
        file.close();
        cout << "File name: ";
        cin >> fileName2;
        fileName2 += ".txt";
        file.open(fileName1, ios::in);
    }
    if (!file.fail()) {
        cout << "File is opened successfully.\n";
    }
}

// Function to append text at the end of the file
void addingContent() {
    fstream file;
    string text;
    char ch, ch2;
    cin.ignore();
    cout<<"Write the text you want to append in that file: "<<endl;
    while(((ch = getchar()) != '\n') || (ch2 != '\n')){
        text += ch;
        ch2 = ch;
    }
    text.resize(text.length()-1);
    cin.ignore(256, '\n');
    file.open(fileName1, ios::app);
    file<<text<<endl;
    file.close();
}

// Function to display the content of the file
void displayContent() {
    fstream file;
    string line;
    file.open(fileName1,ios::in);
    while(getline(file,line)){
        cout<<line<<endl;
    }
    file.close();
}

// Function to clear the content in the file
void emptyTheFile() {
    fstream file;
    file.open(fileName1,ios:: out | ios:: trunc);
    file.close();
}

// Function to encrypt the content of the file
void encryptTheFileContent() {
    fstream file, file2 ;
    string line;
    int temp;
    file.open(fileName1,ios :: in);
    file2.open(fileName1);
    while(!file.eof()){
        getline(file,line);
        for(char letter : line){
        temp = int(letter) + 1;
        letter = char(temp);
        file2 <<letter;
        }
        file2<<endl;
}
file.close();
file2.close();

}

// Function to decrypt the content of the file
void decryptTheFileContent() {
    fstream file,file2;
    string line;
    int temp;
    file2.open(fileName1,ios::in);
    file.open(fileName1);
    while(!file2.eof()){
        getline(file2,line);
        for(char letter : line){
            temp = int(letter)-1;
                    letter = char(temp);
                    file << letter;
        }
        file<<endl;
    }
    file.close();
    file2.close();
}

// function to merge 2 text files and save them to a third file called Merged_File
void mergingAnotherFile() {
    cout << "Please enter the second file name to be merged with the first one: ";
    openingSecondFile();
    checkFileExistence();
    ifstream file1(fileName1);
    ifstream file2(fileName2);
    ofstream combined_file("Merged_File.txt");
    combined_file << file1.rdbuf() << file2.rdbuf();
    combined_file.close();
}

// function to count the number of words in a text file
void countTheNumberOfWords () {
    ifstream file(fileName1);
    int word = 0;
    char ch, ch2;
    file.seekg(0, ios::beg);
    while (file) {
        file.get(ch);
        if ((ch == ' ' || ch == '\n') && isalpha(ch2)) {
            word++;
        }
        ch2 = ch;
    }
    cout << "Number of words = " << word << endl;
    file.close();
}

// function to count the number of characters in a text file (a character is anything in the ascii table)
void countTheNumberOfCharacters() {
    ifstream file(fileName1);
    char ch; int characters = 0;
    while (file >> noskipws >> ch)
        characters++;
    cout << "Number of characters = " << characters << endl;
    file.close();
}

// function to count the number of line in a text file
void countTheNumberOfLines() {
    ifstream file(fileName1);
    int linesNumber = 0;
    string line;
    while (getline(file, line)){
        ++linesNumber;
    }
    cout << "Number of lines =" << linesNumber << endl;
    file.close();
}

// function to search for a word in a text file (case-insensitive)
void searchForAWord() {
    ifstream file(fileName1);
    string word;
    string text;
    cout << "Enter the word you want to look for: ";
    cin.ignore();
    cin >> word;
    bool isFound = false;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    while (!file.eof()){
        file >> text;
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        if (text == word){
            cout << '\'' << word << '\'' <<  " has been found :)" << endl;
            isFound = true;
            break;
        }
    }
    if (!isFound){
        cout << word << " has not been found :(" << endl;
    }
    file.close();
}

// function to count the number of times a word exists in a text file
void numberOfTimesAWordExists() {
    ifstream file(fileName1);
    string word;
    string text;
    int count = 0;
    cout << "Enter the word you want to look for: ";
    cin.ignore();
    cin >> word;
    bool isFound = false;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    while (!file.eof()){
        file >> text;
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        if (text == word){
            isFound = true;
            count++;
        }
    }
    if (!isFound){
        cout << word << " has not been found :(" << endl;
    }
    else{
        cout << "The number of time " << word << " appeared in the text file is " << count << endl;
    }
    file.close();
}

void turnContentUpperCae() {

}

void turnContentLowerCase() {

}

void turnFileContentFirstCaps() {

}

int menu(){
    fstream file;
    cout << "Choose one of the options below:" << endl;
    cout << "1. Add new text to the end of the file \n"
            "2. Display the content of the file\n"
            "3. Empty the file\n"
            "4. Encrypt the file content \n"
            "5. Decrypt the file content\n"
            "6. Merge another file\n"
            "7. Count the number of words in the file.\n"
            "8. Count the number of characters in the file\n"
            "9. Count the number of lines in the file\n"
            "10. Search for a word in the file\n"
            "11. Count the number of times a word exists in the file\n"
            "12. Turn the file content to upper case.\n"
            "13. Turn the file content to lower case.\n"
            "14. Turn file content to 1st caps (1st char of each word is capital) \n"
            "15. Save\n"
            "16. Exit\n"
            "Choice: ";
    cin >> choice;
    while (choice != 16){
        switch (choice) {
            case 1:
                addingContent();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 2:
                displayContent();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 3:
                emptyTheFile();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 4:
                encryptTheFileContent();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 5:
                decryptTheFileContent();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 6:
                mergingAnotherFile();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 7:
                countTheNumberOfWords();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 8:
                countTheNumberOfCharacters();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 9:
                countTheNumberOfLines();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 10:
                searchForAWord();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 11:
                numberOfTimesAWordExists();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 12:
                turnContentUpperCae();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 13:
                turnContentLowerCase();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 14:
                turnFileContentFirstCaps();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 15:
                saveFile();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            default:
                cout << "Invalid input. Please re-enter your choice: ";
                cin >> choice;
        }
    }
    if (choice == 16){
        cout << "Thank you so much for using our app" << endl;
        cout << "Goodbye!" << endl;
    }
    return 0;
}

int main() {
    fstream file;
    cout << "Hello and welcome to our text editor app!\n";
    cout << "Please enter the name of the file you want to deal with: ";
    cin >> fileName1;
    fileName1 = fileName1 + ".txt";
    file.open(fileName1, ios :: in);
    if (file.fail()){
        cout << "file doesn't exists" << endl;
        file.close();
        cout << "This is a new file. I created it for you :)" << endl;
        ofstream {fileName1};
        file.open(fileName1, ios :: in);
        menu();
    }
    else {
        cout << "This file does already exist.\n";
        if (file.is_open()){
            menu();
        }
    }
}