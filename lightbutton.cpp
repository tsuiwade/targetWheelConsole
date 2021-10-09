﻿#pragma execution_character_set("utf-8")

#include "lightbutton.h"
#include "qpainter.h"
#include "qpainterpath.h"
#include "qevent.h"
#include "qtimer.h"
#include "qdebug.h"

LightButton::LightButton(QWidget *parent) : QPushButton(parent)
{
    text = "";
    textColor = QColor(255, 255, 255);
    alarmColor = QColor(255, 107, 107);
    normalColor = QColor(10, 10, 10);

    borderOutColorStart = QColor(255, 255, 255);
    borderOutColorEnd = QColor(166, 166, 166);

    borderOutRadius = 99;
    borderInRadius = 90;
    bgRadius= 80;
    overlayRadius = 80;

    borderInColorStart = QColor(166, 166, 166);
    borderInColorEnd = QColor(255, 255, 255);

    bgColor = QColor(100, 184, 255);

    showRect = false;
    showOverlay = true;
    overlayColor = QColor(255, 255, 255);

    canMove = false;
    this->installEventFilter(this);

    isAlarm = false;
    timerAlarm = new QTimer(this);
    connect(timerAlarm, SIGNAL(timeout()), this, SLOT(alarm()));
    timerAlarm->setInterval(500);

    //setFont(QFont("Arial", 8));
}

bool LightButton::eventFilter(QObject *watched, QEvent *event)
{

    if (event->type() == QEvent::HoverEnter) //鼠标进入
    {
        this->bgRadius = 86;
        this->overlayRadius = 86;
        this->borderOutRadius=100;
        this->borderInRadius=93;
        this->update();
    }
    else if (event->type() == QEvent::HoverLeave)    //鼠标离开
    {
        this->borderOutRadius=99;
        this->borderInRadius=90;
        this->bgRadius = 80;
        this->overlayRadius = 80;
        this->update();
    }

    if (canMove) {
        static QPoint lastPoint;
        static bool pressed = false;
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);

        if (mouseEvent->type() == QEvent::MouseButtonPress) {
            if (this->rect().contains(mouseEvent->pos()) && (mouseEvent->button() == Qt::LeftButton)) {
                lastPoint = mouseEvent->pos();
                pressed = true;
            }
        } else if (mouseEvent->type() == QEvent::MouseMove && pressed) {
            int dx = mouseEvent->pos().x() - lastPoint.x();
            int dy = mouseEvent->pos().y() - lastPoint.y();
            this->move(this->x() + dx, this->y() + dy);
        } else if (mouseEvent->type() == QEvent::MouseButtonRelease && pressed) {
            pressed = false;
        }
    }

    return QWidget::eventFilter(watched, event);
}

void LightButton::paintEvent(QPaintEvent *)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    //绘制准备工作,启用反锯齿,平移坐标轴中心,等比例缩放
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    if (showRect) {
        //绘制矩形区域
        painter.setPen(Qt::NoPen);
        painter.setBrush(bgColor);
        painter.drawRoundedRect(this->rect(), 5, 5);

        //绘制文字
        if (!text.isEmpty()) {
            QFont font;
            font.setPixelSize(side - 20);
            painter.setFont(font);
            painter.setPen(textColor);
            painter.drawText(this->rect(), Qt::AlignCenter, text);
        }
    } else {
        painter.translate(width / 2, height / 2);
        painter.scale(side / 200.0, side / 200.0);

        //绘制外边框
        drawBorderOut(&painter,borderOutRadius);
        //绘制内边框
        drawBorderIn(&painter,borderInRadius);
        //绘制内部指示颜色
        drawBg(&painter,bgRadius);
        //绘制居中文字
        drawText(&painter);
        //绘制遮罩层
        drawOverlay(&painter,overlayRadius);
    }
}

