//
// Created by Aamulya Sehgal on 11/16/21.
//

#ifndef CSCI570FINALPROJECT_NUCLEOTIDEBASES_HPP
#define CSCI570FINALPROJECT_NUCLEOTIDEBASES_HPP

enum NucleotideBases {
	A, C, G, T,
	// never
	none
};

NucleotideBases fromCharacter(char alphabet);

#endif //CSCI570FINALPROJECT_NUCLEOTIDEBASES_HPP
