#ifndef TOGGLEBUTTON_H
#define TOGGLEBUTTON_H


#include <QWidget>

class toggleButton : public QWidget
{
    Q_OBJECT
private:
    QPixmap pic;
    QString leavepic;
    QString enterpic;
    QString presspic;
    QString releasepic;
public:
    explicit toggleButton(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void enterEvent(QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

    void initializePixmaps(QString leavePixmapPath, QString enterPixmapPath,QString pressPixmapPath);

signals:
    void clicked();
};

#endif
