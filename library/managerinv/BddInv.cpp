#include "BddInv.h"

void BddInv::listeMiseAJourBdd(int version)
{
    BddPredef::listeMiseAJourBdd(version);
    switch (version) {
    case bdd::bddVersion::initialePredef:
        creerTable<Acquisition>();
        creerTable<Collection>();
        creerTable<Etat>();
        creerTable<Geographie>();
        creerTable<Ingredient>();
        creerTable<Composition>();
        creerTable<Origine>();
        creerTable<Element>();
        creerTable<Valeur>();
        m_manager->saveVersion(bdd::bddVersion::initialeInv);
    }
}
