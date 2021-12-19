#include "mainwindow.h"
#include "loginDialog.h"
#include "ui_loginDialog.h"

loginDialog::loginDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    ui->login_username_lineEdit->setFocus();
}

void loginDialog::on_buttonBox_accepted() {
    if (ui->login_username_lineEdit->text() == "admin"
    && ui->login_password_lineEdit->text() == "password")
        static_cast<MainWindow *>(this->parentWidget())->loginCallback(true);
    static_cast<MainWindow *>(this->parentWidget())->loginCallback(false);
}

void loginDialog::on_buttonBox_rejected() {
    static_cast<MainWindow *>(this->parentWidget())->loginCallback(false);
}

loginDialog::~loginDialog()
{
    delete ui;
}
