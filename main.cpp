#include "markov.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string testWords[] = {"the", "cat", "sat", "down"};
    // cout << joinWords(testWords, 0, 2) << endl;  // Should print: the cat
    // cout << joinWords(testWords, 1, 3) << endl;  // Should print: cat sat down

    string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);
    // cout << "Read " << count << " words" << endl;
    for (int i = 0; i < count; i++) {
        // cout << words[i] << endl;
    }

    string prefixes[10000], suffixes[10000];
    int chainSize = buildMarkovChain(words, count, 2, prefixes, suffixes, 10000);
    for (int i = 0; i < 20 && i < chainSize; i++) {
        // cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << std::endl;
    }

    for (int i = 0; i < 10; i++) {
        // cout << getRandomSuffix(prefixes, suffixes, chainSize, "the") << std::endl;
    }

    for (int i = 0; i < 5; i++) {
        cout << getRandomPrefix(prefixes, chainSize) << endl;
    }
}
