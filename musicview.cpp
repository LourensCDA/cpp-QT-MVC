#include "musicview.h"

musicview::musicview()
{
    //  set model
    mod = new musicMod(this);


    // grid layout
    QGridLayout *gLayout = new QGridLayout;

    // composer
    edtComposer = new QLineEdit();
    QLabel *lblComposer = new QLabel("Composer:");
    gLayout->addWidget(lblComposer, 1, 1);
    gLayout->addWidget(edtComposer, 2, 1);

    // title
    edtAlbum = new QLineEdit();
    QLabel *lblAlbum = new QLabel("Album Title:");
    gLayout->addWidget(lblAlbum , 1, 2);
    gLayout->addWidget(edtAlbum, 2, 2);

    // cost
    edtCost = new QDoubleSpinBox();
    // set maximum and minimum values
    edtCost->setMaximum(1000);
    edtCost->setMinimum(0);
    // set decimal places
    edtCost->setDecimals(2);

    QLabel *lblCost = new QLabel("Cost (Replace):");
    gLayout->addWidget(lblCost, 1, 3);
    gLayout->addWidget(edtCost, 2, 3);

    // rating
    edtRating = new QSpinBox();
    // set maximum and minimum values
    edtRating->setMaximum(100);
    edtRating->setMinimum(0);

    QLabel *lblRating = new QLabel("Rating:");
    gLayout->addWidget(lblRating, 1, 4);
    gLayout->addWidget(edtRating, 2, 4);

    // add button
    btnAdd = new QPushButton("Add CD");
    gLayout->addWidget(btnAdd, 3,1);

    // add tableView
    tableView = new QTableView();
    gLayout->addWidget(tableView, 4, 1, 1, 4);
    gLayout->setRowStretch(4,4);
    tableView->setModel(mod);

    // add button
    btnDel = new QPushButton("Delete CD");
    gLayout->addWidget(btnDel, 5,4);

    // Outer Layer
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Add the previous inner layout
    mainLayout->addLayout(gLayout);

    // Create a widget
    QWidget *w = new QWidget();

    // Set the outer layout as a main layout
    // of the widget
    w->setLayout(mainLayout);

    // Window title
    w->setWindowTitle("Music");

    // Display
    w->show();

    connect(btnAdd, SIGNAL(clicked()), this, SLOT(addTitle()));
}

void musicview::addTitle()
{
    QString composer = edtComposer->text();
    QString album = edtAlbum->text();
    float cost = edtCost->value();
    int rating = edtRating->value();

    // add to model
    cd *c = new cd(composer, album, cost, rating);
    mod->addNewCD(c);

    // reset
    edtComposer->clear();
    edtAlbum->clear();
    edtCost->setValue(0.0);
    edtRating->setValue(0);
    edtComposer->setFocus();
}

