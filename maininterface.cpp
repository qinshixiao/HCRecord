#include "maininterface.h"


MainInterface::MainInterface(QWidget *parent) :
    QWidget(parent)

{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->move(180,50);
    this->resize(1000,700);

    addinfo=new AddInfo;//这里去掉了(this)，用来满足addInfo对话框去掉边框，否则对话框作为主界面的子部件会继承它的背景

    skin();//切换皮肤函数
    programnameLabel=new QLabel;
    programnameLabel2=new QLabel;
    programnameLabel->setMinimumSize(100,40);
    programnameLabel->setMaximumSize(100,40);
    programnameLabel2->setMinimumSize(250,30);
    programnameLabel2->setMaximumSize(250,30);

    updateAction=new QAction("修改",this);
    deleteAction=new QAction("删除",this);
    copyAction=new QAction("复制",this);
    detailAction=new QAction("详细信息",this);
    refurbishAction=new QAction(tr("刷新"),this);

    table=new QTableView;
    table->setSelectionMode(QAbstractItemView::SingleSelection);//单行选择
    table->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选择习惯,按行选择
    //table->setContextMenuPolicy(Qt::ActionsContextMenu);//设置启用右键动作选项,已经挪到下边的recTabRowCount函数中
    table->setMouseTracking(true);

    table->addAction(this->refurbishAction);
    table->addAction(this->detailAction);
    table->addAction(this->copyAction);
    table->addAction(this->updateAction);
    table->addAction(this->deleteAction);


    stack=new QStackedWidget;
    stack->setMaximumHeight(100);
    stackWidget1=new QWidget;
    stackWidget2=new QWidget;


    knowBtn=new QPushButton;
    knowBtn->setMinimumSize(50,40);
    knowBtn->setMaximumSize(50,40);
    statisticBtn=new QPushButton;
    statisticBtn->setMinimumSize(50,40);
    statisticBtn->setMaximumSize(50,40);
    sayBtn=new QPushButton;
    sayBtn->setMinimumSize(50,40);
    sayBtn->setMaximumSize(50,40);
    growUpBtn=new QPushButton;
    growUpBtn->setMinimumSize(50,40);
    growUpBtn->setMaximumSize(50,40);
    birthdayWallBtn=new QPushButton;
    birthdayWallBtn->setMinimumSize(50,40);
    birthdayWallBtn->setMaximumSize(50,40);

    toHighsearchBtn=new QPushButton;
    toHighsearchBtn->setMinimumSize(50,40);
    toHighsearchBtn->setMaximumSize(50,40);

    //普通检索设置
    skinBtn=new QPushButton;
    skinBtn->setMinimumSize(24,24);
    skinBtn->setMaximumSize(24,24);
    skinMenu=new QMenu;
    switchSkinAction=new QAction(tr("切换皮肤"),this);
    customerSkinAction=new QAction(tr("自定义皮肤"),this);
    skinMenu->addAction(switchSkinAction);
    skinMenu->addAction(customerSkinAction);
    skinBtn->setMenu(skinMenu);
    //skinBtn->setContextMenuPolicy(Qt::ActionsContextMenu);//设置右键菜单
    narrowScreenBtn=new QPushButton;
    fullScreenBtn=new QPushButton;
    quitBtn=new QPushButton;
    narrowScreenBtn->setMinimumSize(35,35);
    narrowScreenBtn->setMaximumSize(35,35);
    fullScreenBtn->setMinimumSize(35,35);
    fullScreenBtn->setMaximumSize(35,35);
    quitBtn->setMinimumSize(35,35);
    quitBtn->setMaximumSize(35,35);
    searchBtn=new QPushButton;
    searchBtn->setMinimumSize(20,20);
    searchBtn->setMaximumSize(20,20);
    //searchBtn->setShortcut(Qt::Key_Enter);
    //searchBtn->setFocus();//设置默认焦点
    //searchBtn->setDefault(true);//当焦点在该键上时在窗口中按下enter键时的默认响应
    addBtn=new QPushButton;
    addBtn->setMinimumSize(50,40);
    addBtn->setMaximumSize(50,40);
    typeComboBox=new QComboBox;
    typeComboBox->setMinimumSize(80,30);
    typeComboBox->setMaximumSize(80,30);
    typeComboBox->addItem("显示全部");
    typeComboBox->addItem("按姓名");
    typeComboBox->addItem("按性别");
    typeComboBox->addItem("按年龄");
    typeComboBox->addItem("按电话号");
    typeComboBox->addItem("按QQ号");
    typeComboBox->addItem("按类型");
    typeComboBox->addItem("按省份");
    typeComboBox->addItem("按城市");
    typeComboBox->addItem("按区县");
    typeComboBox->addItem("按学校");
    typeComboBox->addItem("按生日");
    typeComboBox->addItem("按专业");
    typeComboBox->addItem("按工作");
    typeComboBox->addItem("按详细地址");

    searchLineEdit=new QLineEdit;
    searchLineEdit->setMinimumSize(200,30);
    searchLineEdit->setMaximumSize(200,30);
    QHBoxLayout *searchLEtLayout=new QHBoxLayout;
    searchLEtLayout->addStretch();
    searchLEtLayout->addWidget(searchBtn);
    searchLineEdit->setLayout(searchLEtLayout);


    stkWgt1Layout1=new QHBoxLayout;
    stkWgt1Layout1->setMargin(0);
    stkWgt1Layout1->setSpacing(5);
    stkWgt1Layout1->addWidget(programnameLabel);
    stkWgt1Layout1->addWidget(programnameLabel2);
    stkWgt1Layout1->addStretch();
    stkWgt1Layout1->addWidget(skinBtn);
    stkWgt1Layout1->addWidget(narrowScreenBtn);
    stkWgt1Layout1->addWidget(fullScreenBtn);
    stkWgt1Layout1->addWidget(quitBtn);
    stkWgt1Layout1->addSpacing(5);

    stkWgt1Layout2=new QHBoxLayout;
    stkWgt1Layout2->addSpacing(0);
    stkWgt1Layout2->setMargin(0);
    stkWgt1Layout2->addSpacing(5);
    stkWgt1Layout2->addWidget(sayBtn);
    stkWgt1Layout2->addWidget(knowBtn);
    stkWgt1Layout2->addWidget(birthdayWallBtn);
    stkWgt1Layout2->addWidget(growUpBtn);
    stkWgt1Layout2->addSpacing(25);
    stkWgt1Layout2->addWidget(statisticBtn);
    stkWgt1Layout2->addWidget(addBtn);
    stkWgt1Layout2->addWidget(toHighsearchBtn);
    stkWgt1Layout2->addStretch();
    stkWgt1Layout2->addWidget(typeComboBox);
    stkWgt1Layout2->addWidget(searchLineEdit);
    stkWgt1Layout2->addSpacing(5);
    stkWgt1Layout2->setAlignment(this,Qt::AlignTop);

    stkWgt1MainLayout=new QVBoxLayout;
    stkWgt1MainLayout->setMargin(0);
    stkWgt1MainLayout->addLayout(stkWgt1Layout1);
    stkWgt1MainLayout->addLayout(stkWgt1Layout2);

    stackWidget1->setLayout(stkWgt1MainLayout);


    //高级检索设置
    backBtn=new QPushButton(tr("返回"));
    highSearchBtn=new QPushButton(tr("开始"));
    sexLabel=new QLabel(tr("性别："));  //性别
    sexLabel->setMaximumWidth(30);
    sexComboBox=new QComboBox;
    sexComboBox->setMaximumSize(60,40);
    sexComboBox->setMinimumSize(60,40);
    sexComboBox->setStyleSheet("border-radius:15px;");
    sexComboBox->addItem("未选择");
    sexComboBox->addItem("男");
    sexComboBox->addItem("女");

    ageLabel=new QLabel(tr("年龄："));//年龄
    ageLabel->setMaximumWidth(30);
    agesignLabel=new QLabel(tr("到"));
    agesignLabel->setMaximumWidth(15);
    ageSpinBox1=new QSpinBox;
    ageSpinBox1->setMaximumWidth(35);
    ageSpinBox1->setRange(0,127);
    ageSpinBox1->setMaximumSize(50,40);
    ageSpinBox1->setMinimumSize(50,40);
    ageSpinBox2=new QSpinBox;
    ageSpinBox2->setMaximumWidth(35);
    ageSpinBox2->setRange(0,127);
    ageSpinBox2->setMaximumSize(50,40);
    ageSpinBox2->setMinimumSize(50,40);

    schoolLabel=new QLabel(tr("学校："));      //学校
    schoolLabel->setMaximumWidth(30);
    schoolLineEdit=new QLineEdit;
    schoolLineEdit->setMaximumWidth(150);
    schoolLineEdit->setMaximumSize(150,40);
    schoolLineEdit->setMinimumSize(150,40);

    addressLabel=new QLabel(tr("地址：")); //地址
    addressLabel->setMaximumSize(30,40);
    addressLabel->setMinimumSize(30,40);
    cityLabel=new QLabel(tr("市"));
    cityLabel->setMaximumSize(20,40);
    cityLabel->setMinimumSize(20,40);
    countyLabel=new QLabel(tr("县"));
    provinceComboBox=new QComboBox;
    QStringList provinceList;
    provinceList<<"未选择"<<"陕西省"<<"河南省"<<"北京市"<<"山东省"<<"湖北省"<<"福建省";
    provinceComboBox->addItems(provinceList);
    provinceComboBox->setMinimumSize(80,40);
    provinceComboBox->setMaximumSize(80,40);
    cityLineEdit=new QLineEdit;
    countyLineEdit=new QLineEdit;
    cityLineEdit->setMaximumSize(150,40);
    cityLineEdit->setMinimumSize(150,40);
    countyLineEdit->setMaximumSize(150,40);
    countyLineEdit->setMinimumSize(150,40);

    stkWgt2Layout1=new QHBoxLayout;
    stkWgt2Layout2=new QHBoxLayout;
    stkWgt2Layout1->addWidget(sexLabel);
    stkWgt2Layout1->addWidget(sexComboBox);
    stkWgt2Layout1->addSpacing(10);
    stkWgt2Layout1->addWidget(ageLabel);
    stkWgt2Layout1->addWidget(ageSpinBox1);
    stkWgt2Layout1->addWidget(agesignLabel);
    stkWgt2Layout1->addWidget(ageSpinBox2);
    stkWgt2Layout1->addSpacing(10);
    stkWgt2Layout1->addWidget(schoolLabel);
    stkWgt2Layout1->addWidget(schoolLineEdit);
    stkWgt2Layout1->addSpacing(10);
    stkWgt2Layout1->addWidget(addressLabel);
    stkWgt2Layout1->addWidget(provinceComboBox);

    stkWgt2Layout1->addWidget(cityLineEdit);
    stkWgt2Layout1->addWidget(cityLabel);
    stkWgt2Layout1->addWidget(countyLineEdit);
    stkWgt2Layout1->addWidget(countyLabel);
    stkWgt2Layout1->addSpacing(10);
    stkWgt2Layout1->addWidget(highSearchBtn);
    stkWgt2Layout1->addWidget(backBtn);
    stkWgt2Layout1->setAlignment(this,Qt::AlignTop);

    stkWgt2MainLayout=new QVBoxLayout;
    stkWgt2MainLayout->addLayout(stkWgt2Layout1);

    stackWidget2->setLayout(stkWgt2MainLayout);

    stack->addWidget(stackWidget1);
    stack->addWidget(stackWidget2);

    mainLayout=new QVBoxLayout(this);

    mainLayout->addWidget(stack);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(table);
    mainLayout->setMargin(0);
    mainLayout->setAlignment(this,Qt::AlignTop);

    widgetStyleSheet();
    connect(searchLineEdit,SIGNAL(editingFinished()),this,SLOT(search()));
    connect(addBtn,SIGNAL(clicked()),this,SLOT(addOperation()));
    connect(searchBtn,SIGNAL(clicked()),this,SLOT(search()));
    connect(toHighsearchBtn,SIGNAL(clicked()),this,SLOT(toHighSearch()));
    connect(backBtn,SIGNAL(clicked()),this,SLOT(backtoCommon()));
    connect(highSearchBtn,SIGNAL(clicked()),this,SLOT(highSearch()));
    connect(narrowScreenBtn,SIGNAL(clicked()),this,SLOT(narrowScreen()));
    connect(fullScreenBtn,SIGNAL(clicked()),this,SLOT(fullScreen()));
    connect(quitBtn,SIGNAL(clicked()),this,SLOT(closed()));
    connect(table,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(checkDetailedInfo()));
    connect(refurbishAction,SIGNAL(triggered()),this,SLOT(search()));
    connect(detailAction,SIGNAL(triggered()),this,SLOT(checkDetailedInfo()));
    connect(updateAction,SIGNAL(triggered()),this,SLOT(updateOperation()));
    connect(deleteAction,SIGNAL(triggered()),this,SLOT(deleteOperation()));
    connect(this,SIGNAL(sendTabRowCount(int)),this,SLOT(recTabRowCount(int)));
    connect(this,SIGNAL(sendModelIndex(QModelIndex)),addinfo,SLOT(recModelIndex(QModelIndex)));
    connect(switchSkinAction,SIGNAL(triggered()),this,SLOT(skin()));


}

