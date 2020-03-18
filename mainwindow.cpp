#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcp/tcpclient.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	connectDialog = new ConnectDialog;
	connectDialog->setWindowTitle("Connect To Server");
	connect(ui->actionConnect, SIGNAL(triggered(bool)), connectDialog, SLOT(show()));
	connect(connectDialog, SIGNAL(start_connect(QString,QString)), this, SLOT(connect_to_server(QString,QString)));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::open_connect() {
	connectDialog->show();
}

void MainWindow::connect_to_server(QString server_address, QString username) {
	if (server_address.length() == 0 || username.length() == 0) {
		return;
	}

	qInfo() << "Server Address: " << server_address;
	qInfo() << "Username: " << username;

	QStringList parts = server_address.split(':');
	if (parts.length() > 2) {
		qInfo() << "Invalid address";
		return;
	}

	char *address = parts[0].toLocal8Bit().data();
	ushort port = 3879;

	if (parts.length() == 2) {
		port = parts[1].toUShort();
	}

	tcp::Client* client = new tcp::Client();
	client->connect(address, port);

	server = new Server(client);
}
