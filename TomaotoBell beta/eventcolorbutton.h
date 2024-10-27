#ifndef EVENTCOLORBUTTON_H
#define EVENTCOLORBUTTON_H

#include <QWidget>

class eventColorButton : public QWidget
{
    Q_OBJECT
private:
    QPixmap pic;
    QString leavepic;
    QString enterpic;
    QString presspic;
    QString releasepic;
public:
    explicit eventColorButton(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void enterEvent(QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

    void initializePixmaps(QString leavePixmapPath, QString enterPixmapPath,QString pressPixmapPath);

signals:
    void clicked();
};

#endif // EVENTCOLORBUTTON_H
