#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#define bit_set(var,bit_nom) var=var|(1<<bit_nom)
#define bit_clear(var,bit_nom) var=var&(~(1<<bit_nom))
#define bit_togel(var,bit_nom) var=var^(1<<bit_nom)
#define bit_get(var,bit_nom) bit_nom=(var>>bit_nom)&1
#endif
