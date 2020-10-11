/*
 * fileio.h
 *
 *  Created on: Sep 26, 2020
 *      Author: keith
 */

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../includes/utilities.h"
#include "../includes/constants.h"

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode = std::ios_base::in){
	myfile.open(myFileName.c_str(), mode);
	if (myfile.is_open() == false)
		return false;
	return true;
}

/*iff myfile is open then close it*/
void closeFile(std::fstream& myfile){
	if (myfile.is_open())
		myfile.close();
}

/* serializes all content in entries to file outputfilename
 * check out utils for helpful type conversion functions
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writetoFile(std::vector<constants::entry>  &entries, const std::string &outputfilename){

	std::ofstream outfile;
	outfile.open(outputfilename);

	if(outfile.is_open())
		return constants::FAIL_FILE_DID_NOT_OPEN;
	if (entries.size() == 0)
				return constants::FAIL_NO_ARRAY_DATA;
	for(int i=0; i<entries.size(); i++){
		outfile<<entries[i].word<<" "<<intToString(entries[i].number_occurences)<<std::endl;

	if(outfile.is_open())
		outfile.close();
	//assumming it is open
	return constants::SUCCESS;


	}
}

