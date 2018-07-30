#include "caseinsertdialog.h"
#include "casesearchdialog.h"
#include "claiminsertdialog.h"
#include "claimsearchdialog.h"
#include "compeninsertdialog.h"
#include "compensatesearchdialog.h"
#include "deleteexecuter.h"
#include "employeeinsertdialog.h"
#include "employeequerydialog.h"
#include "incinsertdialog.h"
#include "incsearchdialog.h"
#include "mainwindow.h"
#include "selectexecuter.h"
#include "ui_mainwindow.h"
#include "updateexecuter.h"
#include "utils.h"
#include "warrantinsertdialog.h"
#include "warrantsearchdialog.h"
#include <QDebug>
#include <QMessageBox>
#include <cmath>

string MainWindow::currentTable = "";

MainWindow::MainWindow(QWidget *parent, User* user) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->user = user;
    ui->setupUi(this);
    this->initAction();
    this->initConnection();
    this->initWidget();

}


MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::drawInfoOnTableWidget 渲染数据到表格
 * @param info
 */
void MainWindow::drawInfoOnTableWidget(vector<QuerySet> info)
{
    this->emptyTable();
    if (info.size() == 0) {
        ui->Main_TableTitle->setText("未查到任何内容");
        return;
    }
    else {
        ui->Main_TableTitle->setText("查询结果");
    }
    // 数据条数
    int nums = info.size();
    // 列数
    int colsNumber = info[0].getSize();
    // 设置长宽个数
    ui->Main_InfoShowTable->setColumnCount(colsNumber);
    ui->Main_InfoShowTable->setRowCount(nums);
    // 整行选择
    ui->Main_InfoShowTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    // 不可编辑
    ui->Main_InfoShowTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 设置内部item
    for(int i = 0; i < nums; i++) {

        int j = 0;
        map<string, string>::iterator ite;
        for (ite = info[i].getBegin(); ite != info[i].getEnd(); ite++) {
            QTableWidgetItem *item = new QTableWidgetItem();

            // 偶数变为浅灰色
            if (Utils::isDouble(i)) {

                item->setBackground(QBrush(QColor(Qt::lightGray)));
            }
            else {
                item->setBackground(QBrush(QColor(Qt::white)));
            }
            string content = ite->second;
            if (content.size()) {
                // 设置内容
                item->setText(QString::fromStdString(content));
                // 放置item
                ui->Main_InfoShowTable->setItem(i, j, item);
            }
            else {
                // 设置内容
                item->setText(QString::fromStdString(""));
                // 放置item
                ui->Main_InfoShowTable->setItem(i, j, item);
            }
            j++;
        }

    }

    // 设置列名
    QStringList headerList = QStringList();

    map<string, string>::iterator ite;
    int count = 0;
    for (ite = info[0].getBegin(); ite != info[0].getEnd(); ite++)
    {
        headerList << (ite->first).c_str();
        count++;
    }

    ui->Main_InfoShowTable->setHorizontalHeaderLabels(headerList);
    //qDebug() << headerList.size();
    ui->Main_InfoShowTable->setColumnCount(headerList.size());

    // 不可显示更改按钮
    this->unShowChangeButton();
}

/**
 * @brief MainWindow::drawInfoOnTableWidgetWithOperator 展示信息（可编辑）
 * @param info
 */
void MainWindow::drawInfoOnTableWidgetWithOperator(vector<QuerySet> info)
{
    this->drawInfoOnTableWidget(info);

    if (info.size() != 0)
    {
        // 双击编辑
        ui->Main_InfoShowTable->setEditTriggers(QAbstractItemView::DoubleClicked);
        // 显示保存更改 删除选中按钮
        this->showChangeButton();
        // 最后一列不能编辑
        int cols = ui->Main_InfoShowTable->columnCount();
        int rows = ui->Main_InfoShowTable->rowCount();

        for (int i = 0; i < rows; i++)
        {
            ui->Main_InfoShowTable->item(i, cols - 1)->setFlags((ui->Main_InfoShowTable->item(i, cols - 1)->flags()) & (~Qt::ItemIsEditable));
        }
    }
}

/**
 * @brief MainWindow::emptyTable 清空显示
 */
void MainWindow::emptyTable()
{
    ui->Main_InfoShowTable->clear();
}

/**
 * @brief MainWindow::unShowChangeButton 隐藏更改按钮
 */
void MainWindow::unShowChangeButton()
{
    ui->Main_SaveChangeButton->hide();
    ui->Main_DeleteSelectionButton->hide();
}

/**
 * @brief MainWindow::showChangeButton 显示更改按钮
 */
