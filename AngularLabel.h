#ifndef ANGULARLABEL_H
#define ANGULARLABEL_H

#include <QLabel>

class AngularLabel : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(double angle MEMBER angle NOTIFY angleChanged) 
public:
    explicit AngularLabel(QWidget* parent = 0): QLabel(parent) { }
    explicit AngularLabel(const QString& text, QWidget* parent = 0) : QLabel(text, parent) { }
signals:
    void angleChanged(double);
protected:
    void paintEvent(QPaintEvent*);
    QSize sizeHint() const;
    QSize minimumSizeHint() const;
private:
    double angle = 0;
    QTextDocument doc;
};

#endif // ANGULARLABEL_H
