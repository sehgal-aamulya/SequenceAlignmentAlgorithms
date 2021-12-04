//
// Created by Aamulya Sehgal on 11/16/21.
//

#ifndef CSCI570FINALPROJECT_NUCLEOTIDEBASES_H
#define CSCI570FINALPROJECT_NUCLEOTIDEBASES_H

enum NucleotideBases {
	A, C, G, T,
	// never
	none
};

NucleotideBases fromCharacter(char alphabet);

#endif //CSCI570FINALPROJECT_NUCLEOTIDEBASES_H
