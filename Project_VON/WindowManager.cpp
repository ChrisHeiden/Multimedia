#include "WindowManager.h"

WindowManager::WindowManager(QTranslator *translator)
{
    m_translator = translator;
    this->setWindowIcon(QIcon(":/icon/Icon.png"));
    layout2 = new QVBoxLayout(this);
    layout2->setContentsMargins(0,0,0,0);

    layout2->addWidget(fenster);
    erstes = new erstesFenster(fenster);
    zwei = new zweitesFenster(fenster, m_translator);

    layout = new QStackedLayout(fenster);
    layout->addWidget(erstes);
    layout->addWidget(zwei);
    QObject::connect(this->erstes, &erstesFenster::openSecondWindow, this, &WindowManager::showZweitesFenster);
}

WindowManager::~WindowManager(){
    delete (fenster);
}

void WindowManager::showZweitesFenster()
{
    this->layout->setCurrentWidget(zwei);
    this->zwei->erzeugeZweitesFenster();
}
