#ifndef SEG_LIB_H
#define SEG_LIB_H

#include <Arduino.h>

//ecrit un caractere au shiftreg
void writeShiftReg(bool *numb, int numseg );

//cherche le caractere voulu et renvoie son adresse
bool* fetchAdNum(int fetchcode, int numseg);

//selectionne un afficheur 7 segments
void selSeg(int segpos);

#endif
