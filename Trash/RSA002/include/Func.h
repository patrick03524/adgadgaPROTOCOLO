#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ modulo(ZZ,ZZ);
ZZ euclides(ZZ, ZZ);
vector<ZZ> euclides_extendido(ZZ,ZZ);
ZZ inversa(ZZ,ZZ);
ZZ multiplicacion_modular(ZZ,ZZ,ZZ);
ZZ exponenciacion_modular(ZZ,ZZ,ZZ);
ZZ phi_euler(ZZ,ZZ);
/*
string leer_txt_p();
string leer_txt_q();
*/
///ZZ exponenciacion_modularMod(ZZ n, ZZ m, ZZ mod);
string zz_To_String(ZZ);
ZZ string_To_ZZ(string);
int ZZ_to_int(ZZ);

ZZ generar_Aleatorio(int);
ZZ generar_Aleatorio_Prime(int);
ZZ generar_Aleatorio_Max(ZZ);


//void generar_claves(ZZ&,ZZ&,ZZ);


#endif // FUNC_H
