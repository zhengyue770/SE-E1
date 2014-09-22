/**************************************************************************************************/
/* Copyright (C) RootAmaris                                                                       */
/*                                                                                                */
/*  FILE NAME             :  menuTest.c                                                           */
/*  PRINCIPAL AUTHOR      :  RootAmaris                                                           */
/*  SUBSYSTEM NAME        :  menuTest                                                             */
/*  MODULE NAME           :  menuTest                                                             */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/20                                                           */
/*  DESCRIPTION           :  This is a menu test program                                          */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by RootAmaris, 2014/09/20
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int GetVersion(tMenu *pMenu);

int main()
{
    tMenu *pMenu = CreateMenu();
    AddCommand(pMenu, "cmdlist", "This command show all commands!", ShowAllCommand);
    AddCommand(pMenu, "help", "This command show you what all of these commands are use for!",
               ShowAllInformation);
    AddCommand(pMenu, "version", "This command show version number!", GetVersion);
    AddCommand(pMenu, "exit", "This command can exit menu!", MenuStop);
    MenuStart(pMenu);
    DeleteCommand(pMenu, "version");
    MenuStart(pMenu);
    DeleteMenu(pMenu);
    ShowAllInformation(pMenu);
    return 0;
}

int GetVersion(tMenu *pMenu)
{
    printf("Version: v1.2\n");
    return 0;
}


