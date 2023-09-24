#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <limits>
#include <conio.h>

class DictionaryADT {
private:
    std::map<std::string, std::string> data;

public:
    void addWord(const std::string& key, const std::string& value) {
        if (searchWord(key)) {
            std::cout << "Word already exists in the dictionary\n";
        } else {
            data[key] = value;
        }
    }

    bool searchWord(const std::string key) const {
        return data.find(key) != data.end();
    }

    void displayDictionary() const {
        if (data.empty()) {
            std::cout << "Dictionary is empty (press 1 to add words)\n";
        } else {
            std::cout << "Dictionary Contents:" << std::endl;
            std::cout << "--------------------" << std::endl;
            for (const auto& pair : data) {
                std::cout << pair.first << "  ->  " << pair.second << std::endl;
            }
        }
    }

    bool deleteDictionary() {
        std::cout << "Are you sure you want to delete the entire dictionary? (y/n): ";
        char input;
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        if (input == 'Y' || input == 'y') {
            data.clear();
            std::cout << "Dictionary deleted successfully" << std::endl;
            return true;
        } else {
            std::cout << "Operation Cancelled" << std::endl;
            return false;
        }
    }

    void deleteKey(const std::string& key) {
        if (searchWord(key)) {
            std::cout << "Are you sure you want to delete " << key << " from the dictionary? (y/n): ";
            char input;
            std::cin >> input;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (input == 'Y' || input == 'y') {
                data.erase(key);
                std::cout << key << " Deleted Successfully" << std::endl;
            } else {
                std::cout << "Operation Cancelled" << std::endl;
            }
        } else {
            std::cout << "Word '" << key << "' not found for deletion\n" << std::endl;
            displayDictionary();
        }
    }

    void updateWord(const std::string key) {
        if (searchWord(key)) {
            std::cout << "Enter a new value for " << key << " : ";
            std::string new_value;
            std::getline(std::cin, new_value);
            data[key] = new_value;
        } else {
            std::cout << "Word does not exist in the dictionary" << std::endl;
        }
    }

    std::string findMeaning(const std::string key) {
        auto it = data.find(key);
        if (it != data.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Word not found");
        }
    }
};

class Menu {
public:
    static int showMenu() {
        int choice;
        std::cout << "---------------------------" << std::endl;
        std::cout << "1> Add word(s)" << std::endl;
        std::cout << "2> Delete word" << std::endl;
        std::cout << "3> Search word" << std::endl;
        std::cout << "4> Display the dictionary" << std::endl;
        std::cout << "5> Delete entire dictionary" << std::endl;
        std::cout << "0> Exit!" << std::endl;
        std::cout << "---------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        return choice;
    }
};

int main() {
    DictionaryADT dict;

    dict.addWord("Sakshi Mane", "Sonchafa");
    dict.addWord("Aditya Godse", "Eugene");
    dict.addWord("Jaydeep", "Dr. J");

    bool operation = true;

    while (operation) {
        system("cls");
        std::cout << "Welcome to the Dictionary ADT portal" << std::endl;
        std::cout << "Enter the number associated with the operation you'd like to perform\n\n";

        int choice = Menu::showMenu();

        switch (choice) {
            case 1: {
                system("cls");
                int words;
                std::cout << "How many words do you want to add: ";
                std::cin >> words;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                for (int i = 0; i < words; i++) {
                    std::cout << "------------------------------------" << std::endl;
                    std::string key, value;
                    std::cout << "Enter the word to add in dictionary: \t";
                    std::getline(std::cin, key);
                    std::cout << "Enter the meaning of " << key << ": \t";
                    std::getline(std::cin, value);
                    dict.addWord(key, value);
                }
                getch();
                break;
            }

            case 2: {
                system("cls");
                std::string key;
                std::cout << "Enter the word to delete from dictionary: ";
                std::getline(std::cin, key);
                dict.deleteKey(key);
                getch();
                break;
            }

            case 3: {
                system("cls");
                std::string key;
                std::cout << "Enter the word to search from dictionary: ";
                std::getline(std::cin, key);
                try {
                    std::cout << dict.findMeaning(key) << std::endl;
                } catch (const std::exception& e) {               
                    std::cout << e.what() << std::endl<<std::endl;
                    dict.displayDictionary();
                }
                getch();
                break;
            }

            case 4:
 
                system("cls");               
                dict.displayDictionary();
                getch();
                break;

            case 5:
 
                system("cls");               
                dict.deleteDictionary();
                getch();
                break;

            case 0:
 
                system("cls");               
                operation = false;
                std::cout << "Goodbye, have a nice day!" << std::endl;
                getch();
                break;

            default:
                std::cout << "Invalid Input! Enter a number from 0 to 5." << std::endl;
        }
    }

    return 0;
}
