/*
 * functionstocomplete.h
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include<algorithm>

#include <vector>
#include "../includes/constants.h"
#include "../includes/utilities.h"
#include "../includes/array_functions.h"
using namespace constants;

/*============================================================================
 * The following are declarations for functions that I will test
 * Please provide the definitions in the
 * included cpp file, do not erase the stuff I put in there please
 * DO NOT MODIFY THIS FILE, I WILL USE MY OWN COPY
/============================================================================*/

namespace KP{
	//zero out vector that tracks words and their occurrences (call vectors clear method)
	void clear(std::vector<constants::entry>  &entries)
	{
		entries.clear();
	}

	//how many unique words are in the vector
	int getSize(std::vector<constants::entry>  &entries)
	{
		entries.size();
		return entries.size();
	}

	//get data at a particular location, if i>size() then get the last value in the vector
	//(this is lazy, should throw an exception instead)
	std::string getWordAt(std::vector<constants::entry>  &entries, int i){
		if (i> entries.size()){
			return entries[entries.size()-1].word;
		return entries[i].word;
	}
}

	int getNumbOccurAt(std::vector<constants::entry>  &entries,int i){
		if (i> entries.size()){
					return entries[entries.size()-1].number_occurences;
		return entries[i].number_occurences;
	}
}

	/*loop through whole file, one line at a time
	 * call processLine on each line from the file
	 * returns false: myfstream is not open
	 *         true: otherwise*/
	bool processFile(std::vector<constants::entry>  &entries,std::fstream &myfstream){
		std::string str;
		if (myfstream.is_open() == false){
			return false;
		}
		if (myfstream.is_open() == true){
			while (getline(myfstream, str)){
				KP::processLine(entries,str);

			}
		}
		if (myfstream.is_open() == true){
			myfstream.close();
			return true;
		}
}

	/*take 1 line and extract all the tokens from it
	feed each token to processToken for recording*/
	void processLine(std::vector<constants::entry>  &entries,std::string &myString){
		std::stringstream ss(myString);
		std::string tempToken;
		while(getline(ss,tempToken,constants::CHAR_TO_SEARCH_FOR)){
				processToken(entries,tempToken);
	}
}

	/*Keep track of how many times each token seen*/
	void processToken(std::vector<constants::entry>  &entries,std::string &token){
		//Strip unwanted char and bump out if empty

		strip_unwanted_chars(token);
		entry sam;
		sam.word = token;
		sam.number_occurences = 1;

		for(int i = 0;i<entries.size();i++){
			std::string currententry = entries[i].word;
			std::string previousentry = sam.word;
			toUpper(currententry);
			toUpper(previousentry);
			if(currententry == previousentry){
				entries[i].number_occurences++;
				return;

			}
		}
		if(token !=""){
			entries.push_back(sam);
		}
}

	/*
	 * Sort myEntryArray based on so enum value.
	 * Please provide a solution that sorts according to the enum
	 * The presence of the enum implies a switch statement based on its value
	 * See the course lectures and demo project for how to sort a vector of structs
	 */

bool goingup(entry samone, entry samtwo){
	toUpper(samone.word);
	toUpper(samtwo.word);
	return samone.word < samtwo.word;

}


bool goingdown(entry samone, entry samtwo){
	toUpper(samone.word);
	toUpper(samtwo.word);
	return samone.word > samtwo.word;
}
bool ordernumbers(entry samone, entry samtwo){
	return samone.number_occurences > samtwo.number_occurences;
}


void sort(std::vector<constants::entry> &entries, constants::sortOrder so) {
switch(so){

case ASCENDING:
	sort(entries.begin(),entries.end(), goingup);
	break;
case DESCENDING:
	sort(entries.begin(), entries.end(), goingdown);
	break;
case NUMBER_OCCURRENCES:
	sort(entries.begin(), entries.end(), ordernumbers);
	break;
case NONE:
	break;

		}


}
}

