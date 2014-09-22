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

/*command node struct*/
typedef struct CmdNode tCmdNode;

/*menu struct*/
typedef struct Menu tMenu;

/*create a menu*/
tMenu* CreateMenu();

/*add a command into menu*/
int AddCommand(tMenu *pMenu, char* pCommand, char* pDesc, int (*pOpt)());

/*print all commands in menu on screen*/
int ShowAllCommand(tMenu *pMenu);

/*print all commands and their functions on screen*/
int ShowAllInformation(tMenu *pMenu);

/*start the menu program*/
int MenuStart(tMenu *Menu);

/*stop the menu program*/
int MenuStop(tMenu *pMenu);

/*delete command named pCommand*/
int DeleteCommand(tMenu *pMenu, char* pCommand);

/*delete menu*/
int DeleteMenu(tMenu *pMenu);
