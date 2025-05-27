#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    //added 19 May 2015 @ 21:48 (qt 11)
    QPixmap freshstopLogo(":/freshstop_files/CaltexFreshStopLogo-480x236.jpg");
    ui->lblLogo->setPixmap(freshstopLogo);
    //end of add (qt11)
    //Chris additional code set to fit the image inside of the label
    ui->lblLogo->setScaledContents(true);

    //added 19 May 2015 @ 21:09 (qt 7)

    //freshstopdb = QSqlDatabase::addDatabase("QSQLITE");
    //freshstopdb.setDatabaseName("D:/Unisa/COS2614/db/freshstop.db");

    //Left the below behind
    //if(!freshstopdb.open())
        //Because we have added the function connOpen as of (qt 13), we need to ammend any calls to the above
        if(!connOpen())
        ui->lblStatus->setText("Connection Failed!");
    else
        ui->lblStatus->setText("Connection Successful, yay");
    //end of add
}

Login::~Login()
{
    delete ui;
}

//Chris slightly adjusted code from (qt 13) - added it to implementation rather than header
bool Login::connOpen()
{
    //moved 19 May 2015 @ 22:21 (qt 7/13)

    freshstopdb = QSqlDatabase::addDatabase("QSQLITE");
    freshstopdb.setDatabaseName("C:/Freshstop/db/freshstop.db");

    if(!freshstopdb.open())
        //Because we have added the function connOpen as of (qt 13), we need to ammend any calls to the above
        //if(!freshstopdb.open())
        {
        //modified this to qDebug
        qDebug()<<("Connection Failed!");
        //added this line below (qt 13)
        return false;
        }
    else
        {
        //modified this to qDebug
        qDebug()<<("Connection Successful, yay");
        //added this line below (qt 13)
        return true;
    //end of add
        }
}

//Chris slightly adjusted code from (qt 13) - added it to implementation rather than header
void Login::connClose()
{
    freshstopdb.close();
    freshstopdb.removeDatabase(QSqlDatabase::defaultConnection);
}
//end of Chris adjustmment from (qt 13)

void Login::on_btnLogin_clicked()
{
    //added 19 May 2015 @ 21:25 (qt 8)
    QString username, password;
    username = ui->edtUname->text();
    password = ui->edtPass->text();

    //if(!freshstopdb.isOpen())
        //Because we have added the function connOpen as of (qt 13), we need to ammend any calls to the above
        if(!connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }

    //added 19 May 2015 @ 22:30 - open connection (qt 13)
    connOpen();
    //end of addition

    QSqlQuery qry;
    //if(qry.exec())
        //end of add from (qt 8)

    //added 19 May 2015 @ 22:31 - moved qry.exec comments to here (qt 13)
    qry.prepare("select * from Login where uname='"+username+"' and pass='"+password+"'");
    //end of addition

    //added 19 May 2015 @ 21:30 (qt 9)
    //removed qry.exec comments as of (qt 13) - using them in the qry.prepare statement
    if(qry.exec())
    {
        int count = 0;
        while(qry.next())
        {
            count++;
        }

        if(count==1)
        {
            ui->lblStatus->setText("username and password is correct, yay");
            //modified - additional as of 19 May 2015 @ 22:00
            this->hide();
            //modified - additional as of 19 May 2015 @ 22:34
            connClose();
            //end of additional as of 19 May 2015 @ 22:34
            //The below was before pricelist was added
            Freshstop NewFreshstop;
            NewFreshstop.setModal(true);
            NewFreshstop.exec();
            //end of modification - additional as of 19 May 2015 @ 22:00
            //added 25 May 2015 @ 22:11
            //NewCSVreader = new CsvReader(this);
            //NewCSVreader->show();
        }
        if(count>1)
        {
            ui->lblStatus->setText("Duplicate username and password!");
        }
        if(count<1)
        {
            ui->lblStatus->setText("username and password is incorrect or does not exist");
        }

    }
    //end of add from (qt 9)

}
