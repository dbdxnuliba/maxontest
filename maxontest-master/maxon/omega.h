#ifndef OMEGA_H
#define OMEGA_H

#include <QWidget>
#include "dhdc.h"
#include "omega/OmegaFunction.h"

namespace Ui {
class omega;
}

class omega : public QWidget
{
    Q_OBJECT

public:
    explicit omega(OmegaFunction* omegaFunc, QWidget *parent = nullptr);
    ~omega();

    void init();
    void closeOmega();
    int getStatus();
    void showParameter();
    void setForce();

protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_openButton_clicked();

    void on_closeButton_clicked();

    void on_setForceButton_clicked();

    void on_forceXSetEdit_editingFinished();

    void on_forceYSetEdit_editingFinished();

    void on_forceZSetEdit_editingFinished();

private:
    Ui::omega *ui;
    OmegaFunction *m_omegaFunc;
    bool m_startThread;
    bool m_setForceDone;
    bool m_isOpen;
    double initFx, initFy, initFz, initTx, initTy, initTz;
    double forcex, forcey, forcez, tx, ty, tz;
};

#endif // OMEGA_H
