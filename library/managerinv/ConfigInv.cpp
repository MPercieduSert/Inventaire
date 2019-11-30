#include "ConfigInv.h"

using namespace inventaireMPS;
using namespace fichierMPS;

bool ConfigInv::creer() {
    XmlDoc doc;
    auto iter = doc.begin();
    XmlElement elt;
    elt.setName("conf");
    iter = doc.push_back(iter,elt);
    elt.setName("directories");
    iter = doc.push_back(iter, elt);
    elt.setName("default");
    elt.setText(QDir::homePath()+"/inventaire/");
    iter = doc.push_back(iter, elt);
    iter.toParent(2);
    elt.setName("files");
    elt.setText("");
    iter = doc.push_back(iter, elt);
    elt.setName("databases");
    doc.push_back(iter, elt);

    writeConf(doc);
    return true;
}

//! Renvoie le chemin du dossier par default.
QString ConfigInv::defaultDirectory()
    {return getVars(DEFAULT_DIRECTORY);}
