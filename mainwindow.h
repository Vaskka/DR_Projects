#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vector>
#include "queryset.h"
#include "user.h"


namespace Ui {
class MainWindow;
}

/**
* @projectName   AutomobileInsurance
* @brief         主界面数据展示接口
* @author        Vaskka
* @date          2018-7-29
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, User* user = nullptr);
    ~MainWindow();

    /**
     * @brief drawInfoOnTableWidget 渲染查找到的数据到中心表格
     * @param info vector<QuerySet> information
     */
    void drawInfoOnTableWidget(vector<QuerySet> info);

    /**
     * @brief drawInfoOnTableWidgetWithOperator 渲染查找到的数据到中心表格（可编辑）
     * @param info
     */
    void drawInfoOnTableWidgetWithOperator(vector<QuerySet> info);

    /**
     * @brief emptyTable 清空表格
     */
    void emptyTable();

    /**
     * @brief unShowChangeButton 隐藏更改按钮
     */
    void unShowChangeButton();

    /**
     * @brief showChangeButton 显示更改按钮
     */
    void showChangeButton();

private:

    /**
     * @brief initAction 初始化QAction
     */
    void initAction();

    /**
     * @brief initConnection 初始化信号槽连接
     */
    void initConnection();

    /**
     * 登陆用户
     * @brief user
     */
    User *user;

    /**
     * @brief initWidget 初始化组件
     */
    void initWidget();

    Ui::MainWindow *ui;



public slots:
    /**
     * @brief toSearchInc 搜索公司
     */
    void toSearchInc();

    /**
     * @brief toSearchWarrenty 搜索保单
     */
    void toSearchWarrenty();

    /**
     * @brief toSearchRisk 搜索出险
     */
    void toSearchRisk();

    /**
     * @brief toSearchDamage 搜索定损
     */
    void toSearchDamage();

    /**
     * @brief toSearchClaim 搜索理赔
     */
    void toSearchClaim();

    /**
     * @brief toSeeInc 查看公司
     */
    void toSeeInc();

    /**
     * @brief toSeeWarrenty 查看保单
     */
    void toSeeWarrenty();

    /**
     * @brief toSeeRisk 查看出险
     */
    void toSeeRisk();

    /**
     * @brief toSeeDamage 查看定损
     */
    void toSeeDamage();

    /**
     * @brief toSeeChaim 查看理赔
     */
    void toSeeChaim();

    /**
     * @brief toSignWarrenty 登记保单
     */
    void toSignWarrenty();

    /**
     * @brief toSignRisk 登记出险
     */
    void toSignRisk();

    /**
     * @brief toSignDamage 登记定损
     */
    void toSignDamage();

    /**
     * @brief toSignClaim 登记理赔
     */
    void toSignClaim();

    /**
     * @brief toSignInc 登记承保公司
     */
    void toSignInc();

    /**
     * @brief toSearchEmployee 查询员工
     */
    void toSearchEmployee();

    /**
     * @brief toSeeEmployee 查看员工
     */
    void toSeeEmployee();

    /**
     * @brief toInsertEmployee 登记员工
     */
    void toSignEmployee();



    /**
     * @brief toOutputExcel 输出Excel
     */
    void toOutputExcel();
public:
    /**
     * @brief currentTable 当前查询的表名
     */
    static string currentTable;
private slots:
    void on_Main_SaveChangeButton_clicked();
    void on_Main_DeleteSelectionButton_clicked();
};

#endif // MAINWINDOW_H