MainInterface::~MainInterface()
{
}

//查询按钮响应槽
void MainInterface::search()
{
    table->setStyleSheet("background-color:rgba(255,255,255,75%)");
    Model=new QSqlQueryModel;
    QSqlDatabase peopledatabase = QSqlDatabase::database("people_Database");

    int control=typeComboBox->currentIndex();

    //辅助按年龄检索
    QString searchLEtText=searchLineEdit->text();
    QDateTime time = QDateTime::currentDateTime();
    int timeYear=time.toString("yyyy").toInt();//获取年份
    int year;
    QString temp;//辅助将数字转为字符串
    if(control==3) year=timeYear-searchLEtText.toInt();

    //判断输入框是否为空
    if(searchLEtText.isEmpty()&&control!=0)
        QMessageBox::information(this,"提示","请在输入框中输入所要查询的关键字，然后点击查询按钮",QMessageBox::Ok);
    else
    {
        switch (control)
        {
         case 0:
                //searchLineEdit->clear();
                Model->setQuery("select * from person",peopledatabase);
                table->setModel(Model);
                break;

         case 1:
                Model->setQuery(QString("select id,姓名 from person where 姓名 like '%%1%'").arg(searchLEtText),peopledatabase);
                table->setModel(Model);
                break;
         case 2:
                Model->setQuery(QString("select id,姓名,性别 from person where 性别='%1'").arg(searchLEtText),peopledatabase);
                table->setModel(Model);
                break;
         case 3:
                Model->setQuery(QString("select id,姓名,出生年份 from person where 出生年份='%1'").arg(temp.setNum(year)),peopledatabase);
                table->setModel(Model);
                break;
         case 4:
                Model->setQuery(QString("select id,姓名,电话 from person where 电话 like '%%1%'").arg(searchLEtText),peopledatabase);
                table->setModel(Model);
                break;
         case 5:
                Model->setQuery(QString("select id,姓名,QQ from person where QQ like '%%1%'").arg(searchLEtText),peopledatabase);
                table->setModel(Model);
                break;
         case 6:
                Model->setQuery(QString("select id,姓名,类型 from person where 类型 like '%%1%'").arg(searchLEtText),peopledatabase);
                table->setModel(Model);
                break;
         case 7:
                Model->setQuery(QString("select id,姓名,省份 from person where 省份 like '%%1%'").arg(searchLEtText),peopledatabase);
                table->setModel(Model);
                break;
         case 8:
                Model->setQuery(QString("select id,姓名,城市 from person where 城市 like '%%1%'").arg(searchLEtText),peopledatabase);
                table->setModel(Model);
                break;
         case 9:
                Model->setQuery(QString("select id,姓名,县区 from person where 县区 like '%%1%'").arg(searchLEtText),peopledatabase);
                table->setModel(Model);
                break;
         case 10:
                Model->setQuery(QString("select id,姓名,学校 from person where 学校 like '%%1%'").arg(searchLEtText),peopledatabase);
                table->setModel(Model);
                break;
         case 11:
                Model->setQuery(QString("select id,姓名,生日 from person where 生日 like '%%1'").arg(searchLEtText),peopledatabase);
                table->setModel(Model);
                break;
        case 12:
               Model->setQuery(QString("select id,姓名,专业 from person where 专业 like '%%1%'").arg(searchLEtText),peopledatabase);
               table->setModel(Model);
               break;
        case 13:
               Model->setQuery(QString("select id,姓名,工作 from person where 工作 like '%%1%'").arg(searchLEtText),peopledatabase);
               table->setModel(Model);
               break;
        case 14:
               Model->setQuery(QString("select id,姓名,详细地址 from person where 详细地址 like '%%1%'").arg(searchLEtText),peopledatabase);
               table->setModel(Model);
               break;
         default:
                break;
        }
        int rowCount=Model->rowCount();
        emit sendTabRowCount(rowCount);
    }
}

