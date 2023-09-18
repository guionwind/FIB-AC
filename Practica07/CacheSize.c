#include <stdio.h>

#define N 200000
#define tam 16*1024*1024

#define LINE_SIZE 32

int i, j, limite;
unsigned char v[tam];

void InitCache(int cod);
void Referencia(unsigned char *dir);
int Referencias();
int Fallos();
 
int refs, misses;

int main() 
{  int i, j;
   

  for (limite=0; limite <= 2048*1024; limite+=32*1024) {

    InitCache(0x469756c8); 

    i = 0;
    for (j=0; j<N; j++) {
      Referencia((unsigned char *)&v[i]);     // acceso a v[i] 
      i=i+LINE_SIZE;
      if (i >= limite) i=0;
    }

    refs = Referencias();
    misses = Fallos(); 

    printf("CacheSize? limite=%6d ; fallos=%6d ; referencias=%6d\n", limite/1024, misses, refs);
    if(misses == N) break;
  }

  return 0;
}

