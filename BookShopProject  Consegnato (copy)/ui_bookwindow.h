/********************************************************************************
** Form generated from reading UI file 'bookwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKWINDOW_H
#define UI_BOOKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookWindow
{
public:
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QTextEdit *textEdit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_6;
    QLineEdit *lineEdit_8;
    QLabel *label_8;
    QLabel *label;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_5;

    void setupUi(QDialog *BookWindow)
    {
        if (BookWindow->objectName().isEmpty())
            BookWindow->setObjectName(QStringLiteral("BookWindow"));
        BookWindow->resize(403, 560);
        horizontalLayoutWidget_9 = new QWidget(BookWindow);
        horizontalLayoutWidget_9->setObjectName(QStringLiteral("horizontalLayoutWidget_9"));
        horizontalLayoutWidget_9->setGeometry(QRect(10, 520, 381, 31));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_9);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget_9);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_9->addWidget(pushButton);

        pushButton_3 = new QPushButton(horizontalLayoutWidget_9);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 77, 77)"));

        horizontalLayout_9->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(horizontalLayoutWidget_9);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_9->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_9);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_9->addWidget(pushButton_2);

        verticalLayoutWidget = new QWidget(BookWindow);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 240, 381, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout->addWidget(label_9);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        gridLayoutWidget = new QWidget(BookWindow);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 381, 235));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        lineEdit_8 = new QLineEdit(gridLayoutWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 7, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_6 = new QLineEdit(gridLayoutWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 5, 1, 1, 1);

        lineEdit_5 = new QLineEdit(gridLayoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 4, 1, 1, 1);

        lineEdit_4 = new QLineEdit(gridLayoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);

        lineEdit_3 = new QLineEdit(gridLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_7 = new QLineEdit(gridLayoutWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        horizontalLayout->addWidget(lineEdit_7);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);


        gridLayout->addLayout(horizontalLayout, 6, 1, 1, 1);


        retranslateUi(BookWindow);

        QMetaObject::connectSlotsByName(BookWindow);
    } // setupUi

    void retranslateUi(QDialog *BookWindow)
    {
        BookWindow->setWindowTitle(QApplication::translate("BookWindow", "Modifica libro", 0));
        pushButton->setText(QApplication::translate("BookWindow", "Modifica", 0));
        pushButton_3->setText(QApplication::translate("BookWindow", "Elimina libro", 0));
        pushButton_4->setText(QApplication::translate("BookWindow", "Salva", 0));
        pushButton_2->setText(QApplication::translate("BookWindow", "Esci", 0));
        label_9->setText(QApplication::translate("BookWindow", "Trama:", 0));
        label_2->setText(QApplication::translate("BookWindow", "*Autore:   ", 0));
        label_4->setText(QApplication::translate("BookWindow", "*Prezzo:    ", 0));
        label_3->setText(QApplication::translate("BookWindow", "Genere:    ", 0));
        label_5->setText(QApplication::translate("BookWindow", "Num. pag: ", 0));
        label_7->setText(QApplication::translate("BookWindow", "ISBN:        ", 0));
        label_6->setText(QApplication::translate("BookWindow", "Anno:        ", 0));
        label_8->setText(QApplication::translate("BookWindow", "*Num copie:", 0));
        label->setText(QApplication::translate("BookWindow", "*Titolo:     ", 0));
        pushButton_5->setText(QApplication::translate("BookWindow", "?", 0));
    } // retranslateUi

};

namespace Ui {
    class BookWindow: public Ui_BookWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKWINDOW_H
