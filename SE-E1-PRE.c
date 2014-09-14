
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
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* command linked list node struct */
typedef struct CmdNode
{
    char* cmd;
    char* desc;
    int (*show)();
    struct CmdNode *next;
} tCmdNode;

/*create linked list node*/
tCmdNode* CreateCmdNode(char* nodeCmd, char* nodeDesc, int (*nodeShow)())
{
    tCmdNode *p;
    p = (tCmdNode*)malloc(sizeof(tCmdNode));
    if(p == NULL)
    {
        printf("\nError: command node create failed!\n");
    }
    else
    {
        p->cmd = nodeCmd;
        p->desc = nodeDesc;
        p->show = nodeShow;
        p->next = NULL;
    }
    return p;
}

/*show all commands in linked list*/
int ShowAllCmd(tCmdNode *head)
{
    tCmdNode *p = NULL;
    p = head->next;
    if(p == NULL)
    {
        printf("There is no command.\n");
        return 2;
    }
    printf("\nThis is my command list:\n");
    while(p != NULL)
    {
        printf("     %s     ", p->cmd);
        printf("\n");
        p = p->next;
    }
    return 0;
}

/*show all information about all commands*/
int ShowAllInformation(tCmdNode *head)
{
    tCmdNode *p = NULL;
    p = head->next;
    if(p == NULL)
    {
        printf("There is no command.\n");
        return 2;
    }
    printf("\nThis is all command information:\n");
    while(p != NULL)
    {
        printf("\n%s-------%s\n", p->cmd, p->desc);
        p = p->next;
    }
    return 0;
}

/*show all files in current path*/
int ShowFile(tCmdNode *head)
{
    printf("\n");
    execl("/bin/ls", "ls", NULL);
    printf("\n");
    return 0;
}

/*initialize command linked list*/
tCmdNode* InitCmdList()
{
    tCmdNode *head = NULL;
    tCmdNode *p = NULL;
    tCmdNode *q = NULL;
    head = CreateCmdNode(NULL, NULL, NULL);
    if(head == NULL)
    {
        return NULL;
    }
    p = CreateCmdNode("cmdlist", "This command can show all commands!", ShowAllCmd);
    head->next = p;
    q = CreateCmdNode("help", "This command can show you what all of these commands are use for!", ShowAllInformation);
    p->next = q;
    p = q;
    return head;
}

/*find matched command*/
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

/*menu program*/
int main()
{
    tCmdNode *head = NULL;
    tCmdNode *p;
    char* inputCmd;
    head = InitCmdList();
    if(head == NULL)
    {
        printf("Error: linked list is not built!\n");
        return 1;
    }
    ShowAllCmd(head);
    while(1)
    {
        printf("\nftp[Please enter a command]>");
        scanf("%s", inputCmd);
        if((p = FindCmd(head, inputCmd)) != NULL)
        {
            printf("%s\n", p->desc);
            if(p->show != NULL)
            {
                p->show(head);
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
