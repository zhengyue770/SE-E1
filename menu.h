/**************************************************************************************************/
/* Copyright (C) RootAmaris                                                                       */
/*                                                                                                */
/*  FILE NAME             :  menu.h                                                               */
/*  PRINCIPAL AUTHOR      :  RootAmaris                                                           */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/19                                                           */
/*  DESCRIPTION           :  This is a menu interface head file                                   */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by RootAmaris, 2014/09/19
 * 
 */

#include "linkTable.h"

typedef struct CmdNode
{
    tLinkNode *pNext;
    char* cmd;
    char* desc;
} tCmdNode;

typedef struct Menu
{
    tLinkTable *pMenuHead;
} tMenu;

tMenu* CreateMenu();

int AddCommand(tMenu *pMenu, char* pCommand, char* pDesc);

int ShowAllCommand(tMenu *pMenu);
