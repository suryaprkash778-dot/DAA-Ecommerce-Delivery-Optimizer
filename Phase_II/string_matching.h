// string_matching.h
#ifndef STRING_MATCHING_H
#define STRING_MATCHING_H

#include <stdlib.h>
#include <string.h>

// Computes the Longest Prefix Suffix (LPS) array for KMP
static inline void computeLPSArray(const char* pattern, int M, int* lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;
    
    while (i < M) {
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
// Returns a dynamically allocated array of matching indices. 
// The number of matches is passed back via the matchCount pointer.
// NOTE: The caller is responsible for freeing the returned memory.
static inline int* searchDeliveryEvent(const char* text, const char* pattern, int* matchCount) {
    *matchCount = 0;
    
    if (pattern == NULL || text == NULL) return NULL;
    
    int M = strlen(pattern);
    int N = strlen(text);
    
    if (M == 0 || N == 0) return NULL;

    int* lps = (int*)malloc(M * sizeof(int));
    computeLPSArray(pattern, M, lps);

    // Initial allocation for holding our match results
    int capacity = 10; 
    int* matchIndices = (int*)malloc(capacity * sizeof(int));

    int i = 0; // index for text
    int j = 0; // index for pattern
    
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        
        if (j == M) {
            // Expand the array if we find more matches than our current capacity
            if (*matchCount >= capacity) {
                capacity *= 2;
                matchIndices = (int*)realloc(matchIndices, capacity * sizeof(int));
            }
            
            matchIndices[*matchCount] = i - j;
            (*matchCount)++;
            
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    free(lps);
    
    if (*matchCount == 0) {
        free(matchIndices);
        return NULL;
    }
    
    return matchIndices;
}

#endif
