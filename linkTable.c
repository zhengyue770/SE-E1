/**************************************************************************************************/
/* Copyright (C) RootAmaris                                                                       */
/*                                                                                                */
/*  FILE NAME             :  linkTable.c                                                          */
/*  PRINCIPAL AUTHOR      :  RootAmaris                                                           */
/*  SUBSYSTEM NAME        :  linkTable                                                            */
/*  MODULE NAME           :  linkTable                                                            */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/16                                                           */
/*  DESCRIPTION           :  This is a linked list operation program                              */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by RootAmaris, 2014/09/16
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkTable.h"

tLinkTable* CreateLinkTable()
{
    tLinkTable *pLinkTable = (tLinkTable*)malloc(sizeof(tLinkTable));
    if(pLinkTable == NULL)
    {
        return NULL;
    }
    tLinkNode *pHeadNode = (tLinkNode*)malloc(sizeof(tLinkNode));
    pHeadNode->pNext = NULL;
    pLinkTable->pHead = pHeadNode;
    pLinkTable->pTail = pHeadNode;
    pLinkTable->linkNodeSize = 0;
    return pLinkTable;
}

int DeleteLinkTable(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL)
    {
        printf("Error(1): The link table is not exist.\n");
        return 1;
    }
    tLinkNode *pThisNode;
    pThisNode = pLinkTable->pHead->pNext;
    while(pThisNode != NULL)
    {
        tLinkNode *pFreeNode;
        pLinkTable->pHead->pNext = pThisNode->pNext;
        pFreeNode = pThisNode;
        pThisNode = pThisNode->pNext;
        pFreeNode->pNext = NULL;
        free(pFreeNode);
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->linkNodeSize = -1;
    free(pLinkTable);
    return 0;
}

int AddLinkNode(tLinkTable *pLinkTable, tLinkNode *pAddNode)
{
    if(pLinkTable == NULL || pAddNode == NULL)
    {
        printf("Error(1): The link table or node you add is not exist.\n");
        return 1;
    }
    if(pLinkTable->linkNodeSize == 0)
    {
        pLinkTable->pHead->pNext = pAddNode;
        pAddNode->pNext = NULL;
        pLinkTable->pTail = pAddNode;
    }
    else
    {
        pAddNode->pNext = pLinkTable->pHead->pNext;
        pLinkTable->pHead->pNext = pAddNode;
    }
    pLinkTable->linkNodeSize++;
    return 0;
}

int DeleteLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    {
        printf("Error(1): The link table or node you add is not exist.\n");
        return 1;
    }
    tLinkNode *pThisNode;
    tLinkNode *pBeforeNode;
    pThisNode = pLinkTable->pHead->pNext;
    pBeforeNode = pLinkTable->pHead;
    while(pThisNode != NULL)
    {
        if(pThisNode == pNode)
        {
            pBeforeNode->pNext = pThisNode->pNext;
            if(pThisNode->pNext == NULL)
            {
                pLinkTable->pTail = pBeforeNode;
            }
            pThisNode->pNext = NULL;
            free(pThisNode);
            pLinkTable->linkNodeSize--;
            return 0;
        }
        pBeforeNode = pThisNode;
        pThisNode = pThisNode->pNext;
    }
    printf("There is no match node you want to delete.\n");
    return 0;
}

tLinkNode* SearchLinkNode(tLinkTable *pLinkTable, int Condition(tLinkNode *pNode))
{
    if(pLinkTable == NULL || Condition == NULL)
    {
        printf("Error(1): The link table or node you add is not exist.\n");
        return NULL;
    }
    tLinkNode *pNode = pLinkTable->pHead->pNext;
    while(pNode != NULL)
    {
        if(Condition(pNode))
        {
            return pNode;
        }
        pNode = pNode->pNext;
    }
    return NULL;
}

tLinkNode* GetNextLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    {
        printf("Error(1): The link table or node you add is not exist.\n");
        return NULL;
    }
    if(pLinkTable->linkNodeSize == 0)
    {
        printf("Error(2): There is no node in this link table.\n");
        return NULL;
    }
    tLinkNode *pThisNode;
    pThisNode = pLinkTable->pHead->pNext;
    while(pThisNode != NULL)
    {
        if(pThisNode == pNode)
        {
            if(pThisNode == pLinkTable->pTail)
            {
                return NULL;
            }
            return pThisNode->pNext;
        }
        pThisNode = pThisNode->pNext;
    }
    return NULL;
}

tLinkNode* GetLinkTableFirst(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL)
    {
        printf("Error(1): The link table is not exist.\n");
        return NULL;
    }
    return pLinkTable->pHead->pNext;
}
