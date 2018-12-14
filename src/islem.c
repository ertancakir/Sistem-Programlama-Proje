#include "islem.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <jrb.h>
#include <jval.h>
#include <fields.h>

JRB tmpTree;
char *tmp;

int komut_calistir(char** args,JRB tree){
  tmp = malloc(sizeof(char) * 1024);
  memset(tmp,'\0',1024);
  if(strcmp(args[0],"add") == 0){                                   // Add Komutu
    add(tree,tmp,args);
  } else if(strcmp(args[0],"search") == 0){                        // Search Komutu
    int varmi = 0;
    jrb_traverse(tmpTree, tree){
      if(atoi(args[1]) == jval_i(tmpTree->key)){
        printf("%d,%s\n", tmpTree->key,jval_s(tmpTree->val));
        varmi = 1;
      }
    }
    if(!varmi)
      printf("Aradiğiniz kayit bulunamadi\n");

  } else if(strcmp(args[0],"pro") == 0){                          // Pro Komutu
    IS myis;
    myis = new_inputstruct(args[1]);
    if(myis == NULL){
      perror("Dosya bulunamadi");
      return 1;
    }
    while(get_line(myis) >= 0){
      char ** args;
      args = term_satir_parcala(myis->fields[0]);
      add(tree,tmp,args);
      memset(tmp,'\0',1024);
    }
    jettison_inputstruct(myis);
  } else if(strcmp(args[0],"write") == 0){                        // Write Komutu
    FILE * f;
    f = fopen(args[1],"w");
    jrb_traverse(tmpTree, tree){
      fprintf(f,"%d,%s\n", tmpTree->key,jval_s(tmpTree->val));
    }
    fclose(f);
  } else if(strcmp(args[0],"print") == 0){                        // Print Komutu
    jrb_traverse(tmpTree, tree){
      printf("%d,%s\n", tmpTree->key,jval_s(tmpTree->val));
    }
  } else if(strcmp(args[0],"quit") == 0){                         //Quit Komutu
    free(tmp);
    return 0;
  } else{
    printf("Komut geçerli değil\n");
  }
  free(tmp);
  return 1;
}

void append(char* tmp){
  int len = strlen(tmp);
  tmp[len] = ',';
}

void add(JRB t, char* tmp, char** args){
  for(int i=2;i<5;i++){
    if(i != 2) append(tmp);
    strcat(tmp,args[i]);
  }
  (void) jrb_insert_int(t,atoi(args[1]),new_jval_s(strdup(tmp)));
}
