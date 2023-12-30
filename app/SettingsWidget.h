#pragma once

#include <QMainWindow>
#include "ui_SettingsWidget.h"

class SettingsWidget : public QMainWindow
{
	Q_OBJECT

public:
	SettingsWidget(QWidget *parent = nullptr);
	~SettingsWidget();

	QString getGamemode() const;
	QString getPlayer1Name() const;
	QString getPlayer2Name() const;
	int getGameboardSize() const;

signals:
	void on_backToMenuButton_clicked();

private:
	Ui::SettingsWidgetClass ui;
};
