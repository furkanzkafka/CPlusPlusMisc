#include <iostream>
#include <fstream>
//#include <unistd.h>
//#include <sstream>
//#include <vector>
//#include <math.h>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

int main() {
    // Variable initializing
    // Camel case variables either copied from slides or main function given
    // snake case variables written by me
    unordered_map<string, int> wordCount;
    unordered_map<string, int>::iterator iterator_1;
    string lines[200];
    string max_word = "x";
    int lineCount=0;
    int max_count = 1;
    ifstream inFile; // create an object inFile of type ifstream
    inFile.open("greenEggsAndHam.txt");
    
    // Checking if the file successfully found
    if(!inFile.is_open()){
        cout << "Could not open file! Unable to proceed!" << endl;
        return 0;
    }
    else{
        cout << "File opened... Processing..." << endl << endl;
        // Reading the data from the file line by line
        while(getline(inFile, lines[lineCount])){
            lineCount++;
        }
        
        // Reading the data word by word.
        // I started working on this assigment monday
        // The assigment wasn't updated yet this is the one of the method that worked for word by word
        // while(inFile >> lines) seems like a common way to do but since we need to store the data in a array
        // It didn't work
        /*
        string separator{" \t\r\n,.!?;:"};
        string line;
        string word;
        while(getline (inFile, line)){  // read line by line
            size_t e,s=0;            // s = offset of next word, e = end of next word
            do {
                s = line.find_first_not_of(separator,s);  // skip leading separators
                if (s==string::npos)                  // stop if no word left
                    break;
                e=line.find_first_of(separator, s);   // find next separator
                string word(line.substr(s,e-s));      // construct the word
                cout<<word<<endl;
                s=e+1;                                // position after the separator
            } while (e!=string::npos);                // loop if end of line not reached
        }
         */
    }
         
    
    // Clearing the special characters and storing it back.
    for(int i=0; i < lineCount;i++){
        for(int j=0; j<lines[i].length(); j++){
            if( lines[i][j] < 'A' || lines[i][j] > 'z' ||
                    (lines[i][j] < 'Z' && lines[i][j] > 'a')){
               lines[i][j] = ' ';//set non-alphabetical to spaces
            }
        }
    }
    
    for (int i = 0; i < lineCount; i++) {
        //It's possible there are spaces in front so find first non-space
        //For some reason XCode didn't like int data type so I replaced it to long
        long start = lines[i].find_first_not_of(" ");
        if (start < 0) continue; //skip this line
        //find first space after start
        //For some reason XCode didn't like int data type so I replaced it to long
        long end = lines[i].find_first_of(" ", start);
        if (end <= 0) end = lines[i].length() - 1;
        // Storing the first word of the line to wordCount
        string word = lines[i].substr(start, end - start);
        //add or increment the value in the map matching the word
        ++wordCount[word];
    }
    
    // Printing out the bucket
    cout << "Number of keys: " << wordCount.size() << endl;
    cout << "Bucket Count: " << wordCount.bucket_count() << endl;
    cout << "Load factor: " << wordCount.load_factor() << endl << endl;
    
    // Some reason the sytanx in the slides throw me error adding auto was fixed it.
    // Finding the max used word and it's value will be equal to maxCount
    for (auto iterator_1 = wordCount.begin(); iterator_1 != wordCount.end(); iterator_1++){
            if (iterator_1->second > max_count) {
                max_count = iterator_1->second;
                max_word = iterator_1->first;
            }
    }
    
    cout << "Word with max frequency is " << max_word << " which is used " << max_count << " times..."<< endl << endl;
    // Some reason XCode didn't like int so replaced it to long
    long bucket_num = wordCount.bucket(max_word);
    
    // Some reason the sytanx in the slides throw me error adding auto fixed it
    for (auto iterator_1 = wordCount.begin(bucket_num); iterator_1 != wordCount.end(bucket_num); iterator_1++)
    {
        cout << "Key: " << iterator_1->first << " Value: " << iterator_1->second << " " << endl;
    }
    // File closed
    inFile.close();
    cout << "Code executed! File is closed..."<< endl;
    return 0;
}


