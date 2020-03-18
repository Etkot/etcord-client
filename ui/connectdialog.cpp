#include "connectdialog.h"
#include "ui_connectdialog.h"

ConnectDialog::ConnectDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ConnectDialog)
{
	ui->setupUi(this);

	connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(connect_accepted()));
}

ConnectDialog::~ConnectDialog()
{
	delete ui;
}

void ConnectDialog::connect_accepted() {
	emit start_connect(ui->lineEditAddress->text(), ui->lineEditUsername->text());
}
