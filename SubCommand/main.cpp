#include <QCommandLineParser>
#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCommandLineParser parser;
    parser.setOptionsAfterPositionalArgumentsMode(QCommandLineParser::ParseAsOptions);
    parser.addPositionalArgument("subcommand",
            "cherry-pick\n"
            "pull\n"
            "push\n"
            );

    QTextStream cout(stdout);
    QTextStream cerr(stderr);

    parser.parse(app.arguments());
    QStringList args = parser.positionalArguments();
    if (args.isEmpty()) {
        cerr << "Missing subcommand!" << endl;
        cerr << parser.helpText();
        return 1;
    }

    const QString subCommand = args.first();
    if (subCommand == "cherry-pick") {
        parser.addPositionalArgument("hash", "The commit hash to cherry-pick.");
        const QCommandLineOption editOption("edit", "Edit commit message after cherry-pick");
        parser.addOption(editOption);
    } else if (subCommand == "pull") {
        parser.addPositionalArgument("branch", "The remote branch to pull from.");
    } else if (subCommand == "push") {
        parser.addPositionalArgument("branch", "The remote branch to push to.");
    } else {
        cerr << "Invalid subcommand!" << endl;
        cerr << parser.helpText();
    }

    parser.parse(app.arguments());
    parser.clearPositionalArguments();
    args = parser.positionalArguments();

    if (args.size() < 2) {
        cerr << "Mission command line parameter" << endl;
        cerr << parser.helpText();
        return 1;
    }

    return 0;
}
