#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "homepage.h"
#include "search_page.h"
#include "uploadpage.h"
#include "notifications_page.h"
#include "user_page.h"


/*
  This class called Controller is important for any GUI application
  based on MVC model.
 *  Model      - where data is recieved and manuplation takes place
 *  View       - the ui files
 *  Controller - joins Model with the View and controls logic
                 based on user actions.
 */

class Controller
{
public:
    Controller(char username[16]);
private:
    int page;
    char current_user[16];
};

#endif // CONTROLLER_H
