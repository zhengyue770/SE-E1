/**************************************************************************************************/
/* Copyright (C) RootAmaris                                                                       */
/*                                                                                                */
/*  FILE NAME             :  linkTableTest.c                                                      */
/*  PRINCIPAL AUTHOR      :  RootAmaris                                                           */
/*  SUBSYSTEM NAME        :  linkTestTable                                                        */
/*  MODULE NAME           :  linkTestTable                                                        */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/19                                                           */
/*  DESCRIPTION           :  This is a link table test program                                    */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by RootAmaris, 2014/09/19
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkTable.h"

typedef struct CmdNode
{    
    tLinkNode *pNext;
    char* cmd;
    char* desc;    
} tCmdNode;

/*create linked list node*/
tCmdNode* CreateCmdNode(char* pNodeCmd, char* pNodeDesc)
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
    }
    return pNewNode;
}

/*show all commands in linked list*/
int ShowAllCmd(tLinkTable *pLinkTable)
{
    if(pLinkTable->linkNodeSize == 0)
    {
        printf("There is no command.\n");
        return 2;
    }
    printf("This is my command list:\n");
    tCmdNode *pThisCmdNode;
    pThisCmdNode = (tCmdNode *)GetLinkTableFirst(pLinkTable);
    while(pThisCmdNode != NULL)
    {
        printf("     %s     ", pThisCmdNode->cmd);
        printf("\n");
        pThisCmdNode = (tCmdNode *)GetNextLinkNode(pLinkTable, (tLinkNode *)pThisCmdNode);
    }
    return 0;
}

tLinkTable* InitCmd()
{
    tLinkTable *pMyLinkTable = CreateLinkTable();
    AddLinkNode(pMyLinkTable, (tLinkNode *)CreateCmdNode("help", "This command can show all commands!"));
    AddLinkNode(pMyLinkTable, (tLinkNode *)CreateCmdNode("cmdlist",
                                                         "This command can show all desperation!"));

    return pMyLinkTable;
}

int main()
{
    tLinkTable *pCmdTable = InitCmd();
    ShowAllCmd(pCmdTable);
    return 0;
}
