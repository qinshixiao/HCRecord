#ifndef CREATEDATEBASE_H
#define CREATEDATEBASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

static bool createConnection()
{
    QSqlDatabase peopleDatabase= QSqlDatabase::addDatabase("QSQLITE","people_Database");
    QSqlDatabase detailInfoDatabase= QSqlDatabase::addDatabase("QSQLITE","detailInfo_Database");
    peopleDatabase.setDatabaseName("people.db");
    detailInfoDatabase.setDatabaseName("detailInfo.db");

    qDebug()<<"people.db创建"<<peopleDatabase.open();
    qDebug()<<"detailInfo.db创建"<<detailInfoDatabase.open();
    if (!peopleDatabase.open()&&!detailInfoDatabase.open())
    {
        QMessageBox::critical(NULL, "提示", "连接档案信息库失败，请检查后重新连接！", QMessageBox::Cancel);
        return false;
    }

    QMessageBox::critical(NULL, "提示", "连接档案信息库成功！", QMessageBox::Cancel);
    QSqlQuery query(peopleDatabase);
    QSqlQuery query2(detailInfoDatabase);
    query.exec("CREATE TABLE person(id INTEGER primary key AUTOINCREMENT, 姓名 varchar(8), 性别 varchar(2),出生年份 char(4),生日 char(4),电话 char(11),QQ varchar(12),学校 varchar(30),专业 varchar(30),工作 varchar(30),省份 varchar(8),城市 varchar(20),县区 varchar(20),详细地址 varchar(30),类型 varchar(10))");
    query2.exec("create table detailInfo(id INTEGER primary key AUTOINCREMENT,姓名 varchar(8),现居地 varchar(50),个人简介 varchar(200))");
    return true;
}

#endif // CREATEDATEBASE_H
