#include "pricelist.h"
#include "ui_pricelist.h"

//added 20 May 2015 @ 00:03
#include <QMessageBox>
//end of add

Pricelist::Pricelist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pricelist)
{
    ui->setupUi(this);
}

Pricelist::~Pricelist()
{
    delete ui;
}

/*void Pricelist::on_btnLoadcsv_clicked()
{
    this->hide();
    myCSV = new CsvReader(this);
    myCSV->show();
    //NewCsvReader.setModal(true);
    //NewCsvReader.exec();
}*/


void Pricelist::on_btnLoaddb_clicked()
{
    //added 19 May 2015 @ 23:51 (qt 17)
    Login conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.freshstopdb);

    qry->prepare("Select * from Supplier");

    qry->exec();

    modal->setQuery(*qry);

    ui->tableView->setModel(modal);

    conn.connClose();

    qDebug() << (modal->rowCount());
}

void Pricelist::on_btnLoadcsv_clicked()
{
    //myCSV = new CsvReader(this);
    //myCSV->show();
    //this->hide();
    //myCSV = new CsvReader(this);
    CsvReader *myCSV = new CsvReader();
    myCSV->show();
    this->hide();
    //myCSV->show();
    //myCSV.setModal(true);
    //myCSV.exec();
}
