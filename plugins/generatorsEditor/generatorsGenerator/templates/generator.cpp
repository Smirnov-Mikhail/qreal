#include "generator.h"
#include "@@pathToQReal@@/qrutils/nameNormalizer.h"
#include <QtCore/QFile>
#include <QtCore/QDebug>

using namespace generators::@@generatorName@@;
using namespace qReal;
using namespace utils;

/// Generation target file
QString const templateDir = "./templates";
@@templateConstStringNames@@

Generator::Generator(QString const &outputDirPath
		, QString const &programName
		, qReal::LogicalModelAssistInterface const &logicalModel
		, qReal::ErrorReporterInterface &errorReporter
		)
	: AbstractGenerator(templateDir, QString(outputDirPath + "/" + programName).replace("\\", "/"), logicalModel, errorReporter)
	, mProgramName(programName)
{
}

Generator::~Generator()
{
}

bool Generator::isCorrectedName(QString const &name)
{
	QRegExp patten;
	patten.setPattern("[A-Za-z]+([A-Za-z_0-9]*)");
	return patten.exactMatch(name);
}

void Generator::generate()
{
	mErrorReporter.clear();
	mErrorReporter.clearErrors();

	if (!isCorrectedName(mProgramName)) {
		mErrorReporter.addError("Program name is not correct");
		return;
	}
@@generateBody@@
}
