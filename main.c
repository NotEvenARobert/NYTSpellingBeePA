/* COP 3502C PA2
This program is written by: ANH NHAT LE (Robert) */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define NUMLETTERS 7
#define MAXWORDSIZE 10

void swapChars(char *a, char *b) {
    
    char temp = *a;
    *a = *b;
    *b = temp;
    
}

void sortLetters(char arr[], int n) {
    
    for(int a = 0; a < n - 1; a++) {
        
        int min_idx = a;
        for(int b = a + 1; b < n; b++) {
            
            if(arr[b] < arr[min_idx]) {
                
                min_idx = b;
                
            }
            
        }
        
        swapChars(&arr[a], &arr[min_idx]);
        
    }
    
}

int checkMiddle(const char *word, char middle) {

    for(int g = 0; word[g] != '\0'; g++) {

        if(word[g] == middle) {

        return 1;
     
        }

    }

    return 0;

}

int binarySearch(char** dictionary, char* word, int low, int high) {
    
    if(low > high) {
        
        return 0;
        
    }

    int mid = (low + high) / 2;
    int comparison = strcmp(word, dictionary[mid]);
    if(comparison == 0) {
        
        return 1;
        
    } else if(comparison < 0) {

        return binarySearch(dictionary, word, low, mid - 1);
        
    } else {

        return binarySearch(dictionary, word, mid + 1, high);
        
    }
    
}

void findWords(char letters[], int perm[], int used[], int k, char middle, int n, char** dictionary) {
    
    if(k >= 4) {

        char currentWord[NUMLETTERS + 1];
        for(int e = 0; e < k; e++) {
            
            currentWord[e] = letters[perm[e]];
            
        }
        currentWord[k] = '\0';

        if(checkMiddle(currentWord, middle)) {
            
            if(binarySearch(dictionary, currentWord, 0, n - 1)) {
                
                printf("%s\n", currentWord);
                
            }
            
        }
        
    }

    if(k == NUMLETTERS) {
        
        return;
        
    }

    for(int f = 0; f < NUMLETTERS; f++) {

        if(!used[f]) {

            perm[k] = f;
            used[f] = 1;
            findWords(letters, perm, used, k + 1, middle, n, dictionary);
            used[f] = 0;
            
        }
        
    }
    
}

int main(void) {
    
    char letters[NUMLETTERS + 1];
    int n;
    char middle;
    
    scanf("%s", letters);
    scanf("%d", &n);
    middle = letters[3];

    sortLetters(letters, NUMLETTERS);
    int new_idx = -1;
    for(int c = 0; c < NUMLETTERS; c++) {
        
        if(letters[c] == middle) {
            
            new_idx = c;
            break;
            
        }

    }

    char **dictionary = (char**)malloc(n * sizeof(char*));
    char tempWord[MAXWORDSIZE];
    for(int d = 0; d < n; d++) {
        
        scanf("%s", tempWord);
        dictionary[d] = (char*)malloc((strlen(tempWord) + 1) * sizeof(char));
        strcpy(dictionary[d], tempWord);
        
    }

    int perm[NUMLETTERS];
    int used[NUMLETTERS] = {0};
    findWords(letters, perm, used, 0, middle, n, dictionary);

    for(int h = 0; h < n; h++) {
        
        free(dictionary[h]);
        
    }
    free(dictionary);
    return 0;
    
}
