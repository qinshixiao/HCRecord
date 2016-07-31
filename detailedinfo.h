#ifndef DETAILEDINFO_H
#define DETAILEDINFO_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QTextBrowser>
#include <QMouseEvent>
#include <QSqlQuery>

class DetailedInfo : public QDialog
{
    Q_OBJECT
public:
    explicit DetailedInfo(QWidget *parent = 0);
    void showImage(int id);//显示图片
    void showInfo(int id);//显示个人信息
    void showIntroduction(int id);//显示个人简介

    QPushButton *exitBtn;

protected:
    //鼠标按下
    void  mousePressEvent (QMouseEvent *e);
    //鼠标移动
    void  mouseMoveEvent (QMouseEvent *e);
    //鼠标释放
    void  mouseReleaseEvent (QMouseEvent *e);

signals:

public slots:
private:
    int IndexImages=1;//当前显示图片序号

    QString name;
    QString ID;

    QSqlQuery query;

    QLabel *infoLabel;
    QLabel *imageLabel;
    QLabel *introductionLabel;
    QTextBrowser *introductionText;

    QPoint last;

    void switchImages();//切换图片

private slots:
    void exitDetailedInfo();

};

#endif // DETAILEDINFO_H
