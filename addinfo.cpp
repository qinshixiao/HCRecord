#include "addinfo.h"

AddInfo::AddInfo(QWidget *parent) :
    QDialog(parent)
{
   this->setWindowFlags(Qt::FramelessWindowHint);
   this->setMinimumSize(985,680);
   this->setMaximumSize(985,680);
   this->setStyleSheet("background-image:url(:/images/images/addbk.jpg)");

   nameLineEdit=new QLineEdit(this);
   sexLineEdit=new QLineEdit(this);
   birthYearLineEdit=new QLineEdit(this);
   birthdayLineEdit=new QLineEdit(this);
   QQLineEdit=new QLineEdit(this);
   phoneLineEdit=new QLineEdit(this);

   schoolLineEdit=new QLineEdit(this);
   subjectLineEdit=new QLineEdit(this);
   jobLineEdit=new QLineEdit(this);
   typeLineEdit=new QLineEdit(this);
   provinceLineEdit=new QLineEdit(this);
   cityLineEdit=new QLineEdit(this);
   countyLineEdit=new QLineEdit(this);
   detailAddressLineEdit=new QLineEdit(this);
   nowHomeLineEdit=new QLineEdit(this);

   introductionText=new QTextEdit(this);

   //基本信息
   nameLineEdit->setGeometry(200,26,110,40);
   nameLineEdit->setFrame(false);
   nameLineEdit->setStyleSheet(lineEditStyle);
   sexLineEdit->setGeometry(170,66,40,40);
   sexLineEdit->setFrame(false);
   sexLineEdit->setStyleSheet(lineEditStyle);
   birthYearLineEdit->setGeometry(175,106,80,40);
   birthYearLineEdit->setFrame(false);
   birthYearLineEdit->setStyleSheet(lineEditStyle);
   birthdayLineEdit->setGeometry(110,149,80,40);
   birthdayLineEdit->setFrame(false);
   birthdayLineEdit->setStyleSheet(lineEditStyle);

   //联系方式
   QQLineEdit->setGeometry(570,42,180,40);
   QQLineEdit->setFrame(false);
   QQLineEdit->setStyleSheet(lineEditStyle);
   phoneLineEdit->setGeometry(600,84,180,40);
   phoneLineEdit->setFrame(false);
   phoneLineEdit->setStyleSheet(lineEditStyle);

   //教育状况
   schoolLineEdit->setGeometry(470,190,350,40);
   schoolLineEdit->setFrame(false);
   schoolLineEdit->setStyleSheet(lineEditStyle);
   subjectLineEdit->setGeometry(470,230,350,40);
   subjectLineEdit->setFrame(false);
   subjectLineEdit->setStyleSheet(lineEditStyle);
   jobLineEdit->setGeometry(470,270,350,40);
   jobLineEdit->setFrame(false);
   jobLineEdit->setStyleSheet(lineEditStyle);

   //家庭住址
   provinceLineEdit->setGeometry(125,475,200,40);
   provinceLineEdit->setFrame(false);
   provinceLineEdit->setStyleSheet(lineEditStyle);
   cityLineEdit->setGeometry(125,515,200,40);
   cityLineEdit->setFrame(false);
   cityLineEdit->setStyleSheet(lineEditStyle);
   countyLineEdit->setGeometry(125,555,200,40);
   countyLineEdit->setFrame(false);
   countyLineEdit->setStyleSheet(lineEditStyle);
   detailAddressLineEdit->setGeometry(177,595,250,40);
   detailAddressLineEdit->setFrame(false);
   detailAddressLineEdit->setStyleSheet(lineEditStyle);
   nowHomeLineEdit->setGeometry(167,635,390,40);
   nowHomeLineEdit->setFrame(false);
   nowHomeLineEdit->setStyleSheet("QLineEdit{background-image:url(:/images/images/lineEditbk.png);background-color:rgba(255,255,255,0%);font-size:18px;}");

   //我的关系
   typeLineEdit->setGeometry(330,395,110,40);
   typeLineEdit->setFrame(false);
   typeLineEdit->setStyleSheet(lineEditStyle);

   addInfoBtn=new QPushButton(tr("录入"),this);
   updateBtn=new QPushButton(tr("更新"),this);
   updateBtn->hide();
   addInfoBtn->setEnabled(false);
   cannelBtn=new QPushButton(tr("取消"),this);
   addInfoBtn->setGeometry(20,200,50,40);
   updateBtn->setGeometry(20,265,50,40);
   cannelBtn->setGeometry(20,330,50,40);
   addInfoBtn->setStyleSheet("QPushButton{background-image:url(:/images/images/transparent.png);border-radius:20px;outline:none;background-color:rgba(255,255,255,20%)}\
                        QPushButton:hover{background-color:rgba(255,255,255,50%)}");
   updateBtn->setStyleSheet("QPushButton{background-image:url(:/images/images/transparent.png);border-radius:20px;outline:none;background-color:rgba(255,255,255,20%)}\
                            QPushButton:hover{background-color:rgba(255,255,255,50%)}");
   cannelBtn->setStyleSheet("QPushButton{background-image:url(:/images/images/transparent.png);border-radius:20px;outline:none;background-color:rgba(255,255,255,20%)}\
                            QPushButton:hover{background-color:rgba(255,255,255,50%)}");
   //说点什么吧
   introductionText->setGeometry(610,340,370,330);
   introductionText->setAttribute(Qt::WA_TranslucentBackground,true);//设置透明
   introductionText->setStyleSheet("background-color:rgba(255,255,255,0%);font-size:30px;font-family:楷体;");

   connect(addInfoBtn,SIGNAL(clicked()),this,SLOT(addInfo()));
   connect(updateBtn,SIGNAL(clicked()),this,SLOT(updateInfo()));
   connect(cannelBtn,SIGNAL(clicked()),this,SLOT(closeWindow()));
   connect(nameLineEdit,SIGNAL(textChanged(QString)),this,SLOT(enableAddInfoBtn(const QString &)));
}

