
/**************************************************************************************************/
/* Copyright (C) RootAmaris                                                                       */
/*                                                                                                */
/* FILE NAME : SE-E1-PRE.c                                                                        */
/* PRINCIPAL AUTHOR : RootAmaris                                                                  */
/* SUBSYSTEM NAME : SE-E1-PRE                                                                     */
/* MODULE NAME : SE-E1-PRE                                                                        */
/* LANGUAGE : C                                                                                   */
/* TARGET ENVIRONMENT : ANY                                                                       */
/* DATE OF FIRST RELEASE : 2014/09/10                                                             */
/* DESCRIPTION : This is a menu program                                                           */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by RootAmaris, 2014/09/10
 * Add function FindCmd and ShowAllCmd by RootAmaris, 2014/09/10
 * Alter function main---while(1), 2014/09/10
 * Add function filelist, 2014/09/14
 * Delete command filelist, 2014/09/14
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* command linked list node struct */
typedef struct CmdNode
{
    char* cmd;
    char* desc;
    int (*pShow)();
    struct CmdNode *pNext;
} tCmdNode;

/*create linked list node*/
tCmdNode* CreateCmdNode(char* pNodeCmd, char* pNodeDesc, int (*pNodeShow)())
{
    tCmdNode *pNewNode;
    pNewNode = (tCmdNode*)malloc(sizeof(tCmdNode));
    if(pNewNode == NULL)
    {
        printf("\nError: command node create failed!\n");
    }
    else
    {
        pNewNode->cmd = pNodeCmd;
        pNewNode->desc = pNodeDesc;
        pNewNode->pShow = pNodeShow;
        pNewNode->pNext = NULL;
    }
    return pNewNode;
}

/*show all commands in linked list*/
int ShowAllCmd(tCmdNode *pHead)
{
    tCmdNode *pThisNode = NULL;
    pThisNode = pHead->pNext;
    if(pThisNode == NULL)
    {
        printf("There is no command.\n");
        return 2;
    }
    printf("\nThis is my command list:\n");
    while(pThisNode != NULL)
    {
        printf("     %s     ", pThisNode->cmd);
        printf("\n");
        pThisNode = pThisNode->pNext;
    }
    return 0;
}

/*show all information about all commands*/
int ShowAllInformation(tCmdNode *pHead)
{
    tCmdNode *pThisNode = NULL;
    pThisNode = pHead->pNext;
    if(pThisNode == NULL)
    {
        printf("There is no command.\n");
        return 2;
    }
    printf("\nThis is all command information:\n");
    while(pThisNode != NULL)
    {
        printf("\n%s-------%s\n", pThisNode->cmd, pThisNode->desc);
        pThisNode = pThisNode->pNext;
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
    pHead->pNext = pThisNode;
    qNextNode = CreateCmdNode("help",
                              "This command show you what all of these commands are use for!",
                               ShowAllInformation);
    pThisNode->pNext = qNextNode;
    pThisNode = qNextNode;
    return pHead;
}

/*find matched command*/
tCmdNode* FindCmd(tCmdNode *pHead, char* pInputCmd)
{
    tCmdNode *pThisNode = NULL;
    pThisNode = pHead->pNext;
    while(pThisNode != NULL)
    {
        if(!strcmp(pThisNode->cmd, pInputCmd))
        {
            break;
        }
        pThisNode = pThisNode->pNext;
    }
    return pThisNode;
}

/*menu program*/
int main()
{
    tCmdNode *pHead = NULL;
    tCmdNode *pThisNode;
    char* pInputCmd;
    pHead = InitCmdList();
    if(pHead == NULL)
    {
        printf("Error: linked list is not built!\n");
        return 1;
    }
    ShowAllCmd(pHead);
    while(1)
    {
        printf("\nftp[Please enter a command]>");
        scanf("%s", pInputCmd);
        if((pThisNode = FindCmd(pHead, pInputCmd)) != NULL)
        {
            printf("%s\n", pThisNode->desc);
            if(pThisNode->pShow != NULL)
            {
                pThisNode->pShow(pHead);
            }
        }
        else
        {
            printf("This command is not exist!\n");
	    continue;
        } 
    }
    return 0;
}
