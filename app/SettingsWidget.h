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
	uint8_t getGameboardSize() const;
	uint8_t getMaxDots() const;
	uint8_t getMaxBridges() const;

signals:
	void on_backToMenuButton_clicked();

private:
	Ui::SettingsWidgetClass ui;
};
