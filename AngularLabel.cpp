#include "AngularLabel.h"

#include <QPainter>
#include <regex>

using namespace std;
namespace {
    inline QSize boundingBox(QSize size, double angle) {
        auto α = angle * 2 * M_PI / 360;
        return { int(abs(size.width() * cos(α)) + abs(size.height() * sin(α))), int(abs(size.width() * sin(α)) + abs(size.height() * cos(α))) };
    }
}

void AngularLabel::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    auto angle = property("angle").toDouble();
    angle = fmod(angle, 360);
    const auto currentSize = size();
    painter.translate(currentSize.width() / 2, currentSize.height() / 2);
    painter.rotate(angle);
    auto origSize = QLabel::minimumSizeHint();
    painter.translate(-origSize.width() / 2 - 4, -origSize.height() / 2 - 4);
    if (textFormat() == Qt::TextFormat::MarkdownText) doc.setMarkdown(text());
    else doc.setHtml(text());
    origSize.setWidth(origSize.width() + 5);
    origSize.setHeight(origSize.height() + 3);
    doc.drawContents(&painter, { {0, 0},  origSize });
}

QSize AngularLabel::sizeHint() const {
    auto angle = property("angle").toDouble();
    auto size = QLabel::sizeHint();
    return boundingBox(size, angle);
}

QSize AngularLabel::minimumSizeHint() const { 
    auto angle = property("angle").toDouble();
    auto size = QLabel::minimumSizeHint();
    return boundingBox(size, angle);
}

