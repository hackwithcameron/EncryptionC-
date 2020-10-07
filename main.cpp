#include <iostream>

// Base Encryption Class
class EncryptionTool {
protected:
    std::string Word;
public:
    explicit EncryptionTool(std::string word) {
        Word = std::move(word);
    }

    void getWord() {
        std::cout << "The input word is " << Word << std::endl;
    }
};


// Letter swap class for Encryption Tool
class Swap: public EncryptionTool {
private:
    int FirstIndex;
    int SecondIndex;

public:
    Swap(std::string word, int num1, int num2): EncryptionTool(std::move(word)) {
        FirstIndex = num1;
        SecondIndex = num2;
    }

    void LetterSwap() {
        char temp;
        temp = Word[FirstIndex];
        Word[FirstIndex] = Word[SecondIndex];
        Word[SecondIndex] = temp;

        std::cout << "the word swapped is " << Word << std::endl;
    }
};


// Reverse word class for Encryption Tool
class Reverse: public EncryptionTool {
public:
    explicit Reverse(std::string word): EncryptionTool(std::move(word)) {
    }

    void reverseWord() {
        std::reverse(Word.begin(), Word.end());
        std::cout << "the word reversed is " << Word << std::endl;

    }
};


// Rotate class to rotate letters in word
class Rotate: public EncryptionTool {
private:
    int RotateFrom;
    int NumOfChar;

public:
    Rotate(std:: string word, int rotateFrom, int numOfChar): EncryptionTool(std::move(word)) {
        RotateFrom = rotateFrom;
        NumOfChar = numOfChar;
    }

    void rotateWord() {
        std::string temp = Word.substr(RotateFrom, NumOfChar);
        std::rotate(temp.begin(), temp.begin() + 1, temp.end());
        Word.replace(RotateFrom, NumOfChar, temp);
        std:: cout << "Word is now " << Word << std::endl;
    }
};



class Again {
    
};


// Main function
int main() {
    std::string word;
    std::string againInput;
    std::string yes[] = {"YES", "yes", "Yes", "Y", "y"};
    bool run = true;
    bool again = false;

    std::cout << "\nWelcome to Encryption Tool 1.0.0"<< std::endl;
    while (run) {
        std::cout << "Please enter a word to be encrypted:" << std::endl;
        std::cin >> word;
        std::cout << "the original word entered is " << word << std::endl;
        //Reverse word
        Reverse reversedWord(word);
        reversedWord.reverseWord();
        // Swap word
        Swap inputWord(word, 1, 4);
        inputWord.LetterSwap();
        //Rotate word
        Rotate rotateWord(word, 1, 3);
        rotateWord.rotateWord();

        std::cout << "Would you like to enter another word?" << std::endl;
        std::cin >> againInput;

        for (int i = 0; i < 5; i++) {
            if (yes[i] == againInput) {
                again = true;
                break;
            }
            else {again = false;}
        }

        if (again) {
            continue;
        }
        else {
            std::cout << "Thank you for using Encryption Tool!" << std::endl;
            run = false;
        }
    }
}



