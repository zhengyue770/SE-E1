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

int main()
{
    tMenu *pMenu = CreateMenu();
    AddCommand(pMenu, "help", "This command show all commands!", ShowAllCommand);
    AddCommand(pMenu, "cmdlist", "This command show you what all of these commands are use for!", ShowAllInformation);
    AddCommand(pMenu, "version", "This command show version number!", NULL);
    ShowAllCommand(pMenu);
    MenuStart(pMenu);
    return 0;
}


