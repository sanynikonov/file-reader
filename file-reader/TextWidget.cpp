#include <QtWidgets>
#include "TextWidget.h"

TextWidget::TextWidget(QWidget *parent)
    : QWidget(parent)
{
    QTextEdit *textEdit = new QTextEdit();
    textEdit->setText(text_);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(1, 1, 1, 1);
    mainLayout->addWidget(textEdit);
    setLayout(mainLayout);
}
