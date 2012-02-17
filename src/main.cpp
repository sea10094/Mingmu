/*
 *  mingmu - Aria2 based download utility
 *  Copyright (C) 2012  Iven Hsu <ivenvd#gmail.com>
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QtGui/QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLabel>

const QString TS_PREFIX("mingmu_");

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Setup translator
    QTranslator translator;
    translator.load(TS_PREFIX + QLocale::system().name(), ":/ts/");
    app.installTranslator(&translator);

    QLabel label(QLabel::tr("Hello world!"));
    label.show();

    return app.exec();
}

