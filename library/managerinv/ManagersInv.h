/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/08/2019
 */
#ifndef MANAGERSINV_H
#define MANAGERSINV_H

#include "EntityInv.h"
#include "GestionAutorisationCible.h"
#include "ManagersPredef.h"

namespace bdd {
    namespace cibleId {
        //! Numéro de cible des entités de l'inventaire non prédéfinies.
        enum EntityInv {Acquisition = NbrCibleEntPredef,
                        Collection,
                        Composition,
                        Element,
                        Etat,
                        Geographie,
                        Ingredient,
                        Origine,
                        Valeur,
                       NbrCible};
}}

/*! \ingroup groupeManagerInv
 * \brief Managers de l'application inventaire.
 */
class ManagersInv : public ManagersPredef
{
public:
    //! Constructeur.
    ManagersInv();

    //! Destructeur.
    ~ManagersInv() = default;
};

#endif // MANAGERSINV_H
