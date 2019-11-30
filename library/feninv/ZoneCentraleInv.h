/*Auteur: PERCIE DU SERT Maxime
 *Date: 01/08/2019
 */
#ifndef ZONECENTRALEINV_H
#define ZONECENTRALEINV_H

#include "TabInv.h"
#include "AbstractTabZoneCentrale.h"

namespace inventaireMPS {
/*! \ingroup groupeFenInv
 * \brief Zone centrale de l'application inventaire.
 */
class ZoneCentraleInv : public fmps::AbstractTabZoneCentrale
{
public:
    //! Constructeur.
    explicit ZoneCentraleInv(TabInv * tab = new TabInv, QWidget * parent = nullptr);
};
}
#endif // ZONECENTRALEINV_H