//跳转到高级搜索
void MainInterface::toHighSearch()
{
    stack->setCurrentIndex(1);

}

//返回到普通搜索
void MainInterface::backtoCommon()
{
    stack->setCurrentIndex(0);
}
void MainInterface::highSearch()
{

}

//窗口最小化
void MainInterface::narrowScreen()
{
    this->showMinimized();
}

//窗口全屏显示
void MainInterface::fullScreen()
{
    if(screenFlag==1)
    {
        this->showFullScreen();
        screenFlag=0;
    }
    else
    {
        this->showNormal();
        screenFlag=1;
    }
}

//查询详细信息
void MainInterface::checkDetailedInfo()
{

    QModelIndex index = Model->index(table->currentIndex().row(),0);//获得一条记录的单个属性的值，currentIndex函数获取当前行的记录，包括row和column和（忘了）
    detailedInfo=new DetailedInfo(this);
    if(colorFlag==0)
    {
        detailedInfo->setStyleSheet("background:green");
        colorFlag++;
    }
    else if(colorFlag==1)
    {
        detailedInfo->setStyleSheet("background:purple");
        colorFlag++;
    }
    else if(colorFlag==2)
    {
        detailedInfo->setStyleSheet("background:azure");
        colorFlag++;
    }
    else if(colorFlag==3)
    {
        detailedInfo->setStyleSheet("background:pink");
        colorFlag++;
    }
    else if(colorFlag==4)
    {
        detailedInfo->setStyleSheet("background:orange");
        colorFlag=0;
    }

    detailedInfo->show();
    //detailedInfo->exitBtn->hide();
    detailedInfo->showInfo(index.data().toInt());
    detailedInfo->showImage(index.data().toInt());
}

