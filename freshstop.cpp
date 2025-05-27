#include "freshstop.h"
#include "ui_freshstop.h"

//added 19 May 2015 @ 23:24 (qt 14)
#include <QMessageBox>
//end of addition

Freshstop::Freshstop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Freshstop)
{
    ui->setupUi(this);
    //added 19 May 2015 @ 23:07 - created Login object
    Login conn;
    //added 19 May 2015 @ 23:01 - added code for status
    if(!conn.connOpen())
    ui->lblStatus->setText("Connection Failed!");
else
    {
        ui->lblStatus->setText("Connection Successful, yay");
    //Create a new Query Model
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(conn.freshstopdb);
    // The below query is used to list all tables in the SQLite database
    qry->prepare("SELECT name FROM sqlite_master WHERE type='table' ORDER BY name");
    qry->exec();
    modal->setQuery(*qry);
    ui->cboTables->setModel(modal);
    }


}

Freshstop::~Freshstop()
{
    delete ui;
}

void Freshstop::on_btnSave_clicked()
{
    //added 19 May 2015 @ 23:16 - created Login object
    Login conn;
    //added 19 May 2015 @ 23:16 (qt 14)
    QString id, fname, sname;
    id = ui->edtID->text();
    fname = ui->edtFname->text();
    sname = ui->edtSname->text();

    //if(!freshstopdb.isOpen())
        //Because we have added the function connOpen as of (qt 13), we need to ammend any calls to the above
        if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }

    //added 19 May 2015 @ 22:30 - open connection (qt 13)
    conn.connOpen();
    //end of addition

    QSqlQuery qry;
    //if(qry.exec())
        //end of add from (qt 8)

    //added 19 May 2015 @ 23:24 - moved qry.exec comments to here (qt 13)
    qry.prepare("insert into Login (ID, FName, SName) values ('"+id+"','"+fname+"','"+sname+"')");
    //end of addition

    //added 19 May 2015 @ 21:30 (qt 9)
    //removed qry.exec comments as of (qt 13) - using them in the qry.prepare statement
    if(qry.exec())
    {
        QMessageBox::information(this,tr("Save Successful"),tr("Your data was successfully saved"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }

}

void Freshstop::on_btnEdit_clicked()
{
    //added 19 May 2015 @ 23:16 - created Login object
    Login conn;
    //added 19 May 2015 @ 23:16 (qt 14)
    QString id, fname, sname;
    id = ui->edtID->text();
    fname = ui->edtFname->text();
    sname = ui->edtSname->text();

    //if(!freshstopdb.isOpen())
        //Because we have added the function connOpen as of (qt 13), we need to ammend any calls to the above
        if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }

    //added 19 May 2015 @ 22:30 - open connection (qt 13)
    conn.connOpen();
    //end of addition

    QSqlQuery qry;
    //if(qry.exec())
        //end of add from (qt 8)

    //added 19 May 2015 @ 23:24 - moved qry.exec comments to here (qt 13)
    //qry.prepare("insert into Login (ID, FName, SName) values ('"+id+"','"+fname+"','"+sname+"')");
    qry.prepare("update Login set ID='"+id+"', FName='"+fname+"', SName='"+sname+"' where ID='"+id+"'");
    //end of addition

    //added 19 May 2015 @ 21:30 (qt 9)
    //removed qry.exec comments as of (qt 13) - using them in the qry.prepare statement
    if(qry.exec())
    {
        QMessageBox::information(this,tr("Update Successful"),tr("Your data was successfully updated"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}

void Freshstop::on_btnLoad_clicked()
{
    //added 19 May 2015 @ 23:51 (qt 17)
    //Create a new object conn from the Login Class
    Login conn;
    //Create a new Query Model
    QSqlQueryModel * modal = new QSqlQueryModel();

    //Open the SQL connection
    conn.connOpen();

    QSqlQuery* qry = new QSqlQuery(conn.freshstopdb);
    QString tblName;
    tblName = ui->cboTables->currentText();
    qry->prepare("SELECT * FROM '"+tblName+"'");

    qry->exec();

    modal->setQuery(*qry);

    ui->tableView->setModel(modal);

    conn.connClose();

    qDebug() << (modal->rowCount());


}

void Freshstop::on_btnPricelist_clicked()
{
    this->hide();
    Pricelist NewPricelist;
    NewPricelist.setModal(true);
    NewPricelist.exec();
}
