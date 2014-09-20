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
    AddCommand(pMenu, "help", "This command can show all commands!");
    AddCommand(pMenu, "cmdlist","hahahha");
    ShowAllCommand(pMenu);
    return 0;
}
