#ifndef ZONEDETAILSDIALOG_H
#define ZONEDETAILSDIALOG_H

#include <QDialog>

namespace Ui {
class ZoneDetailsDialog;
}

class ZoneDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZoneDetailsDialog(QWidget *parent = nullptr);
    ~ZoneDetailsDialog();

private slots:
    void onSomeButtonClick();

private:
    ZoneDetailsDialog *ui;

    // Méthodes pour chargement et libération de ressources
    void loadZoneDetails();
    void releaseResources();
};

#endif // ZONEDETAILSDIALOG_H