//关闭事件
void MainInterface::closeEvent(QCloseEvent *event)
{
    int r = QMessageBox::critical(this,"提示","确定要退出吗？",
                           QMessageBox::Yes
                           | QMessageBox::Cancel);
    if (r == QMessageBox::Yes)
    {
        event->accept();
    }
    else if (r == QMessageBox::Cancel)
    {
        event->ignore();
    }

}

//退出按钮响应槽
void MainInterface::closed()
{

   this->close();
}

//鼠标按下事件
void MainInterface:: mousePressEvent (QMouseEvent *e)
{
    if(screenFlag==1)
    {
        last = e->globalPos();
    }
}

//鼠标移动事件
void MainInterface:: mouseMoveEvent (QMouseEvent *e)
{
    if(screenFlag==1)
    {
        int dx = e->globalX() - last.x();
        int dy = e->globalY() - last.y();
        last = e->globalPos();
        move(x()+dx,y()+dy);
    }
}

//鼠标离开事件
void MainInterface:: mouseReleaseEvent (QMouseEvent *e)
{
    if(screenFlag==1)
    {
        int dx = e->globalX() - last.x();
        int dy = e->globalY() - last.y();
        move(x()+dx, y()+dy);
    }
}

//添加操作
void MainInterface::addOperation()
{
    addinfo->exec();
    search();
}

