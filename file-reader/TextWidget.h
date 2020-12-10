#include <QMainWindow>

#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

class TextWidget : public QWidget
{
    Q_OBJECT

private:
    QString text_;

public:
    TextWidget(QWidget *parent = nullptr);
    ~TextWidget();

    void setText(QString text);
};

#endif // TEXTWIDGET_H
