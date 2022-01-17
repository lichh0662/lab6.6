
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map <string, int> words;
    words.insert({ "*", 0 });// define an object on the map and give him(key,element)
    string line;
    cout << "Enter your Line: ";
    getline(cin, line);
    line += ' ';

    string tmp_line = "";// we make a new temperar line from our line
    for (auto i : line) {
        if (i != ' ' and i != ',' and i != '.')
            tmp_line += tolower(i);// put all the letters in lowercase 
        else {
            if (tmp_line != "") {

                if (words.find(tmp_line) != words.end()) { //find word
                    words[tmp_line]++;// count the num of the word that we fond
                }
                else {
                    words.insert({ tmp_line, 1 }); //define the word we fond as new object and give it 
                }                                  //kye(our word) and element(the number of the word in the text)
                words["*"]++; // count the num of the words
            }
            tmp_line = "";// return the word
        }
    }

    //
    cout << "Answer:" << endl;
    cout << "All words: " << words["*"] << endl;
    for (auto i = ++words.begin(); i != words.end(); i++) {
        cout << '\t' << i->first << ": " << i->second / (words["*"] / 100.0) << "%\n";
    } //(iterator) first(key) its the word and secend(element) the num of the word 
}