//删除操作
void MainInterface::deleteOperation()
{
    if(QMessageBox::Yes==QMessageBox::warning(this,"提示","数据删除后将无法恢复，请谨慎操作，是或否？",QMessageBox::Yes|QMessageBox::No))
    {
        QSqlDatabase peopleDatabase=QSqlDatabase::database("people_Database");
        QSqlDatabase detailInfodatabase = QSqlDatabase::database("detailInfo_Database");
        QSqlQuery query2(detailInfodatabase);
        QSqlQuery query(peopleDatabase);
        QModelIndex index = Model->index(table->currentIndex().row(),0);
        query.exec(QString("delete from person where id=%1").arg(index.data().toString()));
        query2.exec(QString("delete from person where id=%1").arg(index.data().toString()));
        search();
    }
}

//更新操作
void MainInterface::updateOperation()
{
    QString introduction;
    QString name;
    QString sex;
    QString phone;
    QString QQ;
    QString school;
    QString subject;
    QString job;
    QString nowHome;
    QString detail;
    QString province;
    QString city;
    QString county;
    QString birthYear;
    QString birthday;
    QString type;
    QSqlDatabase peopleDatabase=QSqlDatabase::database("people_Database");
    QSqlDatabase detailInfodatabase = QSqlDatabase::database("detailInfo_Database");
    QSqlQuery query2(detailInfodatabase);
    QSqlQuery query(peopleDatabase);

    QModelIndex index = Model->index(table->currentIndex().row(),0);
    sendModelIndex(index);

    query.exec(QString("select * from person where id=%1").arg(index.data().toString()));
    query2.exec(QString("select * from detailInfo where id=%1").arg(index.data().toString()));
    query.next();
    name=query.value(1).toString();
    sex=query.value(2).toString();
    birthYear=query.value(3).toString();
    birthday=query.value(4).toString();
    phone=query.value(5).toString();
    QQ=query.value(6).toString();
    school=query.value(7).toString();
    subject=query.value(8).toString();
    job=query.value(9).toString();
    province=query.value(10).toString();
    city=query.value(11).toString();
    county=query.value(12).toString();
    detail=query.value(13).toString();
    type=query.value(14).toString();

    query2.next();
    nowHome=query2.value(2).toString();
    introduction=query2.value(3).toString();
    addinfo->showUpdateInfo(introduction,name,sex,phone,QQ,school,subject,job,nowHome,detail,province,city,county,birthYear,birthday,type);
    search();

}

