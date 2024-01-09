#include "SettingsWidget.h"

SettingsWidget::SettingsWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

SettingsWidget::~SettingsWidget()
{}

QString SettingsWidget::getGamemode() const
{
	return ui.gamemodeOption->currentText();
}

QString SettingsWidget::getPlayer1Name() const {
    QString name = ui.player1Nickname->text();
    return name.isEmpty() ? "Player1" : name;
}

QString SettingsWidget::getPlayer2Name() const {
    QString name = ui.player2Nickname->text();
    return name.isEmpty() ? "Player2" : name;
}

uint8_t SettingsWidget::getGameboardSize() const
{
    return ui.gameboardSize->value();
}

uint8_t SettingsWidget::getMaxDots() const
{
    return ui.maxDots->value();
}

uint8_t SettingsWidget::getMaxBridges() const
{
    return ui.maxBridges->value();
}
