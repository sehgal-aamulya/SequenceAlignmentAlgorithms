//
// Created by Aamulya Sehgal on 11/17/21.
//

#include "NucleotideBases.hpp"

NucleotideBases fromCharacter(char alphabet) {
  switch (alphabet) {
  case 'A': return A;
  case 'C': return C;
  case 'G': return G;
  case 'T': return T;
    // never
  default: return none;
  }
}
