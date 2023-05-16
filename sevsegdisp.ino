#include "seg_lib.h"
//6 afficheurs a 7 segments:
//5: 10^5 || 4: 10^4, etc...downto 0: 10^0

const int numseg = 8; // nombre de segments + point décimal sur 1 afficheur
bool       numb[] = {0,0,0,0,0,0,0,0};

int randnumb;
int randseg;

void setup() {
}

void loop() {
  randseg = random(0,5);
  randnumb = random(0,9);
  bool *adnum = fetchAdNum(randnumb, numseg);
  for (int ctr = 0 ; ctr < numseg ; ctr++)
  {
      numb[ctr] = adnum[ctr];
  }
  writeShiftReg(numb, numseg);
  selSeg(randseg);
  delay(500);

}
