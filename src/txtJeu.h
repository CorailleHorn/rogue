#ifndef _TXTJEU_H_
#define _TXTJEU_H_

#include "Personnages.h"
#include "Map.h"

void txtAff(const Map &m);
void txtInit();
void txtBoucle(Hero &h);
void txtDetruit();

#endif
