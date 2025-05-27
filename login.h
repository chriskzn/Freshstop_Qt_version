#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
//added 19 May 2015 @ 21:08 (qt 7)
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
//end of addition

//added 19 May 2015 @ 21:58 (qt 12)
#include "freshstop.h"
//end of addition
#include "pricelist.h"
//added 25 May 2015
//#include "csvreader.h"

namespace Ui {
class Login;
//class CsvReader;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    //added 19 May 2015 @ 22:17 - Created Connection (qt 13)
    void connClose();
    bool connOpen();
    //end of addition
    //Moved from private to public - 19 May 2015 @ 22:18 (qt 8/13)
    QSqlDatabase freshstopdb;
    // end of addition


private slots:
    void on_btnLogin_clicked();

private:
    Ui::Login *ui;
    //added 19 May 2015 @ 21:24 (qt 8)
    //QSqlDatabase freshstopdb;
    // end of addition
    //CsvReader *NewCSVreader;
};

#endif // LOGIN_H
