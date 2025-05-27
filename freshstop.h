#ifndef FRESHSTOP_H
#define FRESHSTOP_H

#include <QDialog>
//added 19 May 2015 @ 23:02
#include "login.h"
//end of addition
#include "pricelist.h"

namespace Ui {
class Freshstop;
}

class Freshstop : public QDialog
{
    Q_OBJECT

public:
    //added 19 May 2015 @ 23:05
    //Login conn;
    //end of addition
    explicit Freshstop(QWidget *parent = 0);
    ~Freshstop();

private slots:
    void on_btnSave_clicked();

    void on_btnEdit_clicked();

    void on_btnLoad_clicked();

    void on_btnPricelist_clicked();

private:
    Ui::Freshstop *ui;
};

#endif // FRESHSTOP_H
