#include "Initialize.h"
#include "CMenu.h"
#include "CMenuCommand.h"
#include "Command1.h"
#include "Command2.h"
#include "Command3.h"
#include "Command4.h"
#include "Command5.h"
#include "Command6.h"
#include "Command7.h"
#include "Command8.h"
#include "Command9.h"
#include "Command10.h"
#include "CCommand.h"
#include "CTableHandler.h"

CMenu *Initializer::initialize(CTableHandler &handlero){

    CMenu *menuGlowne=new CMenu("Menu Glowne","xxxxx");

    CCommand *prob=new Command1(handlero);
      CMenuItem *teraz=new CMenuCommand("DodawanieCommand","run1",prob);
      //list.push_back(teraz);


      CCommand *prob2=new Command2(handlero);
      CMenuItem *teraz2=new CMenuCommand("Zmiana dlugosci danej CTable","run2",prob2);
      //list.push_back(teraz2);

      CCommand *prob3=new Command3(handlero);
      CMenuItem *teraz3=new CMenuCommand("Usun wybrany element","run3",prob3);
      //list.push_back(teraz3);

      CCommand *prob4=new Command4(handlero);
      CMenuItem *teraz4=new CMenuCommand("Usun wszystkie CTable","run4",prob4);
      //list.push_back(teraz4);

      CCommand *prob5=new Command5(handlero);
      CMenuItem *teraz5=new CMenuCommand("Zmien nazwe wybranego elementu","run5",prob5);
      //list.push_back(teraz5);

      CCommand *prob6=new Command6(handlero);
      CMenuItem *teraz6=new CMenuCommand("Skopiuj wybrany element","run6",prob6);
      //list.push_back(teraz6);

      CCommand *prob7=new Command7(handlero);
      CMenuItem *teraz7=new CMenuCommand("Wyswietl dany obiekt","run7",prob7);
      //list.push_back(teraz7);

      CCommand *prob8=new Command8(handlero);
      CMenuItem *teraz8=new CMenuCommand("Zmien element w tablicy w CTable","run8",prob8);
      //list.push_back(teraz8);

      CCommand *prob9=new Command9(handlero);
      CMenuItem *teraz9=new CMenuCommand("Skopiuj CTable i zmien rozmiar jego tablicy","run9",prob9);
      //list.push_back(teraz9);

      CMenu *menu=new CMenu("Dodawanie","menu1");
      menu->addMenu(teraz);
      menuGlowne->addMenu(menu);


      CMenu *menu1a=new CMenu("Kopiowanie","menu1a");
      menu1a->addMenu(teraz6);
      menu1a->addMenu(teraz9);
      menu->addMenu(menu1a);

      CMenu *menu2=new CMenu("Usuwanie","menu2");
      menu2->addMenu(teraz3);
      menu2->addMenu(teraz4);
      menuGlowne->addMenu(menu2);

      CMenu *menu3=new CMenu("Zmiany","menu3");
      CMenu *menu3a=new CMenu("Zmiany w CTable","menu3a");
      menu3a->addMenu(teraz2);
      menu3a->addMenu(teraz5);
      menu3->addMenu(menu3a);
      CMenu *menu3b=new CMenu("Zmiany w tablicy CTable","menu3b");
      menu3b->addMenu(teraz8);
      menu3->addMenu(menu3b);
      menuGlowne->addMenu(menu3);

      menuGlowne->addMenu(teraz7);

      return menuGlowne;

}
