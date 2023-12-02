#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Create title label
    QLabel *titleLabel = new QLabel("Choose your Twixt gamemode:", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);

    // Create buttons
    QPushButton *defaultButton = new QPushButton("Default", this);
    QPushButton *bulldozerButton = new QPushButton("Bulldozer", this);
    QPushButton *minesButton = new QPushButton("Mines", this);

    // Connect button clicks to slots
    connect(defaultButton, SIGNAL(clicked()), this, SLOT(onDefaultButtonClicked()));
    connect(bulldozerButton, SIGNAL(clicked()), this, SLOT(onBulldozerButtonClicked()));
    connect(minesButton, SIGNAL(clicked()), this, SLOT(onMinesButtonClicked()));

    // Add buttons to the layout
    layout->addWidget(defaultButton);
    layout->addWidget(bulldozerButton);
    layout->addWidget(minesButton);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Set the main window properties
    setWindowTitle("Twixt Game");
    setFixedSize(400, 300);  // Adjust the size as needed
}

MainWindow::~MainWindow()
{
    // Destructor
}

void MainWindow::onDefaultButtonClicked()
{
    // TODO
}

void MainWindow::onBulldozerButtonClicked()
{
    // TODO
}

void MainWindow::onMinesButtonClicked()
{
    // TODO
}
