#ifndef ADDINFO_H
#define ADDINFO_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTextEdit>
#include <QString>
#include <QDebug>
#include <QVariantList>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPoint>
#include <QModelIndex>
#include <QSqlQueryModel>


#define lineEditStyle "QLineEdit{background-image:url(:/images/images/lineEditbk.png);background-color:rgba(255,255,255,0%);font-size:25px;}"
class AddInfo : public QDialog
{
    Q_OBJECT
public:
    explicit AddInfo(QWidget *parent = 0);
    //接收主界面从数据库更新操作中查询到的信息，并显示在添加窗口上，实现更新信息
    void showUpdateInfo(QString &introduction, QString &name,QString &sex,QString &phone,QString &QQ,QString &school,QString &subject,QString &job,QString &nowHome, QString &detail,QString &province,QString &city,QString &county,QString &birthYear,QString &birthday,QString &type);

signals:
protected:
    //鼠标按下
    void  mousePressEvent (QMouseEvent *e);
    //鼠标移动
    void  mouseMoveEvent (QMouseEvent *e);
    //鼠标释放
    void  mouseReleaseEvent (QMouseEvent *e);

public slots:
    //接收从主界面更新操作中传来的index
    void recModelIndex(QModelIndex index);

private:
    QModelIndex index;

    QLineEdit *nameLineEdit;
    QLineEdit *sexLineEdit;
    QLineEdit *phoneLineEdit;
    QLineEdit *QQLineEdit;
    QLineEdit *schoolLineEdit;
    QLineEdit *subjectLineEdit;
    QLineEdit *jobLineEdit;
    QLineEdit *nowHomeLineEdit;
    QLineEdit *detailAddressLineEdit;
    QLineEdit *provinceLineEdit;
    QLineEdit *cityLineEdit;
    QLineEdit *countyLineEdit;
    QLineEdit *birthYearLineEdit;
    QLineEdit *birthdayLineEdit;
    QLineEdit *typeLineEdit;

    QTextEdit *introductionText;

    QPushButton *addInfoBtn;
    QPushButton *updateBtn;
    QPushButton *cannelBtn;

    QGridLayout *mainLayout;

    QPoint last;


    void clearLineEdit();
private slots:

    //确定录入按钮是否允许使用
    void enableAddInfoBtn(const QString &text);
    //添加信息
    void addInfo();
    void updateInfo();
    void closeWindow();

};

#endif // ADDINFO_H
