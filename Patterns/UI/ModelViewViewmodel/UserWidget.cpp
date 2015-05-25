#include "UserWidget.h"
#include "ui_UserWidget.h"

#include "UserWidgetViewmodel.h"

#include <QDebug>

UserWidget::UserWidget(UserWidgetViewmodel &viewModel, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserWidget)
    , m_viewModel(viewModel)
{
    ui->setupUi(this);

    ui->emailEdit->setText(viewModel.email());
    ui->firstNameEdit->setText(viewModel.firstName());
    ui->lastNameEdit->setText(viewModel.lastName());

    this->onEmailValidityChanged(viewModel.isEmailValid());
    this->onFirstNameValidityChanged(viewModel.isFirstNameValid());
    this->onLastNameValidityChanged(viewModel.isLastNameValid());

    this->connect(ui->emailEdit, SIGNAL(textChanged(QString)), &m_viewModel, SLOT(onEmailChanged(QString)));
    this->connect(ui->firstNameEdit, SIGNAL(textChanged(QString)), &m_viewModel, SLOT(onFirstNameChanged(QString)));
    this->connect(ui->lastNameEdit, SIGNAL(textChanged(QString)), &m_viewModel, SLOT(onLastNameChanged(QString)));

    this->connect(&m_viewModel, SIGNAL(isEmailValidChanged(bool)), SLOT(onEmailValidityChanged(bool)));
    this->connect(&m_viewModel, SIGNAL(isFirstNameValidChanged(bool)), SLOT(onFirstNameValidityChanged(bool)));
    this->connect(&m_viewModel, SIGNAL(isLastNameValidChanged(bool)), SLOT(onLastNameValidityChanged(bool)));
}

UserWidget::~UserWidget()
{
    delete ui;
}

void UserWidget::onEmailValidityChanged(bool valid)
{
    qDebug() << valid;
    const QString stylesheet = valid ? "" : "background-color: rgba(255, 0, 0, 1.0);";

    ui->emailEdit->setStyleSheet(stylesheet);
}

void UserWidget::onFirstNameValidityChanged(bool valid)
{
    qDebug() << valid;
    const QString stylesheet = valid ? "" : "background-color: rgba(255, 0, 0, 1.0);";

    ui->firstNameEdit->setStyleSheet(stylesheet);
}

void UserWidget::onLastNameValidityChanged(bool valid)
{
    qDebug() << valid;
    const QString stylesheet = valid ? "" : "background-color: rgba(255, 0, 0, 1.0);";

    ui->lastNameEdit->setStyleSheet(stylesheet);
}
