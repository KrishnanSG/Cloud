#include "controller.h"
#include <cstdio>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>
#include <QDir>

void get_files(QString remote,QString local)      // for files
{
    QProcess::execute("skicka download pixel-database/"+remote+" "+local);
}

Controller::Controller(char username[16])
{
    page=5;
    strcpy(current_user,username);
    while(1)
    {
        if(page==1)
        {
            HomePage H(current_user);
            H.show();
            H.exec();
            page=H.result();
            H.close();
        }
        else if(page==2)
        {
            Search_Page S(current_user);
            S.show();
            S.exec();
            page=S.result();
            S.close();
        }
        else if(page==3)
        {
            Uploadpage U(current_user);
            U.show();
            U.exec();
            page=U.result();
            U.close();
        }
        else if(page==4)
        {
            Notifications_Page N(current_user);
            N.show();
            N.exec();
            page=N.result();
            N.close();
        }
        else if(page==5)
        {
            User_Page UP(current_user);
            UP.show();
            UP.exec();
            page=UP.result();
            UP.close();
        }
        if(page==0)
        {
            QDir dir;
            if(dir.exists(QDir::homePath() + "/pixel-database/Feedpage_pics"))
            {
                QDir deleting(QDir::homePath() + "/pixel-database/Feedpage_pics");
                deleting.removeRecursively();
            }
            exit(0);
        }
        else
        {
            QtConcurrent::run(get_files,QString(current_user)+"/Request.txt",QString(current_user)+"/");
            QtConcurrent::run(get_files,QString(current_user)+"/notification.txt",QString(current_user)+"/");
            QtConcurrent::run(get_files,QString(current_user)+"/friends.txt",QString(current_user)+"/");
            QtConcurrent::run(get_files,QString("/database.dat"),QString("database.dat"));
        }

    }
}
