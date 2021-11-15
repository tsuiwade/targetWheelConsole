/********************************************************************************
** Form generated from reading UI file 'mask_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASK_WIDGET_H
#define UI_MASK_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_MaskWidget
{
public:

    void setupUi(QDialog *MaskWidget)
    {
        if (MaskWidget->objectName().isEmpty())
            MaskWidget->setObjectName(QString::fromUtf8("MaskWidget"));
        MaskWidget->resize(400, 300);
        MaskWidget->setStyleSheet(QString::fromUtf8("QDialog{\n"
"	background-color: rgba(0, 0, 0, 0.4);\n"
"}"));

        retranslateUi(MaskWidget);

        QMetaObject::connectSlotsByName(MaskWidget);
    } // setupUi

    void retranslateUi(QDialog *MaskWidget)
    {
        MaskWidget->setWindowTitle(QCoreApplication::translate("MaskWidget", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MaskWidget: public Ui_MaskWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASK_WIDGET_H
