#ifndef FILTRE_H
#define FILTRE_H

void dcTrend(double &table, float out[]);
void rect(double &table, float out[]);
void lise(double &table, float out[]);
void filtre(double &input[]);

#endif