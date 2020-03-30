#ifndef _TXTJEU_H_
#define _TXTJEU_H_

#include "Personnages.h"
#include "Map.h"

void txtAff(const Map &m);
void txtInit(Map *m, Hero *h);
void txtBoucle(Hero *h);
void txtDetruit(Map *m, Hero *h);

#endif
