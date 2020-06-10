#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile input("./IO/input.txt");
    QFile output("./IO/output.txt");

    if (input.exists() && output.exists())
    {
        input.open(QIODevice::ReadOnly);
        output.open(QIODevice::Append | QIODevice::Text);
        QTextStream outStream(&output);
        char characted;
        while (!input.atEnd())
        {
            input.read(&characted, sizeof(char));
            switch (characted)
            {
            case '\n':
                outStream << " ";
                break;
            case '\t':
                outStream << " ";
                break;
            default:
                outStream << characted;
            }
        }
        cout << "+++++ Success +++++";
    }
    else
        cout << "+++++ Fail +++++";

    input.close();
    output.close();

    return a.exec();
}
