/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int jinwei=0;
        ListNode* p=l1,*q=l2;
        while(p->next!=NULL&&q->next!=NULL)
        {
           p->val+=q->val+jinwei;
           q->val+=p->val+jinwei;
           if(p->val>9)
            {
               jinwei=1;
               p->val-=10;
               q->val-=10;
            }
            else 
            {
               jinwei=0;
            }
            p=p->next;
            q=q->next;
        }

        if(p->next==NULL&&q->next==NULL)
        {
            p->val+=q->val+jinwei;
            if(p->val>9)
            {
                p->val-=10;
                jinwei=1;
                if(p->next==NULL&&jinwei==1)
              {
                ListNode r(1);
                ListNode* s=&r;
                s->val=1;
                s->next=NULL;
                q->next=s;
              }


            }
            else jinwei=0;
        }

        else if(p->next==NULL)
        {
            q->val+=p->val+jinwei;
            if(q->val>9)
           {
               jinwei=1;
               q->val-=10;
           }
             else 
           {
               jinwei=0;
           }
           q=q->next;
           while(q->next!=NULL)
           {
               q->val+=jinwei;
                if(q->val>9)
               {
               jinwei=1;
               q->val-=10;
               }
                else 
               {
               jinwei=0;
               }
               q=q->next;

            }
            if(q->next==NULL&&jinwei==1)
            {
                ListNode r(1);
                ListNode* s=&r;
                s->val=1;
                s->next=NULL;
                q->next=s;
            }

            return l2;
        }

        else if(p->next==NULL)
        {
             p->val+=q->val+jinwei;
            if(p->val>9)
           {
               jinwei=1;
               p->val-=10;
           }
             else 
           {
               jinwei=0;
           }
           p=p->next;
           while(p->next!=NULL)
           {
               p->val+=jinwei;
                if(p->val>9)
               {
               jinwei=1;
               p->val-=10;
               }
                else 
              {
               jinwei=0;
              }
              p=p->next;
            }
            if(p->next==NULL&&jinwei==1)
            {
                ListNode r(1);
                ListNode* s=&r;
                s->val=1;
                s->next=NULL;
                q->next=s;
            }

            return l1;

        }
        return l1;
    }
};