void AddInfo::addInfo()
{
    QSqlDatabase peopledatabase = QSqlDatabase::database("people_Database");
    QSqlQuery query(peopledatabase);
    QSqlDatabase detailInfodatabase = QSqlDatabase::database("detailInfo_Database");
    QSqlQuery query2(detailInfodatabase);
    query.exec(QString("select * from person where 姓名='%1'").arg(nameLineEdit->text()));
    if(!query.next())
    {

        query.prepare("INSERT INTO person(姓名,性别,出生年份,生日,电话,QQ,学校,专业,工作,省份,城市,县区,详细地址,类型) VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
        query2.prepare("insert into detailInfo(姓名,现居地,个人简介) values(?,?,?)");

        QVariantList names;
        names << nameLineEdit->text();
        query.addBindValue(names);
        query2.addBindValue(names);
        QVariantList sexs;
        sexs << sexLineEdit->text();
        query.addBindValue(sexs);

        QVariantList birthYears;
        birthYears << birthYearLineEdit->text();
        query.addBindValue(birthYears);

        QVariantList birthdays;
        birthdays << birthdayLineEdit->text();
        query.addBindValue(birthdays);

        QVariantList phones;
        phones <<phoneLineEdit->text();
        query.addBindValue(phones);

        QVariantList QQs;
         QQs << QQLineEdit->text();
        query.addBindValue(QQs);

        QVariantList schools;
        schools << schoolLineEdit->text();
        query.addBindValue(schools);

        QVariantList subjects;
        subjects << subjectLineEdit->text();
        query.addBindValue(subjects);

        QVariantList jobs;
        jobs << jobLineEdit->text();
        query.addBindValue(jobs);

        QVariantList provinces;
        provinces << provinceLineEdit->text();
        query.addBindValue(provinces);

        QVariantList citys;
        citys << cityLineEdit->text();
        query.addBindValue(citys);

        QVariantList countys;
        countys << countyLineEdit->text();
        query.addBindValue(countys);

        QVariantList detailAddress;
        detailAddress << detailAddressLineEdit->text();
        query.addBindValue(detailAddress);

        QVariantList types;
        types << typeLineEdit->text();
        query.addBindValue(types);

        QVariantList nowHomes;
        nowHomes << nowHomeLineEdit->text();
        query2.addBindValue(nowHomes);

        QVariantList instructions;
        instructions <<introductionText->toPlainText();
        query2.addBindValue(instructions);

        query.execBatch();
        query.finish();
        query2.execBatch();
        query2.finish();
        int flag=QMessageBox::information(this,"提示","录入信息成功，可点击主界面的查询按钮进行更新，是否继续录入信息？",QMessageBox::Yes|QMessageBox::No);
        if(flag==QMessageBox::Yes)
            this->show();
        else
            this->close();
        clearLineEdit();
    }
    else
        QMessageBox::critical(this,"提示","对不起，录入信息失败,检测到该人已经存在,系统拒绝重复添加，请重新命名后继续录入！");
}
//更新信息
void AddInfo::updateInfo()
{
    nameLineEdit->setEnabled(true);
    QSqlDatabase peopledatabase = QSqlDatabase::database("people_Database");
    QSqlQuery query(peopledatabase);
    QSqlDatabase detailInfodatabase = QSqlDatabase::database("detailInfo_Database");
    QSqlQuery query2(detailInfodatabase);
    query.prepare(QString("update person set 性别=?,出生年份=?,生日=?,电话=?,QQ=?,学校=?,专业=?,工作=?,省份=?,城市=?,县区=?,详细地址=?,类型=? where id=%1").arg(index.data().toString()));
    query2.prepare(QString("update detailInfo set 现居地=?,个人简介=? where id=%1").arg(index.data().toString()));
    QVariantList sexs;
    sexs << sexLineEdit->text();
    query.addBindValue(sexs);

    QVariantList birthYears;
    birthYears << birthYearLineEdit->text();
    query.addBindValue(birthYears);

    QVariantList birthdays;
    birthdays << birthdayLineEdit->text();
    query.addBindValue(birthdays);

    QVariantList phones;
    phones <<phoneLineEdit->text();
    query.addBindValue(phones);

    QVariantList QQs;
     QQs << QQLineEdit->text();
    query.addBindValue(QQs);

    QVariantList schools;
    schools << schoolLineEdit->text();
    query.addBindValue(schools);

    QVariantList subjects;
    subjects << subjectLineEdit->text();
    query.addBindValue(subjects);

    QVariantList jobs;
    jobs << jobLineEdit->text();
    query.addBindValue(jobs);

    QVariantList provinces;
    provinces << provinceLineEdit->text();
    query.addBindValue(provinces);

    QVariantList citys;
    citys << cityLineEdit->text();
    query.addBindValue(citys);

    QVariantList countys;
    countys << countyLineEdit->text();
    query.addBindValue(countys);

    QVariantList detailAddress;
    detailAddress << detailAddressLineEdit->text();
    query.addBindValue(detailAddress);

    QVariantList types;
    types << typeLineEdit->text();
    query.addBindValue(types);

    QVariantList nowHomes;
    nowHomes << nowHomeLineEdit->text();
    query2.addBindValue(nowHomes);

    QVariantList instructions;
    instructions <<introductionText->toPlainText();
    query2.addBindValue(instructions);

    query.execBatch();
    query.finish();
    query2.execBatch();
    query2.finish();

    QMessageBox::information(this,"提示","更新成功！");
    clearLineEdit();
    this->close();
}

void AddInfo::enableAddInfoBtn(const QString &text)
{
    addInfoBtn->setEnabled(!text.isEmpty());//如果姓名输入框不为空，则ok键亮起，允许录入信息
}

void AddInfo:: mousePressEvent (QMouseEvent *e)
{
    last = e->globalPos();
}

void AddInfo:: mouseMoveEvent (QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx,y()+dy);
}

