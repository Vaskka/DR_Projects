#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include "mainwindow.h"
#include "user.h"

#include <QMainWindow>

class MyMainWindow : public MainWindow
{
    Q_OBJECT
public:
    explicit MyMainWindow(User *user, QWidget *parent = nullptr);


    /**
     * 登陆用户
     * @brief user
     */
    User *user;


signals:

public slots:
};

#endif // MYMAINWINDOW_H
