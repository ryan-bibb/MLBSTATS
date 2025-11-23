#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
	char firstName[50];
	char lastName[50];
	int playerID;
	int year;
	int hits;
	int singles;
	int doubles;
	int triples;
	int homeRuns;
	double avg;
	double slg;
	double obp;
	double ops;
	int stolenBases;
};

#endif
