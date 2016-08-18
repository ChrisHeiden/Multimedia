#include "WindowManager.h"

WindowManager::WindowManager(QTranslator *translator)
{
    fenster = new QWidget;
    bank= new Datenbank;
    m_translator = translator;
    this->setWindowIcon(QIcon(":/icon/Icon.png"));
    this->setWindowTitle("VON");
    layout2 = new QVBoxLayout(this);
    layout2->setContentsMargins(0,0,0,0);

    layout2->addWidget(fenster);
    erstes = new erstesFenster(fenster, m_translator, bank);
    zweites = new zweitesFenster(fenster, m_translator, bank);
    drittes = new drittesFenster(fenster, bank);
    sprache = new Sprachen(m_translator);

    layout = new QStackedLayout(fenster);
    layout->addWidget(erstes);
    layout->addWidget(zweites);
    layout->addWidget(drittes);
    erstes->erzeugen();
    setzeSignals();
}

WindowManager::~WindowManager(){
    delete (fenster);
    delete (layout);
    delete (layout2);
    delete (erstes);
    delete (zweites);
    delete (drittes);
    delete (bank);
    delete (m_translator);
    delete (sprache);
}

void WindowManager::showZweitesFenster()
{
    erstes->disconnect();
    this->layout->setCurrentWidget(zweites);
    this->zweites->erzeugeNeueGalerie();
    this->showMaximized();
}

void WindowManager::showDrittesFenster(string pfad)
{
    this->layout->setCurrentWidget(drittes);
    this->drittes->erzeugeDrittesFenster(pfad);
    this->showMaximized();
}

void WindowManager::letzte()
{    
    erstes->disconnect();
    this->layout->setCurrentWidget(zweites);
    this->zweites->erzeugeLetzteGalerie();
    this->showMaximized();
}

void WindowManager::deutschUebersetzung(){
    sprache->deutschUebersetzung();
}

void WindowManager::englischUebersetzung(){
    sprache->englischUebersetzung();
}

void WindowManager::setzeSignals()
{
    QObject::connect(this->erstes, &erstesFenster::showLetzteBilder, this, &WindowManager::letzte);
    QObject::connect(this->erstes, &erstesFenster::openSecondWindow, this, &WindowManager::showZweitesFenster);
    QObject::connect(this->zweites, &zweitesFenster::openThirdWindow, this, &WindowManager::showDrittesFenster);
    QObject::connect(this->drittes, &drittesFenster::showBildergalerie, this, &WindowManager::letzte);
    QObject::connect(erstes, &erstesFenster::deutschUebersetzung, this, &WindowManager::deutschUebersetzung);
    QObject::connect(erstes, &erstesFenster::englischUebersetzung, this, &WindowManager::englischUebersetzung);
    QObject::connect(zweites, &zweitesFenster::deutschUebersetzung, this, &WindowManager::deutschUebersetzung);
    QObject::connect(zweites, &zweitesFenster::englischUebersetzung, this, &WindowManager::englischUebersetzung);
}
