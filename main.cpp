#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <stdio.h>

using namespace std;

// Declaring variables
string fileName1, fileName2;
char choice;

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
    ofstream savedFile("new file");
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
    savedFile.close();
}

// Function to display the content of the file
void displayContent() {
    fstream file;
    ofstream savedFile("new file");
    string line;
    file.open(fileName1,ios::in);
    while(getline(file,line)){
        cout<<line<<endl;
    }
    file.close();
    savedFile.close();
}

// Function to clear the content in the file
void emptyTheFile() {
    fstream file;
    ofstream savedFile("new file");
    file.open(fileName1,ios:: out | ios:: trunc);
    file.close();
    savedFile.close();
}

// Function to encrypt the content of the file
void encryptTheFileContent() {
    fstream file ;
    ofstream savedFile("new file");
    string line;
    int temp;
    file.open(fileName1,ios :: in);
    while(!file.eof()){
        getline(file,line);
        for(char letter : line){
            temp = int(letter) + 1;
            letter = char(temp);
            savedFile <<letter;
        }
        savedFile<<endl;
    }
    file.close();
    savedFile.close();
}

// Function to decrypt the content of the file
void decryptTheFileContent() {
    fstream file;
    ofstream savedFile("new file");
    string line;
    int temp;
    file.open(fileName1,ios::in);
    while(!file.eof()){
        getline(file,line);
        for(char letter : line){
            temp = int(letter)-1;
            letter = char(temp);
            savedFile << letter;
        }
        savedFile<<endl;
    }
    file.close();
    savedFile.close();
}

// function to merge 2 text files and save them to a third file called Merged_File
void mergingAnotherFile() {
    cout << "Please enter the second file name to be merged with the first one: ";
    openingSecondFile();
    checkFileExistence();
    ifstream file1(fileName1);
    ifstream file2(fileName2);
    ofstream combined_file("Merged_File.txt");
    combined_file << file1.rdbuf() << endl << file2.rdbuf();
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
    ifstream file(fileName1);
    ofstream savedFile("new file");
    char ch;
    while (file.get(ch)){
        ch = toupper(ch);
        savedFile << ch;
    }
    file.close();
    savedFile.close();
}

void turnContentLowerCase() {
    ifstream file(fileName1);
    ofstream savedFile("new file");
    char ch;
    while (file.get(ch)){
        ch = tolower(ch);
        savedFile << ch;
    }
    file.close();
    savedFile.close();
}

void turnFileContentFirstCaps() {
    fstream file(fileName1);
    ofstream savedFile("new file");
    char ch;
    bool new_word = true;
    while (file.get(ch)) {
        if (ch == '.' || ch == ' ' || ch == '\n') {
            new_word = true;
        }
        if (isalpha(ch)) {
            if (new_word) {
                ch = toupper(ch);
                new_word = false;
            }
            else {
                ch = tolower(ch);
            }
        }
        savedFile.put(ch);
    }
    file.close();
    savedFile.close();
}

void saveFile() {
    int input;
    cout << "Please choose where do want this changes to be saved\n"
        "1- in this file\n"
        "2- in a new file\n"
        "Choice: ";
    cin >> input;
    if(input == 1){
        emptyTheFile();
        char ch;
        ofstream file(fileName1);
        ifstream savedFile("new file");
        while(savedFile.get(ch)){
            file << ch ;
        }
        savedFile.close();
        file.close();
        remove( "new file" );
        cout << "Changes have been saved successfully in this file\n";
    }
    else if (input == 2){
        cout << "Changes have been saved successfully in a new file\n";
    }
    else{
        cout <<"Please enter a valid choice\n";
        saveFile();
    }

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
            "a. Search for a word in the file\n"
            "b. Count the number of times a word exists in the file\n"
            "c. Turn the file content to upper case.\n"
            "d. Turn the file content to lower case.\n"
            "e. Turn file content to 1st caps (1st char of each word is capital) \n"
            "f. Exit\n"
            "Choice: ";
    cin >> choice;
    while (choice != 'f'){
        switch (choice) {
            case '1':
                addingContent();
                saveFile();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case '2':
                displayContent();
                saveFile();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case '3':
                emptyTheFile();
                saveFile();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case '4':
                encryptTheFileContent();
                saveFile();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case '5':
                decryptTheFileContent();
                nextChoice();
                saveFile();
                cout << "Choice: ";
                cin >> choice;
                break;
            case '6':
                mergingAnotherFile();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case '7':
                countTheNumberOfWords();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case '8':
                countTheNumberOfCharacters();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case '9':
                countTheNumberOfLines();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 'a':
                searchForAWord();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 'b':
                numberOfTimesAWordExists();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 'c':
                turnContentUpperCae();
                saveFile();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 'd':
                turnContentLowerCase();
                saveFile();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            case 'e':
                turnFileContentFirstCaps();
                nextChoice();
                cout << "Choice: ";
                cin >> choice;
                break;
            default:
                cout << "Invalid input. Please re-enter your choice: ";
                cin >> choice;
        }
    }
    if (choice == 'f'){
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
        if (file.is_open()){
            menu();
        }
    }
}
