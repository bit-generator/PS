#include <stdio.h>
#include <string.h>

char str[501];

int main() {
    while(1) {
        fgets(str, sizeof(str), stdin);
        str[strlen(str) - 1] = '\0';
        if(!strcmp(str, "END")) break;
        
        for(int i = strlen(str) - 1; i >= 0; --i) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    
    return 0;
}