#include "borderlayout.h"
#include "window.h"
#include <QTextBrowser>
#include <QLabel>

Window::Window()
{
    QTextBrowser *centralWidget = new QTextBrowser;
    centralWidget->setPlainText(tr("Central widget"));

    BorderLayout *layout = new BorderLayout;
    layout->addWidget(centralWidget, BorderLayout::Center);
    layout->addWidget(creatLabel(), BorderLayout::West);
    setLayout(layout);

    setWindowTitle(tr("Project VON"));
}

QLabel *Window::creatLabel()
{
   QVBoxLayout *menu = new QVBoxLayout;

    QLabel *option = new QLabel("Optionen");
    option->setFrameStyle(QFrame::Box | QFrame::Sunken);

    QLabel *filter = new QLabel("Filter");
    filter->setFrameStyle(QFrame::Box | QFrame::Sunken);

    menu->addWidget(option);
    menu->addWidget(filter);


    return option;
}
