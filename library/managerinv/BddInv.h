/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/08/2018
 */
#ifndef BDDINV_H
#define BDDINV_H

#include "ManagersInv.h"
#include "BddPredef.h"

namespace bdd {
    namespace bddVersion  {
        enum versionBddInv{initialeInv = NbrCreationBddPredef,
                           NbrVersionBddInv};
}}


/*! \ingroup groupeManagerInv
 * \brief Base de donnée de l'application inventaire.
 */
class BddInv : public BddPredef
{
public:
    //! Constructeurs hérités.
    using BddPredef::BddPredef;

    //Constructeur.
    BddInv()
        :BddPredef("QSQLITE",bdd::bddVersion::NbrVersionBddInv - 1, new ManagersInv)
    {}

    //! Destructeur. Referme la base de donnée.
    ~BddInv() override = default;

protected:
    //! Mise à jour de la base de donnée.
    void listeMiseAJourBdd(int version) override;
};

#endif // BDDINV_H
