#include <loginform.h>

mainform::mainform(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1000, 800);

    displaytext = new QTextBrowser(this);
    displaytext->move(450, 50);
    displaytext->resize(500, 450);
    displaytext->setStyleSheet("QTextBrowser{border:2px solid #242424;}");

    input = new QTextEdit(this);
    input->move(450, 520);
    input->resize(500, 80);
    input->setStyleSheet("QTextEdit{border:2px solid #242424;}");

    playername = new QLabel(this);
    playername->move(180, 50);
    playername->resize(80, 30);
    playername->setStyleSheet("QLabel{background:#FFFAFA;border:5px solid #242424;font-family:SimHei}");

    sendp = new QPushButton(this);
    sendp->move(850, 620);
    sendp->resize(100, 50);
    sendp->setText(tr("发送"));
    connect(sendp, &QPushButton::clicked, this, &mainform::send);

    next = new QPushButton(this);
    next->move(700, 620);
    next->resize(100, 50);
    next->setText(tr("继续"));

    night = new QLabel(this);
    night->move(0, 0);
    night->resize(60, 60);


    listWidget = new QListWidget(this);
    listWidget->show();
    listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    listWidget->resize(200, 300);
    listWidget->move(70, 420);
    listWidget->setStyleSheet("QListWidget{border:2px solid #242424;}QListWidget::item:hover{background:#fbf588;}");
    connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(tp1(QListWidgetItem*)));

    image = new QLabel(this);
    image->move(70, 100);
    image->resize(300,300);
    image->setStyleSheet("QLabel{border:5px solid #242424;}");
    connect(next, &QPushButton::clicked, this, &mainform::change);

    openeyes = new QPushButton(this);
    openeyes->setText("睁眼");
    openeyes->move(400, 620);
    openeyes->resize(100, 50);
    connect(openeyes, &QPushButton::clicked, this, &mainform::zhengyan);

    notopeneyes = new QPushButton(this);
    notopeneyes->setText("不睁眼");
    notopeneyes->move(550, 620);
    notopeneyes->resize(100, 50);
    connect(notopeneyes, &QPushButton::clicked, this, &mainform::notzhengyan);

    ch = new choosehead();
    connect(ch, SIGNAL(headnum(int)), this, SLOT(changehead(int)));

    savegame = new QPushButton(this);
    savegame->move(400, 700);
    savegame->resize(100, 50);
    savegame->setText("存档");
    connect(savegame, &QPushButton::clicked, this, &mainform::SaveGame);


}

void mainform::start()
{
    QVector<int> tempint;
    for(int i = 0;i < number;i++){
        tempint.push_back(i + 1);
    }

    std::random_shuffle(tempint.begin(), tempint.end());   //随机数分配

    for(int i = 0;i < number;i++){
        player temp;
        p.push_back(temp);
        p[i].number = i;
        p[i].identitynum = tempint[i];
        p[i].img = new QImage;
        p[i].img->load(":/images/平民.jpg");
        if(p[i].identitynum % 2 == 0)
            p[i].identity = "红牌";
        else p[i].identity = "黑牌";
    }
    image->setPixmap(QPixmap::fromImage(*p[0].img));

    temp = p;

    image->setVisible(false);
    notopeneyes->setVisible(false);
    listWidget->setVisible(false);
    playername->setVisible(false);
    openeyes->setVisible(false);

}

void mainform::start2()
{
    for(int i = 0;i < temp.size();i++){
        if(temp[i].identitynum % 2 == 0){
            temp[i].identity = "红牌";
        }
        else temp[i].identity = "黑牌";
        if(!temp[i].life)
            temp[i].img->load(":/images/死亡.jpg");
        else if(temp[i].head)
            temp[i].img->load(":/images/村长.jpg");
        else temp[i].img->load(":/images/平民.jpg");
    }
    for(int i = 0;i < p.size();i++){
        if(p[i].identitynum % 2 == 0){
            p[i].identity = "红牌";
        }
        else p[i].identity = "黑牌";
        if(!p[i].life)
            p[i].img->load(":/images/死亡.jpg");
        else if(p[i].head)
            p[i].img->load(":/images/村长.jpg");
        else p[i].img->load(":/images/平民.jpg");
    }
    switch(stage){
    case 1:{
        break;
    }
    case 2:{
        image->setPixmap(QPixmap::fromImage(*temp[index].img));
        playername->setText(QString("%1号玩家").arg(temp[index].number + 1));
        listWidget->clear();
        image->setPixmap(QPixmap::fromImage(*temp[index].img));
        QString s = QString("%1号玩家").arg(temp[index].number + 1);
        playername->setText(s);
        for(int i = 0;i < temp.size();i++){
            QListWidgetItem *item = new QListWidgetItem;
            item->setText(QString("%1号玩家").arg(temp[i].number + 1));
            item->setTextAlignment(Qt::AlignCenter);
            item->setSizeHint(QSize(60,50));
            listWidget->addItem(item);
            map[item->text()] = temp[i].number;
        }
        break;
    }
    case 3:{
        image->setPixmap(QPixmap::fromImage(*temp[index].img));
        playername->setText(QString("%1号玩家").arg(temp[index].number + 1));
        break;
    }
    case 4:{
        image->setPixmap(QPixmap::fromImage(*p[n].img));
        playername->setText(QString("%1号玩家").arg(p[n].number + 1));
        break;
    }
    }

}

