/**************************************************************************************************/
/* Copyright (C) RootAmaris                                                                       */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  RootAmaris                                                           */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/20                                                           */
/*  DESCRIPTION           :  This is a menu operation program                                     */
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
#include "linkTable.h"
#define CMD_MAX_LEN 128

int out = 0;
char pInputCmd[CMD_MAX_LEN];
char* deleteCmd;

/*command struct*/
typedef struct CmdNode
{
    tLinkNode *pNext;
    char* cmd;
    char* desc;
    int (*pOpt)();
} tCmdNode;

/*menu struct*/
struct Menu
{
    tLinkTable *pMenuHead;
};

/*create a menu*/
tMenu* CreateMenu()
{
    tMenu *pNewMenu = (tMenu*)malloc(sizeof(tMenu));
    tLinkTable *pNewLinkTable = CreateLinkTable();
    pNewMenu->pMenuHead = pNewLinkTable;
    return pNewMenu;
}

/*create linked list node*/
tCmdNode* CreateCmdNode(char* pNodeCmd, char* pNodeDesc, int (*pNodeOpt)())
{
    tCmdNode *pNewNode;
    pNewNode = (tCmdNode*)malloc(sizeof(tCmdNode));
    if(pNewNode == NULL)
    {
        printf("Error: command node create failed!\n");
        return NULL;
    }
    else
    {
        pNewNode->cmd = pNodeCmd;
        pNewNode->desc = pNodeDesc;
        pNewNode->pOpt = pNodeOpt;
    }
    return pNewNode;
}

/*add a command into menu*/
int AddCommand(tMenu *pMenu, char* pCommand, char* pDesc, int (*pOpt)())
{
    AddLinkNode(pMenu->pMenuHead, (tLinkNode *)CreateCmdNode(pCommand, pDesc, pOpt));
    return 0;
}

/*print all commands in menu on screen*/
int ShowAllCommand(tMenu *pMenu)
{
    tLinkTable *pLinkTable = pMenu->pMenuHead;
    if(pLinkTable->linkNodeSize == 0)
    {
        printf("There is no command.\n");
        return -1;
    }
    printf("This is my command list:\n");
    tCmdNode *pThisCmdNode;
    pThisCmdNode = (tCmdNode *)GetLinkTableFirst(pLinkTable);
    while(pThisCmdNode != NULL)
    {
        printf("%s     ", pThisCmdNode->cmd);
        printf("\n");
        pThisCmdNode = (tCmdNode *)GetNextLinkNode(pLinkTable, (tLinkNode *)pThisCmdNode);
    }
    return 0;
}

/*print all commands and their functions on screen*/
int ShowAllInformation(tMenu *pMenu)
{
    tLinkTable *pLinkTable = pMenu->pMenuHead;
    if(pLinkTable->linkNodeSize == 0)
    {
        return -1;
    }
    tCmdNode *pThisCmdNode;
    pThisCmdNode = (tCmdNode *)GetLinkTableFirst(pLinkTable);
    printf("\n");
    while(pThisCmdNode != NULL)
    {
        printf("%s-------%s\n", pThisCmdNode->cmd, pThisCmdNode->desc);
        pThisCmdNode = (tCmdNode *)GetNextLinkNode(pLinkTable, (tLinkNode *)pThisCmdNode);
    }
    return 0;
}

/*the condition of search the matched command*/
int InputCondition(tLinkNode *pLinkNode)
{
    tCmdNode *pNode = (tCmdNode *)pLinkNode;
    if(!strcmp(pNode->cmd, pInputCmd))
    {
        return 1;  
    }
    return 0;	       
}

/*start the menu program*/
int MenuStart(tMenu *pMenu)
{
    printf("\nMenu program start......\n");
    ShowAllInformation(pMenu);
    tCmdNode *pThisNode;
    while(1)
    {
        printf("\nMenu[Please enter a command]>");
        scanf("%s", pInputCmd);
        if((pThisNode = (tCmdNode *)SearchLinkNode(pMenu->pMenuHead, InputCondition)) != NULL)
        {
            if(pThisNode->pOpt != NULL)
            {
                pThisNode->pOpt(pMenu);
            }
        }
        else
        {
            printf("This command is not exist!\n");
	    continue;
        }
        if(out)
        {
            out = 0;
            break;           
        } 
    }
}

/*stop the menu program*/
int MenuStop(tMenu *pMenu)
{

    printf("exit success!\n\n");
    out = 1;
}

/*the condition of delete the matched command*/
int DeleteCondition(tLinkNode *pLinkNode)
{
    tCmdNode *pNode = (tCmdNode *)pLinkNode;
    if(!strcmp(pNode->cmd, deleteCmd))
    {
        return 1;
    }
    return 0;
}

/*delete command named pCommand*/
int DeleteCommand(tMenu *pMenu, char* pCommand)
{

    deleteCmd = pCommand;
    tLinkNode *pLinkNode = SearchLinkNode(pMenu->pMenuHead, DeleteCondition);
    if(!DeleteLinkNode(pMenu->pMenuHead, pLinkNode))
    {
        printf("Delete command (%s) success.\n", pCommand);
        return 0;
    }
    else
    {
        printf("Delete command (%s) failed.\n", pCommand);
        return -1;
    }
}

/*delete menu*/
int DeleteMenu(tMenu *pMenu)
{
    if(!DeleteLinkTable(pMenu->pMenuHead))
    {
        printf("Delete menu success!\n\n");
        free(pMenu);
        return 0;
    }
    else
    {
        printf("Delete menu failed!\n\n");
        return -1;
    }
}