//接收tableview上的行数
void MainInterface::recTabRowCount(int rowCount)
{
    qDebug()<<rowCount;
    if(rowCount!=0)
    table->setContextMenuPolicy(Qt::ActionsContextMenu);//设置启用右键动作选项
}

//窗体控件样式
void MainInterface::widgetStyleSheet()
{
    table->setStyleSheet("background-image:url(:/images/images/welcomeInfo.jpg);background-repeat:no-repeat");
    stack->setStyleSheet("background-image:url(:/images/images/stackbk.png)");
    programnameLabel->setStyleSheet("QLabel{background-image:url(:/images/images/programName.png);}");
    programnameLabel2->setStyleSheet("QLabel{background-image:url(:/images/images/programName2.png);}");
    typeComboBox->setStyleSheet("QComboBox{background-color:rgba(255,255,255,10%);color:orange;outline:none;border-radius:10px;}\
                                QComboBox:hover{background-color:rgba(255,255,255,40%);border-radius:10px;}");
    statisticBtn->setStyleSheet("QPushButton{background-image:url(:/images/images/statistic.png);background-color:rgba(255,255,255,10%);outline:none;border-radius:5px;}\
                                QPushButton:hover{background-color:rgba(255,255,255,40%);border-radius:5px;}");
    sayBtn->setStyleSheet("QPushButton{background-color:rgba(255,255,255,10%);background-image:url(:/images/images/say.png);outline:none;border-radius:5px;}\
                          QPushButton:hover{background-color:rgba(255,255,255,40%);border-radius:5px;}");
    birthdayWallBtn->setStyleSheet("QPushButton{background-color:rgba(255,255,255,10%);background-image:url(:/images/images/birthday.png);outline:none;border-radius:5px;}\
                                   QPushButton:hover{background-color:rgba(255,255,255,40%);border-radius:5px;}");
    growUpBtn->setStyleSheet("QPushButton{background-color:rgba(255,255,255,10%);background-image:url(:/images/images/growup.png);outline:none;border-radius:5px;}\
                             QPushButton:hover{background-color:rgba(255,255,255,40%);border-radius:5px;}");

    knowBtn->setStyleSheet("QPushButton{background-color:rgba(255,255,255,10%);background-image:url(:/images/images/know.png);outline:none;border-radius:5px;}\
                           QPushButton:hover{background-color:rgba(255,255,255,40%);border-radius:5px;}");
    addBtn->setStyleSheet("QPushButton{background-image:url(:/images/images/add.png);background-color:rgba(255,255,255,10%);outline:none;border-radius:5px;}\
                          QPushButton:hover{background-color:rgba(255,255,255,40%);border-radius:5px;}");
    toHighsearchBtn->setStyleSheet("QPushButton{background-color:rgba(255,255,255,10%);background-image:url(:/images/images/highsearch.png);outline:none;border-radius:5px;}\
                                   QPushButton:hover{background-color:rgba(255,255,255,40%);border-radius:5px;}");
    searchLineEdit->setStyleSheet("background:white;border-radius:10px;");
    searchBtn->setStyleSheet("QPushButton{background-color:rgba(255,255,255,50%);background-image:url(:/images/images/search.png);outline:none;border-radius:10px;}\
                                    QPushButton:hover{background-color:rgba(0,0,255,20%);border-radius:10px;}");
    skinBtn->setStyleSheet("QPushButton{background-color:rgba(255,255,255,10%);background-image:url(:/images/images/skinBtn.png);outline:none;border-radius:10px;}\
                         QPushButton:hover{background-color:rgb(255,255,255);border-radius:10px;}");
    quitBtn->setStyleSheet("QPushButton{background-color:rgba(255,255,255,10%);background-image:url(:/images/images/close.png);outline:none;border-radius:10px;}\
                           QPushButton:hover{background-color:rgb(255,0,0);border-radius:10px;}");
    narrowScreenBtn->setStyleSheet("QPushButton{background-image:url(:/images/images/min.png);background-color:rgba(255,255,255,10%);outline:none;border-radius:10px;}\
                                   QPushButton:hover{background-color:rgba(255,255,255,40%);border-radius:10px;}");
    fullScreenBtn->setStyleSheet("QPushButton{background-image:url(:/images/images/max.png);background-color:rgba(255,255,255,10%);outline:none;border-radius:10px;}\
                                 QPushButton:hover{background-color:rgba(255,255,255,40%);border-radius:10px;}");
}

void MainInterface::skin()
{
    QString skinflag;
    QPalette palette;
    if(skinFlag==9) skinFlag=0;
    QPixmap pixmap(QString(":/images/images/skin%1.jpg").arg(skinflag.setNum(skinFlag)));
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
    skinFlag++;
}
