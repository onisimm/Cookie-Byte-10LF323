#pragma once

#include <QMainWindow>
#include "ui_SettingsWidget.h"

class SettingsWidget : public QMainWindow
{
	Q_OBJECT

public:
	SettingsWidget(QWidget *parent = nullptr);
	~SettingsWidget();

signals:
	void on_backToMenuButton_clicked();

private:
	Ui::SettingsWidgetClass ui;
};
