#include "View/mainwindow.h"
#include "View/loginwindow.h"

#include "Model/userlist.h"

#include "View/bookwindow.h"

#include <QApplication>
//#include <windows.h>

int main(int argc, char *argv[])
{
    //creazione classi utenti
    UserList ul;
    //inserire il controllo degli errori nella lettura file
    QApplication a(argc, argv);

    if(!ul.read("userfile.txt")){
        QString t="Il file userfile.txt non esiste o e' vuoto,il file verrà generato all' interno della cartella che contiene il file .exe durante il salvataggio.\n E' stato generato automaticamente l' account:\n nickname=admin\npassword=admin\n";
        QMessageBox::warning(0,"ERRORE",t);
    }
        const User * userl=0;//logged user utente loggato
        //creazione classe lista libri
        BookList bl;

        MainWindow w(&userl,&bl,&ul);
        LoginWindow lw(&ul,&userl,&w);
        lw.show();
        return a.exec();
}