void mainform::send()
{
    if(n == 0 && index == 0){
        input->clear();
        return;
    }

    int n1 = n;
    switch (rol) {
    case true:
        if(n1 == TotalNumber - 1){
            n1 = 0;
        }
        else{
            n1++;
        }
        break;
    case false:
        if(n1 == 0){
            n1 = TotalNumber - 1;
        }
        else{
            n1--;
        }
        break;
    }

    QString tempstring = input->toPlainText();
    QString tn = QString("%1号玩家").arg(p[n1].number + 1);
    input->clear();
    displaytext->append("[" + tn + "]");
    displaytext->append(tempstring);
    displaytext->append("\n");
}


void mainform::judge(QVector<player> p)
{
    countred = 0, countblack = 0;
    for(int i = 0;i < p.size();i++){
        if(!p[i].life)
            continue;
        if(p[i].identity == "红牌"){
            countred++;
        }
        else{
            countblack++;
        }
    }
    if(countblack == 0){
        QMessageBox::about(this, tr("提示"), tr("红牌胜利"));
        finish =true;
    }
    if(countred == 0){
        QMessageBox::about(this, tr("提示"), tr("黑牌胜利"));
        finish =true;
    }
}



void mainform::toupiao(QListWidget *listWidget)
{
    stage = 2;
    listWidget->clear();
    image->setPixmap(QPixmap::fromImage(*temp[0].img));
    QString s = QString("%1号玩家").arg(temp[0].number + 1);
    playername->setText(s);

    next->setVisible(false);

    for(int i = 0;i < temp.size();i++){
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(QString("%1号玩家").arg(temp[i].number + 1));
        item->setTextAlignment(Qt::AlignCenter);
        item->setSizeHint(QSize(60,50));
        listWidget->addItem(item);
        map[item->text()] = temp[i].number;
    }
    index = 0;

    listWidget->setVisible(true);
    sendp->setVisible(false);

}

void mainform::zhengyan()
{
    opennumber++;
    index++;
    if(index == number){
        QMessageBox *msgbox = new QMessageBox();
        msgbox->setText("天亮了，村长请选择发言顺序");
        night->setVisible(false);
        msgbox->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        msgbox->button(QMessageBox::Yes)->setText("左侧");
        msgbox->button(QMessageBox::No)->setText("右侧");
        int result=msgbox->exec();
        if(result == QMessageBox::Yes){
            n = headnumber == 0 ?  TotalNumber - 1 : headnumber - 1;
            rol = false;
        }
        else{
            n = headnumber == TotalNumber - 1 ? 0 : headnumber + 1;
            rol = true;
        }


        next->setVisible(true);
        openeyes->setVisible(false);
        notopeneyes->setVisible(false);

        index = 0;

        image->setVisible(false);
        playername->setVisible(false);
        sendp->setVisible(false);


    }
    else{
        image->setPixmap(QPixmap::fromImage(*temp[index].img));
        QString s = QString("%1号玩家").arg(temp[index].number + 1);
        playername->setText(s);
    }
}

void mainform::notzhengyan()
{
    index++;

    if(index == number){
        QMessageBox *msgbox = new QMessageBox();
        msgbox->setText("天亮了，村长请选择发言顺序");
        night->setVisible(false);
        msgbox->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        msgbox->button(QMessageBox::Yes)->setText("左侧");
        msgbox->button(QMessageBox::No)->setText("右侧");
        int result=msgbox->exec();
        if(result == QMessageBox::Yes){
            n = headnumber == 0 ?  TotalNumber - 1 : headnumber - 1;
            rol = false;
        }
        else{
            n = headnumber == TotalNumber - 1 ? 0 : headnumber + 1;
            rol = true;
        }


        next->setVisible(true);
        openeyes->setVisible(false);
        notopeneyes->setVisible(false);

        index = 0;

        image->setVisible(false);
        playername->setVisible(false);
        sendp->setVisible(false);
    }
    else{
        image->setPixmap(QPixmap::fromImage(*temp[index].img));
        QString s = QString("%1号玩家").arg(temp[index].number + 1);
        playername->setText(s);
    }
}

