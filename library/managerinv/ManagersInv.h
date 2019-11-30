/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/08/2019
 */
#ifndef MANAGERSINV_H
#define MANAGERSINV_H

#include "EntityInv.h"
#include "GestionAutorisationCible.h"
#include "ManagersPredef.h"

namespace bddMPS {
    namespace cibleIdInv {
        //! Numéro de cible des entités de l'inventaire non prédéfinies.
        enum EntityInv {Acquisition = cibleId::NbrCibleEntPredef,
                        Collection,
                        Composition,
                        Element,
                        Etat,
                        Geographie,
                        Historique,
                        Ingredient,
                        Origine,
                        Usage,
                        Valeur,
                       NbrCible};
}}

namespace inventaireMPS {
namespace bmps = bddMPS;
/*! \ingroup groupeManagerInv
 * \brief Managers de l'application inventaire.
 */
class ManagersInv : public managerMPS::ManagersPredef {
public:
    //! Constructeur.
    ManagersInv();

    //! Destructeur.
    ~ManagersInv() = default;
};
}
#endif // MANAGERSINV_H
