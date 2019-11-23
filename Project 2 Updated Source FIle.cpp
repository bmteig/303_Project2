#include<iostream>
#include<map>
#include<string> 
#include<fstream>
using namespace std;

//Create binary tree structure and O(1)
struct Tree {
	string data;
	Tree* left;
	Tree* right;

};

//Function to create new nodes and O(n)
Tree* newnode(string code) {
	Tree* tempTree = new Tree;
	tempTree->left = tempTree->right = NULL;
	tempTree->data = code;
	return tempTree;

}

//Functions to set Left and Right nodes in Tree and O(1)
void setLeft(Tree* new_value, string value) {
	new_value->left = newnode(value);
}

void setRight(Tree* new_value, string value) {
	new_value->right = newnode(value);
}

//Function to insert new nodes into the tree and O(n)
void insert(Tree* new_value, string code) {
	while (1) {
		if (code <= new_value->data) {
			if (new_value->left != NULL) {
				new_value = new_value->left;
			}
			else {
				setLeft(new_value, code);
				break;
			}
		}
		else {
			if (new_value->right != NULL) {
				new_value = new_value->right;
			}
			else {
				setRight(new_value, code);
				break;
			}
		}
	}
}

//Function that does an inorder traversal of binary tree and O(n)
void inTrav(Tree* aTree) { 
	if (aTree->left != NULL) {
		inTrav(aTree->left);
	}
	cout << "Value is = " << aTree->data << endl;
	if (aTree->right != NULL) {
		inTrav(aTree->right);
	}
}

int main() {

	// Adds the alphabet morse code letters to binary tree
	Tree* morseTree = newnode("._");
	insert(morseTree, "_...");
	insert(morseTree, "_._.");
	insert(morseTree, "_..");
	insert(morseTree, ".");
	insert(morseTree, ".._.");
	insert(morseTree, "__.");
	insert(morseTree, "....");
	insert(morseTree, "..");
	insert(morseTree, ".___");
	insert(morseTree, "_._");
	insert(morseTree, "._..");
	insert(morseTree, "__");
	insert(morseTree, "_.");
	insert(morseTree, "___");
	insert(morseTree, ".__.");
	insert(morseTree, "__._");
	insert(morseTree, "._.");
	insert(morseTree, "...");
	insert(morseTree, "_");
	insert(morseTree, ".._");
	insert(morseTree, "..._");
	insert(morseTree, ".__");
	insert(morseTree, "_.._");
	insert(morseTree, "_.__");
	insert(morseTree, "__..");
	//inTrav(morseTree);

	// Map for Tree Values 
	map<string, int> morseDecoder; 

	morseDecoder["._"] = 1;
	morseDecoder["_..."] = 2;
	morseDecoder["_._."] = 3;
	morseDecoder["_.."] = 4;
	morseDecoder["."] = 5;
	morseDecoder[".._."] = 6;
	morseDecoder["__."] = 7;
	morseDecoder["...."] = 8;
	morseDecoder[".."] = 9;
	morseDecoder[".___"] = 10;
	morseDecoder["_._"] = 11;
	morseDecoder["._.."] = 12;
	morseDecoder["__"] = 13;
	morseDecoder["_."] = 14;
	morseDecoder["___"] = 15;
	morseDecoder[".__."] = 16;
	morseDecoder["__._"] = 17;
	morseDecoder["._."] = 18;
	morseDecoder["..."] = 19;
	morseDecoder["_"] = 20;
	morseDecoder[".._"] = 21;
	morseDecoder["..._"] = 22;
	morseDecoder[".__"] = 23;
	morseDecoder["_.._"] = 24;
	morseDecoder["_.__"] = 25;
	morseDecoder["__.."] =26;

	// User Input
	int userChoice;
	string userEncode;
	string letters[26];
	string alphabet[] = { "a", "b", "c", "d", "e", "f", "g", "h", "i","j", "k" , "l", "m", "n", "o", "p", "q", "r", "s", "t","u","v","w","x","y","z" };
	string morseCode[] = { "._","_...","_._.","_..",".",".._.","__.","....","..",".___","_._","._..","__","_.","___",".__.","__._","._.","...","_",".._","..._",".__","_.._","_.__","__.." };
	cout << "Welcome to the Morse Coder" << endl << "What would you like to do today?" << endl << "1. Upload a txt file and Decode it" << endl << "2. Type in a word and have it encoded";
	cout << "\nPlease Enter 1 for the first option or a 2 for the second option:" << endl;
	cin >> userChoice;

	if (userChoice == 1) {	// decode from file, uses map as permitted in class discussion, O(log(n))
		string path;
		ifstream inputFile;
		string encoded;	// stores letter code from file
		int decode;		// stores int value from map lookup based on encoded key
		cout << "Please enter the path to the file you would like to decode (type \"Example.txt\" for a built-in test):" << endl;
		cin >> path;
		inputFile.open(path);

		while (!inputFile) {  //checks for valid filename
			cout << "File could not be opened. Please try again." << endl;
			cout << "Please enter the path to the file you would like to decode (type \"Example.txt\" for a built-in test):" << endl;
			cin >> path;
		}

		cout << "Below is the decoded file:" << endl;

		while (inputFile) {
			getline(inputFile, encoded, ' ');
			decode = morseDecoder.at(encoded);
			cout << alphabet[decode-1];
		}

		inputFile.close();
	}

	if (userChoice == 2) { // Encoding of User's Word and O(N^2)
		cout << "Enter the word you wish to encode:" << endl;
		cin >> userEncode;

		for (int i = 0; i < userEncode.length(); i++) { //Breakdown the string into characters 
			letters[i] = userEncode[i]; 
			for (int j = 0; j < 26; j++) { //Find the associated Morse Code with letter 
				if (letters[i] == alphabet[j]) {
					cout << morseCode[j] << " ";
				}
			}
		}

		
	}
	cout << endl;
	system("pause");
}
