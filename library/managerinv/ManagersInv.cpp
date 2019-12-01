#include "ManagersInv.h"

using namespace inventaireMPS;
using namespace managerMPS;

ManagersInv::ManagersInv()
    : ManagersPredef (infoEntityInv::NbrEntityId,bmps::cibleIdInv::NbrCible,"InventaireVersion") {
    enableRestriction("RestModif");
    enableType("Type","PermType",
               std::make_unique<GestionAutorisationCibleCode<Type,Restriction>>(bmps::cibleId::Type,get<Restriction>()),
               std::make_unique<GestionAutorisationCibleCode<TypePermission,Restriction>>(bmps::cibleId::TypePermission,get<Restriction>()));
    enableCommentaire("Commentaire","CbCommentaire");
    enableDonnee("Donnee","ArbDonnee","CbDonnee","CardDonnee",
                 std::make_unique<GestionAutorisationCibleCode<Donnee,Restriction>>(bmps::cibleId::Donnee,get<Restriction>()),
                 std::make_unique<GestionAutorisationCibleCode<DonneeCible,Restriction>>(bmps::cibleId::DonneeCible,get<Restriction>()),
                 std::make_unique<GestionAutorisationCibleCode<DonneeCard,Restriction>>(bmps::cibleId::DonneeCard,get<Restriction>()));
    enableHistorique("Historique");
    enableMotCle("MotCle","ArbMotCle","CbMotCle","CbMotProg","PermMotCle","PermMotProg",
          std::make_unique<GestionAutorisationCibleCode<MotCle,Restriction>>(bmps::cibleId::MotCle,get<Restriction>()),
          std::make_unique<GestionAutorisationCibleCode<MotClePermission,Restriction>>(bmps::cibleId::MotClePermission,get<Restriction>()),
          std::make_unique<GestionAutorisationCibleCode<MotProgPermission,Restriction>>(bmps::cibleId::MotProgPermission,get<Restriction>()));


    //Acquisition
    using UniqueAc = NomUniqueSql<Acquisition>;
    InfoBdd infoAc("Acquisition",Acquisition::NbrAtt,{UniqueAc::NbrUnique});
    infoAc.setAttribut(Acquisition::DateTime,"dt",bmps::typeAttributBdd::DateTime);
    infoAc.setAttribut(Acquisition::Nc,"nc",bmps::typeAttributBdd::Text);
    infoAc.setAttribut(Acquisition::Nom,"nm",bmps::typeAttributBdd::Text);
    infoAc.setAttribut(Acquisition::Type,"tp");
    infoAc.setUnique(Acquisition::Nom,UniqueAc::NomUnique);
    setTypeForeignKey<Acquisition>(infoAc);
    setManager<Acquisition>(std::make_unique<ManagerSql<Acquisition>>(infoAc, std::make_unique<UniqueAc>()));
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
    setManager<Collection>(std::make_unique<ManagerArbreModifControle<Collection>>(infoCol,infoArbCol,
               std::make_unique<GestionAutorisationCibleCode<Collection,Restriction>>(bmps::cibleIdInv::Collection,get<Restriction>()),
               std::make_unique<UniqueCol>()));
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
    setManager<Ingredient>(std::make_unique<ManagerArbre<Ingredient>>(infoIng, infoArbIng, std::make_unique<UniqueIng>()));
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
    setManager<Composition>(std::make_unique<ManagerSql<Composition>>(infoComp, std::make_unique<UniqueComp>()));
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
    setManager<Etat>(std::make_unique<ManagerArbreModifControle<Etat>>(infoEt,infoArbEt,
               std::make_unique<GestionAutorisationCibleCode<Etat,Restriction>>(bmps::cibleIdInv::Etat,get<Restriction>()),
               std::make_unique<UniqueEt>()));
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
    setManager<Element>(std::make_unique<ManagerSql<Element>>(infoEl, std::make_unique<UniqueEl>()));
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
    setManager<Geographie>(std::make_unique<ManagerArbre<Geographie>>(infoGeo, infoArbGeo, std::make_unique<UniqueGeo>()));
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
    setManager<Usage>(std::make_unique<ManagerArbreModifControle<Usage>>(infoUs,infoArbUs,
               std::make_unique<GestionAutorisationCibleCode<Usage,Restriction>>(bmps::cibleIdInv::Usage,get<Restriction>()),
               std::make_unique<UniqueUsage>()));
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
    setManager<Historique>(std::make_unique<ManagerSql<Historique>>(infoHisto,std::make_unique<UniqueHisto>()));
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
    setManager<Origine>(std::make_unique<ManagerSql<Origine>>(infoOrg, std::make_unique<UniqueOrg>()));
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
    setManager<Valeur>(std::make_unique<ManagerSql<Valeur>>(infoVal, std::make_unique<UniqueVal>()));
    setCible<Valeur>(bmps::cibleIdInv::Valeur);
}
