#include <stdio.h>

#define N 200000
#define tam 16*1024*1024

int i, j, step;
unsigned char v[tam];

void InitCache(int cod);
void Referencia(unsigned char *dir);
int Referencias();
int Fallos();


int main() 
{  int i, j, step;
   int refs, misses;


  for (step=4; step<=32; step+=4) {
	
    InitCache(0x469756c8); 

    i = 0;

    for (j=0; j<N; j++) {
      Referencia((unsigned char *)&v[i]);     // acceso a v[i] 
      i = i + step;
      if (i >= tam) i = 0;
    }

    refs = Referencias();
    misses = Fallos(); 
    printf("LineSize? step=%3d ; fallos=%6d ; referencias=%6d\n", step, misses, refs);

  }

  return 0;
}