void LightButton::drawBorderOut(QPainter *painter,int borderOutRadius  )
{
    //    int borderOutRadius = 99;
    painter->save();
    painter->setPen(Qt::NoPen);
    QLinearGradient borderGradient(0, -borderOutRadius, 0, borderOutRadius);
    borderGradient.setColorAt(0, borderOutColorStart);
    borderGradient.setColorAt(1, borderOutColorEnd);
    painter->setBrush(borderGradient);
    painter->drawEllipse(-borderOutRadius, -borderOutRadius, borderOutRadius * 2, borderOutRadius * 2);
    painter->restore();
}

void LightButton::drawBorderIn(QPainter *painter,int borderInRadius  )
{
    //    int radius = 90;
    painter->save();
    painter->setPen(Qt::NoPen);
    QLinearGradient borderGradient(0, -borderInRadius, 0, borderInRadius);
    borderGradient.setColorAt(0, borderInColorStart);
    borderGradient.setColorAt(1, borderInColorEnd);
    painter->setBrush(borderGradient);
    painter->drawEllipse(-borderInRadius, -borderInRadius, borderInRadius * 2, borderInRadius * 2);
    painter->restore();
}

void LightButton::drawBg(QPainter *painter, int bgRadius)
{
    //    int radius = 80;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(bgColor);
    painter->drawEllipse(-bgRadius, -bgRadius, bgRadius * 2, bgRadius * 2);
    painter->restore();
}

void LightButton::drawText(QPainter *painter)
{
    if (text.isEmpty()) {
        return;
    }

    int radius = 100;
    painter->save();

    QFont font;
    font.setPixelSize(bgRadius);
    painter->setFont(font);
    painter->setPen(textColor);
    QRect rect(-radius, -radius, radius * 2, radius * 2);
    painter->drawText(rect, Qt::AlignCenter, text);
    painter->restore();
}

void LightButton::drawOverlay(QPainter *painter,int overlayRadius )
{
    if (!showOverlay) {
        return;
    }

    //    int radius = 60;
    painter->save();
    painter->setPen(Qt::NoPen);

    QPainterPath smallCircle;
    QPainterPath bigCircle;
    overlayRadius -= 1;
    smallCircle.addEllipse(-overlayRadius, -overlayRadius, overlayRadius * 2, overlayRadius * 2);
    overlayRadius *= 2;
    bigCircle.addEllipse(-overlayRadius, -overlayRadius + 140, overlayRadius * 2, overlayRadius * 2);

    //高光的形状为小圆扣掉大圆的部分
    QPainterPath highlight = smallCircle - bigCircle;

    QLinearGradient linearGradient(0, -overlayRadius / 2, 0, 0);
    overlayColor.setAlpha(100);
    linearGradient.setColorAt(0.0, overlayColor);
    overlayColor.setAlpha(30);
    linearGradient.setColorAt(1.0, overlayColor);
    painter->setBrush(linearGradient);
    painter->rotate(-20);
    painter->drawPath(highlight);

    painter->restore();
}

QString LightButton::getText() const
{
    return this->text;
}

QColor LightButton::getTextColor() const
{
    return this->textColor;
}

QColor LightButton::getAlarmColor() const
{
    return this->alarmColor;
}

QColor LightButton::getNormalColor() const
{
    return this->normalColor;
}

QColor LightButton::getBorderOutColorStart() const
{
    return this->borderOutColorStart;
}

QColor LightButton::getBorderOutColorEnd() const
{
    return this->borderOutColorEnd;
}

QColor LightButton::getBorderInColorStart() const
{
    return this->borderInColorStart;
}

QColor LightButton::getBorderInColorEnd() const
{
    return this->borderInColorEnd;
}

QColor LightButton::getBgColor() const
{
    return this->bgColor;
}

bool LightButton::getCanMove() const
{
    return this->canMove;
}

bool LightButton::getShowRect() const
{
    return this->showRect;
}

bool LightButton::getShowOverlay() const
{
    return this->showOverlay;
}

QColor LightButton::getOverlayColor() const
{
    return this->overlayColor;
}

QSize LightButton::sizeHint() const
{
    return QSize(100, 100);
}

QSize LightButton::minimumSizeHint() const
{
    return QSize(10, 10);
}

