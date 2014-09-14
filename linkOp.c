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

tCmdNode* CreateCmdNode(char* nodeCmd, char* nodeDesc, int (*nodeShow)())
{
    tCmdNode *p = NULL;
    p = (tCmdNode*)malloc(sizeof(tCmdNode));
    p->cmd = nodeCmd;
    p->desc = nodeDesc;
    p->show = nodeShow;
    p->next = NULL;
    return p;
}

int ShowAllCmd(tCmdNode *head)
{
    tCmdNode *p = NULL;
    p = head->next;
    if(p == NULL)
    {
        printf("There is no command.");
        return 2;
    }
    printf("This is my command list:\n");
    while(p != NULL)
    {
        printf("%s-------%s\n", p->cmd, p->desc);
        p = p->next;
    }
    return 0;
}


tCmdNode* InitCmdList()
{
    tCmdNode *head = NULL;
    tCmdNode *p = NULL;
    tCmdNode *q = NULL;
    head = CreateCmdNode(NULL, NULL, NULL);
    p = CreateCmdNode("cmdlist", "This command can show all commands!", ShowAllCmd);
    head->next = p;
    q = CreateCmdNode("clear", "This command can clear the screen!", NULL);
    p->next = q;
    p = q;
    q = CreateCmdNode("help", "This command can show you what all of these commands use for!", NULL);
    p->next = q;
    p = q;
    return head;
}

tCmdNode* FindCmd(tCmdNode *head, char* inputCmd)
{
    tCmdNode *p = NULL;
    p = head->next;
    while(p != NULL)
    {
        if(!strcmp(p->cmd, inputCmd))
        {
            break;
        }
	p = p->next;
    }
    return p;
}

