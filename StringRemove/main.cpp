#include <QDebug>
#include <QRegularExpression>

int main(int argc, char *argv[])
{
    QString s = "%$Hello/World![";

    // Remove everything that is not a letter
    s.remove(QRegularExpression("[^\\p{L}]"));

    qDebug() << "s =" << s;
}
