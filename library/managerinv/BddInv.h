/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/08/2019
 */
#ifndef BDDINV_H
#define BDDINV_H

#include "ManagersInv.h"
#include "BddPredef.h"

namespace bddMPS {
    namespace bddVersion  {
        enum versionBddInv{initialeInv = NbrCreationBddPredef,
                           NbrVersionBddInv};
}}

namespace inventaireMPS {
/*! \ingroup groupeManagerInv
 * \brief Base de donnée de l'application inventaire.
 */
class BddInv : public bmps::BddPredef {
public:
    //! Constructeurs hérités.
    using BddPredef::BddPredef;

    //Constructeur.
    BddInv()
        :BddPredef("QSQLITE",bmps::bddVersion::NbrVersionBddInv - 1, std::make_unique<ManagersInv>()) {}

    //! Destructeur. Referme la base de donnée.
    ~BddInv() override = default;

protected:
    //! Mise à jour de la base de donnée.
    void listeMiseAJourBdd(int version) override;
};
}
#endif // BDDINV_H
