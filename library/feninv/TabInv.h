/*Auteur: PERCIE DU SERT Maxime
 *Date: 01/08/2019
 */
#ifndef TABINV_H
#define TABINV_H

#include "AbstractTab.h"

/*! \ingroup groupeFenInv
 * \brief Fenêtre à onglet de l'application inventaire.
 */
class TabInv : public AbstractTab
{
public:
    TabInv() = default;

    //! Connect l'onglet aux signaux commun à tous les onglets.
    void connectTab(AbstractTabModule * tab) const override
        {}

    //! Créateur d'onglet.
    AbstractTabModule *createTab(QPair<int,int> pair) const override
        {return nullptr;}
};

#endif // TABINV_H
