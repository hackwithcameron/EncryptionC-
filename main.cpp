#include <iostream>
#include <cmath>

// Base Encryption Class
class EncryptionTool {
protected:
    std::string Word;
    int WordLength;
    int Num1;
    int Num2;
public:
    explicit EncryptionTool(std::string word)
    : Word(std::move(word)), WordLength(Word.length()), Num1(0 + int(floor(WordLength/4))),
    Num2(WordLength - int(floor(WordLength/2))){
    }
    // Prints Original input word to console
    void getWord() {
        std::cout << "the original word entered is " << Word << std::endl;
    }
};


// Letter swap class for Encryption Tool
class Swap: public EncryptionTool {
private:
    int FirstIndex;
    int SecondIndex;

public:
    explicit Swap(std::string word)
    : EncryptionTool(std::move(word)), FirstIndex(Num1), SecondIndex(Num2) {
    }

    void LetterSwap() {
        char temp = Word[FirstIndex];  // Assigns letter at first index to temp
        Word[FirstIndex] = Word[SecondIndex];  // Changes letter at first index to letter at second index
        Word[SecondIndex] = temp;  // Changes letter at second index to letter at first index.

        std::cout << "the word swapped is " << Word << std::endl;
    }
};


// Reverse word class for Encryption Tool
class Reverse: public EncryptionTool {
public:
    explicit Reverse(std::string word): EncryptionTool(std::move(word)) {
    }
    // Method to reverse input word
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
    explicit Rotate(std:: string word)
    : EncryptionTool(std::move(word)), RotateFrom(Num1), NumOfChar(Num2 +1) {
    }

    void rotateWord() {
        std::string temp = Word.substr(RotateFrom, NumOfChar);  // Sets variable temp to a substring from the center of the input word
        std::rotate(temp.begin(), temp.begin() + 1, temp.end());  // Rotates letters in temp substring to the left one place
        Word.replace(RotateFrom, NumOfChar, temp); // Replaces the old substring with new rotated substring in the input word
        std:: cout << "The word with the characters rotated is " << Word << std::endl;
    }
};


// Checks to see if user would like to enter another word
class Again {
private:
    std::string Yes[5] = {"yes", "Yes", "YES", "Y", "y"};
    std::string AgainInput;
    bool PlayAgain = false;

public:
    explicit Again(std::string againInput)
    :AgainInput(std::move(againInput)){
    }

    bool again(){
        for (auto & Ye : Yes) {  // Loops through "yes list" checking for a match to user input
            if (Ye == AgainInput) {  // If user input equals a form of yes, break the loop and set PlayAgain to true
                PlayAgain = true;
                break;
            }
            else {PlayAgain = false;}
        }

        if (PlayAgain) {  // If PlayAgain is true return true else return false and thank the user
            return true;
        }
        else {
            std::cout << "Thank you for using Encryption Tool!" << std::endl;
            return false;
        }
    }
};


// Main function
int main() {
    std::string word;
    std::string againInput;
    bool run = true;

    std::cout << "\nWelcome to Encryption Tool 1.0.0"<< std::endl;
    while (run) {
        std::cout << "Please enter a word to be encrypted:" << std::endl;
        std::cin >> word;
        EncryptionTool input(word);
        input.getWord();
        //Reverse word
        Reverse reversedWord(word);
        reversedWord.reverseWord();
        Swap inputWord(word);
        inputWord.LetterSwap();
        Rotate rotateWord(word);
        rotateWord.rotateWord();

        // Checks to see if user would like to encrypt a new word
        std::cout << "Would you like to enter another word?" << std::endl;
        std::cin >> againInput;
        Again again(againInput);
        if (!again.again()) {run = false;}
    }
    return 0;
}



