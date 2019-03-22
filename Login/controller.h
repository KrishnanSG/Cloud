#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "homepage.h"
#include "search_page.h"
#include "uploadpage.h"
#include "notifications_page.h"
#include "user_page.h"

class Controller
{
public:
    Controller(char username[16]);
private:
    int page;
    char current_user[16];
};

#endif // CONTROLLER_H
