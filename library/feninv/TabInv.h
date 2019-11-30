/*Auteur: PERCIE DU SERT Maxime
 *Date: 01/08/2019
 */
#ifndef TABINV_H
#define TABINV_H

#include "AbstractTab.h"

namespace inventaireMPS {
namespace fmps = fenMPS;
/*! \ingroup groupeFenInv
 * \brief Fenêtre à onglet de l'application inventaire.
 */
class TabInv : public fmps::AbstractTab {
public:
    TabInv() = default;

    //! Connect l'onglet aux signaux commun à tous les onglets.
    void connectTab(fmps::AbstractTabModule * tab) const override
        {}

    //! Créateur d'onglet.
    fmps::AbstractTabModule *createTab(std::pair<int,int> pair) const override
        {return nullptr;}
};
}
#endif // TABINV_H
