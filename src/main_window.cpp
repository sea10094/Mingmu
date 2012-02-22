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

#include <QtGui>

#include "main_window.h"

MainWindow::MainWindow()
{
    createActions();
    createToolBar();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void MainWindow::createActions()
{
    QDEBUG << "Creating actions...";
    taskNewAction = new QAction(QIcon::fromTheme("document-new"),
            tr("&New Task"), this);
    quitAction = new QAction(QIcon::fromTheme("application-exit"),
            tr("&Quit"), this);
    QDEBUG << "Actions created.";
}

void MainWindow::createToolBar()
{
    QDEBUG << "Creating ToolBar...";

    toolbar = addToolBar(tr("Main"));
    toolbar->addAction(taskNewAction);
    toolbar->addSeparator();
    toolbar->addAction(quitAction);

    QDEBUG << "ToolBar created.";
}

#include "main_window.moc"

