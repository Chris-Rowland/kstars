/***************************************************************************
                          skylabel.h  -  K Desktop Planetarium
                             -------------------
    begin                : 2007/07/20
    copyright            : (C) 2007 by James B. Bowlin
    email                : bowlin@mindspring.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef SKYLABEL_H
#define SKYLABEL_H

#include <QPointF>
#include <QList>

class SkyLabel;
typedef QList<SkyLabel>                LabelList;

class SkyLabel {

    public:
        SkyLabel( qreal ra, qreal dec, const QString& text_in) : 
            o( ra, dec), text(text_in)
        {}

//        SkyLabel( double ra, double dec, QString& text_in) : 
//            o( ra, dec), text(text_in)
//        {}

        SkyLabel( const QPointF o_in, const QString& text_in) : o(o_in), text(text_in)
        {}

        //~StarLabel() { delete m_p; }

        QPointF& point() { return o; }
        QPointF  o;
        QString  text;
};

#endif
