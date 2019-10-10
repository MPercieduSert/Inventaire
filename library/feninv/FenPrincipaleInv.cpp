#include "FenPrincipaleInv.h"

FenPrincipaleInv::FenPrincipaleInv(NoyauInv * noyau, BddInv *bdd, ZoneCentraleInv * centralZone,
                                   const QString &bddPathXML, const QString & configPath, QWidget *parent)
    : FenPrincipale (noyau,bdd,centralZone,bddPathXML,configPath,parent)
{

}
