#include <stdio.h>

int main() {
    char letra;
    letra = getchar();
    if (letra > 96) letra -= 32;
    char cursor = 'A';
    do {
      for (int i = cursor; i <= letra-1; i++) printf(".");
      for (int i = 'A'; i <= cursor; i++) printf("%c", i);
      for (int i = cursor; i > 'A'; i--) printf("%c", i-1);
      for (int i = cursor; i <= letra-1; i++) printf(".");
      printf("\n");
      cursor++;
    } while (letra >= cursor);
    return 0;
}