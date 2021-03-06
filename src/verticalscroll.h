/*
 * Copyright (C) 2015 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     kirigaya <kirigaya@mkacg.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef VERTICALSCROLL_H
#define VERTICALSCROLL_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QPainter>

//滚动控件
class VerticalScroll : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int deviation WRITE setDeviation)
public:

    explicit VerticalScroll(QWidget *parent = nullptr);

    //设置范围
    void setRange(double min, double max);
    //获取当前值
    int readValue();
    //设置当前值
    void setCurrValue(int value);

protected:
    void mousePressEvent(QMouseEvent *) Q_DECL_OVERRIDE;

    void mouseMoveEvent(QMouseEvent *) Q_DECL_OVERRIDE;

    void mouseReleaseEvent(QMouseEvent *) Q_DECL_OVERRIDE;

    void wheelEvent(QWheelEvent *) Q_DECL_OVERRIDE;

    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    //描绘数字
    void paintNum(QPainter &painter, int num, int deviation);
    //使选中的数字回到屏幕中间
    void homing();
    //鼠标移动偏移量，默认为0
    int readDeviation();
    //设置偏移量
    void setDeviation(int n);

signals:

    void currentValueChanged(int value);

    void deviationChange(double deviation);

private:
    int m_minRange;      //最小值
    int m_maxRange;      //最大值
    int m_currentValue;  //当前选中的值
    bool isDragging;        //鼠标是否按下
    int m_deviation;        //偏移量,记录鼠标按下后移动的垂直距离
    int m_mouseSrcPos;
    int m_numSize;
    QPropertyAnimation *homingAni;
    int interval;  //间隔大小
    int devide;       //分隔数量
    int m_currentY;   //当前选中值的中点值
    int m_Devideheight; //间隔高

    bool m_bClicked; //点选
};

#endif // VERTICALSCROLL_H
