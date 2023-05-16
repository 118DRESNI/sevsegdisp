#include "seg_lib.h"

const int DS =  4;  // Data Serial
const int STCP =  3;// Storage Register Clock Input
const int SHCP =  2;// Shift Register Clock Input

const int A = 5; //pin 4051:A
const int B = 6; //pin 4051:B
const int C = 7; //pin 4051:C

// tous les nombres et caracteres en afficheur 7seg
const bool one[] = {0,1,1,0,0,0,0,0};
const bool two[] = {1,1,0,1,1,0,1,0}; 
const bool tre[] = {1,1,1,1,0,0,1,0};
const bool fou[] = {0,1,1,0,0,1,1,0};
const bool fiv[] = {1,0,1,1,0,1,1,0};
const bool six[] = {1,0,1,1,1,1,1,0};
const bool sev[] = {1,1,1,0,0,0,0,0};
const bool eig[] = {1,1,1,1,1,1,1,0};
const bool nin[] = {1,1,1,1,0,1,1,0};
const bool zer[] = {1,1,1,1,1,1,0,0};
const bool def[] = {1,0,0,1,1,1,1,0};
const bool an1[] = {0,0,1,0,0,1,1,0};
const bool an2[] = {0,0,0,0,0,0,1,0};
const bool an3[] = {0,1,0,0,1,0,1,0};



void writeShiftReg(bool *num, int numseg){
  pinMode(DS, OUTPUT);
  pinMode(STCP, OUTPUT);
  pinMode(SHCP, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);

  digitalWrite(STCP, LOW);
  for(char ctr = 0x00; ctr<= numseg-0x01; ctr++){
    digitalWrite(SHCP, LOW);
    delay(10);
    digitalWrite(DS, num[ctr]);
    digitalWrite(SHCP, HIGH);
    delay(10);
  }
  digitalWrite(STCP, HIGH);
  return;
}

//cherche le caractere voulu et renvoie son adresse
bool* fetchAdNum(int fetchcode, int numseg){
  bool num[] = {0,0,0,0,0,0,0,0};
  switch(fetchcode){
    case 0:
     memcpy( num, zer, numseg );
    break;
    case 1:
     memcpy( num, one, numseg );
    break;
    case 2:
     memcpy( num, two, numseg );
    break;
    case 3:
     memcpy( num, tre, numseg );
    break;
    case 4:
     memcpy( num, fou, numseg );
    break;
    case 5:
     memcpy( num, fiv, numseg );
    break;
    case 6:
     memcpy( num, six, numseg );
    break;
    case 7:
     memcpy( num, sev, numseg );
    break;
    case 8:
     memcpy( num, eig, numseg );
    break;
    case 9:
     memcpy( num, nin, numseg );
    break;
    default:
     memcpy( num, def, numseg );
 }
return num;  
}

//selectionne un afficheur 7 segments
void selSeg(int segpos){
  switch(segpos){
    case 0:
      digitalWrite(A, 0);
      digitalWrite(B, 0);
      digitalWrite(C, 0);
    break;
    case 1:
      digitalWrite(A, 1);
      digitalWrite(B, 0);
      digitalWrite(C, 0);
    break;
    case 2:
      digitalWrite(A, 0);
      digitalWrite(B, 1);
      digitalWrite(C, 0);
    break;
    case 3:
      digitalWrite(A, 1);
      digitalWrite(B, 1);
      digitalWrite(C, 0);
    break;
    case 4:
      digitalWrite(A, 0);
      digitalWrite(B, 0);
      digitalWrite(C, 1);
    break;
    case 5:
      digitalWrite(A, 1);
      digitalWrite(B, 0);
      digitalWrite(C, 1);
    break;
    default:
      digitalWrite(A, 1);
      digitalWrite(B, 1);
      digitalWrite(C, 1);

  }
  return;
}
