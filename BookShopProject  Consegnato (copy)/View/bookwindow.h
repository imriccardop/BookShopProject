#ifndef BOOKWINDOW_H
#define BOOKWINDOW_H

#include"Model/booklist.h"
#include"View/mainwindow.h"

#include <QDialog>
#include <QMessageBox>

class MainWindow;

namespace Ui {
class BookWindow;
}

class BookWindow : public QDialog
{
    Q_OBJECT
private:
    MainWindow *mw;
    BookList *bl;
    const Book *b;
    Book makeBook();
    void makeLErules();
    bool voidBook()const;
public:
    explicit BookWindow(BookList *blp,MainWindow *mwp,QWidget *parent = 0);
    explicit BookWindow(BookList *blp,const Book *book,MainWindow *mwp,QWidget *parent = 0);
    ~BookWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::BookWindow *ui;
};

#endif // BOOKWINDOW_H
