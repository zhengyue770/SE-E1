
/**************************************************************************************************/
/* Copyright (C) RootAmaris                                                                       */
/*                                                                                                */
/*  FILE NAME             :  SE-E1.c                                                              */
/*  PRINCIPAL AUTHOR      :  RootAmaris                                                           */
/*  SUBSYSTEM NAME        :  SE-E1                                                                */
/*  MODULE NAME           :  SE-E1                                                                */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/10                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by RootAmaris, 2014/09/10
 * Add function FindCmd and ShowAllCmd by RootAmaris, 2014/09/10
 * Alter function main---while(1), 2014/09/10
 *
 */


#include <stdio.h>
#include <stdlib.h>

#define CMD_MAX_LEN 128

/* data struct and its operations */

typedef struct CmdNode
{
    char*   cmd;
    char*   desc;
    struct  CmdNode *next;
} tCmdNode;

tCmdNode* CreateCmdNode(char* nodeCmd, char* nodeDesc)
{
    tCmdNode *p;
    p = (tCmdNode*)malloc(sizeof(tCmdNode));
    p->cmd = nodeCmd;
    p->desc = nodeDesc;
    p->next = NULL;
    return p;
}

tCmdNode* InitCmdList()
{
    tCmdNode *head;
    tCmdNode *p;
    tCmdNode *q;
    head = CreateCmdNode(NULL, NULL);
    p = CreateCmdNode("cmdlist", "This command can show all commands!");
    head->next = p;
    q = CreateCmdNode("clear", "This command can clear the screen!");
    p->next = q;
    p = q;
    q = CreateCmdNode("help", "This command can show you what all of these commands use for!");
    p->next = q;
    p = q;
    return head;
}

tCmdNode* FindCmd(tCmdNode *head, char* inputCmd)
{
    tCmdNode *p;
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

int ShowAllCmd(tCmdNode *head)
{
    tCmdNode *p;
    p = head->next;
    printf("This is my command list:\n");
    while(p != NULL)
    {
        printf("%s-------%s\n", p->cmd, p->desc);
        p = p->next;
    }
    return 0;
}

int main()
{
    tCmdNode *head;
    tCmdNode *p;
    char* inputCmd;
    head = InitCmdList();
    ShowAllCmd(head);
    while(1)
    {
        printf("Please enter a command:");
        scanf("%s", inputCmd);
	if((p = FindCmd(head, inputCmd)) != NULL)
	{
	    printf("%s\n", p->desc);
	    if(!strcmp(p->cmd, "cmdlist"))
	    {
		ShowAllCmd(head);
  	    }
	}
	else
	{
	    printf("This command is not exist!\n");
	}
    }
    return 0;
}
