/* COP 3502C PA2
This program is written by: ANH NHAT LE (Robert) */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define NUMLETTERS 7

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
        
    return 0;
    
}
