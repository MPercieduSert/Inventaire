#include <QApplication>

#include "FenPrincipaleInv.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    inventaireMPS::FenPrincipaleInv fen;
    fen.show();
    return a.exec();
}
