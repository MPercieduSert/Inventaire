/*Auteur: PERCIE DU SERT Maxime
 *Date: 01/08/2019
 */
#ifndef NOYAUINV_H
#define NOYAUINV_H


#include "BddInv.h"
#include "ConfigInv.h"
#include "AbstractNoyau.h"

/*! \defgroup groupeFenInv Fenêtre inventaire
 * \brief Ensemble des fenêtre et du noyau de l'application inventaire.
 */

namespace inventaireMPS {
/*! \ingroup groupeFenInv
 * \brief Noyau de l'application inventaire.
 *
 * Noyau de l'application inventaire:
 *
 */
class NoyauInv : public fenMPS::AbstractNoyau {
public:
    NoyauInv()
        : AbstractNoyau() {}

    //!Ouvre le gestionnaire de configuration au chemin indiquer.
    void setConfigByPath(const QString & configPath, QWidget * modalParent = nullptr) override;
};
}
#endif // NOYAUINV_H
