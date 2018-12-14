#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jrb.h>

int main(){
  char * satir;
  char ** args;
  int durum;
  JRB tree;
  tree = make_jrb();

  do{
    printf("> ");
    satir = term_satir_oku();
    args = term_satir_parcala(satir);
    durum = komut_calistir(args,tree);
  }while(durum);
  free(satir);
  free(args);
  jrb_free_tree(tree);
  return 0;
}
