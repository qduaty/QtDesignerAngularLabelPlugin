#include "AngularLabel.h"
#include "QtDesignerAngularLabelPlugin.h"

#include <QtCore/QtPlugin>

QtDesignerAngularLabelPlugin::QtDesignerAngularLabelPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void QtDesignerAngularLabelPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool QtDesignerAngularLabelPlugin::isInitialized() const
{
    return initialized;
}

QWidget *QtDesignerAngularLabelPlugin::createWidget(QWidget *parent)
{
    return new AngularLabel(parent);
}

QString QtDesignerAngularLabelPlugin::name() const
{
    return "AngularLabel";
}

QString QtDesignerAngularLabelPlugin::group() const
{
    return "Display Widgets";
}

QIcon QtDesignerAngularLabelPlugin::icon() const
{
    return QIcon();
}

QString QtDesignerAngularLabelPlugin::toolTip() const
{
    return QString();
}

QString QtDesignerAngularLabelPlugin::whatsThis() const
{
    return QString();
}

bool QtDesignerAngularLabelPlugin::isContainer() const
{
    return false;
}

QString QtDesignerAngularLabelPlugin::domXml() const
{
    return "<widget class=\"AngularLabel\" name=\"label\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n";
}

QString QtDesignerAngularLabelPlugin::includeFile() const
{
    return "AngularLabel.h";
}
