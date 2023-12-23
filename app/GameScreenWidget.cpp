#include "GameScreenWidget.h"
#include "ui_GameScreenWidget.h"

GameScreenWidget::GameScreenWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::GameScreenWidget),
    gameBoard(new GameBoardWidget(this)) // Initialize the game board
{
    ui->setupUi(this);

    ui->mainLayout->addWidget(gameBoard);

    setupConnections();
}

void GameScreenWidget::setupConnections()
{
    connect(ui->backToMenuButton, &QPushButton::clicked, this, &GameScreenWidget::on_backToMenuButton_clicked);
}

GameScreenWidget::~GameScreenWidget() {
    delete ui; // ui is deleted and it will automatically delete child widgets (including gameBoard if added to ui)
}
