
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
 * Add struct member (*show)(), 2014/09/12
 * Modularity, 2014/09/13
 * Add some judgments of null pointer, 2014/09/14
 * Alter names of two pointers---head and inputCmd, 2014/09/16
 */


#include <stdio.h>
#include <stdlib.h>
#include "linkOp.h"

int main()
{
    tCmdNode *pHead = NULL;
    tCmdNode *pThisNode;
    char* pInputCmd;
    pHead = InitCmdList();
    if(pHead == NULL)
    {
        printf("Error: linked list is not built!");
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