void mainform::change()
{

    if(index == TotalNumber){
        index = 0;
        day++;
        if(day == 1){
            index = TotalNumber;
            QMessageBox::about(this, tr("提示"), tr("开始投票选择村长"));
            toupiao(listWidget);
        }
        else if(!isnight){
            QMessageBox::about(this, tr("提示"), tr("开始投票"));
            isnight = true;
            toupiao(listWidget);
        }
        else{
            isnight = false;

            QVector<int> tempint;
            for(int i = 0;i < 2;i++){
                tempint.push_back(i + 1);
            }
            std::random_shuffle(tempint.begin(), tempint.end()); //随机进入夜晚
            stage = 3;
            nightcolor = tempint[0];


            if(tempint[0] == 1){
                boolnight = false;
                QMessageBox::about(this, tr("提示"), tr("进入黑夜"));
                image->setPixmap(QPixmap::fromImage(*temp[0].img));
                image->setVisible(true);
                QString s = QString("%1号玩家").arg(temp[0].number + 1);
                playername->setText(s);
                playername->setVisible(true);
                QPixmap *pixmap = new QPixmap(":/images/黑月.jpg");
                pixmap->scaled(night->size(), Qt::KeepAspectRatio);
                night->setScaledContents(true);
                night->setPixmap(*pixmap);
                night->setVisible(true);
                openeyes->setVisible(true);
                notopeneyes->setVisible(true);
                next->setVisible(false);
            }
            else{
                QMessageBox::about(this, tr("提示"), tr("进入红夜"));
                image->setPixmap(QPixmap::fromImage(*temp[0].img));
                image->setVisible(true);
                QString s = QString("%1号玩家").arg(temp[0].number + 1);
                playername->setText(s);
                playername->setVisible(true);
                openeyes->setVisible(true);
                QPixmap *pixmap = new QPixmap(":/images/红月.jpg");
                pixmap->scaled(night->size(), Qt::KeepAspectRatio);
                night->setScaledContents(true);
                night->setPixmap(*pixmap);
                night->setVisible(true);
                notopeneyes->setVisible(true);
                next->setVisible(false);
                boolnight = true;
            }
        }
    }
    else{
        stage = 4;
        image->setVisible(true);
        sendp->setVisible(true);
        playername->setVisible(true);
        image->setPixmap(QPixmap::fromImage(*p[n].img));
        QString s = QString("%1号玩家").arg(p[n].number + 1);
        playername->setText(s);
        if(!p[n].life){
            QString temp = QString("系统：%1号玩家已死亡").arg(n + 1);
            displaytext->append(temp);
        }

        switch (rol) {
        case true:
            if(n == 0){
                n = TotalNumber - 1;
            }
            else{
                n--;
            }
            break;
        case false:
            if(n == TotalNumber - 1){
                n = 0;
            }
            else{
                n++;
            }
            break;
        }
        index++;
    }
}

void mainform::headchange(int maxnumber)
{
    ch->listwidget->clear();
    ch->p = temp;
    ch->p.erase(ch->p.begin() + maxnumber);

    for(int i = 0;i < ch->p.size();i++){
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(QString("%1号玩家").arg(ch->p[i].number + 1));
        item->setTextAlignment(Qt::AlignCenter);
        item->setSizeHint(QSize(60,30));
        ch->listwidget->addItem(item);
        ch->map[item->text()] = ch->p[i].number;
    }

    ch->show();

}

void mainform::changehead(int a)
{
    headnumber = a;
    p[a].head = true;
    p[a].img->load(":/images/村长.jpg");
    ch->close();

    QMessageBox *msgbox = new QMessageBox();
    msgbox->setText("新村长请选择发言顺序");
    night->setVisible(false);
    msgbox->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    msgbox->button(QMessageBox::Yes)->setText("左侧");
    msgbox->button(QMessageBox::No)->setText("右侧");
    int result=msgbox->exec();
    if(result == QMessageBox::Yes){
        n = headnumber == 0 ? TotalNumber : headnumber - 1;
        rol = false;
    }
    else{
        n = headnumber == TotalNumber ? 1 : headnumber + 1;
        rol = true;
    }

    index = 0;
}

