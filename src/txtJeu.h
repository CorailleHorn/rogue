#ifndef _TXTJEU_H_
#define _TXTJEU_H_

#include "Personnages.h"

void txtAff(const Hero &me, const Ennemi &you);
void txtInit();
void txtBoucle(Hero &me, Ennemi &you);
void txtDetruit();

#endif
