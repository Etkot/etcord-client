#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>

namespace Ui {
class ConnectDialog;
}

class ConnectDialog : public QDialog
{
	Q_OBJECT

public:
	explicit ConnectDialog(QWidget *parent = 0);
	~ConnectDialog();

signals:
	void start_connect(QString address, QString username);

private:
	Ui::ConnectDialog *ui;

public slots:
	void connect_accepted();
};

#endif // CONNECTDIALOG_H
