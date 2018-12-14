#include "komut.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *term_satir_oku(void){
  int boyut = BOYUT;
  int konum = 0;
  char *karakterDizi = malloc(sizeof(char) * boyut);
  int c;

  if (!karakterDizi) {
    fprintf(stderr, "bellek ayirma hatasi\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    c = getchar();

    if (c == EOF) {
      exit(EXIT_SUCCESS);
    } else if (c == '\n') {
      karakterDizi[konum] = '\0';
      return karakterDizi;
    } else {
      karakterDizi[konum] = c;
    }
    konum++;

    if (konum >= boyut) {
      boyut += BOYUT;
      karakterDizi = realloc(karakterDizi, boyut);
      if (!karakterDizi) {
        fprintf(stderr, "bellek ayirma hatasi\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}

char **term_satir_parcala(char *satir){
  char **tokens = malloc(1024 * sizeof(char*));
  char *token;
  token = strtok(satir," >|");
  int i=-1;
  while(token!=NULL){
    tokens[++i] = token;
    token = strtok(NULL," >|");
  }
  return tokens;
}
