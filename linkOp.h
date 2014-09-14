/**************************************************************************************************/
/* Copyright (C) RootAmaris                                                                       */
/*                                                                                                */
/*  FILE NAME             :  linkOp.h                                                             */
/*  PRINCIPAL AUTHOR      :  RootAmaris                                                           */
/*  SUBSYSTEM NAME        :  linkOp                                                               */
/*  MODULE NAME           :  linkOp                                                               */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/13                                                           */
/*  DESCRIPTION           :  This is a link operation head file                                   */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by RootAmaris, 2014/09/13
 * 
 */

/* data struct and its operations */

typedef struct CmdNode
{
    char*   cmd;
    char*   desc;
    int (*show)();
    struct  CmdNode *next;
} tCmdNode;

tCmdNode* CreateCmdNode(char* nodeCmd, char* nodeDesc, int (*nodeShow)());

int ShowAllCmd(tCmdNode *head);

tCmdNode* InitCmdList();

tCmdNode* FindCmd(tCmdNode *head, char* inputCmd);
