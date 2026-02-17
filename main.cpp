#include "markov.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    srand(time(0));
    string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);
    // cout << "Read " << count << " words" << endl;
    for (int i = 0; i < count; i++) {
        // cout << words[i] << endl;
    }

    string prefixes[10000], suffixes[10000];
    int chainSize = buildMarkovChain(words, count, 1, prefixes, suffixes, 10000);
    // cout << "chain size: " << chainSize << endl;
    for (int i = 0; i < 20 && i < chainSize; i++) {
        // cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << endl;
    }

    for (int i = 0; i < 10; i++) {
        // cout << getRandomSuffix(prefixes, suffixes, chainSize, "the") << endl;
    }

    for (int i = 0; i < 5; i++) {
        // cout << getRandomPrefix(prefixes, chainSize) << std::endl;
    }
    string output = generateText(prefixes, suffixes, chainSize, 1, 20);
    cout << output << endl;

}
