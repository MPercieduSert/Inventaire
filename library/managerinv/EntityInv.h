/*Auteur: PERCIE DU SERT Maxime
 *Date: 01/08/2019
 */
#ifndef ENTITYINV_H
#define ENTITYINV_H

#include "EntityPredef.h"

/*! \defgroup groupeManagerInv Entités et base de données inventaire
 * \brief Ensemble des entités, managers et base de données de l'application inventaire.
 */

namespace infoEntityInv {

    //! Liste des identifiants des entités
    enum entityId{AcquisitionId = infoEntity::NbrEntityPredefinie,
                  CollectionId,
                  CompositionId,
                  ElementId,
                  EtatId,
                  GeographieId,
                  HistoriqueId,
                  IngredientId,
                  OrigineId,
                  UsageId,
                  ValeurId,
                  NbrEntityId};
}

/*! \ingroup groupeManagerInv
 * \brief Espace de noms de l'application inventaire.
 */
namespace inventaireMPS {
using namespace typeMPS;
namespace emps = entityMPS;

// Entités prédéfinies
using namespace emps::ensembleCommentaire;
using namespace emps::ensembleDonnee;
using namespace emps::ensembleMotCle;
using namespace emps::ensembleRestriction;
using namespace emps::ensembleType;

// Entités de type prédéfinies
ID1_ENTITY(Etat,IdNullNcNomType,infoEntityInv::EtatId,Prog)
RELATION_ENTITY(Composition,RelationNumTypeValeurDouble,infoEntityInv::CompositionId,Collection,Ingredient)
RELATION_ENTITY(Origine,RelationType,infoEntityInv::OrigineId,Collection,Geo)
using Acquisition = entityBaseMPS::DateTimeValideNcNomTypeEntity<infoEntityInv::AcquisitionId>;
using Collection = entityBaseMPS::NcNomTypeEntity<infoEntityInv::CollectionId>;
using Geographie = entityBaseMPS::NcNomTypeEntity<infoEntityInv::GeographieId>;
using Ingredient = entityBaseMPS::NcNomTypeEntity<infoEntityInv::IngredientId>;
using Usage = entityBaseMPS::NcNomTypeEntity<infoEntityInv::UsageId>;
using Valeur = entityBaseMPS::CibleSimpleDateTimeValideNumTypeValeurIntEntity<infoEntityInv::ValeurId>;

/*! \ingroup groupeManagerInv
 * \brief Représentation de l'entité Element.
 */
class Element : public emps::EntityIDs<infoEntityInv::ElementId,attributMPS::Id1Attribut,
                                                             attributMPS::Id2Attribut,
                                                             attributMPS::Id3Attribut,
                                                             attributMPS::NumAttribut> {
protected:
    template<class T> using PositionEnum = emps::PositionEnum<T,Element>;
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut>::Position,
                   Id1 = PositionEnum<Id1Attribut>::Position,
                   Id2 = PositionEnum<Id2Attribut>::Position,
                   Id3 = PositionEnum<Id3Attribut>::Position,
                   Num = PositionEnum<NumAttribut>::Position,
                   NbrAtt,
                   IdAcquisition = Id1,
                   IdCollection = Id2,
                   IdEtat = Id3,
                   };

    using EAID = emps::EntityIDs<infoEntityInv::ElementId,attributMPS::Id1Attribut,
                                                       attributMPS::Id2Attribut,
                                                       attributMPS::Id3Attribut,
                                                       attributMPS::NumAttribut>;
    using EAID::EntityID;
    BASE_ENTITY(Element)
    ALIAS_CLE(Collection,1)
    ALIAS_CLE(Acquisition,2)
    ALIAS_CLE(Etat,3)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    Element(idt idCol, int num, idt id = 0)
        : EAID(id) {
        setIdCollection(idCol);
        setNum(num);
    }

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    Element(idt idAcq, idt idCol, idt idEtat, int num, idt id = 0)
        : Element(idCol,num,id) {
        setIdAcquisition(idAcq);
        setIdEtat(idEtat);
    }
};

/*! \ingroup groupeManagerInv
 * \brief Représentation de l'entité Historique.
 */
class Historique : public emps::EntityIDs<infoEntityInv::HistoriqueId,attributMPS::Id1Attribut,
                                                             attributMPS::Id2Attribut,
                                                             attributMPS::Id3Attribut,
                                                             attributMPS::DateTimeValideAttribut,
                                                             attributMPS::NumAttribut> {
protected:
    template<class T> using PositionEnum = emps::PositionEnum<T,Historique>;
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut>::Position,
                   Id1 = PositionEnum<Id1Attribut>::Position,
                   Id2 = PositionEnum<Id2Attribut>::Position,
                   Id3 = PositionEnum<Id3Attribut>::Position,
                   DateTime = PositionEnum<DateTimeValideAttribut>::Position,
                   Num = PositionEnum<NumAttribut>::Position,
                   NbrAtt,
                   IdElement = Id1,
                   IdEtat = Id2,
                   IdUsage = Id3,
                   };

    using EAID = emps::EntityIDs<infoEntityInv::HistoriqueId,attributMPS::Id1Attribut,
                                                             attributMPS::Id2Attribut,
                                                             attributMPS::Id3Attribut,
                                                             attributMPS::DateTimeValideAttribut,
                                                             attributMPS::NumAttribut>;
    using EAID::EntityID;
    BASE_ENTITY(Historique)
    ALIAS_CLE(Element,1)
    ALIAS_CLE(Etat,2)
    ALIAS_CLE(Usage,3)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    Historique(idt idEl, int num, idt id = 0)
        : EAID(id) {
        setIdElement(idEl);
        setNum(num);
    }

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    Historique(idt idEl, idt idEtat, idt idUsage, const QDateTime & date, int num, idt id = 0)
        : Historique(idEl,num,id) {
        setIdElement(idEl);
        setIdEtat(idEtat);
        setIdUsage(idUsage);
        setDateTime(date);
        setNum(num);
    }
};
}
#endif // ENTITYINV_H
