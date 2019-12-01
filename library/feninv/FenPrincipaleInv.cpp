#include "FenPrincipaleInv.h"

using namespace inventaireMPS;

FenPrincipaleInv::FenPrincipaleInv(NoyauInv * noyau, std::unique_ptr<BddInv> bdd, ZoneCentraleInv * centralZone,
                                   const QString &bddPathXML, const QString & configPath, QWidget *parent)
    : FenPrincipale (noyau,std::move(bdd),centralZone,bddPathXML,configPath,parent)
{

}