void MainWindow::showChangeButton()
{
    ui->Main_SaveChangeButton->show();
    ui->Main_DeleteSelectionButton->show();
}

/**
 * @brief MainWindow::initAction 初始化QAction
 */
void MainWindow::initAction()
{
    // 信息查询action
    ui->Main_WarrantyQueryAction->activate(QAction::Trigger);
    ui->Main_RiskQueryAction->activate(QAction::Trigger);
    ui->Main_DamageQueryAction->activate(QAction::Trigger);
    ui->Main_ClaimQueryAction->activate(QAction::Trigger);
    ui->Main_IncQueryAction->activate(QAction::Trigger);

    // 信息查看
    ui->Main_WarrantSearchAction->activate(QAction::Trigger);
    ui->Main_RiskSearchAction->activate(QAction::Trigger);
    ui->Main_DamageSearchAction->activate(QAction::Trigger);
    ui->Main_ClaimSearchAction->activate(QAction::Trigger);
    ui->Main_IncSearchAction->activate(QAction::Trigger);

    // 信息登记
    ui->Main_IncSignAction->activate((QAction::Trigger));
    ui->Main_CaseSign->activate(QAction::Trigger);
    ui->Main_ClaimSign->activate(QAction::Trigger);
    ui->Main_DamageSign->activate(QAction::Trigger);
    ui->Main_WarrantSignAction->activate(QAction::Trigger);

    // 员工操作
    ui->EmployeeInsertAction->activate(QAction::Trigger);
    ui->EmployeeQueryAction->activate(QAction::Trigger);
    ui->EmployeeShowAllAction->activate(QAction::Trigger);
}

/**
 * @brief MainWindow::initConnection 初始化信号槽连接
 */
void MainWindow::initConnection()
{
    /* 信息查询 */

    // 绑定查询保单的信号和槽
    QObject::connect(ui->Main_WarrantyQueryAction,SIGNAL(triggered()),this,SLOT(toSearchWarrenty()));
    // 绑定查询出险的信号和槽
    QObject::connect(ui->Main_RiskQueryAction,SIGNAL(triggered()),this,SLOT(toSearchRisk()));
    // 绑定定损公司的信号和槽
    QObject::connect(ui->Main_DamageQueryAction,SIGNAL(triggered()),this,SLOT(toSearchDamage()));
    // 绑定理赔公司的信号和槽
    QObject::connect(ui->Main_ClaimQueryAction,SIGNAL(triggered()),this,SLOT(toSearchClaim()));
    // 绑定查询公司的信号和槽
    QObject::connect(ui->Main_IncQueryAction,SIGNAL(triggered()),this,SLOT(toSearchInc()));
    // 绑定查询公司的信号和槽
    QObject::connect(ui->EmployeeQueryAction,SIGNAL(triggered()),this,SLOT(toSearchEmployee()));


    /* 信息查看 */
    // 绑定查询保单的信号和槽
    QObject::connect(ui->Main_WarrantSearchAction, SIGNAL(triggered()),this,SLOT(toSeeWarrenty()));
    // 绑定查询出险的信号和槽
    QObject::connect(ui->Main_RiskSearchAction, SIGNAL(triggered()),this,SLOT(toSeeRisk()));
    // 绑定定损公司的信号和槽
    QObject::connect(ui->Main_DamageSearchAction, SIGNAL(triggered()),this,SLOT(toSeeDamage()));
    // 绑定理赔公司的信号和槽
    QObject::connect(ui->Main_ClaimSearchAction, SIGNAL(triggered()),this,SLOT(toSeeChaim()));
    // 绑定查询公司的信号和槽
    QObject::connect(ui->Main_IncSearchAction,SIGNAL(triggered()),this,SLOT(toSeeInc()));
    // 绑定查询员工的信号和槽
    QObject::connect(ui->EmployeeShowAllAction,SIGNAL(triggered()),this,SLOT(toSeeEmployee()));

    /* 信息登记 */
    // 绑定登记保单的信号和槽
    QObject::connect(ui->Main_WarrantSignAction, SIGNAL(triggered()),this,SLOT(toSignWarrenty()));
    // 绑定登记出险的信号和槽
    QObject::connect(ui->Main_CaseSign, SIGNAL(triggered()),this,SLOT(toSignRisk()));
    // 绑定登记定损的信号和槽
    QObject::connect(ui->Main_DamageSign, SIGNAL(triggered()),this,SLOT(toSignDamage()));
    // 绑定登记理赔的信号和槽
    QObject::connect(ui->Main_ClaimSign, SIGNAL(triggered()),this,SLOT(toSignClaim()));
    // 绑定登记承保公司的信号和槽
    QObject::connect(ui->Main_IncSignAction,SIGNAL(triggered()),this,SLOT(toSignInc()));
    // 绑定登记员工的信号和槽
    QObject::connect(ui->EmployeeInsertAction,SIGNAL(triggered()),this,SLOT(toSignEmployee()));


}

