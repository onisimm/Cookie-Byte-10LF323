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