void AddInfo:: mouseReleaseEvent (QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}
//弹出更新对话框，并接收主界面传来的要显示在对话框上各lineEdit上的值
void AddInfo:: showUpdateInfo(QString &introduction,QString &name,QString &sex,QString &phone,QString &QQ,QString &school,QString &subject,QString &job,QString &nowHome, QString &detail,QString &province,QString &city,QString &county,QString &birthYear,QString &birthday,QString &type)
{
    addInfoBtn->hide();
    updateBtn->show();
    nameLineEdit->setText(name);
    nameLineEdit->setEnabled(false);//姓名不允许修改
    sexLineEdit->setText(sex);

    phoneLineEdit->setText(phone);
    QQLineEdit->setText(QQ);
    schoolLineEdit->setText(school);
    subjectLineEdit->setText(subject);
    jobLineEdit->setText(job);
    nowHomeLineEdit->setText(nowHome);
    provinceLineEdit->setText(province);
    cityLineEdit->setText(city);
    countyLineEdit->setText(county);
    detailAddressLineEdit->setText(detail);
    birthYearLineEdit->setText(birthYear);
    birthdayLineEdit->setText(birthday);
    typeLineEdit->setText(type);
    introductionText->setText(introduction);
    this->exec();
}

void AddInfo::closeWindow()
{
    addInfoBtn->show();
    updateBtn->hide();
    clearLineEdit();
    nameLineEdit->setEnabled(true);
    this->close();//close只是隐藏了窗口

}

void AddInfo::recModelIndex(QModelIndex index)
{
    this->index=index;
}

void AddInfo::clearLineEdit()
{
    nameLineEdit->clear();
    sexLineEdit->clear();
    birthYearLineEdit->clear();
    birthdayLineEdit->clear();
    phoneLineEdit->clear();
    QQLineEdit->clear();
    schoolLineEdit->clear();
    subjectLineEdit->clear();
    jobLineEdit->clear();
    typeLineEdit->clear();
    provinceLineEdit->clear();
    cityLineEdit->clear();
    countyLineEdit->clear();
    detailAddressLineEdit->clear();
    nowHomeLineEdit->clear();
    introductionText->clear();
}
