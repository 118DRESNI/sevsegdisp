#include "seg_lib.h"
//6 afficheurs a 7 segments:
//5: 10^5 || 4: 10^4, etc...downto 0: 10^0

const int numseg = 8; // nombre de segments + point décimal sur 1 afficheur
bool       num[] = {0,0,0,0,0,0,0,0};

void setup() {
  
}

void loop() {
  selSeg(3);
  bool *adnum = fetchAdNum(5, numseg);
  for (int ctr = 0 ; ctr < numseg ; ctr++)
  {
      num[i] = adnum[i];
  }
  writeShiftReg(num, numseg);
  delay(500);

  free(adnum);
}




