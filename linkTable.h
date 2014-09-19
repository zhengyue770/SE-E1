/**************************************************************************************************/
/* Copyright (C) RootAmaris                                                                       */
/*                                                                                                */
/*  FILE NAME             :  linkTable.h                                                          */
/*  PRINCIPAL AUTHOR      :  RootAmaris                                                           */
/*  SUBSYSTEM NAME        :  linkTable                                                            */
/*  MODULE NAME           :  linkTable                                                            */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/16                                                           */
/*  DESCRIPTION           :  This is a linked list interface head file                            */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by RootAmaris, 2014/09/16
 * 
 */

typedef struct LinkNode
{
    struct LinkNode *pNext;
} tLinkNode;

typedef struct LinkTable
{
    tLinkNode *pHead;
    tLinkNode *pTail;
    int linkNodeSize;
} tLinkTable;

tLinkTable* CreateLinkTable();

int DeleteLinkTable(tLinkTable *pLinkTable);

int AddLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode);

int DeleteLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode);

tLinkNode* SearchLinkNode(tLinkTable *pLinkTable, int Condition(tLinkNode *pNode));

tLinkNode* GetNextLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode);

tLinkNode* GetLinkTableFirst(tLinkTable *pLinkTable);
