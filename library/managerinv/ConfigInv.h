/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/08/2019
 */
#ifndef CONFIGINV_H
#define CONFIGINV_H

#include "Config.h"

/*! \ingroup groupeManagerInv
 * \brief Chemin XML du dossier de l'application par default.
 */
#define DEFAULT_DIRECTORY "conf/directories/default"

/*! \ingroup groupeNoyau
 * \brief Chemin XML de la base de donnée.
 */
#define DATA_BASE "conf/files/databases/database"

namespace inventaireMPS {
/*! \ingroup groupeManagerInv
 * \brief Gestionnaire du fichier de configuration.
 *
 * Gestionnaire du fichier de configuration enregistré sous la forme d'un document XML. Tous les noeuds ont des chemins uniques.
 */
class ConfigInv : public fichierMPS::Config {
public:
    using Config::Config;

    //! Créer un fichier de configuration avec les entrées par défault.
    bool creer() override;

    //! Renvoie le chemin du dossier par default.
    QString defaultDirectory() override;
};
}
#endif // CONFIGINV_H
