#include <stdio.h>

#include <stdlib.h>

#include <string.h>


int word_count(char * str, char * word) {
    int cnt = 0, str_len = strlen(str), word_len = strlen(word), same;
    for (int i = -1; i < str_len + 1 - word_len; i++) {
        if ((str[i] == '\0' || str[i] == ' ') && (str[i + 1] == word[0] && (str[i + 1 + word_len] == ' ' || str[i + 1 + word_len] == '\0'))) {
            same = 1;
            for (int j = 0; j < word_len; j++) {
                if (str[i + 1 + j] != word[j]) {
                    same = 0;
                    break;
                }
            }
            if (same) cnt++;
        }
    }

    return cnt;
}



int main(void) {

    char * str = "S al omy :)   :)   hona anu yyy... !";
    char * wrd = ":)";
    //printf("%d", str[-1] == '\0');

    printf("%d\n", word_count(str, wrd));
}
