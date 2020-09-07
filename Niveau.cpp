#include "Niveau.h"

Niveau::Niveau(int numeroNiveau)
    : m_numeroNiveau{numeroNiveau}
{
    switch(numeroNiveau)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

void Niveau::ajouter_cases(Cases *cases)
{
   m_mes_cases.push_back(cases);
}

void Niveau::afficher()
{
//    for(auto a : m_mes_cases)
//        a->afficher();
}
