#include "hilfe.h"

Hilfe::Hilfe()
{
}

Hilfe::~Hilfe()
{
    delete (information);
}


void Hilfe::hilfeAnzeigenZweitesFenster()
{
    QMessageBox message;
    message.setWindowTitle(tr("Hilfe"));
    message.setIcon(QMessageBox::Question);

    text1 = (tr("Hintergrundfarbe ändern\n"
                "Um die Hintergrundfarbe zu ändern müssen "
                "sie eine einen der Buttons drücken, welche "
                "unter dem Textfeld Hintergrund angklicken. "
                "Dadurch verändert sich die Hintergrundfarbe,"
                "die Farbe der Schrift und die Farbe der Menuleiste."
                "Standart ist die Farbe weiß.\n\n"

                "Anzahl Bilder\n"
                "Um die Anzahl der angezeigten Bilder zu bestimmen, "
                "müssen sie auf einen der Buttons drücken, die unter dem"
                "Textfeld Anzahl Bilder angezeigt werden. Zur Auswahl stehen"
                "20 Bilder, 40 Bilder und 60 Bilder. Standartgemäß werden "
                "20 Bilder angezeigt.\n\n"

                "Vollbildmodus\n"
                "Damit die Menuleiste verschindet und man somit mehr Platz"
                "für das Anzeigen der Bild hat, kann man den Vollbildmodus aktivieren "
                "Um aus diesem Modus wieder rauszukommen, muss der Button Vollbildmodus"
                "deaktivieren angeklicket werden.\n\n"

                "Sprache\n"
                "Um die Sprache zu Ändern, muss man die Button für Deutsch oder Englisch"
                "anglicken. Standart ist die deutsche Sprache.\n\n"

                "Filter\n"
                "Um die Bilder nach etwas bestimmten zu Filtern, kann man entweder die"
                "Bewertung des Bildes angegeben, woduch nur die Bilder angezeigt werden, die "
                "solch einer Bewertung entsprechen oder man Filtern nach Themen oder Tags.\n\n"));

    message.setText(text1);
    message.setStandardButtons(QMessageBox::Ok);
    message.setDefaultButton(QMessageBox::Ok);
    message.exec();
}

void Hilfe::hilfeAnzeigenErstesFenster()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Hilfe"));
    msgBox.setIcon(QMessageBox::Question);

    text2 = (tr("Startverzeichnis\n"
                "Durch das Klicken des Buttons öffnet sich ihre "
                "Verzeichnisstruktur mit Hilfe der Sie ein Startverzeichnis "
                "auswählen können, um jpg-Dateien ab den verzeichnis zu suchen.\n\n"

                "Letzte Bilder\n"
                "Öffnet die Galiere mit den Bilder, die Sie beim letzten mal"
                "sich angesehen haben.\n\n"

                "Deutschlandflage\n"
                "Ändert die Sprache in Deutsch"
                "für das Anzeigen der Bild hat, kann man den Vollbildmodus aktivieren "
                "Um aus diesem Modus wieder rauszukommen, muss der Button Vollbildmodus"
                "deaktivieren angeklicket werden.\n\n"

                "United Kingdom Flag\n"
                "Translate everything into English."));

    msgBox.setText(text2);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}


