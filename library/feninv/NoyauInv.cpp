#include "NoyauInv.h"

//!Ouvre le gestionnaire de configuration au chemin indiquer.
void NoyauInv::setConfigByPath(const QString &configPath, QWidget *modalParent)
    {setConfig(new ConfigInv(configPath), modalParent);}
