/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of "StringTriples" (a typedef'd std::tuple, see top of 
 * cartalk_puzzle.h). Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector< StringTriple > cartalk_puzzle(PronounceDict d,
                                      const string& word_list_fname)
{
    vector<StringTriple> solution;
    ifstream word_list_file(word_list_fname);

    if(word_list_file.is_open()){
        string word;
        while(getline(word_list_file, word)){
            if(word.size() < 5) {
                continue;
            }

            string word_without_first = word.substr(1);
            if(d.homophones(word, word_without_first)){
                string word_without_second = word.substr(0,1) + word.substr(2);
                if(d.homophones(word_without_first, word_without_second)) {
                    solution.push_back(make_tuple(word, word_without_first, word_without_second));
                }
            }
        }
    }
    return solution;
}
