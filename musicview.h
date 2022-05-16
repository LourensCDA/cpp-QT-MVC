#ifndef MUSICVIEW_H
#define MUSICVIEW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QPushButton>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include <QDate>
#include <QAbstractButton>
#include <QTableWidget>
#include "musicmod.h"

class musicview : public QMainWindow
{
    Q_OBJECT
public:
    musicview();

private slots:
    void addTitle();

private:
    QLineEdit *edtComposer;
    QLineEdit *edtAlbum;
    QDoubleSpinBox *edtCost;
    QSpinBox *edtRating;
    QPushButton *btnAdd;
    QPushButton *btnDel;
    QTableView *tableView;
    musicMod *mod;
};

#endif // MUSICVIEW_H
