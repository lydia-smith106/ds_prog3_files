//Lydia Smith
//Program 3
//COSC 2030
//4/20/21

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include "timer.h"
#include "Hash.cpp"

using namespace std;

string cleanWord(string word);

int main()
{

	//declare strings 
	string line;
	string word;
	string newWord;


	//declare files for I/O
	ifstream myfile("dict.txt");
	ifstream bookfile("book.txt");
	ofstream outFile{ "misspelled.txt" };

	//declare vector and hash to hold dictionary
	vector<string> misspelled;
	Hash<string> dictHash;

	//declare integers for finds and compares
	int found = 0;
	int not_found = 0;
	int not_checked = 0;
	int found_compares = 0;
	int not_found_compares = 0;

	//declare watch to time book compares
	Timer Watch;

	//add words from dictionary to hash table
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			string newLine = cleanWord(line);
			//cout << newLine << endl;
			dictHash.insertItem(newLine);
			//dict_list.AddLeaf(newLine);
			//cout << newLine;
		}
		myfile.close();
	}

	else cout << "Unable to open file";
	
	//start timer
	Watch.Start();

	//read words from book file and check in clean word
	if (bookfile.is_open())
	{
		while (!bookfile.eof())
		{
			bookfile >> word;

			newWord = cleanWord(word);
			//cout << newWord << endl;

			//check if first letter is a number or apostraphe
			if (isdigit(newWord[0]) != 0 || newWord[0] == '\'')
			{
				//word.clear();
				not_checked++;

			}
			else if(newWord.empty()== false)
			{
				//cout << newWord;
				bool check = dictHash.find(newWord);
				if(check == true)
				{
					found++;
				
				}else
				{
					misspelled.push_back(newWord);
					not_found++;
				
				}
				
			}
		}
		bookfile.close();
	}

	else cout << "Unable to open file";

	Watch.Stop();

	//add misspelled to file
	for (int i = 0; i < misspelled.size(); i++)
	{
		outFile << misspelled.at(i) << endl;

	}

	//not_found_compares = dict_list.getTotalCompares() - found_compares;

	cout << std::fixed;
	std::cout << std::setprecision(2);
	cout << "dictionary size: " <<dictHash.returnSize()<< endl;
	cout << "Done checking and these are the results:" << endl;
	cout << "finished in time: " << Watch.Time() << endl;
	cout << "finished in Milliseconds time: " << Watch.TimeMS() << endl;
	cout << "There are " << found << " words found in the dictionary." << endl;
	//cout << "     " << found_compares << " compares. Average: " << (found_compares / found) << endl;
	cout << "There are " << not_found << " words not found in the dictionary." << endl;
	//cout << "     " << not_found_compares << " compares. Average: " << (not_found_compares / not_found) << endl;
	cout << "There are " << not_checked << " words not checked." << endl;


	return 0;
};

string cleanWord(string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		word[i] = tolower(word[i]);
		if (!(isalnum(word[i])) && word[i] != '\'')
		{
			//cout << practice[i];
			word.erase(i, 1);
			i--;
		}

	}

	return word;


};


