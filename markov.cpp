#include "markov.h"
#include <fstream>
#include <iostream>

string joinWords(const string words[], int startIndex, int count) {
    string result = "";

    for (int i = 0; i < count; i++) {
        result += words[startIndex + i];
        if (i != count - 1) {
            result += " ";
        }
    }
    return result;
}

int readWordsFromFile(string filename, string words[], int maxWords) {
    ifstream inputFile;
    inputFile.open("./" + filename);

    if (!inputFile.is_open()) {
        return -1;
    }

    int counter = 0;
    while (counter < maxWords && inputFile >> words[counter]) {
        counter++;
    }

    inputFile.close();
    return counter;
}

int buildMarkovChain(const string words[], int numWords, int order, string prefixes[], string suffixes[], int maxChainSize) {
    int count = 0;

    for (int i = 0; i <= numWords - order - 1; i++) {
        string prefix = joinWords(words, i, order);
        string suffix = words[i + order];
        prefixes[count] = prefix;
        suffixes[count] = suffix;
        count++;

        if (count == maxChainSize) {
            break;
        }
    }
    return count;
}

string getRandomSuffix(const string prefixes[], const string suffixes[], int chainSize, string currentPrefix) {
    int matchCount = 0;
    for (int i = 0; i < chainSize; i++) {
        if (prefixes[i] == currentPrefix) {
            matchCount++;
        }
    }
    if (matchCount == 0) return "";

    int currentMatch = 0;
    int pick = rand() % matchCount;
    for (int i = 0; i < chainSize; i++) {
        if (prefixes[i] == currentPrefix) {
            if (currentMatch == pick) {
                return suffixes[i];
            }
            currentMatch++;
        }
    }
    return "";
}

string getRandomPrefix(const string prefixes[], int chainSize) {
    int index = rand() % chainSize;
    return prefixes[index];
}

string generateText(const string prefixes[], const string suffixes[], int chainSize, int order, int numWords) {
    string prefix = getRandomPrefix(prefixes, chainSize);
    string result = prefix; 

    for (int i = 0; i < numWords; i++) {
        string suffix = getRandomSuffix(prefixes, suffixes, chainSize, prefix); // cat
        if (suffix == "") {
            break;
        }
        result += " " + suffix;
        prefix = suffix;
    }

    return result;
}