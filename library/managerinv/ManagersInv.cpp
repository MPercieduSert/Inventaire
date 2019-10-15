#include "ManagersInv.h"

ManagersInv::ManagersInv()
    : ManagersPredef (InfoEntity::NbrEntityId,bdd::cibleId::NbrCible,"InventaireVersion")
{
    enableRestriction("RestModif");
    enableCommentaire("Commentaire","CbCommentaire");
    enableDonnee("Donnee","ArbDonnee","CbDonnee","CardDonnee",
                 new GestionAutorisationCibleCode<Donnee,Restriction>(bdd::cibleId::Donnee,get<Restriction>()),
                 new GestionAutorisationCibleCode<CibleDonnee,Restriction>(bdd::cibleId::CibleDonnee,get<Restriction>()),
                 new GestionAutorisationCibleCode<DonneeCard,Restriction>(bdd::cibleId::DonneeCard,get<Restriction>()));
    enableHistorique("Historique");
    enableMotCle("MotCle","ArbMotCle","CbMotCle","PermMotCle",
                 new GestionAutorisationCibleCode<MotCle,Restriction>(bdd::cibleId::MotCle,get<Restriction>()),
                 new GestionAutorisationCibleCode<MotClePermission,Restriction>(bdd::cibleId::MotClePermission,get<Restriction>()));
    enableType("Type","PermType",
               new GestionAutorisationCibleCode<Type,Restriction>(bdd::cibleId::Type,get<Restriction>()),
               new GestionAutorisationCibleCode<TypePermission,Restriction>(bdd::cibleId::TypePermission,get<Restriction>()));

    //Acquisition
    using UniqueAc = NomUniqueSql<Acquisition>;
    InfoBdd infoAc("Acquisition",Acquisition::NbrAtt,{UniqueAc::NbrUnique});
    infoAc.setAttribut(Acquisition::Nc,"nc",bdd::TypeAttributBdd::Text);
    infoAc.setAttribut(Acquisition::Nom,"nm",bdd::TypeAttributBdd::Text);
    infoAc.setAttribut(Acquisition::Type,"tp");
    infoAc.setAttribut(Acquisition::DateTime,"dt",bdd::TypeAttributBdd::DateTime);
    infoAc.setUnique(Acquisition::Nom,UniqueAc::NomUnique);
    setManager(new ManagerSql<Acquisition>(infoAc, new UniqueAc));
    setCible<Acquisition>(bdd::cibleId::Acquisition);

    //Collections
    auto infoArbCol = infoBddArbre("ArbCol");
    using UniqueCol = NomUniqueSql<Collection>;
    InfoBdd infoCol("Collection",Collection::NbrAtt,{UniqueCol::NbrUnique});
    infoCol.setAttribut(Collection::Nc,"nc",bdd::TypeAttributBdd::Text);
    infoCol.setAttribut(Collection::Nom,"nm",bdd::TypeAttributBdd::Text);
    infoCol.setAttribut(Collection::Type,"tp");
    infoCol.setUnique(Collection::Nom,UniqueCol::NomUnique);
    infoCol.setForeignKey(Collection::Id,infoArbCol);
    setManager(new ManagerOfArbreModifControle<Collection>(infoCol,infoArbCol,
               new GestionAutorisationCibleCode<Collection,Restriction>(0,get<Restriction>()),
               new UniqueCol));
    setCible<Collection>(bdd::cibleId::Collection);

    //Etat
    auto infoArbEt = infoBddArbre("ArbEtat");
    using UniqueEt = IdProgNomUniqueSql<Etat>;
    InfoBdd infoEt("Etat",Etat::NbrAtt,{UniqueEt::NbrUnique_1,UniqueEt::NbrUnique_2});
    infoEt.setAttribut(Etat::IdProg,"IdPg",bdd::TypeAttributBdd::Integer,false);
    infoEt.setAttribut(Etat::Nc,"nc",bdd::TypeAttributBdd::Text);
    infoEt.setAttribut(Etat::Nom,"nm",bdd::TypeAttributBdd::Text);
    infoEt.setAttribut(Etat::Type,"tp");
    infoEt.setUnique(Etat::IdProg,UniqueEt::IdProgUnique,UniqueEt::IdProgUniqueSet);
    infoEt.setUnique(Etat::Nom,UniqueEt::NomUnique,UniqueEt::NomUniqueSet);
    infoEt.setForeignKey(Etat::Id,infoArbEt);
    setManager(new ManagerOfArbreModifControle<Etat>(infoEt,infoArbEt,
               new GestionAutorisationCibleCode<Etat,Restriction>(0,get<Restriction>()),
               new UniqueEt));
    setCible<Etat>(bdd::cibleId::Etat);

    //Géographie
    auto infoArbGeo = infoBddArbre("ArbGeo");
    using UniqueGeo = NomUniqueSql<Geographie>;
    InfoBdd infoGeo("Geo",Geographie::NbrAtt,{UniqueGeo::NbrUnique});
    infoGeo.setAttribut(Geographie::Nc,"nc",bdd::TypeAttributBdd::Text);
    infoGeo.setAttribut(Geographie::Nom,"nm",bdd::TypeAttributBdd::Text);
    infoGeo.setAttribut(Geographie::Type,"tp");
    infoGeo.setUnique(Geographie::Nom,UniqueGeo::NomUnique);
    infoGeo.setForeignKey(Geographie::Id,infoGeo);
    setManager(new ManagerOfArbre<Geographie>(infoGeo, infoArbGeo, new UniqueGeo));
    setCible<Geographie>(bdd::cibleId::Geographie);

    //Ingédient
    auto infoArbIng = infoBddArbre("ArbIng");
    using UniqueIng = NomUniqueSql<Ingredient>;
    InfoBdd infoIng("Ingredient",Ingredient::NbrAtt,{UniqueIng::NbrUnique});
    infoIng.setAttribut(Ingredient::Nc,"nc",bdd::TypeAttributBdd::Text);
    infoIng.setAttribut(Ingredient::Nom,"nm",bdd::TypeAttributBdd::Text);
    infoIng.setAttribut(Ingredient::Type,"tp");
    infoIng.setUnique(Ingredient::Nom,UniqueGeo::NomUnique);
    infoIng.setForeignKey(Ingredient::Id,infoIng);
    setManager(new ManagerOfArbre<Ingredient>(infoIng, infoArbIng, new UniqueIng));
    setCible<Ingredient>(bdd::cibleId::Ingredient);

    //Composition
    using UniqueComp = IdNumUniqueSql<Composition>;
    InfoBdd infoComp("Composition",Composition::NbrAtt,{UniqueComp::NbrUnique});
    infoComp.setAttribut(Composition::IdCollection,"idCol");
    infoComp.setAttribut(Composition::IdIngredient,"idIng");
    infoComp.setAttribut(Composition::Num,"num");
    infoComp.setAttribut(Composition::Type,"tp");
    infoComp.setAttribut(Composition::Valeur,"val",bdd::TypeAttributBdd::Double,false);
    infoComp.setUnique(Composition::IdCollection,UniqueComp::Id1Unique);
    infoComp.setUnique(Composition::Num,UniqueComp::NumUnique);
    infoComp.setForeignKey(Composition::IdCollection,infoCol);
    infoComp.setForeignKey(Composition::IdIngredient,infoIng);
    setManager(new ManagerSql<Composition>(infoComp, new UniqueComp));
    setCible<Composition>(bdd::cibleId::Composition);

    //Origine
    using UniqueOrg = IdTypeUniqueSql<Origine>;
    InfoBdd infoOrg("Origine",Origine::NbrAtt,{UniqueOrg::NbrUnique});
    infoOrg.setAttribut(Origine::IdCollection,"idCol");
    infoOrg.setAttribut(Origine::IdGeo,"idGeo");
    infoOrg.setAttribut(Origine::Type,"tp");
    infoOrg.setUnique(Origine::IdCollection,UniqueOrg::Id1Unique);
    infoOrg.setUnique(Origine::Type,UniqueOrg::TypeUnique);
    infoOrg.setForeignKey(Origine::IdCollection,infoCol);
    infoOrg.setForeignKey(Origine::IdGeo,infoGeo);
    setManager(new ManagerSql<Origine>(infoOrg, new UniqueOrg));
    setCible<Origine>(bdd::cibleId::Origine);

    //Element
    using UniqueEl = IdNumUniqueSql<Element>;
    InfoBdd infoEl("Element",Element::NbrAtt,{UniqueEl::NbrUnique});
    infoEl.setAttribut(Element::IdCollection,"idCol");
    infoEl.setAttribut(Element::IdAcquisition,"idAcq");
    infoEl.setAttribut(Element::IdEtat,"idEt");
    infoEl.setAttribut(Element::Num,"num");
    infoEl.setUnique(Element::IdCollection,UniqueEl::Id1Unique);
    infoEl.setUnique(Element::Num,UniqueEl::NumUnique);
    infoEl.setForeignKey(Element::IdAcquisition,infoAc);
    infoEl.setForeignKey(Element::IdCollection,infoCol);
    infoEl.setForeignKey(Element::IdEtat,infoEt);
    setManager(new ManagerSql<Element>(infoEl, new UniqueEl));
    setCible<Element>(bdd::cibleId::Element);

    //Valeur
    using UniqueVal = CibleSimpleNumTypeUniqueSql<Valeur>;
    InfoBdd infoVal("Valeur",Valeur::NbrAtt,{UniqueVal::NbrUnique});
    infoVal.setAttribut(Valeur::IdCible,"idCb");
    infoVal.setAttribut(Valeur::Cible,"cb");
    infoVal.setAttribut(Valeur::Num,"num");
    infoVal.setAttribut(Valeur::Type,"tp");
    infoVal.setAttribut(Valeur::DateTime,"dt",bdd::TypeAttributBdd::DateTime);
    infoVal.setAttribut(Valeur::Valeur,"val",bdd::TypeAttributBdd::Integer,false);
    infoVal.setUnique(Valeur::IdCible,UniqueVal::IdCibleUnique);
    infoVal.setUnique(Valeur::Cible,UniqueVal::CibleUnique);
    infoVal.setUnique(Valeur::Num,UniqueVal::NumUnique);
    infoVal.setUnique(Valeur::Type,UniqueVal::TypeUnique);
    setManager(new ManagerSql<Valeur>(infoVal, new UniqueVal));
    setCible<Valeur>(bdd::cibleId::Valeur);
}
