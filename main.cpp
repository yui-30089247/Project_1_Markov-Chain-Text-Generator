#include "markov.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));

    string filename;
    int order;
    int numOfWords;

    cout << "------User input--------" << endl;
    cout << "Enter the filename: ";
    cin >> filename;
    cout << "Enter the order: ";
    cin >> order;
    cout << "Enter the number of words: ";
    cin >> numOfWords;
    cout << "------------------------" << endl;

    string words[100000];
    int count = readWordsFromFile(filename, words, 1000);
    cout << "Result of readWordsFromFile function: " << endl; 
    cout << "Read " << count << " words" << endl;
    for (int i = 0; i < count; i++) {
        cout << words[i] << " ";
    }

    cout << endl;
    cout << "------------------------" << endl;
    cout << "Result of buildMarkovChain function: " << endl; 
    string prefixes[10000], suffixes[10000];
    int chainSize = buildMarkovChain(words, count, order, prefixes, suffixes, 10000);
    for (int i = 0; i < 20 && i < chainSize; i++) {
        cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << endl;
    }

    cout << "------------------------" << endl;
    cout << "Result of getRandomSuffix function: " << endl; 
    for (int i = 0; i < 10; i++) {
        cout << getRandomSuffix(prefixes, suffixes, chainSize, "the") << endl;
    }

    cout << "------------------------" << endl;
    cout << "Result of getRandomPrefix function: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << getRandomPrefix(prefixes, chainSize) << std::endl;
    }

    cout << "------------------------" << endl;
    cout << "Result of generateText function: " << endl;
    string output = generateText(prefixes, suffixes, chainSize, order, numOfWords);
    cout << output << endl;

}
