#include "WindowManager.h"

WindowManager::WindowManager(QTranslator *translator)
{
    fenster = new QWidget;
    m_translator = translator;
    this->setWindowIcon(QIcon(":/icon/Icon.png"));
    this->setWindowTitle("VON");
    layout2 = new QVBoxLayout(this);
    layout2->setContentsMargins(0,0,0,0);

    layout2->addWidget(fenster);
    erstes = new erstesFenster(fenster);
    zweites = new zweitesFenster(fenster, m_translator);
    drittes = new drittesFenster(fenster);

    layout = new QStackedLayout(fenster);
    layout->addWidget(erstes);
    layout->addWidget(zweites);
    layout->addWidget(drittes);
    QObject::connect(this->erstes, &erstesFenster::showLetzteBilder, this, &WindowManager::letzteBilder);
    QObject::connect(this->erstes, &erstesFenster::openSecondWindow, this, &WindowManager::showZweitesFenster);
    QObject::connect(this->zweites, &zweitesFenster::openThirdWindow, this, &WindowManager::showDrittesFenster);

}

WindowManager::~WindowManager(){
    delete (fenster);
    delete (layout);
    delete (layout2);
    delete (erstes);
    delete (zweites);
    delete (drittes);
    delete (m_translator);


}

void WindowManager::showZweitesFenster()
{
    this->layout->setCurrentWidget(zweites);
    this->zweites->erzeugeZweitesFenster();
}

void WindowManager::showDrittesFenster(string pfad)
{
    this->layout->setCurrentWidget(drittes);
    this->drittes->erzeugeDrittesFenster(pfad);
}

void WindowManager::letzteBilder()
{
    this->layout->setCurrentWidget(zweites);
    this->zweites->letzter();
}

