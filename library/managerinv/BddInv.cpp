#include "BddInv.h"

using namespace inventaireMPS;

void BddInv::listeMiseAJourBdd(int version) {
    BddPredef::listeMiseAJourBdd(version);
    switch (version) {
    case bmps::bddVersion::initialePredef:
        creerTable<Acquisition>();
        creerTable<Collection>();
        creerTable<Ingredient>();
        creerTable<Composition>();
        creerTable<Etat>();
        creerTable<Element>();
        creerTable<Geographie>();
        creerTable<Usage>();
        creerTable<Historique>();
        creerTable<Origine>();
        creerTable<Valeur>();

        m_manager->saveVersion(bmps::bddVersion::initialeInv);
    }
}
