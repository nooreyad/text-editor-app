#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string fileName1, fileName2;
int choice;

int nextChoice() {
    cout << "What do you want to do next?" << endl;
    cout << "Please enter the name of the file you want to deal with: ";
    fstream file;
    cin >> fileName1;
    fileName1 = fileName1 + ".txt";
    file.open(fileName1, ios::in);
    return 0;
}

void openingSecondFile() {
    fstream file;
    cin >> fileName2;
    fileName2 = fileName2 + ".txt";
    file.open(fileName2, ios::in);
}

void saveFile() {

}

void checkFileExistence(){
    ifstream file;
    file.open (fileName2);
    if (file.fail()){
        cout << "Failed to open; check if file exists. \n";
    }
    else {
        cout << "File is opened successfully.\n";
    }
}

void addingContent() {

}

void displayContent() {

}

void emptyTheFile() {

}

void encryptTheFileContent() {

}

void decryptTheFileContent() {

}

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

void countTheNumberOfWords () {
    ifstream file(fileName1);
    int word = 1;
    char ch;
    file.seekg(0, ios::beg);
    while (file) {
        file.get(ch);
        if (ch == ' ' || ch == '\n') {
            word++;
        }
    }
    cout << "\nWords = " << word << "\n";
    file.close();
}

void countTheNumberOfCharacters() {
    ifstream file(fileName1);
    char ch; int characters = 0;
    while (file >> noskipws >> ch)
        characters++;
    cout << "Characters = " << characters << endl;
    file.close();
}

void countTheNumberOfLines() {

}

void searchForAWord() {

}

void countTheNumberOfTimesAWordExists() {

}

void turnContentUpperCae() {

}

void turnContentLowerCase() {

}

void turnFileContentFirstCaps() {

}

int menu(){
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
                countTheNumberOfTimesAWordExists();
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
        cout << "This is a new file. I created it for ypu :)" << endl;
        ofstream {"New File.txt"};
        file.open("New File.txt", ios :: in);
        menu();
    }
    else {
        if (file.is_open()){
            menu();
        }
    }
}