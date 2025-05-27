#ifndef PRICELIST_H
#define PRICELIST_H

#include <QDialog>
#include <QMainWindow>

#include "login.h"
#include "freshstop.h"
#include <csvreader.h>

namespace Ui {
class Pricelist;
}

class Pricelist : public QDialog
{
    Q_OBJECT

public:
    explicit Pricelist(QWidget *parent = 0);
    ~Pricelist();

private slots:
    void on_btnLoadcsv_clicked();
    void on_btnLoaddb_clicked();

private:
    Ui::Pricelist *ui;
    //Ui::CsvReader *myCSV;
    //CsvReader *myCSV;
};

#endif // PRICELIST_H
