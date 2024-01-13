/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *mainStackedWidget;
    QWidget *acceuil;
    QPushButton *pushButton;
    QPlainTextEdit *descriptionText;
    QPlainTextEdit *creditSpace;
    QLineEdit *titleApp;
    QWidget *overview;
    QLabel *label;
    QWidget *analyse;
    QWidget *mainpage;
    QLineEdit *lineEdit_7;
    QWidget *formLayoutWidget_3;
    QFormLayout *formSettings_5;
    QLabel *recchercheLabel;
    QLineEdit *recchercheLineEdit;
    QLabel *lieuCulturelLabel;
    QLineEdit *lieuCulturelLineEdit;
    QLabel *monumentLabel;
    QLineEdit *monumentLineEdit;
    QLabel *boiteDeNuitLabel;
    QLineEdit *boiteDeNuitLineEdit;
    QLabel *metroLabel;
    QComboBox *metroComboBox;
    QPushButton *pushButton_2;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_2graph;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_map;
    QLineEdit *line;
    QPushButton *pushButton_Analyse;
    QLineEdit *lineEdit_8;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(847, 616);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainStackedWidget = new QStackedWidget(centralwidget);
        mainStackedWidget->setObjectName("mainStackedWidget");
        mainStackedWidget->setGeometry(QRect(0, 0, 841, 591));
        acceuil = new QWidget();
        acceuil->setObjectName("acceuil");
        acceuil->setStyleSheet(QString::fromUtf8("background-color:rgb(119, 118, 123)"));
        pushButton = new QPushButton(acceuil);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(620, 160, 161, 61));
        QFont font;
        font.setPointSize(15);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(190, 183, 183);"));
        descriptionText = new QPlainTextEdit(acceuil);
        descriptionText->setObjectName("descriptionText");
        descriptionText->setGeometry(QRect(80, 240, 231, 301));
        QFont font1;
        font1.setPointSize(13);
        descriptionText->setFont(font1);
        descriptionText->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        descriptionText->setReadOnly(true);
        creditSpace = new QPlainTextEdit(acceuil);
        creditSpace->setObjectName("creditSpace");
        creditSpace->setGeometry(QRect(610, 420, 131, 81));
        creditSpace->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        creditSpace->setReadOnly(true);
        titleApp = new QLineEdit(acceuil);
        titleApp->setObjectName("titleApp");
        titleApp->setGeometry(QRect(80, 90, 391, 41));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setItalic(true);
        titleApp->setFont(font2);
        titleApp->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(190, 183, 183);"));
        titleApp->setReadOnly(true);
        mainStackedWidget->addWidget(acceuil);
        overview = new QWidget();
        overview->setObjectName("overview");
        overview->setStyleSheet(QString::fromUtf8("background-color:rgb(119, 118, 123)"));
        label = new QLabel(overview);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 430, 67, 17));
        mainStackedWidget->addWidget(overview);
        analyse = new QWidget();
        analyse->setObjectName("analyse");
        analyse->setStyleSheet(QString::fromUtf8("background-color:rgb(119, 118, 123)"));
        mainStackedWidget->addWidget(analyse);
        mainpage = new QWidget();
        mainpage->setObjectName("mainpage");
        mainpage->setStyleSheet(QString::fromUtf8("background-color:rgb(119, 118, 123)"));
        lineEdit_7 = new QLineEdit(mainpage);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(510, 200, 113, 25));
        lineEdit_7->setReadOnly(true);
        formLayoutWidget_3 = new QWidget(mainpage);
        formLayoutWidget_3->setObjectName("formLayoutWidget_3");
        formLayoutWidget_3->setGeometry(QRect(510, 230, 291, 188));
        formSettings_5 = new QFormLayout(formLayoutWidget_3);
        formSettings_5->setObjectName("formSettings_5");
        formSettings_5->setContentsMargins(0, 0, 0, 0);
        recchercheLabel = new QLabel(formLayoutWidget_3);
        recchercheLabel->setObjectName("recchercheLabel");

        formSettings_5->setWidget(0, QFormLayout::LabelRole, recchercheLabel);

        recchercheLineEdit = new QLineEdit(formLayoutWidget_3);
        recchercheLineEdit->setObjectName("recchercheLineEdit");

        formSettings_5->setWidget(0, QFormLayout::FieldRole, recchercheLineEdit);

        lieuCulturelLabel = new QLabel(formLayoutWidget_3);
        lieuCulturelLabel->setObjectName("lieuCulturelLabel");

        formSettings_5->setWidget(1, QFormLayout::LabelRole, lieuCulturelLabel);

        lieuCulturelLineEdit = new QLineEdit(formLayoutWidget_3);
        lieuCulturelLineEdit->setObjectName("lieuCulturelLineEdit");

        formSettings_5->setWidget(1, QFormLayout::FieldRole, lieuCulturelLineEdit);

        monumentLabel = new QLabel(formLayoutWidget_3);
        monumentLabel->setObjectName("monumentLabel");

        formSettings_5->setWidget(2, QFormLayout::LabelRole, monumentLabel);

        monumentLineEdit = new QLineEdit(formLayoutWidget_3);
        monumentLineEdit->setObjectName("monumentLineEdit");

        formSettings_5->setWidget(2, QFormLayout::FieldRole, monumentLineEdit);

        boiteDeNuitLabel = new QLabel(formLayoutWidget_3);
        boiteDeNuitLabel->setObjectName("boiteDeNuitLabel");

        formSettings_5->setWidget(3, QFormLayout::LabelRole, boiteDeNuitLabel);

        boiteDeNuitLineEdit = new QLineEdit(formLayoutWidget_3);
        boiteDeNuitLineEdit->setObjectName("boiteDeNuitLineEdit");

        formSettings_5->setWidget(3, QFormLayout::FieldRole, boiteDeNuitLineEdit);

        metroLabel = new QLabel(formLayoutWidget_3);
        metroLabel->setObjectName("metroLabel");

        formSettings_5->setWidget(4, QFormLayout::LabelRole, metroLabel);

        metroComboBox = new QComboBox(formLayoutWidget_3);
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->addItem(QString());
        metroComboBox->setObjectName("metroComboBox");

        formSettings_5->setWidget(4, QFormLayout::FieldRole, metroComboBox);

        pushButton_2 = new QPushButton(formLayoutWidget_3);
        pushButton_2->setObjectName("pushButton_2");

        formSettings_5->setWidget(5, QFormLayout::LabelRole, pushButton_2);

        verticalLayoutWidget_5 = new QWidget(mainpage);
        verticalLayoutWidget_5->setObjectName("verticalLayoutWidget_5");
        verticalLayoutWidget_5->setGeometry(QRect(40, 440, 761, 89));
        verticalLayout_2graph = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_2graph->setObjectName("verticalLayout_2graph");
        verticalLayout_2graph->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(verticalLayoutWidget_5);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_2graph->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout_2graph->addWidget(lineEdit_2);

        verticalLayoutWidget_6 = new QWidget(mainpage);
        verticalLayoutWidget_6->setObjectName("verticalLayoutWidget_6");
        verticalLayoutWidget_6->setGeometry(QRect(40, 30, 451, 391));
        verticalLayout_map = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_map->setObjectName("verticalLayout_map");
        verticalLayout_map->setContentsMargins(0, 0, 0, 0);
        line = new QLineEdit(verticalLayoutWidget_6);
        line->setObjectName("line");
        line->setReadOnly(true);

        verticalLayout_map->addWidget(line);

        pushButton_Analyse = new QPushButton(mainpage);
        pushButton_Analyse->setObjectName("pushButton_Analyse");
        pushButton_Analyse->setGeometry(QRect(510, 30, 251, 61));
        lineEdit_8 = new QLineEdit(mainpage);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(510, 100, 131, 25));
        horizontalLayoutWidget = new QWidget(mainpage);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(510, 129, 291, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(horizontalLayoutWidget);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(horizontalLayoutWidget);
        pushButton_6->setObjectName("pushButton_6");

        horizontalLayout->addWidget(pushButton_6);

        mainStackedWidget->addWidget(mainpage);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 847, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());

        retranslateUi(MainWindow);

        mainStackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Commencer", nullptr));
        descriptionText->setPlainText(QCoreApplication::translate("MainWindow", "Dans cette application nous allons simuler l'influence des JO 2024 sur les lieux de Paris.\n"
"\n"
"On esp\303\250re que cela vous plaira\n"
"\n"
"-Simulation sur paris en g\303\251n\303\251rale\n"
"-Page d'analyse\n"
"-Simulation systeme m\303\251tro", nullptr));
        creditSpace->setPlainText(QCoreApplication::translate("MainWindow", "Cr\303\251ateur:\n"
"Cl\303\251ment ZHUANG\n"
"Linda TALA", nullptr));
        titleApp->setText(QCoreApplication::translate("MainWindow", "OLYMPIC SIM'S", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Aper\303\247ue", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "Settings:", nullptr));
        recchercheLabel->setText(QCoreApplication::translate("MainWindow", "Restaurant", nullptr));
        lieuCulturelLabel->setText(QCoreApplication::translate("MainWindow", "LieuCulturel", nullptr));
        monumentLabel->setText(QCoreApplication::translate("MainWindow", "Monument", nullptr));
        boiteDeNuitLabel->setText(QCoreApplication::translate("MainWindow", "BoiteDeNuit", nullptr));
        metroLabel->setText(QCoreApplication::translate("MainWindow", "Metro", nullptr));
        metroComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        metroComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        metroComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        metroComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3bis", nullptr));
        metroComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        metroComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        metroComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));
        metroComboBox->setItemText(7, QCoreApplication::translate("MainWindow", "7", nullptr));
        metroComboBox->setItemText(8, QCoreApplication::translate("MainWindow", "7bis", nullptr));
        metroComboBox->setItemText(9, QCoreApplication::translate("MainWindow", "8", nullptr));
        metroComboBox->setItemText(10, QCoreApplication::translate("MainWindow", "9", nullptr));
        metroComboBox->setItemText(11, QCoreApplication::translate("MainWindow", "10", nullptr));
        metroComboBox->setItemText(12, QCoreApplication::translate("MainWindow", "11", nullptr));
        metroComboBox->setItemText(13, QCoreApplication::translate("MainWindow", "12", nullptr));
        metroComboBox->setItemText(14, QCoreApplication::translate("MainWindow", "13", nullptr));
        metroComboBox->setItemText(15, QCoreApplication::translate("MainWindow", "14", nullptr));

        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "Evolution nb personne", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "Temp d'attente cumul\303\251", nullptr));
        line->setText(QCoreApplication::translate("MainWindow", "MAP", nullptr));
        pushButton_Analyse->setText(QCoreApplication::translate("MainWindow", "Deeper Analysis", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("MainWindow", "Simulation panel", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "End", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
