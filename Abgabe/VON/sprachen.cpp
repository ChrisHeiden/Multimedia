#include "sprachen.h"

Sprachen::Sprachen(QTranslator *translator)
{
    m_translator = translator;
}

Sprachen::~Sprachen(){
    delete (m_translator);
}

void Sprachen::englischUebersetzung()
{
    QApplication::instance()->removeTranslator(m_translator);
}

void Sprachen::deutschUebersetzung()
{
    QApplication::instance()->removeTranslator(m_translator);

    if (m_translator->load(":/language/VON_Englisch_zu_Deutsch.qm"))

    {
    qDebug() << "LOAD FINISHED";

    QApplication::instance()->installTranslator(m_translator);
    }
}
