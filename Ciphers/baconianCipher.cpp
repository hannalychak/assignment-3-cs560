#include "BaconianCipher.h"
#include <cctype>

const std::string BACON_MAP[26] = {
    "AAAAA", "AAAAB", "AAABA", "AAABB", "AABAA", "AABAB", "AABBA", "AABBB", // A-H
    "ABAAA", "ABAAB", "ABABA", "ABABB", "ABBAA", "ABBAB", "ABBBA", "ABBBB", // I-P
    "BAAAA", "BAAAB", "BAABA", "BAABB", "BABAA", "BABAB", "BABBA", "BABBB", // Q-X
    "BBAAA", "BBAAB"                                                        // Y-Z
};
BaconianCipher::BaconianCipher() {
}

std::string BaconianCipher::encrypt(const std::string& text) {
    std::string result = "";

    for (char symbol : text) {
        if (std::isalpha(symbol)) {
            int index = std::tolower(symbol) - 'a';
            result += BACON_MAP[index];
        } else {
            result += symbol;
        }
    }
    return result;
}

std::string BaconianCipher::decrypt(const std::string& text) {
    std::string result = "";
    for (size_t i = 0; i < text.length(); ) {
        if (text[i] == 'A' || text[i] == 'B') {
            std::string chunk = text.substr(i, 5);
            char decodedSymbol = '?';
            for (int j = 0; j < 26; j++) {
                if (BACON_MAP[j] == chunk) {
                    decodedSymbol = 'a' + j;
                    break;
                }
            }
            result += decodedSymbol;
            i += 5;
        } else {
            result += text[i];
            i++;
        }
    }
    return result;
}
