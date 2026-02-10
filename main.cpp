#include "markov.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // string testWords[] = {"the", "cat", "sat", "down"};
    // cout << joinWords(testWords, 0, 2) << endl;  // Should print: the cat
    // cout << joinWords(testWords, 1, 3) << endl;  // Should print: cat sat down

    string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);
    cout << "Read " << count << " words" << endl;
    for (int i = 0; i < count; i++) {
        cout << words[i] << endl;
    }
}
