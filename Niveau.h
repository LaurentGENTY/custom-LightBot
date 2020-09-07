#ifndef NIVEAU_H
#define NIVEAU_H
#include<vector>
#include<Cases.h>
class Niveau
{
private:
    std::vector<Cases *> m_mes_cases;
    int m_numeroNiveau;
public:
    Niveau(int numeroNiveau);

    void ajouter_cases(Cases *cases);
    void afficher();
};

#endif // NIVEAU_H
