#include "mymainwindow.h"


MyMainWindow::MyMainWindow(User *user, QWidget *parent) : MainWindow(parent)
{
    this->user = user;
}
