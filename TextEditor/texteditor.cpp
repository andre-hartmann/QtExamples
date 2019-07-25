#include "texteditor.h"

TextEditor::TextEditor(QWidget *parent) :
    QPlainTextEdit(parent)
{
}

void TextEditor::keyPressEvent(QKeyEvent *e)
{
    QChar lastChar = document()->characterAt(textCursor().position() - 1);
    QChar secondLastChar = document()->characterAt(textCursor().position() - 2);

    // If we are at the beginning of text, start a new line,
    // or start a new sentence, include an uppercase letter
    if (textCursor().atStart()
            || lastChar == QChar::ParagraphSeparator
            || lastChar == QChar::LineSeparator
            || (lastChar == QChar::Space && secondLastChar == '.')) {
        QKeyEvent event(e->type(), e->key(), e->modifiers() | Qt::ShiftModifier,
                        e->text().toUpper(), e->isAutoRepeat(), ushort(e->count()));

        QPlainTextEdit::keyPressEvent(&event);
        return;
    }

    QPlainTextEdit::keyPressEvent(e);
}
