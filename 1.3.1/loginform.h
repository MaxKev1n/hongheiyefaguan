#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <headers.h>
#include <player.h>



class mainform : public QMainWindow
{
    Q_OBJECT
public:
    explicit mainform(QWidget *parent = 0);
    int number = 0;
    QVector<player> p;
    QVector<player> temp;
    int tempnumber = number;
    void start();

private:
    QTextEdit *input;
    QPushButton *startp;
    QTextBrowser *displaytext;
    QPushButton *sendp;
    QPushButton *next;
    QLabel *night;
    QString nightcolor;
    QListWidget *listWidget;
    QLabel *image;
    QPushButton *openeyes;
    QPushButton *notopeneyes;
    QLabel *playername;
    bool boolnight = false;  //红true，黑false
    int index = 1;
    int count = 1;
    int day = 0;
    bool isnight = true;
    QMap<QString, int> map;
    int opennumber = 0;
    int n = 1;
    int headnumber = number;
    bool rol = true; //tr,fl

public slots:
    void change();
    void send();
    void zhengyan();
    void notzhengyan();
    void tp1(QListWidgetItem*);
public:
    void toupiao(QListWidget*, QVector<player>);
    void judge(QVector<player>);

};


#endif // LOGINFORM_H
