/**
  * This file is part of the KDE project
  * Copyright (C) 2009 Kevin Ottens <ervin@kde.org>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Library General Public
  * License as published by the Free Software Foundation; either
  * version 2 of the License, or (at your option) any later version.
  *
  * This library is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  * Library General Public License for more details.
  *
  * You should have received a copy of the GNU Library General Public License
  * along with this library; see the file COPYING.LIB.  If not, write to
  * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  * Boston, MA 02110-1301, USA.
  */

#ifndef SODEPCLIENT_H
#define SODEPCLIENT_H

#include <QtCore/QtGlobal>

class QIODevice;
class QObject;

class SodepClientPrivate;
class SodepMessage;
class SodepPendingCall;

class Q_DECL_EXPORT SodepClient
{
public:
    enum Error
    {
        NoError,
        UnexpectedClose,
        UnkownError
    };

    explicit SodepClient(const QString &hostName, quint16 port);
    ~SodepClient();

    Error error() const;
    QString errorString() const;

    SodepPendingCall asyncCall(const SodepMessage &message);
    SodepMessage call(const SodepMessage &message);
    void callNoReply(const SodepMessage &message);

private:
    friend class SodepClientPrivate;
    SodepClientPrivate * const d;
};

#endif
