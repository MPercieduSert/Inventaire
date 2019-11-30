#include "ManagersInv.h"

using namespace inventaireMPS;
using namespace managerMPS;

ManagersInv::ManagersInv()
    : ManagersPredef (infoEntityInv::NbrEntityId,bmps::cibleIdInv::NbrCible,"InventaireVersion") {
    enableRestriction("RestModif");
    enableType("Type","PermType",
               new GestionAutorisationCibleCode<Type,Restriction>(bmps::cibleId::Type,get<Restriction>()),
               new GestionAutorisationCibleCode<TypePermission,Restriction>(bmps::cibleId::TypePermission,get<Restriction>()));
    enableCommentaire("Commentaire","CbCommentaire");
    enableDonnee("Donnee","ArbDonnee","CbDonnee","CardDonnee",
                 new GestionAutorisationCibleCode<Donnee,Restriction>(bmps::cibleId::Donnee,get<Restriction>()),
                 new GestionAutorisationCibleCode<DonneeCible,Restriction>(bmps::cibleId::DonneeCible,get<Restriction>()),
                 new GestionAutorisationCibleCode<DonneeCard,Restriction>(bmps::cibleId::DonneeCard,get<Restriction>()));
    enableHistorique("Historique");
    enableMotCle("MotCle","ArbMotCle","CbMotCle","CbMotProg","PermMotCle","PermMotProg",
                 new GestionAutorisationCibleCode<MotCle,Restriction>(bmps::cibleId::MotCle,get<Restriction>()),
                 new GestionAutorisationCibleCode<MotClePermission,Restriction>(bmps::cibleId::MotClePermission,get<Restriction>()),
                 new GestionAutorisationCibleCode<MotProgPermission,Restriction>(bmps::cibleId::MotProgPermission,get<Restriction>()));


    //Acquisition
    using UniqueAc = NomUniqueSql<Acquisition>;
    InfoBdd infoAc("Acquisition",Acquisition::NbrAtt,{UniqueAc::NbrUnique});
    infoAc.setAttribut(Acquisition::DateTime,"dt",bmps::typeAttributBdd::DateTime);
    infoAc.setAttribut(Acquisition::Nc,"nc",bmps::typeAttributBdd::Text);
    infoAc.setAttribut(Acquisition::Nom,"nm",bmps::typeAttributBdd::Text);
    infoAc.setAttribut(Acquisition::Type,"tp");
    infoAc.setUnique(Acquisition::Nom,UniqueAc::NomUnique);
    setTypeForeignKey<Acquisition>(infoAc);
    setManager(new ManagerSql<Acquisition>(infoAc, new UniqueAc));
    setCible<Acquisition>(bmps::cibleIdInv::Acquisition);

    //Collections
    auto infoArbCol = infoBddArbre("ArbCol");
    using UniqueCol = NomUniqueSql<Collection>;
    InfoBdd infoCol("Collection",Collection::NbrAtt,{UniqueCol::NbrUnique});
    infoCol.setAttribut(Collection::Nc,"nc",bmps::typeAttributBdd::Text);
    infoCol.setAttribut(Collection::Nom,"nm",bmps::typeAttributBdd::Text);
    infoCol.setAttribut(Collection::Type,"tp");
    infoCol.setUnique(Collection::Nom,UniqueCol::NomUnique);
    infoCol.setForeignKey(Collection::Id,infoArbCol);
    setTypeForeignKey<Collection>(infoCol);
    setManager(new ManagerArbreModifControle<Collection>(infoCol,infoArbCol,
               new GestionAutorisationCibleCode<Collection,Restriction>(bmps::cibleIdInv::Collection,get<Restriction>()),
               new UniqueCol));
    setCible<Collection>(bmps::cibleIdInv::Collection);

    //Ingédient
    auto infoArbIng = infoBddArbre("ArbIng");
    using UniqueIng = NomUniqueSql<Ingredient>;
    InfoBdd infoIng("Ingredient",Ingredient::NbrAtt,{UniqueIng::NbrUnique});
    infoIng.setAttribut(Ingredient::Nc,"nc",bmps::typeAttributBdd::Text);
    infoIng.setAttribut(Ingredient::Nom,"nm",bmps::typeAttributBdd::Text);
    infoIng.setAttribut(Ingredient::Type,"tp");
    infoIng.setUnique(Ingredient::Nom,UniqueIng::NomUnique);
    infoIng.setForeignKey(Ingredient::Id,infoIng);
    setTypeForeignKey<Ingredient>(infoIng);
    setManager(new ManagerArbre<Ingredient>(infoIng, infoArbIng, new UniqueIng));
    setCible<Ingredient>(bmps::cibleIdInv::Ingredient);

    //Composition
    using UniqueComp = IdNumUniqueSql<Composition>;
    InfoBdd infoComp("Composition",Composition::NbrAtt,{UniqueComp::NbrUnique});
    infoComp.setAttribut(Composition::IdCollection,"idCol");
    infoComp.setAttribut(Composition::IdIngredient,"idIng");
    infoComp.setAttribut(Composition::Num,"num");
    infoComp.setAttribut(Composition::Type,"tp");
    infoComp.setAttribut(Composition::Valeur,"val",bmps::typeAttributBdd::Double);
    infoComp.setUnique(Composition::IdCollection,UniqueComp::Id1Unique);
    infoComp.setUnique(Composition::Num,UniqueComp::NumUnique);
    infoComp.setForeignKey(Composition::IdCollection,infoCol);
    infoComp.setForeignKey(Composition::IdIngredient,infoIng);
    setTypeForeignKey<Composition>(infoComp);
    setManager(new ManagerSql<Composition>(infoComp, new UniqueComp));
    setCible<Composition>(bmps::cibleIdInv::Composition);

    //Etat
    auto infoArbEt = infoBddArbre("ArbEtat");
    using UniqueEt = IdProgNomUniqueSql<Etat>;
    InfoBdd infoEt("Etat",Etat::NbrAtt,{UniqueEt::NbrUnique_1,UniqueEt::NbrUnique_2});
    infoEt.setAttribut(Etat::IdProg,"IdPg",bmps::typeAttributBdd::Integer,false);
    infoEt.setAttribut(Etat::Nc,"nc",bmps::typeAttributBdd::Text);
    infoEt.setAttribut(Etat::Nom,"nm",bmps::typeAttributBdd::Text);
    infoEt.setAttribut(Etat::Type,"tp");
    infoEt.setUnique(Etat::IdProg,UniqueEt::IdProgUnique,UniqueEt::IdProgUniqueSet);
    infoEt.setUnique(Etat::Nom,UniqueEt::NomUnique,UniqueEt::NomUniqueSet);
    infoEt.setForeignKey(Etat::Id,infoArbEt);
    setTypeForeignKey<Etat>(infoEt);
    setManager(new ManagerArbreModifControle<Etat>(infoEt,infoArbEt,
               new GestionAutorisationCibleCode<Etat,Restriction>(0,get<Restriction>()),
               new UniqueEt));
    setCible<Etat>(bmps::cibleIdInv::Etat);

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
    setCible<Element>(bmps::cibleIdInv::Element);

    //Géographie
    auto infoArbGeo = infoBddArbre("ArbGeo");
    using UniqueGeo = NomUniqueSql<Geographie>;
    InfoBdd infoGeo("Geo",Geographie::NbrAtt,{UniqueGeo::NbrUnique});
    infoGeo.setAttribut(Geographie::Nc,"nc",bmps::typeAttributBdd::Text);
    infoGeo.setAttribut(Geographie::Nom,"nm",bmps::typeAttributBdd::Text);
    infoGeo.setAttribut(Geographie::Type,"tp");
    infoGeo.setUnique(Geographie::Nom,UniqueGeo::NomUnique);
    infoGeo.setForeignKey(Geographie::Id,infoGeo);
    setTypeForeignKey<Geographie>(infoGeo);
    setManager(new ManagerArbre<Geographie>(infoGeo, infoArbGeo, new UniqueGeo));
    setCible<Geographie>(bmps::cibleIdInv::Geographie);

    //Usage
    auto infoArbUs = infoBddArbre("ArbUsage");
    using UniqueUsage = NomUniqueSql<Usage>;
    InfoBdd infoUs("Usage",Usage::NbrAtt,{UniqueUsage::NbrUnique});
    infoUs.setAttribut(Usage::Nc,"nc",bmps::typeAttributBdd::Text);
    infoUs.setAttribut(Usage::Nom,"nm",bmps::typeAttributBdd::Text);
    infoUs.setAttribut(Usage::Type,"tp");
    infoUs.setUnique(Usage::Nom,UniqueUsage::NomUnique);
    infoUs.setForeignKey(Usage::Id,infoArbUs);
    setTypeForeignKey<Usage>(infoUs);
    setManager(new ManagerArbreModifControle<Usage>(infoUs,infoArbUs,
               new GestionAutorisationCibleCode<Usage,Restriction>(bmps::cibleIdInv::Usage,get<Restriction>()),
               new UniqueUsage));
    setCible<Usage>(bmps::cibleIdInv::Usage);

    //Historique
    using UniqueHisto = IdNumUniqueSql<Historique>;
    InfoBdd infoHisto("Historique",Historique::NbrAtt,{UniqueHisto::NbrUnique});
    infoHisto.setAttribut(Historique::IdElement,"idEl");
    infoHisto.setAttribut(Historique::IdEtat,"idEt");
    infoHisto.setAttribut(Historique::IdUsage,"idUs");
    infoHisto.setAttribut(Historique::DateTime,"dt",bmps::typeAttributBdd::Text);
    infoHisto.setAttribut(Historique::Num,"num");
    infoHisto.setUnique(Historique::IdElement,UniqueHisto::Id1Unique);
    infoHisto.setUnique(Historique::Num,UniqueHisto::NumUnique);
    infoHisto.setForeignKey(Historique::IdElement,infoEl);
    infoHisto.setForeignKey(Historique::IdEtat,infoEt);
    infoHisto.setForeignKey(Historique::IdUsage,infoUs);
    setManager(new ManagerSql<Historique>(infoHisto,new UniqueHisto));
    setCible<Historique>(bmps::cibleIdInv::Historique);

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
    setTypeForeignKey<Origine>(infoOrg);
    setManager(new ManagerSql<Origine>(infoOrg, new UniqueOrg));
    setCible<Origine>(bmps::cibleIdInv::Origine);

    //Valeur
    using UniqueVal = CibleSimpleNumTypeUniqueSql<Valeur>;
    InfoBdd infoVal("Valeur",Valeur::NbrAtt,{UniqueVal::NbrUnique});
    infoVal.setAttribut(Valeur::IdCible,"idCb");
    infoVal.setAttribut(Valeur::Cible,"cb");
    infoVal.setAttribut(Valeur::Num,"num");
    infoVal.setAttribut(Valeur::Type,"tp");
    infoVal.setAttribut(Valeur::DateTime,"dt",bmps::typeAttributBdd::DateTime);
    infoVal.setAttribut(Valeur::Valeur,"val",bmps::typeAttributBdd::Integer);
    infoVal.setUnique(Valeur::IdCible,UniqueVal::IdCibleUnique);
    infoVal.setUnique(Valeur::Cible,UniqueVal::CibleUnique);
    infoVal.setUnique(Valeur::Num,UniqueVal::NumUnique);
    infoVal.setUnique(Valeur::Type,UniqueVal::TypeUnique);
    setTypeForeignKey<Valeur>(infoVal);
    setManager(new ManagerSql<Valeur>(infoVal, new UniqueVal));
    setCible<Valeur>(bmps::cibleIdInv::Valeur);
}
