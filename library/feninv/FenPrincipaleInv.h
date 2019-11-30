/*Auteur: PERCIE DU SERT Maxime
 *Date: 01/08/2019
 */
#ifndef FENPRINCIPALEINV_H
#define FENPRINCIPALEINV_H

#include "NoyauInv.h"
#include "ZoneCentraleInv.h"
#include "FenPrincipale.h"

namespace inventaireMPS {
/*! \ingroup groupeFenInv
 * \brief Fenêtre principale de l'application inventaire.
 *
 * Fenêtre principale de l'application inventaire:
 *  + Crée les différents menus.
 *
 */
class FenPrincipaleInv : public fmps::FenPrincipale {
public:
    //! Constructeur.
    FenPrincipaleInv(NoyauInv * noyau = new NoyauInv, BddInv * bdd = new BddInv, ZoneCentraleInv * centralZone = new ZoneCentraleInv,
                     const QString &bddPathXML = DATA_BASE, const QString & configPath = QDir::currentPath().append("/Config.xml"),
                     QWidget *parent = nullptr);
};
}
#endif // FENPRINCIPALEINV_H
