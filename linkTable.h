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

/*linked list node struct*/
typedef struct LinkNode
{
    struct LinkNode *pNext;
} tLinkNode;

/*linked list table struct*/
typedef struct LinkTable
{
    tLinkNode *pHead;
    tLinkNode *pTail;
    int linkNodeSize;
} tLinkTable;

/*create a linked list table*/
tLinkTable* CreateLinkTable();

/*delete the linked list table*/
int DeleteLinkTable(tLinkTable *pLinkTable);

/*add a node into linked list*/
int AddLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode);

/*delete a node in linked list*/
int DeleteLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode);

/*search a linked list node with condition*/
tLinkNode* SearchLinkNode(tLinkTable *pLinkTable, int Condition(tLinkNode *pNode));

/*get next linked list node*/
tLinkNode* GetNextLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode);

/*get first node in linked list table*/
tLinkNode* GetLinkTableFirst(tLinkTable *pLinkTable);
