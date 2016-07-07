#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) :
    QLabel(parent)
{}

MyLabel::MyLabel(string pfad, QWidget *parent) :
    QLabel(parent)
{

    m_pfad = pfad;
}

void MyLabel::mousePressEvent(QMouseEvent *e)
{
    int j = MyLabel::buttonByNumber (e->button());
    QString result = "Mouse Press: raw button=" + QString::number(j) + "  Qt=" + enumNameFromValue(e->button());
    QString buttonsString = MyLabel::enumNamesFromMouseButtons(e->buttons());
    result += "\n heldbuttons " + buttonsString;
    //qDebug() << result;
    std::cout << m_pfad << std::endl;


}

void MyLabel::mouseReleaseEvent(QMouseEvent *e)
{
    int j = MyLabel::buttonByNumber (e->button());
    QString result = "Mouse Release: raw button=" + QString::number(j) + "  Qt=" + enumNameFromValue(e->button());
    QString buttonsString = MyLabel::enumNamesFromMouseButtons(e->buttons());
    result += "\n heldbuttons " + buttonsString;
    //std::cout << m_pfad << std::endl;
    //qDebug() << result;

}

void MyLabel::mouseDoubleClickEvent(QMouseEvent *e)
{
    int j = MyLabel::buttonByNumber (e->button());
    QString result = "Mouse DoubleClick: raw button=" + QString::number(j)
                + "  Qt=" + enumNameFromValue(e->button());
    QString buttonsString = MyLabel::enumNamesFromMouseButtons(e->buttons());
    result += "\n heldbuttons" + buttonsString;
    getPfad();
    //std::cout << m_pfad << std::endl;
    //qDebug() << result;

}


int MyLabel::buttonByNumber(const Qt::MouseButton button)
{
    if (button == Qt::NoButton)      return 0;
    if (button == Qt::LeftButton)    return 1;
    if (button == Qt::RightButton)   return 2;
    if (button == Qt::MiddleButton)  return 3;
    if (button == Qt::BackButton)    return 8;
    if (button == Qt::ForwardButton) return 9;
    if (button == Qt::TaskButton)    return 10;
    qDebug("QMouseShortcutEntry::addShortcut contained Invalid Qt::MouseButton value");
    return 0;
}

QString MyLabel::enumNameFromValue(const Qt::MouseButton button)
{
    if (button == Qt::NoButton)      return "NoButton";
    if (button == Qt::LeftButton)    return "LeftButton";
    if (button == Qt::RightButton)   return "RightButton";
    if (button == Qt::MiddleButton)  return "MiddleButton";
    if (button == Qt::BackButton)    return "BackButton";
    if (button == Qt::ForwardButton) return "ForwardButton";
    if (button == Qt::TaskButton)    return "TaskButton";
    qDebug("QMouseShortcutEntry::addShortcut contained Invalid Qt::MouseButton value");
    return "NoButton";
}

QString MyLabel::enumNamesFromMouseButtons(const Qt::MouseButtons buttons)
{
    QString returnText = "";
    if (buttons == Qt::NoButton)      return "NoButton";
    if (buttons & Qt::LeftButton)    returnText += "LeftButton ";
    if (buttons & Qt::RightButton)   returnText +=  "RightButton ";
    if (buttons & Qt::MiddleButton)  returnText +=  "MiddleButton ";
    if (buttons & Qt::BackButton)    returnText +=  "BackButton ";
    if (buttons & Qt::ForwardButton) returnText +=  "ForwardButton ";
    if (buttons & Qt::TaskButton)    returnText +=  "TaskButton ";
    return returnText;
}

string MyLabel::getPfad(){
    std::cout << m_pfad << std::endl;
    return m_pfad;
}
