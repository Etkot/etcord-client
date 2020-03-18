#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui/connectdialog.h"
#include "server.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindow *ui;
	ConnectDialog *connectDialog;

	Server* server;

	void open_connect();

private slots:
	void connect_to_server(QString server_address, QString username);
};

#endif // MAINWINDOW_H
