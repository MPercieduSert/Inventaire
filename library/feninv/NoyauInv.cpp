#include "NoyauInv.h"

using namespace inventaireMPS;

//!Ouvre le gestionnaire de configuration au chemin indiquer.
void NoyauInv::setConfigByPath(const QString &configPath, QWidget *modalParent)
    {setConfig(std::make_unique<ConfigInv>(configPath), modalParent);}
