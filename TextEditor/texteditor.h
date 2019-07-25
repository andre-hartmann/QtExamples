#pragma once

#include <QPlainTextEdit>

class TextEditor : public QPlainTextEdit
{
public:
    TextEditor(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;
};