void mainform::tp1(QListWidgetItem *item)
{
    int equal = 0;

    for(int i = 0;i < temp.size();i++){
            if(temp[i].number == map[item->text()])
                temp[i].ballot++;
            if(day != 1){
                if(boolnight && opennumber % 2 != 0 && temp[index].head == true){
                    switch (TotalNumber % 2) {
                    case 0:
                        temp[i].ballot += 0.5;
                        break;
                    case 1:
                        temp[i].ballot -= 0.5;
                        break;
                    }
                }
                if(!boolnight && opennumber % 2 != 0 && temp[index].head == true){
                    switch (TotalNumber % 2) {
                    case 0:
                        temp[i].ballot += 0.5;
                        break;
                    case 1:
                        temp[i].ballot -= 0.5;
                        break;
                    }
                }
            }
        }

        index++;

        if(index == number){
            index = 0;

            QMessageBox::about(this, tr("提示"), tr("投票结束"));
            sendp->setVisible(true);
            listWidget->setVisible(false);
            playername->clear();
            image->setVisible(false);
            playername->setVisible(false);

            int maxnumber;
            if(day == 1){
                maxnumber = 0;
                int max =temp[0].ballot;
                for(int j = 0;j < temp.size();j++){
                    if(temp[j].ballot > max){
                        maxnumber = j;
                        max = temp[j].ballot;
                    }
                }
                for(int j = 0;j < temp.size();j++){
                    if(temp[j].ballot == max)
                        equal++;
                }
                if(equal >= 2){
                    QMessageBox::about(this, tr("提示"), tr("票数相同，请重新发言后进行投票！"));
                    isnight =false;
                    day = 0;
                    next->setVisible(true);
                    listWidget->clear();
                    return;
                }

                temp[maxnumber].head = true;
                temp[maxnumber].img->load(":/images/村长.jpg");
                QMessageBox::about(this, tr("提示"), QString("%1号玩家成为村长").arg(temp[maxnumber].number + 1));
                sendp->setVisible(false);
                headnumber = temp[maxnumber].number;
                isnight = true;
                index = TotalNumber;
                next->setVisible(true);
                listWidget->clear();

            }
            else{
                maxnumber = 0;
                int max =temp[0].ballot;
                for(int j = 0;j < temp.size();j++){
                    if(temp[j].ballot > max){
                        maxnumber = j;
                        max = temp[j].ballot;
                    }
                }
                for(int j = 0;j < temp.size();j++){
                    if(temp[j].ballot == max)
                        equal++;
                }
                if(equal >= 2){
                    QMessageBox::about(this, tr("提示"), tr("票数相同，请重新投票！"));
                    next->setVisible(true);
                    day--;
                    isnight = false;
                    listWidget->clear();
                    return;
                }

                QMessageBox::about(this, tr("提示"), QString("%1号玩家死亡").arg(temp[maxnumber].number + 1));
                sendp->setVisible(false);
                p[temp[maxnumber].number].life = false;
                p[temp[maxnumber].number].img->load(":/images/死亡.jpg");
                if(temp[maxnumber].number == headnumber){
                    judge(p);
                    if(!finish){
                        headchange(maxnumber);
                    }
                }

                next->setVisible(true);
                temp.erase(temp.begin() + maxnumber);
                number--;
                listWidget->clear();
                map.clear();
                if(!finish)
                    judge(p);

            }

            for(int j = 0;j < temp.size();j++){
                temp[j].ballot = 0;
            }
        }
        else{
            playername->setText(QString("%1号玩家").arg(temp[index].number + 1));
            image->setPixmap(QPixmap::fromImage(*temp[index].img));
        }
}

void mainform::SaveGame()
{

    Save save;
    save.stage = stage;
    save.TotalNumber = number;
    save.number = number;
    save.sendp = !sendp->isHidden();
    save.next = !next->isHidden();
    save.night = night;
    save.nightcolor = nightcolor;
    save.listWidget = !listWidget->isHidden();
    save.image = !image->isHidden();
    save.openeyes = !openeyes->isHidden();
    save.notopeneyes = !notopeneyes->isHidden();
    save.playername = !playername->isHidden();
    save.boolnight = boolnight;  //红true，黑false
    save.index = index;
    save.day = day;
    save.isnight = isnight;
    save.map = map;
    save.opennumber = opennumber;
    save.n = n;
    save.headnumber = headnumber;
    save.rol = rol; //tr,fl
    save.countred = countred;
    save.countblack = countblack;
    save.finish = finish;

    QString path1 = QDir::currentPath();
    int i = 1;
    while(1){
        QString path2 = QString("/save%1.txt").arg(i);
        QString fullpath = path1 + path2;
        QFileInfo fileInfo(fullpath);
        if(fileInfo.isFile()){
            i++;
            continue;
        }
        else{
            break;
        }
    }
    path1 += QString("/save%1.txt").arg(i);
    QFile file(path1);
    file.open(QIODevice::WriteOnly);
    file.close();
    if (!file.open(QIODevice::WriteOnly)){
        qDebug()<< "Cannot open file for writing: "
                  <<qPrintable(file.errorString());
        return;
    }
    else{
        QDataStream out(&file);
        out<<save;
        out<<p.size();
        for(int i = 0;i < p.size();i++){
            player temp = p[i];
            out<<temp;
        }
        out<<temp.size();
        for(int i = 0;i < temp.size();i++){
            player temp1 = temp[i];
            out<<temp1;
        }
        QMessageBox::about(this, tr("提示"), tr("save%1存档成功").arg(i));
        file.close();
    }
}
