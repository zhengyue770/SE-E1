/**************************************************************************************************/
/* Copyright (C) RootAmaris                                                                       */
/*                                                                                                */
/*  FILE NAME             :  linkOp.c                                                             */
/*  PRINCIPAL AUTHOR      :  RootAmaris                                                           */
/*  SUBSYSTEM NAME        :  linkOp                                                               */
/*  MODULE NAME           :  linkOp                                                               */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/13                                                           */
/*  DESCRIPTION           :  This is a link operation program                                     */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by RootAmaris, 2014/09/13
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include "linkOp.h"

/*create linked list node*/
tCmdNode* CreateCmdNode(char* pNodeCmd, char* pNodeDesc, int (*pNodeShow)())
{
    tCmdNode *pNewNode;
    pNewNode = (tCmdNode*)malloc(sizeof(tCmdNode));
    if(pNewNode == NULL)
    {
        printf("\nError: command node create failed!\n");
        return NULL;
    }
    else
    {
        pNewNode->cmd = pNodeCmd;
        pNewNode->desc = pNodeDesc;
        pNewNode->show = pNodeShow;
        pNewNode->next = NULL;
    }
    return pNewNode;
}

/*show all commands in linked list*/
int ShowAllCmd(tCmdNode *pHead)
{
    tCmdNode *pThisNode = NULL;
    pThisNode = pHead->next;
    if(pThisNode == NULL)
    {
        printf("There is no command.");
        return 2;
    }
    printf("\nThis is my command list:\n");
    while(pThisNode != NULL)
    {
        printf("     %s     ", pThisNode->cmd);
        pThisNode = pThisNode->next;
    }
    return 0;
}

/*show all information about all commands*/
int ShowAllInformation(tCmdNode *pHead)
{
    tCmdNode *pThisNode = NULL;
    pThisNode = pHead->next;
    if(pThisNode == NULL)
    {
        printf("There is no command.\n");
        return 2;
    }
    printf("\nThis is all command information:\n");
    while(pThisNode != NULL)
    {
        printf("\n%s-------%s\n", pThisNode->cmd, pThisNode->desc);
        pThisNode = pThisNode->next;
    }
    return 0;
}

/*initialize command linked list*/
tCmdNode* InitCmdList()
{
    tCmdNode *pHead = NULL;
    tCmdNode *pThisNode = NULL;
    tCmdNode *qNextNode = NULL;
    pHead = CreateCmdNode(NULL, NULL, NULL);
    if(pHead == NULL)
    {
        return NULL;
    }
    pThisNode = CreateCmdNode("cmdlist", "This command can show all commands!", ShowAllCmd);
    if(pThisNode == NULL)
    {
        return NULL;
    }
    pHead->next = pThisNode;
    qNextNode = CreateCmdNode("help", "This command can show you what all of these commands are use for!",
                               ShowAllInformation);
    if(qNextNode == NULL)
    {
        return NULL;
    }
    pThisNode->next = qNextNode;
    pThisNode = qNextNode;
    return pHead;
}

/*find matched command*/
tCmdNode* FindCmd(tCmdNode *pHead, char* pInputCmd)
{
    tCmdNode *pThisNode = NULL;
    pThisNode = pHead->next;
    while(pThisNode != NULL)
    {
        if(!strcmp(pThisNode->cmd, pInputCmd))
        {
            break;
        }
	pThisNode = pThisNode->next;
    }
    return pThisNode;
}