/**
 * @brief MainWindow::initWidget 初始化组件
 */
void MainWindow::initWidget()
{
    if (this->user->access != 0) {
        ui->EmployeeMenu->menuAction()->setVisible(false);
    }

    // 隐藏编辑按钮
    this->unShowChangeButton();
}



/**
 * @brief MainWindow::toSearchInc 查找公司
 */
void MainWindow::toSearchInc()
{
    IncSearchDialog *incSearchDialog = new  IncSearchDialog(this);
    // 设置主窗口模态（待实现）
    /**/

    incSearchDialog->show();

}

/**
 * @brief MainWindow::toSearchWarrenty 搜索保单
 */
void MainWindow::toSearchWarrenty()
{
    WarrantSearchDialog *warrantSearchDialog = new  WarrantSearchDialog(this);
    // 设置主窗口模态（待实现）
    /**/

    warrantSearchDialog->show();
}

/**
 * @brief MainWindow::toSearchRisk 搜索出险
 */
void MainWindow::toSearchRisk()
{
    CaseSearchDialog *caseSearchDialog = new  CaseSearchDialog(this);
    // 设置主窗口模态（待实现）
    /**/

    caseSearchDialog->show();
}

/**
 * @brief MainWindow::toSearchDamage 搜索定损
 */
void MainWindow::toSearchDamage()
{
    CompensateSearchDialog *compensateSearchDialog = new  CompensateSearchDialog(this);
    // 设置主窗口模态（待实现）
    /**/

    compensateSearchDialog->show();
}

/**
 * @brief MainWindow::toSearchClaim 搜索理赔
 */
void MainWindow::toSearchClaim()
{
    ClaimSearchDialog *claimSearchDialog = new  ClaimSearchDialog(this);
    // 设置主窗口模态（待实现）
    /**/

    claimSearchDialog->show();
}

/**
 * @brief MainWindow::toSeeInc 查看公司所有信息
 */
void MainWindow::toSeeInc()
{
    SelectExecuter sel = SelectExecuter("sys_insurancecomputer");

    vector<QuerySet> result = sel.doSelect();
    this->drawInfoOnTableWidget(result);
    MainWindow::currentTable = "sys_insurancecomputer";
}

/**
 * @brief MainWindow::toSeeWarrenty 查看保单所有信息
 */
void MainWindow::toSeeWarrenty()
{
    SelectExecuter sel = SelectExecuter("insur_guaranteeslip");

    vector<QuerySet> result = sel.doSelect();
    this->drawInfoOnTableWidget(result);
       MainWindow::currentTable = "insur_guaranteeslip";
}

/**
 * @brief MainWindow::toSeeRisk 查看出险所有信息
 */
void MainWindow::toSeeRisk()
{
    SelectExecuter sel = SelectExecuter("case_reportcaseinfo");

    vector<QuerySet> result = sel.doSelect();
    this->drawInfoOnTableWidget(result);
       MainWindow::currentTable = "case_reportcaseinfo";
}

/**
 * @brief MainWindow::toSeeDamage 查看定损所有信息
 */
void MainWindow::toSeeDamage()
{
    SelectExecuter sel = SelectExecuter("compen_carcompensate");

    vector<QuerySet> result = sel.doSelect();
    this->drawInfoOnTableWidget(result);
           MainWindow::currentTable = "compen_carcompensate";
}

/**
 * @brief MainWindow::toSeeChaim 查看理赔所有信息
 */
void MainWindow::toSeeChaim()
{
    SelectExecuter sel = SelectExecuter("claim_claimmanagmentinfo");

    vector<QuerySet> result = sel.doSelect();
    this->drawInfoOnTableWidget(result);
               MainWindow::currentTable = "claim_claimmanagmentinfo";
}

void MainWindow::toSignWarrenty()
{
    WarrantInsertDialog *warrantInsert = new WarrantInsertDialog(this);
    // 设置主窗口模态（待实现）
    /**/
    warrantInsert->show();
}

/**
 * @brief MainWindow::toSignrchRisk 登记出险
 */
void MainWindow::toSignRisk()
{
    CaseInsertDialog *caseInsert = new CaseInsertDialog(this);

    // 设置主窗口模态（待实现）
    /**/
    caseInsert->show();
}

