#include "ConfigInv.h"

bool ConfigInv::creer()
{
    XmlDoc doc;
    XmlElement elt;
    elt.setName("conf");
    doc.addChild(elt);
    elt.setName("directories");
    doc.addChild(elt);
    elt.setName("default");
    elt.setText(QDir::homePath()+"/inventaire/");
    doc.addChild(elt);
    doc.toParent();
    doc.toParent();
    elt.setName("files");
    elt.setText("");
    doc.addChild(elt);
    elt.setName("databases");
    doc.addChild(elt);

    writeConf(doc);
    return true;
}

//! Renvoie le chemin du dossier par default.
QString ConfigInv::defaultDirectory()
    {return getVars(DEFAULT_DIRECTORY);}
