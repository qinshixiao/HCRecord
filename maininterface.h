#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QBoxLayout>
#include <QComboBox>
#include <QTableView>
#include "addinfo.h"
#include "detailedinfo.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDateTime>
#include <QStringList>
#include <QDebug>
#include <QSqlQueryModel>
#include <QStackedWidget>
#include <QSpinBox>
#include <QAction>
#include <QMenu>

class  MainInterface : public QWidget
{
    Q_OBJECT

public:
    explicit MainInterface(QWidget *parent = 0);
    ~MainInterface();

protected:
    void closeEvent(QCloseEvent *event);
    //鼠标按下
    void  mousePressEvent (QMouseEvent *e);
    //鼠标移动
    void  mouseMoveEvent (QMouseEvent *e);
    //鼠标释放
    void  mouseReleaseEvent (QMouseEvent *e);

signals:
    void sendTabRowCount(int rowCount);//发送table行数
    void sendModelIndex(QModelIndex index);//发送table单元格内容
private:

    int screenFlag=1;//当前是否允许全屏的标志
    int colorFlag=0;//决定当前已显示的详细信息框的颜色
    int skinFlag=0;//决定当前界面显示的皮肤颜色

    QPoint last;

    QAction *updateAction;//修改
    QAction *deleteAction;//删除
    QAction *copyAction;//复制
    QAction *detailAction;//详细信息
    QAction *refurbishAction;//刷新

    QSqlQueryModel *Model;
    QStackedWidget *stack;
    QWidget *stackWidget1;
    QWidget *stackWidget2;

    QLabel *programnameLabel;//程序名
    QLabel *programnameLabel2;//程序标识

    //普通检索
    QPushButton *skinBtn;//皮肤
    QMenu *skinMenu;
    QAction *switchSkinAction;//切换皮肤
    QAction *customerSkinAction;//自定义皮肤
    QPushButton *narrowScreenBtn;
    QPushButton *fullScreenBtn;
    QPushButton *quitBtn;
    QPushButton *addBtn;
    QPushButton *knowBtn;//可能认识的人
    QPushButton *statisticBtn;//数据统计
    QPushButton *growUpBtn;//忧乐成长
    QPushButton *sayBtn;//说说
    QPushButton *birthdayWallBtn;//生日墙
    QPushButton *searchBtn;
    QLineEdit *searchLineEdit;
    QComboBox *typeComboBox;

    QVBoxLayout *mainLayout;
    QVBoxLayout *stkWgt1MainLayout;
    QHBoxLayout *stkWgt1Layout1;
    QHBoxLayout *stkWgt1Layout2;



    //高级检索
    QPushButton *toHighsearchBtn;
    QPushButton *highSearchBtn;
    QPushButton *backBtn;
    QLabel *sexLabel;         //性别
    QComboBox *sexComboBox;

    QLabel *ageLabel;         //年龄
    QLabel *agesignLabel;
    QSpinBox *ageSpinBox1;
    QSpinBox *ageSpinBox2;

    QLabel *schoolLabel;      //学校
    QLineEdit *schoolLineEdit;

    QLabel *addressLabel;     //地址
    QLabel *cityLabel;
    QLabel *countyLabel;
    QComboBox *provinceComboBox;
    QLineEdit *cityLineEdit;
    QLineEdit *countyLineEdit;

    QVBoxLayout *stkWgt2MainLayout;
    QHBoxLayout *stkWgt2Layout1;
    QHBoxLayout *stkWgt2Layout2;

    QTableView *table;
    AddInfo *addinfo;
    DetailedInfo *detailedInfo;

    void widgetStyleSheet();//设置控件风格
private slots:
    void addOperation();//添加信息
    void search();//普通检索
    void toHighSearch();//跳转到高级检索
    void backtoCommon();  //返回到普通检索
    void highSearch();//高级检索
    void checkDetailedInfo();//查看详细信息
    void deleteOperation();//删除操作
    void updateOperation();//修改操作
    void narrowScreen();//最小化窗口
    void fullScreen();//全屏显示
    void closed();//退出程序
    void recTabRowCount(int rowCount);//接收table行数，确定是否允许显示右键功能
    void skin();//切换皮肤

};

#endif // MAININTERFACE_H
