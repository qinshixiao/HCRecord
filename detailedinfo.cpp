#include "detailedinfo.h"

#include<QDebug>

DetailedInfo::DetailedInfo(QWidget *parent) :
    QDialog(parent)
{
    this->resize(800,269);
    {
    //this->setWindowFlags(Qt::FramelessWindowHint);
    //QPalette palette;
    //QPixmap pixmap=QPixmap(":/images/images/skin.png").scaled(800,400);//背景图片
    //palette.setBrush(QPalette::Background, QBrush(pixmap));
    //this->setPalette(palette);

    //this->setAttribute(Qt::WA_TintedBackground,true);
    }
    this->move(50,100);
    //去掉标题栏
    this->setWindowFlags(Qt::FramelessWindowHint);
    {
    //设置背景透明
    //this->setAttribute(Qt::WA_TranslucentBackground, true);
    //窗体添加样式，样式为CSS 样式表
    // background-image:url 添加图片
    // background-repeat:no-repeat 不平铺
    //this->setStyleSheet("background:green");
    //this->setStyleSheet("background-image:url(:/images/images/skin.png);background-repeat:no-repeat;");
    }

    infoLabel=new QLabel(this);
    //label 样式(CSS 样式表)
    //font-size 字号
    //color 字体颜色
    //font-weight 字宽
    //font-style 字体样式
    infoLabel->setStyleSheet("font-size:12px;color:black;font-weight:bold");
    infoLabel->setGeometry(20,0,300,267);

    imageLabel=new QLabel("没有照片",this);
    imageLabel->setGeometry(600,2,200,267);

    exitBtn=new QPushButton(this);
   // exitBtn->setAttribute(Qt::WA_TranslucentBackground, true);
    exitBtn->setStyleSheet("QPushButton{background-image:url(:/images/images/exitBtn.png);border-radius:10px;outline:none;}\
                           QPushButton:hover{background-color:rgba(255,0,0,50%);border-radius:10px;}");
    //exitBtn->setIcon(QPixmap(":/images/images/exitBtn.png"));
    //exitBtn->setIconSize(QPixmap(":/images/images/exitBtn.png").size());
    exitBtn->setGeometry(300,219,36,36);
    //exitBtn->setFocusPolicy(Qt::NoFocus);//设置无聚焦，避免出现虚线框
    exitBtn->setFlat(true);


   // introductionLabel=new QLabel(this);
   // introductionText=new QTextBrowser(this);
    connect(exitBtn,SIGNAL(clicked()),this,SLOT(exitDetailedInfo()));

}

void DetailedInfo::showImage(int id)
{
    QSqlDatabase peopledatabase = QSqlDatabase::database("people_Database");
    QSqlQuery query(peopledatabase);
    query.exec(QString("select * from person where id=%1").arg(ID.setNum(id)));
    query.next();
    name=query.value(1).toString();//获取这条记录的第一个属性的值，即取出name
    imageLabel->setPixmap(QPixmap(QString("images/%1%2.jpg").arg(name).arg(ID.setNum(0))).scaled(200,267,Qt::KeepAspectRatio));

   // imageLabel->resize(QPixmap(QString("images/%1.jpg").arg(name)).size());//label控件自适应图片大小
}

void DetailedInfo::showInfo(int id)
{
    QString name;
    QString sex;
    QString school;
    QString address;
    QString phone;
    QString QQ;
    QString born;
    QString job;
    QString subject;
    QString type;
    QString nowHome;
    QString introduction;
    QString ID;

    QSqlDatabase peopledatabase = QSqlDatabase::database("people_Database");
    QSqlDatabase detailInfodatabase = QSqlDatabase::database("detailInfo_Database");
    QSqlQuery query(peopledatabase);
    QSqlQuery query2(detailInfodatabase);

    query.exec(QString("select * from person where id=%1").arg(ID.setNum(id)));
    query2.exec(QString("select * from detailInfo where id=%1").arg(ID.setNum(id)));
    query.next();
    query2.next();
    name=query.value(1).toString();
    sex=query.value(2).toString();
    born=query.value(3).toString()+"年"+query.value(4).toString();
    phone=query.value(5).toString();
    QQ=query.value(6).toString();
    school=query.value(7).toString();
    subject=query.value(8).toString();
    job=query.value(9).toString();
    address=query.value(10).toString()+query.value(11).toString()+query.value(12).toString()+query.value(13).toString();
    type=query.value(14).toString();

    nowHome=query2.value(2).toString();
    introduction=query2.value(3).toString();



    infoLabel->setText(QString("姓名： %1\n\n性别： %2\n\n出生日期：%3\n\n联系方式：电话号%4 QQ号%5\n\n学校： %6\n\n专业： %7\n\n工作： %8\n\n家庭住址：%9\n\n类型：%10").arg(name).arg(sex).arg(born).arg(phone).arg(QQ).arg(school).arg(subject).arg(job).arg(address).arg(type));
}

void DetailedInfo:: mousePressEvent (QMouseEvent *e)
{
    last = e->globalPos();
}

void DetailedInfo:: mouseMoveEvent (QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx,y()+dy);
}

void DetailedInfo:: mouseReleaseEvent (QMouseEvent *e)
{
    switchImages();
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

void DetailedInfo::exitDetailedInfo()
{
    this->close();
}

void DetailedInfo::switchImages()
{
    QPixmap pix=QPixmap(QString("images/%1%2.jpg").arg(name).arg(ID.setNum(IndexImages)));
    if(!pix.isNull())
    {
        imageLabel->setPixmap(pix.scaled(200,267,Qt::KeepAspectRatio));//scaled使图片自适应控件大小
        IndexImages++;
    }
    else
    {
        imageLabel->setPixmap(QPixmap("images/end.jpg").scaled(200,267,Qt::KeepAspectRatio));
        IndexImages=0;
    }

    qDebug()<<IndexImages;
}