/**
 * @brief MainWindow::toSignDamage 登记定损
 */
void MainWindow::toSignDamage()
{
    CompenInsertDialog *damageInsert = new CompenInsertDialog(this);
    // 设置主窗口模态（待实现）
    /**/
    damageInsert->show();

}

/**
 * @brief MainWindow::toSignClaim 登记理赔
 */
void MainWindow::toSignClaim()
{
    ClaimInsertDialog *claimInsert = new ClaimInsertDialog(this);
    // 设置主窗口模态（待实现）
    /**/
    claimInsert->show();
}

/**
 * @brief MainWindow::toSignInc 登记承保公司
 */
void MainWindow::toSignInc()
{

    IncInsertDialog *incInsert = new IncInsertDialog(this);
    // 设置主窗口模态（待实现）
    /**/

    incInsert->show();

}

/**
 * @brief MainWindow::toSearchEmployee 查询员工
 */
void MainWindow::toSearchEmployee()
{
    EmployeeQueryDialog *que = new EmployeeQueryDialog(this);
    // 设置主窗口模态（待实现）
    /**/
    que->show();

}

/**
 * @brief MainWindow::toSeeEmployee 查看全部员工
 */
void MainWindow::toSeeEmployee()
{
    SelectExecuter sel = SelectExecuter("sys_employeeinfo");

    vector<QuerySet> result = sel.doSelect();
    this->drawInfoOnTableWidget(result);
                   MainWindow::currentTable = "sys_employeeinfo";
}

/**
 * @brief MainWindow::toInsertEmployee 登记员工
 */
void MainWindow::toSignEmployee()
{
    EmployeeInsertDialog *ins = new EmployeeInsertDialog(this);
    // 设置主窗口模态（待实现）
    /**/
    ins->show();
}


/**
 * @brief MainWindow::on_Main_SaveChangeButton_clicked 保存修改
 */
void MainWindow::on_Main_SaveChangeButton_clicked()
{
    // 数据源
//    QTableWidgetItem* items = ui->Main_InfoShowTable->currentItem();
//    if (!ui->Main_InfoShowTable->isItemSelected(items)) {
//        QMessageBox::information(this, "提示", "没有数据需要更新..", QMessageBox::Ok, QMessageBox::Ok);
//        return ;
//    }

    /* 检查数据正确与否 */
    /**/



    // 行数和列数
    int rows = ui->Main_InfoShowTable->rowCount();
    int cols = ui->Main_InfoShowTable->columnCount();

    // 字段列表
    string *fieldList = new string[cols];
    // 表头一行

    for (int i = 0; i < cols; i++)
    {
        QTableWidgetItem *header = ui->Main_InfoShowTable->horizontalHeaderItem(i);

        fieldList[i] = header->text().toStdString();
    }

    // 拿到id列表
    SelectExecuter sel = SelectExecuter(MainWindow::currentTable);
    vector<QuerySet> result = sel.doSelect();

    string *list = new string[result.size()];
    for (int i = 0; i < result.size(); i++)
    {
        list[i] = result[i]["id"];
        qDebug() << list[i].c_str();
    }

    // 执行更新
    for (int i = 0; i < rows; i++)
    {
        QuerySet data = QuerySet();
        for (int j = 0; j < cols; j++)
        {

            if (ui->Main_InfoShowTable->item(i, j))
            {
                data.setValue(fieldList[j], ui->Main_InfoShowTable->item(i, j)->text().toStdString());
            }

        }
        UpdateExecuter upd = UpdateExecuter(MainWindow::currentTable);

        // 构造过滤器
        upd.filter.addFilter("id", list[i]);

        upd.doUpdate(data);

    }


}


/**
 * @brief MainWindow::on_Main_DeleteSelectionButton_clicked 删除
 */
void MainWindow::on_Main_DeleteSelectionButton_clicked()
{
    QList<QTableWidgetItem *> itemList = ui->Main_InfoShowTable->selectedItems();

    // 列数
    int cols = ui->Main_InfoShowTable->columnCount();
    int selectedRows = itemList.size() / cols;
    for (int i = 0; i < selectedRows; i++)
    {
        DeleteExecuter del = DeleteExecuter(MainWindow::currentTable);
        // 包含id的item
        QTableWidgetItem * idItem = itemList.at(((int) (pow(cols, i + 1))) - 1);
        // 构造删除过滤器
        del.filter.addFilter("id", idItem->text().toStdString());
        del.doDelete();
        ui->Main_InfoShowTable->removeRow(ui->Main_InfoShowTable->row(idItem));

    }


}
