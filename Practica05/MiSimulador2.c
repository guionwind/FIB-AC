#include "CacheSim.h"
#include "string.h"
#include <stdio.h>
/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

typedef struct {
	//debemos guardar el contenido de la cache
	//en cada fila, la columna 0 sera el tag y la columna 1 sera el bloque_m
	// la cache tiene 2^7 lineas
	unsigned int Contenido;
	unsigned char Validez;
} Cache_directa;

Cache_directa Cache[64];
int notlru[64];

int hit_count = 0;
int miss_count = 0;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al començar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */

    for (int i = 0; i < 128; ++i) {
        Cache[i].Contenido = 0;
        Cache[i].Validez = 0;
	}

}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int conj_mc;
	unsigned int via_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reemplaça una linia valida
	unsigned int tag_out;	   // TAG de la linia reemplaçada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */

    byte = address % 32;			// 5 bits
	bloque_m = address >> 5;
	conj_mc = bloque_m % 64;		// 6 bits de linea; 2 conjuntos
	tag = bloque_m >> 6;			// 21 bits de mayor peso

    
    // hit
    miss = 1;
    while (int i < 2 && miss != 0) {
        unsigned int tag_via0 = Cache[conj_mc][i].Contenido;
        unsigned char validez0 = Cache[conj_mc][i].Validez;
        
        //hit
        if (tag == tag_cache && validez == 1) {
            miss = 0;
            replacement = 0;
            hit_count += 1;
            notlru[conj_mc] = Cache[conj_mc][i].Contenido;
        }

        // miss
        else {
            miss = 1;
            miss_count += 1;
            // dato no valido
            if (validez == 0) {
                replacement = 0;
            }
            // reemplazo de una tag
            else {
                replacement = 1;
                tag_out = tag_cache;

            }
            // escritura de la tag
            Cache[linea_mc].Contenido = tag;
            Cache[linea_mc].Validez = 1;
        }
    }











	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. També mesurem el temps d'execució
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print2 (address, byte, bloque_m, conj_mc, via_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
    char buff[256];
	sprintf(buff,"El numero de hits son:%d\n",hit_count);
	write(1,buff,strlen(buff));

	sprintf(buff,"El numero de misses son:%d\n",miss_count);
	write(1,buff,strlen(buff));
  
}
