#include "CacheSim.h"

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

Cache_directa Cache[128];


/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
	/* Escriu aqui el teu codi */
	// buidat de la cache
	for (int i = 0; i < 128; ++i) {
		Cache[i].Contenido = 0;
		Cache[i].Validez = 0;
	}
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address, unsigned int LE)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;

	unsigned int miss;
	unsigned int lec_mp;
	unsigned int mida_lec_mp;

	unsigned int esc_mp;
	unsigned int mida_esc_mp;

	unsigned int replacement;
	unsigned int tag_out;

	/* Escriu aqui el teu codi */

	//informacio taules
	byte = address % 32;			// 5 bits de menor pes
	bloque_m = address >> 5;
	linea_mc = bloque_m % 128;		// 7 bits de linea
	tag = bloque_m >> 7;			// 20 bits de mayor peso


	//bits
	lec_mp = 0;
	esc_mp = 0;
	mida_lec_mp = 0;
	mida_esc_mp = 0;
	replacement = 0;


	unsigned int tag_cache = Cache[linea_mc].Contenido;
	unsigned char validez = Cache[linea_mc].Validez;

	// hit
	if (tag == tag_cache && validez) {
		miss = 0;

		//escriptura
		if (LE) {
			esc_mp = 1;
			mida_esc_mp = 1;
		}

	}

	// miss
	else {
		miss = 1;

		// primer acceso a la posicion: dato invalido
		if (!validez) {

			// escritura
			if (LE) {
				esc_mp = 1;
				mida_esc_mp = 1;
			}
			// lectura
			else {
				lec_mp = 1;
				mida_lec_mp = 32;
				Cache[linea_mc].Validez = 1;
				Cache[linea_mc].Contenido = tag;
			}
			
		}

		// accesos posteriores: la tag no coincide
		else {

			// escritura
			if (LE) {
				esc_mp = 1;
				mida_esc_mp = 1;
			}
			// lectura: guardado de tags
			else {
				replacement = 1;
				lec_mp = 1;
				mida_lec_mp = 32;
				tag_out = tag_cache;
				Cache[linea_mc].Contenido = tag;
			}
		}		

	}

	


	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual
	 * */
	test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
			miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
			replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  
  
}
