class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int word_index = 1;
        bool start = true;
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] == ' ') {
                if (i != 0) {
                    word_index++;
                    start = true;
                }
                continue;
            } else {
                if (start) {
                    if (sentence[i] == searchWord[0]) {
                        int j;
                        bool found = true;
                        for (j = 0; j < searchWord.length(); j++) {
                            if (sentence[i+j] != searchWord[j]) {
                                found = false;
                                break;
                            }
                            cout << "word is: " << word_index << endl;
                            cout << "from: " << sentence[i+j] << " to: " << searchWord[j] << endl;
                        }
                        if (found)
                            return word_index;
                        else {
                            start = false;
                        }
                    } else {
                        start = false;
                    }
                }
            }
        }

        return -1;
    }
};