void LightButton::setText(const QString &text)
{
    if (this->text != text) {
        this->text = text;
        this->update();
    }
}

void LightButton::setTextColor(const QColor &textColor)
{
    if (this->textColor != textColor) {
        this->textColor = textColor;
        this->update();
    }
}

void LightButton::setAlarmColor(const QColor &alarmColor)
{
    if (this->alarmColor != alarmColor) {
        this->alarmColor = alarmColor;
        this->update();
    }
}

void LightButton::setNormalColor(const QColor &normalColor)
{
    if (this->normalColor != normalColor) {
        this->normalColor = normalColor;
        this->update();
    }
}

void LightButton::setBorderOutColorStart(const QColor &borderOutColorStart)
{
    if (this->borderOutColorStart != borderOutColorStart) {
        this->borderOutColorStart = borderOutColorStart;
        this->update();
    }
}

void LightButton::setBorderOutColorEnd(const QColor &borderOutColorEnd)
{
    if (this->borderOutColorEnd != borderOutColorEnd) {
        this->borderOutColorEnd = borderOutColorEnd;
        this->update();
    }
}

void LightButton::setBorderInColorStart(const QColor &borderInColorStart)
{
    if (this->borderInColorStart != borderInColorStart) {
        this->borderInColorStart = borderInColorStart;
        this->update();
    }
}

void LightButton::setBorderInColorEnd(const QColor &borderInColorEnd)
{
    if (this->borderInColorEnd != borderInColorEnd) {
        this->borderInColorEnd = borderInColorEnd;
        this->update();
    }
}

void LightButton::setBgColor(const QColor &bgColor)
{
    if (this->bgColor != bgColor) {
        this->bgColor = bgColor;
        this->update();
    }
}

void LightButton::setBorderOutRadius(int value)
{
    this->borderOutRadius = value;
    this->update();
}

void LightButton::setBorderInRadius(int value)
{
    this->borderInRadius = value;
    this->update();
}
void LightButton::setBgRadius(int value)
{
    this->bgRadius = value;
    this->update();
}
void LightButton::setOverlayRadius(int value)
{
    this->overlayRadius = value;
    this->update();
}

void LightButton::setCanMove(bool canMove)
{
    if (this->canMove != canMove) {
        this->canMove = canMove;
        this->update();
    }
}

void LightButton::setShowRect(bool showRect)
{
    if (this->showRect != showRect) {
        this->showRect = showRect;
        this->update();
    }
}

void LightButton::setShowOverlay(bool showOverlay)
{
    if (this->showOverlay != showOverlay) {
        this->showOverlay = showOverlay;
        this->update();
    }
}

void LightButton::setOverlayColor(const QColor &overlayColor)
{
    if (this->overlayColor != overlayColor) {
        this->overlayColor = overlayColor;
        this->update();
    }
}

void LightButton::setGreen()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(0, 166, 0));
}

void LightButton::setRed()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(255, 0, 0));
}

void LightButton::setYellow()
{
    textColor = QColor(25, 50, 7);
    setBgColor(QColor(238, 238, 0));
}

void LightButton::setBlack()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(10, 10, 10));
}

void LightButton::setGray()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(129, 129, 129));
}

void LightButton::setBlue()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(0, 0, 166));
}

void LightButton::setLightBlue()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(100, 184, 255));
}

void LightButton::setLightRed()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(255, 107, 107));
}

void LightButton::setLightGreen()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(24, 189, 155));
}

void LightButton::startAlarm()
{
    if (!timerAlarm->isActive()) {
        timerAlarm->start();
    }
}

void LightButton::stopAlarm()
{
    if (timerAlarm->isActive()) {
        timerAlarm->stop();
    }
}

void LightButton::alarm()
{
    if (isAlarm) {
        textColor = QColor(255, 255, 255);
        bgColor = normalColor;
    } else {
        textColor = QColor(255, 255, 255);
        bgColor = alarmColor;
    }

    this->update();
    isAlarm = !isAlarm;
}
