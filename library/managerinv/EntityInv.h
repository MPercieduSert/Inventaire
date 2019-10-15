/*Auteur: PERCIE DU SERT Maxime
 *Date: 01/08/2019
 */
#ifndef ENTITYINV_H
#define ENTITYINV_H

#include "EntityCible.h"
#include "EntityDivers.h"
#include "EntityRelation.h"

/*! \defgroup groupeManagerInv Entités et base de données inventaire
 * \brief Ensemble des entités, managers et base de données de l'application inventaire.
 */

namespace InfoEntity {

    //! Liste des identifiants des entités
    enum entityId{AcquisitionId=NbrEntityPredefinie,
                  CollectionId,
                  CompositionId,
                  ElementId,
                  EtatId,
                  GeographieId,
                  IngredientId,
                  OrigineId,
                  ValeurId,
                  NbrEntityId};
}

// Entités de type prédéfinies
//ID1_ENTITY(cibleGeographie,CibleNumType,InfoEntity::CibleGeographieId,Geo)
ID1_ENTITY(Etat,IdNullNcNomType,InfoEntity::EtatId,Prog)
RELATION_ENTITY(Composition,NumTypeValeurDouble,InfoEntity::CompositionId,Collection,Ingredient)
RELATION_ENTITY(Origine,Type,InfoEntity::OrigineId,Collection,Geo)
using Acquisition = DateTimeValideNcNomTypeEntity<InfoEntity::AcquisitionId>;
using Collection = NcNomTypeEntity<InfoEntity::CollectionId>;
using Geographie = NcNomTypeEntity<InfoEntity::GeographieId>;
using Ingredient = NcNomTypeEntity<InfoEntity::IngredientId>;
using Valeur = CibleSimpleDateTimeValideNumTypeValeurIntEntity<InfoEntity::ValeurId>;

/*! \ingroup groupeManagerInv
 * \brief Représentation de l'entité Element.
 */
class Element : public EntityAttributsID<Attributs<Id1Attribut,
                                                   Id2Attribut,
                                                   Id3Attribut,
                                                   NumAttribut>,
                                            InfoEntity::ElementId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,Element>::Position,
                   Id1 = PositionEnum<Id1Attribut,Element>::Position,
                   Id2 = PositionEnum<Id2Attribut,Element>::Position,
                   Id3 = PositionEnum<Id3Attribut,Element>::Position,
                   Num = PositionEnum<NumAttribut,Element>::Position,
                   NbrAtt,
                   IdCollection = Id1,
                   IdAcquisition = Id2,
                   IdEtat = Id3,
                   };

    using EAID = EntityAttributsID<Attributs<Id1Attribut,Id2Attribut,Id3Attribut,NumAttribut>,InfoEntity::ElementId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(Element)
    ALIAS_CLE(Collection,1)
    ALIAS_CLE(Acquisition,2)
    ALIAS_CLE(Etat,3)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    Element(int idCol, int num, int id = 0)
        : EAID(id)
    {
        setIdCollection(idCol);
        setNum(num);
    }

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    Element(int idAcq, int idCol, int idEtat, int num, int id = 0)
        : Element(idCol,num,id)
    {
        setIdAcquisition(idAcq);
        setIdEtat(idEtat);
    }
};

#endif // ENTITYINV_H
