#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
typedef int item_type;
class node
{
  public:
   item_type info;
   node * next;
};
class list
{
    node * start;
    node * end;

   public:
    list()
     {
      start=NULL;
      end=NULL;
     }
    int isempty()
     {
      return start==NULL;
     }
     node * create(item_type item)
     {
      node * ptr;
      ptr=(node *)malloc(sizeof(node));
      if(ptr==NULL)
       {
	puts("Memory space id Full !!");
	return NULL;
       }
       ptr->info=item;
       ptr->next=NULL;
       return ptr;
     }
    node * search(item_type item)
     {
      node * ptr;

       for(ptr=start;ptr;ptr=ptr->next)
       {
	if(ptr->info==item)
	break;
       }
      return ptr;
     }
    node * searchprevious(item_type item)
     {
      node * ptr,* pre;
      for(ptr=start,pre=NULL;ptr;pre=ptr,ptr=ptr->next)
       {
	if(ptr->info==item);
	 break;
       }
       return pre;
     }
    void insertfirst(item_type item)
     {
      node * ptr;
      ptr=create(item);
      if(ptr==NULL)
	return ;
      if(isempty())
       {
	start=end=ptr;
       }
      else
       {
	ptr->next=start;
	start=ptr;
       }
     }
    void insertlast(item_type item)
     {
      node * ptr;
      ptr=create(item);
      if(ptr==NULL)
       return;
      if(isempty())
      {
       start=end=ptr;
      }
      else
      {
	end->next=ptr;
	end=ptr;
      }
     }
    void createlist(int n)
     {
      int i;
      item_type item;
      printf("Enter %d Element",n);
      for(i=0;i<n;i++)
      {
	cin>>item;
	insertlast(item);
      }
     }
    void insertaftergiven(item_type item,item_type given)
     {
      node * ptr,* gptr;
      gptr=search(given);
       if(gptr==NULL)
       {
	cout<<"Searching Item not Found"<<endl;
	return;
       }
       ptr=create(item);
       if(gptr==end)
	{
	 end->next=ptr;
	 end=ptr;
	}
       else
	{
	ptr->next=gptr->next;
	gptr->next=ptr;
	}
     }
    void insertbeforegiven(item_type item,item_type given)
     {
       node * ptr, * gptr, * pre;
       gptr=search(given);
       if(gptr==NULL)
       {
	cout<<"Searching item Not Found !!"<<endl;
	return;
       }
	ptr=create(item);
       if(gptr==start)
       {
	ptr->next=start;
	start=ptr;
       }
       else
       {
	pre=searchprevious(given);
	ptr->next=gptr;
	pre->next=ptr;
       }
     }
    void inseratgivenposition(item_type item,item_type position)
     {
       node * ptr,* curr;
	if(position<1 && position>size()+1)
	{
	 cout<<"Position not found !!"<<endl;
	 return;
	}
      ptr=create(item);
      curr=start;
      int c=position-1;
      while(--c)
      {
       curr=curr->next;
      }
      if(curr->next==NULL)
      {
       curr->next=ptr;
       end=ptr;
      }
      else if(position==1)
      {
       ptr->next=start;
       start=ptr;
      }
      else
      {
       ptr->next=curr->next;
       curr->next=ptr;
      }
  }

    void insertinsortedlist(item_type item)
    {
     node * ptr, * gptr,* pre;
     for(gptr=start;gptr;gptr=gptr->next)
     {
       if(gptr->info > item)
       break;
     }
     ptr=create(item);
     if(start==NULL)
     {
      start=end=ptr;
     }
     else if(gptr==start)
     {
      ptr->next=start;
      start=ptr;
     }
     else if(gptr==end)
     {
      end->next=ptr;
      end=ptr;
     }
     else
     {
      pre=searchprevious(gptr->info);
      ptr->next=pre->next;
      pre->next=ptr;
     }
    }
    int size()
    {
     node * ptr;
     int c=0;
     for(ptr=start;ptr;ptr=ptr->next)
     {
      c++;
     }
     return c;
    }
    void display()
    {
     node * ptr;
     for(ptr=start;ptr;ptr=ptr->next)
     {
       printf("%d ",ptr->info);
     }
    }
    item_type deletefirst()
    {
     node * temp;
     item_type item;
     if(isempty())
     {
      puts("List is Already empty !! NO operation performed !!");
      return 0;
     }
      temp=start;
      item=start->info;
     if(start==end)
     {
      start=end=NULL;
     }
     else
     {
      start= temp->next;
     }
     free(temp);
     return item;
    }
    item_type deletelast()
    {
     node * temp,* pre;
     item_type item;
     if(isempty())
     {
      puts("List is already empty !!");
      return 0;
     }
     temp=end;
     item=temp->info;
     if(start==end)
     {
      start=end=NULL;
     }
     else
     {
      for(pre=start;pre->next!=end;pre=pre->next);
      pre->next=NULL;
      end=pre;
     }
     free(temp);
     return item;
    }
    item_type deletegiven(item_type given)
    {
      node * ptr,* pre,* temp;
      if(isempty())
      {
       puts("List is already Empty !!");
       return 0;
      }
      ptr=search(given);
      pre=searchprevious(given);
      if(ptr==NULL)
      {
       puts("Given item not Found !!");
       return 0;
      }
      temp=ptr;
      if(start==end)
      {
       start=end=NULL;
      }
      else if(ptr==start)
      {
       start=ptr->next;
      }
      else if(ptr==end)
      {
       pre->next=NULL;
       end=pre;
      }
      else
      {
	pre->next=ptr->next;
      }
      free(temp);
      return given;

    }
    item_type deleteaftergiven(item_type given)
    {
     node * ptr, * pre , * temp;
     item_type item;
     if(isempty())
      {
       puts("List is already Empty !!");
       return 0;
      }
     ptr=search(given);
     if(ptr==NULL)
     {
      puts("No deleted element found");
       return 0;
     }
     if(ptr==end)
     {
      puts("No deletion possible");
      return 0;
     }
     temp= ptr->next;
     item=temp->info;
     if(ptr->next == end)
     {
      ptr->next =NULL;
      end=ptr;
     }
     else
     {
      ptr->next=temp->next;
     }
     free(temp);
     return item;
    }
    item_type deletebeforegiven(item_type given)
    {
     node * ptr, * pre, * temp;
     item_type item;
     if(isempty())
      {
       puts("List is already Empty !!");
       return 0;
      }
     ptr=search(given);
     if(ptr==NULL)
     {
      puts("No deleted element found");
       return 0;
     }
     if(ptr==start)
     {
      puts("No deletion possible !!");
      return 0;
     }
      pre=searchprevious(given);
      temp=pre;
      item=pre->info;
     if(ptr==start->next)
      {
       start=ptr;
      }
      else
      {
       pre->next=ptr->next;
      }
      free(temp);
      return item;
    }
    item_type deleteatgivenposition(item_type position);
    item_type deletelargest();
    item_type deletesmallest();
    item_type findmin();
    item_type findmax();
    void reverse();
};



