#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to sort the characters of a string
string sortString(const string &str) {
  string sorted_str = str;
  sort(sorted_str.begin(), sorted_str.end());
  return sorted_str;
}

// Function to check if two words are anagrams
bool areAnagrams(const string &word1, const string &word2) {
  string sorted_word1 = sortString(word1);
  string sorted_word2 = sortString(word2);

  return std::includes(sorted_word1.begin(),sorted_word1.end(),
                        sorted_word2.begin(),sorted_word2.end()); //Checks whether letters of word2 are a subset of the letters in word 1

  //sortString(word1) == sortString(word2);
}

// Function to find and return all anagrams in the file
vector<string> findAnagrams(const string &word, const string &filename) {
  ifstream file(filename);
  vector<string> anagrams;
  string line;

  if (!file.is_open()) {
    cerr << "Error: Could not open the file " << filename << endl;
    return anagrams;
  }

  while (getline(file, line)) {
    if (areAnagrams(word, line)) {
      anagrams.push_back(line);
    }
  }

  file.close();
  return anagrams;
}

int main() {
  string word, filename;
  int i = 1; // Index for numbering outputs

  // Get the word from the user
  cout << "Enter a word: ";
  cin >> word;

  // Get the filename from the user
  cout << "Enter the filename containing the list of words: ";
  cin >> filename;

  // Find anagrams in the file
  vector<string> anagrams = findAnagrams(word, filename);

  // Output the results
  if (anagrams.empty()) {
    cout << "No anagrams found for the word '" << word << "' in the file."
         << endl;
  } else {
    cout << "Anagrams found for the word '" << word << "':" << endl;
    for (const string &anagram : anagrams) {
      cout << i << ". " << anagram << endl;
      i++;
    }
  }

  return 0;
}
