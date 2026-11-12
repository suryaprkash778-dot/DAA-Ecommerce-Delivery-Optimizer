// string_matching.h
#ifndef STRING_MATCHING_H
#define STRING_MATCHING_H

#include <vector>
#include <string>
#include <iostream>

// Computes the Longest Prefix Suffix (LPS) array for KMP
inline void computeLPSArray(const std::string& pattern, std::vector<int>& lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;
    
    while (i < pattern.length()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Knuth-Morris-Pratt (KMP) Algorithm for Delivery Event Log Searching
inline std::vector<int> searchDeliveryEvent(const std::string& text, const std::string& pattern) {
    std::vector<int> matchIndices;
    if (pattern.empty() || text.empty()) return matchIndices;

    std::vector<int> lps(pattern.length());
    computeLPSArray(pattern, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern
    
    while (i < text.length()) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        
        if (j == pattern.length()) {
            matchIndices.push_back(i - j);
            j = lps[j - 1];
        } else if (i < text.length() && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return matchIndices;
}

#endif
